// @generated by Thrift for thrift/compiler/test/fixtures/inheritance/src/module.thrift
// This file is probably not the place you want to edit!

//! Mock definitions for `module`.
//!
//! Client mocks. For every service, a struct TheService that implements
//! client::TheService.
//!
//! As an example of the generated API, for the following thrift service in
//! example.thrift:
//!
//! ```thrift
//! service MyService {
//!     FunctionResponse myFunction(
//!         1: FunctionRequest request,
//!     ) throws {
//!         1: StorageException s,
//!         2: NotFoundException n,
//!     ),
//!
//!     // other functions
//! }
//! ```
//!
//! we would end up with this mock object in an `example_mocks` crate:
//!
//! ```
//! # const _: &str = stringify! {
//! impl example_clients::MyService for MyService<'mock> {...}
//!
//! pub struct MyService<'mock> {
//!     pub myFunction: myFunction<'mock>,
//!     // ...
//! }
//!
//! impl myFunction<'mock> {
//!     // directly return the given success response
//!     pub fn ret(&self, value: FunctionResponse);
//!
//!     // invoke closure to compute success response
//!     pub fn mock(
//!         &self,
//!         mock: impl FnMut(FunctionRequest) -> FunctionResponse + Send + Sync + 'mock,
//!     );
//!
//!     // invoke closure to compute response
//!     pub fn mock_result(
//!         &self,
//!         mock: impl FnMut(FunctionRequest) -> Result<FunctionResponse, example_services::errors::MyFunctionExn> + Send + Sync + 'mock,
//!     );
//!
//!     // return one of the function's declared exceptions
//!     pub fn throw<E>(&self, exception: E)
//!     where
//!         E: Clone + Into<example_services::errors::MyFunctionExn> + Send + Sync + 'mock;
//! }
//! # };
//! ```
//!
//! The intended usage from a test would be:
//!
//! ```
//! # const _: &str = stringify! {
//! use std::sync::Arc;
//! use example_clients::MyService;
//!
//! #[tokio::test]
//! async fn test_my_client() {
//!     let mock = Arc::new(example_mocks::new::<dyn MyService>());
//!
//!     // directly return a success response
//!     let resp = FunctionResponse {...};
//!     mock.myFunction.ret(resp);
//!
//!     // or give a closure to compute the success response
//!     mock.myFunction.mock(|request| FunctionResponse {...});
//!
//!     // or throw one of the function's exceptions
//!     mock.myFunction.throw(StorageException::ItFailed);
//!
//!     // or compute a Result (useful if your exceptions aren't Clone)
//!     mock.myFunction.mock_result(|request| Err(...));
//!
//!     let out = do_the_thing(mock).await.unwrap();
//!     assert!(out.what_i_expected());
//! }
//!
//! async fn do_the_thing(
//!     client: Arc<dyn MyService + Send + Sync + 'static>,
//! ) -> Out {...}
//! # };
//! ```

#![recursion_limit = "100000000"]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies, unused_imports, clippy::all)]

pub(crate) use :: as types;
pub(crate) use :: as client;
#[allow(deprecated)]
pub(crate) use ::::dependencies;
pub(crate) use ::::errors;

pub fn new<'mock, Client>() -> Client::Mock<'mock>
where
    Client: ?::std::marker::Sized + DynClient,
{
    Client::mock()
}

pub trait DynClient {
    type Mock<'mock>;
    fn mock<'mock>() -> Self::Mock<'mock>;
}

pub struct MyRoot<'mock> {
    pub do_root: r#impl::my_root::do_root<'mock>,
    _marker: ::std::marker::PhantomData<&'mock ()>,
}

impl crate::DynClient for dyn ::::MyRoot {
    type Mock<'mock> = MyRoot<'mock>;
    fn mock<'mock>() -> Self::Mock<'mock> {
        MyRoot {
            do_root: r#impl::my_root::do_root::unimplemented(),
            _marker: ::std::marker::PhantomData,
        }
    }
}

impl<'mock> ::::MyRoot for MyRoot<'mock> {
    fn do_root(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_root::DoRootError>> {
        let mut closure = self.do_root.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut() -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure()))
    }
}

pub struct MyNode<'mock> {
    pub parent: crate::MyRoot<'mock>,
    pub do_mid: r#impl::my_node::do_mid<'mock>,
    _marker: ::std::marker::PhantomData<&'mock ()>,
}

impl crate::DynClient for dyn ::::MyNode {
    type Mock<'mock> = MyNode<'mock>;
    fn mock<'mock>() -> Self::Mock<'mock> {
        MyNode {
            parent: crate::new::<dyn crate::client::MyRoot>(),
            do_mid: r#impl::my_node::do_mid::unimplemented(),
            _marker: ::std::marker::PhantomData,
        }
    }
}

impl<'mock> ::::MyNode for MyNode<'mock> {
    fn do_mid(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_node::DoMidError>> {
        let mut closure = self.do_mid.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut() -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure()))
    }
}

#[::async_trait::async_trait]
#[allow(deprecated)]
impl<'mock> ::std::convert::AsRef<dyn crate::client::MyRoot + 'mock> for MyNode<'mock>
{
    fn as_ref(&self) -> &(dyn crate::client::MyRoot + 'mock) {
        &self.parent
    }
}

pub struct MyLeaf<'mock> {
    pub parent: crate::MyNode<'mock>,
    pub do_leaf: r#impl::my_leaf::do_leaf<'mock>,
    _marker: ::std::marker::PhantomData<&'mock ()>,
}

impl crate::DynClient for dyn ::::MyLeaf {
    type Mock<'mock> = MyLeaf<'mock>;
    fn mock<'mock>() -> Self::Mock<'mock> {
        MyLeaf {
            parent: crate::new::<dyn crate::client::MyNode>(),
            do_leaf: r#impl::my_leaf::do_leaf::unimplemented(),
            _marker: ::std::marker::PhantomData,
        }
    }
}

impl<'mock> ::::MyLeaf for MyLeaf<'mock> {
    fn do_leaf(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_leaf::DoLeafError>> {
        let mut closure = self.do_leaf.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut() -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure()))
    }
}

#[::async_trait::async_trait]
#[allow(deprecated)]
impl<'mock> ::std::convert::AsRef<dyn crate::client::MyNode + 'mock> for MyLeaf<'mock>
{
    fn as_ref(&self) -> &(dyn crate::client::MyNode + 'mock) {
        &self.parent
    }
}

#[::async_trait::async_trait]
#[allow(deprecated)]
impl<'mock> ::std::convert::AsRef<dyn crate::client::MyRoot + 'mock> for MyLeaf<'mock>
{
    fn as_ref(&self) -> &(dyn crate::client::MyRoot + 'mock) {
        &self.parent
    }
}

pub mod r#impl {
    pub mod my_root {

        pub struct do_root<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut() -> ::std::result::Result<
                    (),
                    ::::errors::my_root::DoRootError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> do_root<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|| panic!(
                        "{}::{} is not mocked",
                        "MyRoot",
                        "do_root",
                    ))),
                }
            }

            pub fn ret(&self, value: ()) {
                self.mock(move || value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut() -> () + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Ok(mock()));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut() -> ::std::result::Result<(), ::::errors::my_root::DoRootError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || mock());
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_root::DoRootError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Err(exception.clone().into()));
            }
        }
    }
    pub mod my_node {

        pub struct do_mid<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut() -> ::std::result::Result<
                    (),
                    ::::errors::my_node::DoMidError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> do_mid<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|| panic!(
                        "{}::{} is not mocked",
                        "MyNode",
                        "do_mid",
                    ))),
                }
            }

            pub fn ret(&self, value: ()) {
                self.mock(move || value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut() -> () + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Ok(mock()));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut() -> ::std::result::Result<(), ::::errors::my_node::DoMidError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || mock());
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_node::DoMidError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Err(exception.clone().into()));
            }
        }
    }
    pub mod my_leaf {

        pub struct do_leaf<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut() -> ::std::result::Result<
                    (),
                    ::::errors::my_leaf::DoLeafError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> do_leaf<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|| panic!(
                        "{}::{} is not mocked",
                        "MyLeaf",
                        "do_leaf",
                    ))),
                }
            }

            pub fn ret(&self, value: ()) {
                self.mock(move || value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut() -> () + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Ok(mock()));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut() -> ::std::result::Result<(), ::::errors::my_leaf::DoLeafError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || mock());
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_leaf::DoLeafError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Err(exception.clone().into()));
            }
        }
    }
}
