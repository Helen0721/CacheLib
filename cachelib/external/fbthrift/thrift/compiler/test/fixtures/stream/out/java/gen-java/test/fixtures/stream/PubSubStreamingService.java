/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.stream;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.service.*;
import com.facebook.thrift.client.*;
import com.google.common.util.concurrent.ListenableFuture;
import java.io.*;
import java.util.*;
import reactor.core.publisher.Mono;

@SwiftGenerated
@com.facebook.swift.service.ThriftService("PubSubStreamingService")
public interface PubSubStreamingService extends java.io.Closeable, com.facebook.thrift.util.BlockingService {
    static com.facebook.thrift.server.RpcServerHandlerBuilder<PubSubStreamingService> serverHandlerBuilder(PubSubStreamingService _serverImpl) {
        return new com.facebook.thrift.server.RpcServerHandlerBuilder<PubSubStreamingService>(_serverImpl) {
                @java.lang.Override
                public com.facebook.thrift.server.RpcServerHandler build() {
                return new PubSubStreamingServiceRpcServerHandler(impl, eventHandlers);
            }
        };
    }

    static com.facebook.thrift.client.ClientBuilder<PubSubStreamingService> clientBuilder() {
        return new ClientBuilder<PubSubStreamingService>() {
            @java.lang.Override
            public PubSubStreamingService build(Mono<RpcClient> rpcClientMono) {
                PubSubStreamingService.Reactive _delegate =
                    new PubSubStreamingServiceReactiveClient(protocolId, rpcClientMono, headersMono, persistentHeadersMono);
                return new PubSubStreamingServiceReactiveBlockingWrapper(_delegate);
            }
        };
    }

    @com.facebook.swift.service.ThriftService("PubSubStreamingService")
    public interface Async extends java.io.Closeable, com.facebook.thrift.util.AsyncService {
        static com.facebook.thrift.server.RpcServerHandlerBuilder<PubSubStreamingService.Async> serverHandlerBuilder(PubSubStreamingService.Async _serverImpl) {
            return new com.facebook.thrift.server.RpcServerHandlerBuilder<PubSubStreamingService.Async>(_serverImpl) {
                @java.lang.Override
                public com.facebook.thrift.server.RpcServerHandler build() {
                    return new PubSubStreamingServiceRpcServerHandler(impl, eventHandlers);
                }
            };
        }

        static com.facebook.thrift.client.ClientBuilder<PubSubStreamingService.Async> clientBuilder() {
            return new ClientBuilder<PubSubStreamingService.Async>() {
                @java.lang.Override
                public PubSubStreamingService.Async build(Mono<RpcClient> rpcClientMono) {
                    PubSubStreamingService.Reactive _delegate =
                        new PubSubStreamingServiceReactiveClient(protocolId, rpcClientMono, headersMono, persistentHeadersMono);
                    return new PubSubStreamingServiceReactiveAsyncWrapper(_delegate);
                }
            };
        }

        @java.lang.Override void close();

    }
    @java.lang.Override void close();

    @com.facebook.swift.service.ThriftService("PubSubStreamingService")
    interface Reactive extends reactor.core.Disposable, com.facebook.thrift.util.ReactiveService {
        static com.facebook.thrift.server.RpcServerHandlerBuilder<PubSubStreamingService.Reactive> serverHandlerBuilder(PubSubStreamingService.Reactive _serverImpl) {
            return new com.facebook.thrift.server.RpcServerHandlerBuilder<PubSubStreamingService.Reactive>(_serverImpl) {
                @java.lang.Override
                public com.facebook.thrift.server.RpcServerHandler build() {
                    return new PubSubStreamingServiceRpcServerHandler(impl, eventHandlers);
                }
            };
        }

        static com.facebook.thrift.client.ClientBuilder<PubSubStreamingService.Reactive> clientBuilder() {
            return new ClientBuilder<PubSubStreamingService.Reactive>() {
                @java.lang.Override
                public PubSubStreamingService.Reactive build(Mono<RpcClient> rpcClientMono) {
                    return new PubSubStreamingServiceReactiveClient(protocolId, rpcClientMono, headersMono, persistentHeadersMono);
                }
            };
        }

        reactor.core.publisher.Flux<Integer> returnstream(final int i32From, final int i32To);

        default reactor.core.publisher.Flux<Integer> returnstream(final int i32From, final int i32To, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Flux<ResponseWrapper<Integer>> returnstreamWrapper(final int i32From, final int i32To, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Flux<Integer> streamthrows(final int foo);

        default reactor.core.publisher.Flux<Integer> streamthrows(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Flux<ResponseWrapper<Integer>> streamthrowsWrapper(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Flux<Integer> servicethrows(final int foo);

        default reactor.core.publisher.Flux<Integer> servicethrows(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Flux<ResponseWrapper<Integer>> servicethrowsWrapper(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Flux<Integer> servicethrows2(final int foo);

        default reactor.core.publisher.Flux<Integer> servicethrows2(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Flux<ResponseWrapper<Integer>> servicethrows2Wrapper(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Flux<Integer> boththrows(final int foo);

        default reactor.core.publisher.Flux<Integer> boththrows(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Flux<ResponseWrapper<Integer>> boththrowsWrapper(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Flux<com.facebook.thrift.model.StreamResponse<Integer,Integer>> responseandstreamstreamthrows(final int foo);

        default reactor.core.publisher.Flux<com.facebook.thrift.model.StreamResponse<Integer,Integer>> responseandstreamstreamthrows(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Flux<ResponseWrapper<com.facebook.thrift.model.StreamResponse<Integer,Integer>>> responseandstreamstreamthrowsWrapper(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Flux<com.facebook.thrift.model.StreamResponse<Integer,Integer>> responseandstreamservicethrows(final int foo);

        default reactor.core.publisher.Flux<com.facebook.thrift.model.StreamResponse<Integer,Integer>> responseandstreamservicethrows(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Flux<ResponseWrapper<com.facebook.thrift.model.StreamResponse<Integer,Integer>>> responseandstreamservicethrowsWrapper(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Flux<com.facebook.thrift.model.StreamResponse<Integer,Integer>> responseandstreamboththrows(final int foo);

        default reactor.core.publisher.Flux<com.facebook.thrift.model.StreamResponse<Integer,Integer>> responseandstreamboththrows(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Flux<ResponseWrapper<com.facebook.thrift.model.StreamResponse<Integer,Integer>>> responseandstreamboththrowsWrapper(final int foo, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        reactor.core.publisher.Flux<Integer> returnstreamFast(final int i32From, final int i32To);

        default reactor.core.publisher.Flux<Integer> returnstreamFast(final int i32From, final int i32To, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

        default reactor.core.publisher.Flux<ResponseWrapper<Integer>> returnstreamFastWrapper(final int i32From, final int i32To, RpcOptions rpcOptions) {
            throw new UnsupportedOperationException();
        }

    }
}
