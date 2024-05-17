/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.service_schema;

import com.facebook.thrift.client.*;
import java.util.*;

public class PrimitivesServiceAsyncReactiveWrapper 
    implements PrimitivesService.Reactive {
    private final PrimitivesService.Async _delegate;

    public PrimitivesServiceAsyncReactiveWrapper(PrimitivesService.Async _delegate) {
        
        this._delegate = _delegate;
    }

    @java.lang.Override
    public void dispose() {
        _delegate.close();
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Long> init(final long param0, final long param1) {
        return com.facebook.thrift.util.FutureUtil.toMono(() -> _delegate.init(param0, param1));
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<test.fixtures.service_schema.Result> methodThatThrows() {
        return com.facebook.thrift.util.FutureUtil.toMono(() -> _delegate.methodThatThrows());
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Void> returnVoidMethod(final long id) {
        return com.facebook.thrift.util.FutureUtil.toMono(() -> _delegate.returnVoidMethod(id));
    }

}
