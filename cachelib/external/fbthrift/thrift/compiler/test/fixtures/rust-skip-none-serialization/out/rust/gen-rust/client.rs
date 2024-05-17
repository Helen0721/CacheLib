// @generated by Thrift for thrift/compiler/test/fixtures/rust-skip-none-serialization/src/module.thrift
// This file is probably not the place you want to edit!

//! Client implementation for each service in `module`.

#![recursion_limit = "100000000"]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies, unused_imports, clippy::all)]


#[doc(inline)]
pub use :: as types;

pub mod errors;

pub(crate) use crate as client;
pub(crate) use ::::services;

// Used by Thrift-generated code to implement service inheritance.
#[doc(hidden)]
#[deprecated]
pub mod dependencies {
}


/// Client definitions for `MyService`.
pub struct MyServiceImpl<P, T, S = ::fbthrift::NoopSpawner> {
    transport: T,
    _phantom: ::std::marker::PhantomData<fn() -> (P, S)>,
}

impl<P, T, S> MyServiceImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    pub fn new(
        transport: T,
    ) -> Self {
        Self {
            transport,
            _phantom: ::std::marker::PhantomData,
        }
    }

    pub fn transport(&self) -> &T {
        &self.transport
    }


    fn _ping_impl(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PingError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "MyService";
            SERVICE_METHOD_NAME = "MyService.ping";
        }
        let args = self::Args_MyService_ping {
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("ping", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "MyService.ping"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let res = ::fbthrift::help::async_deserialize_response_envelope::<P, crate::errors::my_service::PingReader, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(res) => res,
                ::std::result::Result::Err(aexn) => {
                    ::std::result::Result::Err(crate::errors::my_service::PingError::ApplicationException(aexn))
                }
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "MyService.ping"))
        .boxed()
    }

    fn _getRandomData_impl(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetRandomDataError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "MyService";
            SERVICE_METHOD_NAME = "MyService.getRandomData";
        }
        let args = self::Args_MyService_getRandomData {
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("getRandomData", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "MyService.getRandomData"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let res = ::fbthrift::help::async_deserialize_response_envelope::<P, crate::errors::my_service::GetRandomDataReader, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(res) => res,
                ::std::result::Result::Err(aexn) => {
                    ::std::result::Result::Err(crate::errors::my_service::GetRandomDataError::ApplicationException(aexn))
                }
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "MyService.getRandomData"))
        .boxed()
    }

    fn _hasDataById_impl(
        &self,
        arg_id: ::std::primitive::i64,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::bool, crate::errors::my_service::HasDataByIdError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "MyService";
            SERVICE_METHOD_NAME = "MyService.hasDataById";
        }
        let args = self::Args_MyService_hasDataById {
            id: arg_id,
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("hasDataById", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "MyService.hasDataById"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let res = ::fbthrift::help::async_deserialize_response_envelope::<P, crate::errors::my_service::HasDataByIdReader, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(res) => res,
                ::std::result::Result::Err(aexn) => {
                    ::std::result::Result::Err(crate::errors::my_service::HasDataByIdError::ApplicationException(aexn))
                }
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "MyService.hasDataById"))
        .boxed()
    }

    fn _getDataById_impl(
        &self,
        arg_id: ::std::primitive::i64,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetDataByIdError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "MyService";
            SERVICE_METHOD_NAME = "MyService.getDataById";
        }
        let args = self::Args_MyService_getDataById {
            id: arg_id,
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("getDataById", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "MyService.getDataById"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let res = ::fbthrift::help::async_deserialize_response_envelope::<P, crate::errors::my_service::GetDataByIdReader, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(res) => res,
                ::std::result::Result::Err(aexn) => {
                    ::std::result::Result::Err(crate::errors::my_service::GetDataByIdError::ApplicationException(aexn))
                }
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "MyService.getDataById"))
        .boxed()
    }

    fn _putDataById_impl(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PutDataByIdError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "MyService";
            SERVICE_METHOD_NAME = "MyService.putDataById";
        }
        let args = self::Args_MyService_putDataById {
            id: arg_id,
            data: arg_data,
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("putDataById", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "MyService.putDataById"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let res = ::fbthrift::help::async_deserialize_response_envelope::<P, crate::errors::my_service::PutDataByIdReader, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(res) => res,
                ::std::result::Result::Err(aexn) => {
                    ::std::result::Result::Err(crate::errors::my_service::PutDataByIdError::ApplicationException(aexn))
                }
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "MyService.putDataById"))
        .boxed()
    }

    fn _lobDataById_impl(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::LobDataByIdError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "MyService";
            SERVICE_METHOD_NAME = "MyService.lobDataById";
        }
        let args = self::Args_MyService_lobDataById {
            id: arg_id,
            data: arg_data,
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("lobDataById", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "MyService.lobDataById"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let res = ::fbthrift::help::async_deserialize_response_envelope::<P, crate::errors::my_service::LobDataByIdReader, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(res) => res,
                ::std::result::Result::Err(aexn) => {
                    ::std::result::Result::Err(crate::errors::my_service::LobDataByIdError::ApplicationException(aexn))
                }
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "MyService.lobDataById"))
        .boxed()
    }
}

pub trait MyService: ::std::marker::Send {
    fn ping(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PingError>>;

    fn getRandomData(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetRandomDataError>>;

    fn hasDataById(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::bool, crate::errors::my_service::HasDataByIdError>>;

    fn getDataById(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetDataByIdError>>;

    fn putDataById(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PutDataByIdError>>;

    fn lobDataById(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::LobDataByIdError>>;
}

pub trait MyServiceExt<T>: MyService
where
    T: ::fbthrift::Transport,
{
    fn ping_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PingError>>;
    fn getRandomData_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetRandomDataError>>;
    fn hasDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::bool, crate::errors::my_service::HasDataByIdError>>;
    fn getDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetDataByIdError>>;
    fn putDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PutDataByIdError>>;
    fn lobDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::LobDataByIdError>>;

    fn transport(&self) -> &T;
}

struct Args_MyService_ping<'a> {
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_MyService_ping<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "MyService.ping"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_stop();
        p.write_struct_end();
    }
}

struct Args_MyService_getRandomData<'a> {
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_MyService_getRandomData<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "MyService.getRandomData"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_stop();
        p.write_struct_end();
    }
}

struct Args_MyService_hasDataById<'a> {
    id: ::std::primitive::i64,
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_MyService_hasDataById<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "MyService.hasDataById"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_begin("id", ::fbthrift::TType::I64, 1i16);
        ::fbthrift::Serialize::write(&self.id, p);
        p.write_field_end();
        p.write_field_stop();
        p.write_struct_end();
    }
}

struct Args_MyService_getDataById<'a> {
    id: ::std::primitive::i64,
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_MyService_getDataById<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "MyService.getDataById"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_begin("id", ::fbthrift::TType::I64, 1i16);
        ::fbthrift::Serialize::write(&self.id, p);
        p.write_field_end();
        p.write_field_stop();
        p.write_struct_end();
    }
}

struct Args_MyService_putDataById<'a> {
    id: ::std::primitive::i64,
    data: &'a ::std::primitive::str,
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_MyService_putDataById<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "MyService.putDataById"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_begin("id", ::fbthrift::TType::I64, 1i16);
        ::fbthrift::Serialize::write(&self.id, p);
        p.write_field_end();
        p.write_field_begin("data", ::fbthrift::TType::String, 2i16);
        ::fbthrift::Serialize::write(&self.data, p);
        p.write_field_end();
        p.write_field_stop();
        p.write_struct_end();
    }
}

struct Args_MyService_lobDataById<'a> {
    id: ::std::primitive::i64,
    data: &'a ::std::primitive::str,
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_MyService_lobDataById<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "MyService.lobDataById"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_begin("id", ::fbthrift::TType::I64, 1i16);
        ::fbthrift::Serialize::write(&self.id, p);
        p.write_field_end();
        p.write_field_begin("data", ::fbthrift::TType::String, 2i16);
        ::fbthrift::Serialize::write(&self.data, p);
        p.write_field_end();
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P, T, S> MyService for MyServiceImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    fn ping(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PingError>> {
        let rpc_options = T::RpcOptions::default();
        self._ping_impl(
            rpc_options,
        )
    }
    fn getRandomData(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetRandomDataError>> {
        let rpc_options = T::RpcOptions::default();
        self._getRandomData_impl(
            rpc_options,
        )
    }
    fn hasDataById(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::bool, crate::errors::my_service::HasDataByIdError>> {
        let rpc_options = T::RpcOptions::default();
        self._hasDataById_impl(
            arg_id,
            rpc_options,
        )
    }
    fn getDataById(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetDataByIdError>> {
        let rpc_options = T::RpcOptions::default();
        self._getDataById_impl(
            arg_id,
            rpc_options,
        )
    }
    fn putDataById(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PutDataByIdError>> {
        let rpc_options = T::RpcOptions::default();
        self._putDataById_impl(
            arg_id,
            arg_data,
            rpc_options,
        )
    }
    fn lobDataById(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::LobDataByIdError>> {
        let rpc_options = T::RpcOptions::default();
        self._lobDataById_impl(
            arg_id,
            arg_data,
            rpc_options,
        )
    }
}

impl<P, T, S> MyServiceExt<T> for MyServiceImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    fn ping_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PingError>> {
        self._ping_impl(
            rpc_options,
        )
    }
    fn getRandomData_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetRandomDataError>> {
        self._getRandomData_impl(
            rpc_options,
        )
    }
    fn hasDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::bool, crate::errors::my_service::HasDataByIdError>> {
        self._hasDataById_impl(
            arg_id,
            rpc_options,
        )
    }
    fn getDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetDataByIdError>> {
        self._getDataById_impl(
            arg_id,
            rpc_options,
        )
    }
    fn putDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PutDataByIdError>> {
        self._putDataById_impl(
            arg_id,
            arg_data,
            rpc_options,
        )
    }
    fn lobDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::LobDataByIdError>> {
        self._lobDataById_impl(
            arg_id,
            arg_data,
            rpc_options,
        )
    }

    fn transport(&self) -> &T {
      self.transport()
    }
}

#[allow(deprecated)]
impl<'a, S> MyService for S
where
    S: ::std::convert::AsRef<dyn MyService + 'a>,
    S: ::std::marker::Send,
{
    fn ping(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PingError>> {
        self.as_ref().ping(
        )
    }
    fn getRandomData(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetRandomDataError>> {
        self.as_ref().getRandomData(
        )
    }
    fn hasDataById(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::bool, crate::errors::my_service::HasDataByIdError>> {
        self.as_ref().hasDataById(
            arg_id,
        )
    }
    fn getDataById(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetDataByIdError>> {
        self.as_ref().getDataById(
            arg_id,
        )
    }
    fn putDataById(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PutDataByIdError>> {
        self.as_ref().putDataById(
            arg_id,
            arg_data,
        )
    }
    fn lobDataById(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::LobDataByIdError>> {
        self.as_ref().lobDataById(
            arg_id,
            arg_data,
        )
    }
}

#[allow(deprecated)]
impl<S, T> MyServiceExt<T> for S
where
    S: ::std::convert::AsRef<dyn MyService + 'static>,
    S: ::std::convert::AsRef<dyn MyServiceExt<T> + 'static>,
    S: ::std::marker::Send,
    T: ::fbthrift::Transport,
{
    fn ping_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PingError>> {
        <Self as ::std::convert::AsRef<dyn MyServiceExt<T>>>::as_ref(self).ping_with_rpc_opts(
            rpc_options,
        )
    }
    fn getRandomData_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetRandomDataError>> {
        <Self as ::std::convert::AsRef<dyn MyServiceExt<T>>>::as_ref(self).getRandomData_with_rpc_opts(
            rpc_options,
        )
    }
    fn hasDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::bool, crate::errors::my_service::HasDataByIdError>> {
        <Self as ::std::convert::AsRef<dyn MyServiceExt<T>>>::as_ref(self).hasDataById_with_rpc_opts(
            arg_id,
            rpc_options,
        )
    }
    fn getDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetDataByIdError>> {
        <Self as ::std::convert::AsRef<dyn MyServiceExt<T>>>::as_ref(self).getDataById_with_rpc_opts(
            arg_id,
            rpc_options,
        )
    }
    fn putDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PutDataByIdError>> {
        <Self as ::std::convert::AsRef<dyn MyServiceExt<T>>>::as_ref(self).putDataById_with_rpc_opts(
            arg_id,
            arg_data,
            rpc_options,
        )
    }
    fn lobDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::LobDataByIdError>> {
        <Self as ::std::convert::AsRef<dyn MyServiceExt<T>>>::as_ref(self).lobDataById_with_rpc_opts(
            arg_id,
            arg_data,
            rpc_options,
        )
    }

    fn transport(&self) -> &T {
        <dyn MyServiceExt<T> as MyServiceExt<T>>::transport(<Self as ::std::convert::AsRef<dyn MyServiceExt<T>>>::as_ref(self))
    }
}

#[derive(Clone)]
pub struct make_MyService;

/// To be called by user directly setting up a client. Avoids
/// needing ClientFactory trait in scope, avoids unidiomatic
/// make_Trait name.
///
/// ```
/// # const _: &str = stringify! {
/// use bgs::client::BuckGraphService;
///
/// let protocol = BinaryProtocol::new();
/// let transport = HttpClient::new();
/// let client = <dyn BuckGraphService>::new(protocol, transport);
/// # };
/// ```
impl dyn MyService {
    pub fn new<P, T>(
        protocol: P,
        transport: T,
    ) -> ::std::sync::Arc<impl MyService + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
    {
        let spawner = ::fbthrift::help::NoopSpawner;
        Self::with_spawner(protocol, transport, spawner)
    }

    pub fn with_spawner<P, T, S>(
        protocol: P,
        transport: T,
        spawner: S,
    ) -> ::std::sync::Arc<impl MyService + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        let _ = protocol;
        let _ = spawner;
        ::std::sync::Arc::new(MyServiceImpl::<P, T, S>::new(transport))
    }
}

impl<T> dyn MyServiceExt<T>
where
    T: ::fbthrift::Transport,
{
    pub fn new<P>(
        protocol: P,
        transport: T,
    ) -> ::std::sync::Arc<impl MyServiceExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        P::Deserializer: ::std::marker::Send,
    {
        let spawner = ::fbthrift::help::NoopSpawner;
        Self::with_spawner(protocol, transport, spawner)
    }

    pub fn with_spawner<P, S>(
        protocol: P,
        transport: T,
        spawner: S,
    ) -> ::std::sync::Arc<impl MyServiceExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        let _ = protocol;
        let _ = spawner;
        ::std::sync::Arc::new(MyServiceImpl::<P, T, S>::new(transport))
    }
}

pub type MyServiceDynClient = <make_MyService as ::fbthrift::ClientFactory>::Api;
pub type MyServiceClient = ::std::sync::Arc<MyServiceDynClient>;

/// The same thing, but to be called from generic contexts where we are
/// working with a type parameter `C: ClientFactory` to produce clients.
impl ::fbthrift::ClientFactory for make_MyService {
    type Api = dyn MyService + ::std::marker::Send + ::std::marker::Sync + 'static;

    fn with_spawner<P, T, S>(protocol: P, transport: T, spawner: S) -> ::std::sync::Arc<Self::Api>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        <dyn MyService>::with_spawner(protocol, transport, spawner)
    }
}

