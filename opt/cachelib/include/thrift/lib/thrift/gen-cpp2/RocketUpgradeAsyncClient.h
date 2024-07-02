/**
 * Autogenerated by Thrift for /disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/lib/thrift/gen-cpp2/RocketUpgrade_types.h"

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace apache::thrift {
class RocketUpgrade;
} // namespace apache::thrift
namespace apache::thrift {

template <>
class Client<::apache::thrift::RocketUpgrade> : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "RocketUpgrade";
  }


  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual void upgradeToRocket(std::unique_ptr<apache::thrift::RequestCallback> callback);
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual void upgradeToRocket(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback);
 protected:
  void upgradeToRocketImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, bool stealRpcOptions = false);
 public:

  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual void sync_upgradeToRocket();
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual void sync_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions);

  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual folly::Future<folly::Unit> future_upgradeToRocket();
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual folly::SemiFuture<folly::Unit> semifuture_upgradeToRocket();
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual folly::Future<folly::Unit> future_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions);
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual folly::SemiFuture<folly::Unit> semifuture_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions);
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions);
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions);

#if FOLLY_HAS_COROUTINES
#if __clang__
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  template <int = 0>
  folly::coro::Task<void> co_upgradeToRocket() {
    return co_upgradeToRocket<false>(nullptr);
  }
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  template <int = 0>
  folly::coro::Task<void> co_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions) {
    return co_upgradeToRocket<true>(&rpcOptions);
  }
#else
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  folly::coro::Task<void> co_upgradeToRocket() {
    co_await folly::coro::detachOnCancel(semifuture_upgradeToRocket());
  }
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  folly::coro::Task<void> co_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions) {
    co_await folly::coro::detachOnCancel(semifuture_upgradeToRocket(rpcOptions));
  }
#endif
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<void> co_upgradeToRocket(apache::thrift::RpcOptions* rpcOptions) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientCoroCallback<false> callback(&returnState, co_await folly::coro::co_current_executor);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = upgradeToRocketCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static apache::thrift::RpcOptions* defaultRpcOptions = new apache::thrift::RpcOptions();
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if constexpr (hasRpcOptions) {
      upgradeToRocketImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    } else {
      upgradeToRocketImpl(*defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    if (auto ew = recv_wrapped_upgradeToRocket(returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual void upgradeToRocket(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback);


  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  static folly::exception_wrapper recv_wrapped_upgradeToRocket(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  static void recv_upgradeToRocket(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual void recv_instance_upgradeToRocket(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "/disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift", "service": "RocketUpgrade", "function": "upgradeToRocket"} */
  virtual folly::exception_wrapper recv_instance_wrapped_upgradeToRocket(::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_, typename RpcOptions>
  void upgradeToRocketT(Protocol_* prot, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback);
  std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> upgradeToRocketCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
};

} // namespace apache::thrift

namespace apache::thrift {
using RocketUpgradeAsyncClient [[deprecated("Use apache::thrift::Client<RocketUpgrade> instead")]] = ::apache::thrift::Client<RocketUpgrade>;
} // namespace apache::thrift
