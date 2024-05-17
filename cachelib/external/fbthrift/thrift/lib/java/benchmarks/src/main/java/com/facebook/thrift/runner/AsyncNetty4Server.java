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

package com.facebook.thrift.runner;

import com.facebook.swift.service.ThriftServerConfig;
import com.facebook.thrift.example.ping.PingRequest;
import com.facebook.thrift.example.ping.PingResponse;
import com.facebook.thrift.example.ping.PingService;
import com.facebook.thrift.legacy.server.LegacyServerTransport;
import com.facebook.thrift.legacy.server.LegacyServerTransportFactory;
import com.facebook.thrift.server.RpcServerHandler;
import com.google.common.util.concurrent.Futures;
import com.google.common.util.concurrent.ListenableFuture;
import io.netty.util.ResourceLeakDetector;
import java.net.InetSocketAddress;
import java.util.concurrent.locks.LockSupport;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class AsyncNetty4Server {
  private static final Logger logger = LoggerFactory.getLogger(AsyncNetty4Server.class);

  public static void main(String... args) {
    ResourceLeakDetector.setLevel(ResourceLeakDetector.Level.DISABLED);
    // Optional arg <port>, defaults to 0(OS selects an available port)
    int port = 0;
    if (args.length > 0) {
      port = Integer.parseInt(args[0]);
    }

    logger.info("create server");
    RpcServerHandler serverHandler =
        PingService.Async.serverHandlerBuilder(new PingServiceImpl()).build();

    logger.info("starting server");
    LegacyServerTransportFactory transportFactory =
        new LegacyServerTransportFactory(
            new ThriftServerConfig().setPort(port).setSslEnabled(false));
    LegacyServerTransport transport = transportFactory.createServerTransport(serverHandler).block();
    InetSocketAddress address = (InetSocketAddress) transport.getAddress();

    logger.info("server started at -> {}", address.toString());

    LockSupport.park();
  }

  public static class PingServiceImpl implements PingService.Async {
    @Override
    public void close() {}

    @Override
    public ListenableFuture<PingResponse> ping(PingRequest pingRequest) {
      return Futures.immediateFuture(new PingResponse(pingRequest.getRequest()));
    }

    @Override
    public ListenableFuture<PingResponse> pingException(PingRequest pingRequest) {
      return Futures.immediateFailedFuture(new UnsupportedOperationException("not implemented"));
    }

    @Override
    public ListenableFuture<byte[]> pingBinary(PingRequest pingRequest) {
      return null;
    }

    @Override
    public ListenableFuture<Void> pingVoid(PingRequest pingRequest) {
      return null;
    }
  }
}
