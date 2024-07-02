/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package thrift

import (
	"errors"
	"net"
	"time"
)

// Socket is a Transport that can be opened and reopened.
type Socket interface {
	Transport
	// Opens the socket for communication
	Open() error
}

type socket struct {
	conn    net.Conn
	addr    net.Addr
	timeout time.Duration
}

// SocketOption is the type used to set options on the socket
type SocketOption func(*socket) error

// SocketTimeout sets the timeout
func SocketTimeout(timeout time.Duration) SocketOption {
	return func(socket *socket) error {
		socket.timeout = timeout
		return nil
	}
}

// SocketAddr sets the socket address
func SocketAddr(hostPort string) SocketOption {
	return func(socket *socket) error {
		addr, err := net.ResolveTCPAddr("tcp6", hostPort)
		if err != nil {
			addr, err = net.ResolveTCPAddr("tcp", hostPort)
			if err != nil {
				return err
			}
		}
		socket.addr = addr
		return nil
	}
}

// SocketConn sets the socket connection
func SocketConn(conn net.Conn) SocketOption {
	return func(socket *socket) error {
		socket.conn = conn
		socket.addr = conn.RemoteAddr()
		return nil
	}
}

// NewSocket creates a net.Conn-backed Transport, given a host and port,
// or an existing connection.
//
//	trans, err := thrift.NewSocket(thrift.SocketAddr("localhost:9090"))
func NewSocket(options ...SocketOption) (Socket, error) {
	socket := &socket{}

	for _, option := range options {
		err := option(socket)
		if err != nil {
			return nil, err
		}
	}

	if socket.addr.String() == "" && socket.conn.RemoteAddr().String() == "" && socket.addr.Network() != "unix" {
		return nil, errors.New("must supply either an address or a connection")
	}

	return socket, nil
}

// Sets the socket timeout
func (p *socket) SetTimeout(timeout time.Duration) error {
	p.timeout = timeout
	return nil
}

func (p *socket) pushDeadline(read, write bool) {
	var t time.Time
	if p.timeout > 0 {
		t = time.Now().Add(time.Duration(p.timeout))
	}
	if read && write {
		p.conn.SetDeadline(t)
	} else if read {
		p.conn.SetReadDeadline(t)
	} else if write {
		p.conn.SetWriteDeadline(t)
	}
}

// Open connects the socket to a server, creating a new socket object if necessary.
func (p *socket) Open() error {
	if p.conn != nil {
		return NewTransportException(ALREADY_OPEN, "Socket already connected.")
	}
	if p.addr == nil {
		return NewTransportException(NOT_OPEN, "Cannot open nil address.")
	}
	if len(p.addr.Network()) == 0 {
		return NewTransportException(NOT_OPEN, "Cannot open bad network name.")
	}
	if len(p.addr.String()) == 0 {
		return NewTransportException(NOT_OPEN, "Cannot open bad address.")
	}
	var err error
	if p.conn, err = net.DialTimeout(p.addr.Network(), p.addr.String(), p.timeout); err != nil {
		return NewTransportException(NOT_OPEN, err.Error())
	}
	return nil
}

// Addr returns the address the Socket is listening on.
func (p *socket) Addr() net.Addr {
	return p.addr
}

// Conn retrieves the underlying net.Conn
func (p *socket) Conn() net.Conn {
	return p.conn
}

// Close cleans up all resources used by the Socket.
func (p *socket) Close() error {
	// Close the socket
	if p.conn != nil {
		err := p.conn.Close()
		if err != nil {
			return err
		}
		p.conn = nil
	}
	return nil
}

func (p *socket) Read(buf []byte) (int, error) {
	if p.conn == nil {
		return 0, NewTransportException(NOT_OPEN, "connection not open")
	}
	p.pushDeadline(true, false)
	n, err := p.conn.Read(buf)
	return n, NewTransportExceptionFromError(err)
}

func (p *socket) Write(buf []byte) (int, error) {
	if p.conn == nil {
		return 0, NewTransportException(NOT_OPEN, "connection not open")
	}
	p.pushDeadline(false, true)
	return p.conn.Write(buf)
}

// Flush is not implementable by lower-level transports but must still be kept
// for interface compatibility with Thrift1.
func (p *socket) Flush() error {
	return nil
}

// RemainingBytes is not implementable by lower-level transports but must still
// be kept for interface compatibility with Thrift1.
func (p *socket) RemainingBytes() uint64 {
	return UnknownRemaining // the truth is, we just don't know unless framed is used
}
