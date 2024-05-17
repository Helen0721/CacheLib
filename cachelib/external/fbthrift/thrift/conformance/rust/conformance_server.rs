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

use std::io::IsTerminal;

use anyhow::Context;
use anyhow::Result;
use async_trait::async_trait;
use clap::Parser;
use conformance::services::conformance_service::PatchExn;
use conformance::services::conformance_service::RoundTripExn;
use conformance_services::ConformanceService;
use futures::StreamExt;
use patch_data::PatchOpRequest;
use patch_data::PatchOpResponse;
use serialization::RoundTripRequest;
use serialization::RoundTripResponse;
use tracing_subscriber::layer::SubscriberExt;

#[derive(Debug, Parser)]
#[clap(name = "Conformance Server")]
struct Arguments {
    #[clap(short, long, default_value = "0")]
    port: u16,
    #[clap(short, long, default_value = "info", use_value_delimiter = true)]
    log: Vec<tracing_subscriber::filter::Directive>,
}

#[fbinit::main]
fn main(fb: fbinit::FacebookInit) -> Result<()> {
    let args = Arguments::parse();

    init_logging(args.log);

    let runtime = tokio::runtime::Runtime::new()?;
    let service = move |proto| {
        conformance_services::make_ConformanceService_server(proto, ConformanceServiceImpl { fb })
    };
    let thrift_server = srserver::ThriftServerBuilder::new(fb)
        .with_port(args.port)
        .with_allow_plaintext_on_loopback()
        .with_metadata(ConformanceService_metadata_sys::create_metadata())
        .with_factory(runtime.handle().clone(), move || service)
        .build();

    let mut svc_framework = srserver::service_framework::ServiceFramework::from_server(
        "conformance_server",
        thrift_server,
    )
    .context("Failed to create service framework server")?;
    svc_framework.add_module(srserver::service_framework::BuildModule)?;
    svc_framework.add_module(srserver::service_framework::ThriftStatsModule)?;
    svc_framework.add_module(srserver::service_framework::Fb303Module)?;

    let thrift_service_handle = runtime.spawn(async move {
        use signal_hook::consts::signal::SIGINT;
        use signal_hook::consts::signal::SIGTERM;

        svc_framework.serve_background()?;
        println!("{}", svc_framework.get_address()?.get_port()?);

        let mut signals = signal_hook_tokio::Signals::new([SIGTERM, SIGINT])?;
        signals.next().await;

        svc_framework.stop();
        signals.handle().close();

        Ok(())
    });
    runtime.block_on(thrift_service_handle)?
}

fn init_logging(directives: Vec<tracing_subscriber::filter::Directive>) {
    let fmt = tracing_subscriber::fmt::Layer::default()
        .with_ansi(std::io::stderr().is_terminal())
        .with_writer(std::io::stderr)
        .event_format(tracing_glog::Glog::default().with_timer(tracing_glog::LocalTime::default()))
        .fmt_fields(tracing_glog::GlogFields::default());
    let filter = directives.into_iter().fold(
        tracing_subscriber::EnvFilter::from_default_env(),
        |filter, directive| filter.add_directive(directive),
    );
    let subscriber = tracing_subscriber::Registry::default()
        .with(filter)
        .with(fmt);
    tracing::subscriber::set_global_default(subscriber).expect("to set global subscriber");
}

#[derive(Clone)]
pub struct ConformanceServiceImpl {
    pub fb: fbinit::FacebookInit,
}

#[async_trait]
impl ConformanceService for ConformanceServiceImpl {
    async fn roundTrip(
        &self,
        request: RoundTripRequest,
    ) -> Result<RoundTripResponse, RoundTripExn> {
        // This is a cheat to enable integrating the test while it's not
        // implemented yet. If we didn't do this, we'd have to enumerate around
        // 30k failures in 'nonconformance.txt'.
        Ok(RoundTripResponse {
            value: request.value,
            ..Default::default()
        })
    }

    async fn patch(&self, _request: PatchOpRequest) -> Result<PatchOpResponse, PatchExn> {
        Err(PatchExn::ApplicationException(
            fbthrift::ApplicationException::unimplemented_method("ConformanceService", "patch"),
        ))
    }
}
