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

#pragma once

#include <atomic>
#include <cstring>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <folly/Format.h>
#pragma GCC diagnostic pop
#include <folly/container/Array.h>
#include <folly/lang/Aligned.h>
#include <folly/synchronization/DistributedMutex.h>

#include "cachelib/allocator/Cache.h"
#include "cachelib/allocator/CacheStats.h"
#include "cachelib/allocator/Util.h"
#include "cachelib/allocator/datastruct/SieveList.h"
#include "cachelib/allocator/memory/serialize/gen-cpp2/objects_types.h"
#include "cachelib/common/CompilerUtils.h"
#include "cachelib/common/Mutex.h"

namespace facebook::cachelib {

class MMSieve {
 public:
  // unique identifier per MMType
  static const int kId;

  // forward declaration;serialize/gen-cpp2/objects_types.h
  template <typename T>
  using Hook = SieveListHook<T>;
  using SerializationType = serialization::MMSieveObject;
  using SerializationConfigType = serialization::MMSieveConfig;
  using SerializationTypeContainer = serialization::MMSieveCollection;

  // This is not applicable for MMSieve, just for compile of cache allocator
  enum LruType { NumTypes };

  // Config class for MMSieve
  struct Config {
    // create from serialized config
    explicit Config(SerializationConfigType configState)
        : Config(*configState.lruRefreshTime(),
                 *configState.lruRefreshRatio(),
                 *configState.updateOnWrite(),
                 *configState.updateOnRead(),
                 *configState.tryLockUpdate()) {}

    // @param time        the LRU refresh time in seconds.
    //                    An item will be promoted only once in each lru refresh
    //                    time depite the number of accesses it gets.
    // @param udpateOnW   whether to promote the item on write
    // @param updateOnR   whether to promote the item on read
    // @param tryLockU    whether to use a try lock when doing update.
    Config(uint32_t time, bool updateOnW, bool updateOnR)
        : Config(time, updateOnW, updateOnR, false) {}

    Config(uint32_t time,
           bool updateOnW,
           bool updateOnR,
           bool tryLockU)
        : Config(time, 0., updateOnW, updateOnR, tryLockU) {}

    // @param time        the LRU refresh time in seconds.
    //                    An item will be promoted only once in each lru refresh
    //                    time depite the number of accesses it gets.
    // @param ratio       the lru refresh ratio. The ratio times the
    //                    oldest element's lifetime in warm queue
    //                    would be the minimum value of LRU refresh time.
    // @param udpateOnW   whether to promote the item on write
    // @param updateOnR   whether to promote the item on read
    // @param tryLockU    whether to use a try lock when doing update. 
    Config(uint32_t time,
           double ratio,
           bool updateOnW,
           bool updateOnR,
           bool tryLockU)
        : Config(time, ratio, updateOnW, updateOnR, tryLockU, 0) {}

    // @param time        the LRU refresh time in seconds.
    //                    An item will be promoted only once in each lru refresh
    //                    time depite the number of accesses it gets.
    // @param ratio       the lru refresh ratio. The ratio times the
    //                    oldest element's lifetime in warm queue
    //                    would be the minimum value of LRU refresh time.
    // @param udpateOnW   whether to promote the item on write
    // @param updateOnR   whether to promote the item on read
    // @param tryLockU    whether to use a try lock when doing update. 
    // @param mmReconfigureInterval   Time interval for recalculating lru
    //                                refresh time according to the ratio.
    Config(uint32_t time,
           double ratio,
           bool updateOnW,
           bool updateOnR,
           bool tryLockU,
           uint32_t mmReconfigureInterval)
        : Config(time,
                 ratio,
                 updateOnW,
                 updateOnR,
                 tryLockU,
                 mmReconfigureInterval,
                 false) {}

    // @param time        the LRU refresh time in seconds.
    //                    An item will be promoted only once in each lru refresh
    //                    time depite the number of accesses it gets.
    // @param ratio       the lru refresh ratio. The ratio times the
    //                    oldest element's lifetime in warm queue
    //                    would be the minimum value of LRU refresh time.
    // @param udpateOnW   whether to promote the item on write
    // @param updateOnR   whether to promote the item on read
    // @param tryLockU    whether to use a try lock when doing update.
    // @param mmReconfigureInterval   Time interval for recalculating lru
    //                                refresh time according to the ratio.
    // useCombinedLockForIterators    Whether to use combined locking for
    //                                withEvictionIterator
    Config(uint32_t time,
           double ratio,
           bool updateOnW,
           bool updateOnR,
           bool tryLockU,
           uint32_t mmReconfigureInterval,
           bool useCombinedLockForIterators)
        : defaultLruRefreshTime(time),
          lruRefreshRatio(ratio),
          updateOnWrite(updateOnW),
          updateOnRead(updateOnR),
          tryLockUpdate(tryLockU),
          mmReconfigureIntervalSecs(
              std::chrono::seconds(mmReconfigureInterval)),
          useCombinedLockForIterators(useCombinedLockForIterators) {}

    Config() = default;
    Config(const Config& rhs) = default;
    Config(Config&& rhs) = default;

    Config& operator=(const Config& rhs) = default;
    Config& operator=(Config&& rhs) = default;

    template <typename... Args>
    void addExtraConfig(Args...) {}

    // threshold value in seconds to compare with a node's update time to
    // determine if we need to update the position of the node in the linked
    // list. By default this is 60s to reduce the contention on the lru lock.
    uint32_t defaultLruRefreshTime{60};
    uint32_t lruRefreshTime{defaultLruRefreshTime};

    // ratio of LRU refresh time to the tail age. If a refresh time computed
    // according to this ratio is larger than lruRefreshtime, we will adopt
    // this one instead of the lruRefreshTime set.
    double lruRefreshRatio{0.};

    // whether the lru needs to be updated on writes for recordAccess. If
    // false, accessing the cache for writes does not promote the cached item
    // to the head of the lru.
    bool updateOnWrite{false};

    // whether the lru needs to be updated on reads for recordAccess. If
    // false, accessing the cache for reads does not promote the cached item
    // to the head of the lru.
    bool updateOnRead{true};

    // whether to tryLock or lock the lru lock when attempting promotion on
    // access. If set, and tryLock fails, access will not result in promotion.
    bool tryLockUpdate{false};
  
    // Minimum interval between reconfigurations. If 0, reconfigure is never
    // called.
    std::chrono::seconds mmReconfigureIntervalSecs{};

    // Whether to use combined locking for withEvictionIterator.
    bool useCombinedLockForIterators{false};
  };

  // The container object which can be used to keep track of objects of type
  // T. T must have a public member of type Hook. This object is wrapper
  // around SieveList, is thread safe and can be accessed from multiple threads.
  // The current implementation models an LRU using the above SieveList
  // implementation.
  template <typename T, Hook<T> T::*HookPtr>
  struct Container {
   private:
    using SIEVEList = SieveList<T, HookPtr>;
    using Mutex = folly::DistributedMutex;
    using LockHolder = std::unique_lock<Mutex>;
    using PtrCompressor = typename T::PtrCompressor;
    using Time = typename Hook<T>::Time;
    using CompressedPtr = typename T::CompressedPtr;
    using RefFlags = typename T::Flags;

   public:
    Container() = default;
    Container(Config c, PtrCompressor compressor)
        : compressor_(std::move(compressor)),
          queue_(compressor_),
          config_(std::move(c)) {
      lruRefreshTime_ = config_.lruRefreshTime;
      nextReconfigureTime_ =
          config_.mmReconfigureIntervalSecs.count() == 0
              ? std::numeric_limits<Time>::max()
              : static_cast<Time>(util::getCurrentTimeSec()) +
                    config_.mmReconfigureIntervalSecs.count();
    }
    Container(serialization::MMSieveObject object, PtrCompressor compressor);

    Container(const Container&) = delete;
    Container& operator=(const Container&) = delete;

    using Iterator = typename SIEVEList::Iterator;

    // context for iterating the MM container. At any given point of time,
    // there can be only one iterator active since we need to lock the LRU for
    // iteration. we can support multiple iterators at same time, by using a
    // shared ptr in the context for the lock holder in the future.
    class LockedIterator : public Iterator {
     public:
      // noncopyable but movable.
      LockedIterator(const LockedIterator&) = delete;
      LockedIterator& operator=(const LockedIterator&) = delete;

      LockedIterator(LockedIterator&&) noexcept = default;

      // 1. Invalidate this iterator
      // 2. Unlock
      void destroy() {
        Iterator::reset();
        if (l_.owns_lock()) {
          l_.unlock();
        }
      }

      // Reset this iterator to the beginning
      void resetToBegin() {
        if (!l_.owns_lock()) {
          l_.lock();
        }
        Iterator::resetToBegin();
      }

     private:
      // private because it's easy to misuse and cause deadlock for MMSieve
      LockedIterator& operator=(LockedIterator&&) noexcept = default;

      // create an sieve iterator with the lock being held.
      LockedIterator(LockHolder l, const Iterator& iter) noexcept;

      // only the container can create iterators
      friend Container<T, HookPtr>;

      // lock protecting the validity of the iterator
      LockHolder l_;
    };

    // records the information that the node was accessed. 
    // accessed node remains where they are, so no locking required.
    // @param node  node that we want to mark as relevant/accessed
    // @param mode  the mode for the access operation.
    //
    // @return      True if the information is recorded and bumped the node
    //              to the head of the lru, returns false otherwise
    bool recordAccess(T& node, AccessMode mode) noexcept;

    // adds the given node into the container and marks it as being present in
    // the container. The node is added to the head of the lru.
    //
    // @param node  The node to be added to the container.
    // @return  True if the node was successfully added to the container. False
    //          if the node was already in the contianer. On error state of node
    //          is unchanged.
    bool add(T& node) noexcept;

    // removes the node from the lru and sets it previous and next to nullptr.
    //
    // @param node  The node to be removed from the container.
    // @return  True if the node was successfully removed from the container.
    //          False if the node was not part of the container. On error, the
    //          state of node is unchanged.
    bool remove(T& node) noexcept;

    // same as the above but uses an iterator context. The iterator is updated
    // on removal of the corresponding node to point to the next node. The
    // iterator context is responsible for locking.
    //
    // iterator will be advanced to the next node after removing the node
    //
    // @param it    Iterator that will be removed
    void remove(Iterator& it) noexcept;

    // replaces one node with another, at the same position
    //
    // @param oldNode   node being replaced
    // @param newNode   node to replace oldNode with
    //
    // @return true  If the replace was successful. Returns false if the
    //               destination node did not exist in the container, or if the
    //               source node already existed.
    bool replace(T& oldNode, T& newNode) noexcept;

    // Obtain an iterator that start from the tail and can be used
    // to search for evictions. This iterator holds a lock to this
    // container and only one such iterator can exist at a time
    LockedIterator getEvictionIterator()  noexcept;

    // Execute provided function under container lock. Function gets
    // iterator passed as parameter.
    template <typename F>
    void withEvictionIterator(F&& f);

    // Execute provided function under container lock.
    template <typename F>
    void withContainerLock(F&& f);

    // get copy of current config
    Config getConfig() const;

    // override the existing config with the new one.
    void setConfig(const Config& newConfig);

    bool isEmpty() const noexcept { return size() == 0; }

    // reconfigure the MMContainer: update refresh time according to current
    // tail age
    void reconfigureLocked(const Time& currTime);

    // returns the number of elements in the container
    size_t size() const noexcept {
      return sieveMutex_->lock_combine([this]() { return queue_.size(); });
    }

    // Returns the eviction age stats. See CacheStats.h for details
    EvictionAgeStat getEvictionAgeStat(uint64_t projectedLength) const noexcept;

    // for saving the state of the lru
    //
    // precondition:  serialization must happen without any reader or writer
    // present. Any modification of this object afterwards will result in an
    // invalid, inconsistent state for the serialized data.
    //
    serialization::MMSieveObject saveState() const noexcept;

    // return the stats for this container.
    MMContainerStat getStats() const noexcept;

    static LruType getLruType(const T& /* node */) noexcept {
      return LruType{};
    }

    void inspectSieveList() noexcept;

   private:
    EvictionAgeStat getEvictionAgeStatLocked(
        uint64_t projectedLength) const noexcept;

    static Time getUpdateTime(const T& node) noexcept {
      return (node.*HookPtr).getUpdateTime();
    }

    static void setUpdateTime(T& node, Time time) noexcept {
      (node.*HookPtr).setUpdateTime(time);
    }

    // remove node from lru and adjust insertion points
    // @param node          node to remove
    void removeLocked(T& node);

    // Bit MM_BIT_0 is used to record if the item is in tail. This
    // is used to implement LRU insertion points
    void markTail(T& node) noexcept {
      node.template setFlag<RefFlags::kMMFlag0>();
    }

    void unmarkTail(T& node) noexcept {
      node.template unSetFlag<RefFlags::kMMFlag0>();
    }

    bool isTail(T& node) const noexcept {
      return node.template isFlagSet<RefFlags::kMMFlag0>();
    }

    // Bit MM_BIT_1 is used to record if the item has been accessed since
    // being written in cache. Unaccessed items are ignored when determining
    // projected update time.
    void markAccessed(T& node) noexcept {
      node.template setFlag<RefFlags::kMMFlag1>();
    }

    void unmarkAccessed(T& node) noexcept {
      node.template unSetFlag<RefFlags::kMMFlag1>();
    }

    bool isAccessed(const T& node) const noexcept {
      return node.template isFlagSet<RefFlags::kMMFlag1>();
    }

    // protects all operations on the lru. We never really just read the state
    // of the LRU. Hence we dont really require a RW mutex at this point of
    // time.
    mutable folly::cacheline_aligned<Mutex> sieveMutex_;

    const PtrCompressor compressor_{};

    // Sieve FIFO queue
    SIEVEList queue_{};

    // insertion point
    //T* insertionPoint_{nullptr};

    // hand
    T* hand_{nullptr};

    // size of tail after insertion point
    //size_t tailSize_{0};

    // The next time to reconfigure the container.
    std::atomic<Time> nextReconfigureTime_{};

    // How often to promote an item in the eviction queue.
    std::atomic<uint32_t> lruRefreshTime_{};

    // Config for this sieve.
    // Write access to the MMSieve Config is serialized.
    // Reads may be racy.
    Config config_{};

    // Max lruFreshTime.
    static constexpr uint32_t kLruRefreshTimeCap{900};

    //TODO: make a test for Sieve
    //FRIEND_TEST(MMLruTest, Reconfigure);
  };
};

/* Container Interface Implementation */
template <typename T, MMSieve::Hook<T> T::*HookPtr>
MMSieve::Container<T, HookPtr>::Container(serialization::MMSieveObject object,
                                        PtrCompressor compressor)
    : compressor_(std::move(compressor)),
      queue_(*object.queue(), compressor_),
      //insertionPoint_(compressor_.unCompress(
      //    CompressedPtr{*object.compressedInsertionPoint()})),
      hand_(compressor_.unCompress(
	    CompressedPtr{*object.compressedHand()})),
      //tailSize_(*object.tailSize()),
      config_(*object.config()) {
  lruRefreshTime_ = config_.lruRefreshTime;
  nextReconfigureTime_ = config_.mmReconfigureIntervalSecs.count() == 0
                             ? std::numeric_limits<Time>::max()
                             : static_cast<Time>(util::getCurrentTimeSec()) +
                                   config_.mmReconfigureIntervalSecs.count();
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
bool MMSieve::Container<T, HookPtr>::recordAccess(T& node,
                                                AccessMode mode) noexcept {
  if ((mode == AccessMode::kWrite && !config_.updateOnWrite) ||
      (mode == AccessMode::kRead && !config_.updateOnRead)) {
    return false;
  }
  if (queue_.getTail()==nullptr)  std::cout << "MMSieve-recordAccess(start)-tail is null"<<std::endl;
  const auto curr = static_cast<Time>(util::getCurrentTimeSec());
  // check if the node is still being memory managed
  if (node.isInMMContainer() &&
      ((curr >= getUpdateTime(node) +
                    lruRefreshTime_.load(std::memory_order_relaxed)) ||
       !isAccessed(node))) {
    if (!isAccessed(node)) {
      markAccessed(node);
    }
   }
  if (queue_.getTail()==nullptr)  std::cout << "MMSieve-recordAccess(end)-tail is null"<<std::endl;
  return true;
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
cachelib::EvictionAgeStat MMSieve::Container<T, HookPtr>::getEvictionAgeStat(
    uint64_t projectedLength) const noexcept {
  if (queue_.getTail()==nullptr)  std::cout << "MMSieve-getEvictionAgeStat(start)-tail is null"<<std::endl;
  return sieveMutex_->lock_combine([this, projectedLength]() {
    return getEvictionAgeStatLocked(projectedLength);
  });
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
cachelib::EvictionAgeStat
MMSieve::Container<T, HookPtr>::getEvictionAgeStatLocked(
    uint64_t projectedLength) const noexcept {
  EvictionAgeStat stat{};
  const auto currTime = static_cast<Time>(util::getCurrentTimeSec());

  const T* node = queue_.getTail();
  stat.warmQueueStat.oldestElementAge =
      node ? currTime - getUpdateTime(*node) : 0;
  for (size_t numSeen = 0; numSeen < projectedLength && node != nullptr;
       numSeen++, node = queue_.getPrev(*node)) {
  }
  stat.warmQueueStat.projectedAge = node ? currTime - getUpdateTime(*node)
                                         : stat.warmQueueStat.oldestElementAge;
  //XDCHECK(detail::areBytesSame(stat.hotQueueStat, EvictionStatPerType{}));
  //XDCHECK(detail::areBytesSame(stat.coldQueueStat, EvictionStatPerType{}));
  if (queue_.getTail()==nullptr)  std::cout << "MMSieve-getEvictionAgeStatLocked(end)-tail is null"<<std::endl;
  return stat;
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
void MMSieve::Container<T, HookPtr>::setConfig(const Config& newConfig) {
    sieveMutex_->lock_combine([this, newConfig]() {
    config_ = newConfig;
    lruRefreshTime_.store(config_.lruRefreshTime, std::memory_order_relaxed);
    nextReconfigureTime_ = config_.mmReconfigureIntervalSecs.count() == 0
                               ? std::numeric_limits<Time>::max()
                               : static_cast<Time>(util::getCurrentTimeSec()) +
                                     config_.mmReconfigureIntervalSecs.count();
  });
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
typename MMSieve::Config MMSieve::Container<T, HookPtr>::getConfig() const {
  return sieveMutex_->lock_combine([this]() { return config_; });
}


template <typename T, MMSieve::Hook<T> T::*HookPtr>
bool MMSieve::Container<T, HookPtr>::add(T& node) noexcept {
  const auto currTime = static_cast<Time>(util::getCurrentTimeSec());
  // Lock and insert at head
  // Set hand_ to queue's tail is hand_ is null.
  return sieveMutex_->lock_combine([this, &node, currTime]() {
    if (node.isInMMContainer()) {
      return false;
    }
    //if (queue_.getTail()==nullptr)  std::cout << "MMSieve-add(start)-tail is null"<<std::endl;
    queue_.linkAtHead(node);
    queue_.setAsVisited(node);
    node.markInMMContainer();
    setUpdateTime(node, currTime);
    unmarkAccessed(node);


    if (hand_ == nullptr){
    	hand_ = queue_.getTail();
    }

    if (hand_ == nullptr) std::cout << "MMSieve-add-hand is null"<<std::endl;
    if (queue_.getTail()==nullptr)  std::cout << "MMSieve-add(end)-tail is null"<<std::endl;

    return true;
  });
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
void MMSieve::Container<T, HookPtr>::inspectSieveList() noexcept{
  queue_.inspectSieveList();
}


template <typename T, MMSieve::Hook<T> T::*HookPtr>
typename MMSieve::Container<T, HookPtr>::LockedIterator
MMSieve::Container<T, HookPtr>::getEvictionIterator() noexcept {
  std::cout << "MMSieve-getEvItr..";
  LockHolder l(*sieveMutex_);
  if (queue_.getTail()==nullptr)  std::cout << "MMSieve-getEvItr-tail is null"<<std::endl;
  
  return LockedIterator{std::move(l), queue_.iterBackFromHand()};
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
template <typename F>
void MMSieve::Container<T, HookPtr>::withEvictionIterator(F&& fun) {
  if (queue_.getTail()==nullptr)  std::cout << "MMSieve-withEvItr-tail(start) is null";
  if (config_.useCombinedLockForIterators) {
    sieveMutex_->lock_combine([this, &fun]() { fun(Iterator{queue_.iterBackFromHand()}); });
  } else {
    LockHolder lck{*sieveMutex_};
    auto iter = Iterator{queue_.iterBackFromHand()};
    if (!iter) std::cout << "MMSieve-withEvIter(end) is NULL" << std::endl;
    fun(iter);
  }
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
template <typename F>
void MMSieve::Container<T, HookPtr>::withContainerLock(F&& fun) {
  sieveMutex_->lock_combine([&fun]() { fun(); });
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
void MMSieve::Container<T, HookPtr>::removeLocked(T& node) {
  if (queue_.getTail()==nullptr)  std::cout << "MMSieve-removeLocked(start)-tail is null"<<std::endl;
  queue_.remove(node);
  unmarkAccessed(node);
  if (isTail(node)) {
    unmarkTail(node);
    //tailSize_--;
  }
  node.unmarkInMMContainer();
  //updateLruInsertionPoint();
  if (queue_.getTail()==nullptr)  std::cout << "MMSieve-removeLocked(end)-tail is null"<<std::endl;
  return;
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
bool MMSieve::Container<T, HookPtr>::remove(T& node) noexcept {
  return sieveMutex_->lock_combine([this, &node]() {
    if (!node.isInMMContainer()) {
      return false;
    }
    removeLocked(node);
    return true;
  });
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
void MMSieve::Container<T, HookPtr>::remove(Iterator& it) noexcept {
  T& node = *it;
  XDCHECK(node.isInMMContainer());
  if (queue_.getTail()==nullptr)  std::cout << "MMSieve-remove(start)-tail is null"<<std::endl;
  ++it;
  removeLocked(node);
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
bool MMSieve::Container<T, HookPtr>::replace(T& oldNode, T& newNode) noexcept {
  if (queue_.getTail()==nullptr)  std::cout << "MMSieve-replace(start)-tail is null"<<std::endl;
  return sieveMutex_->lock_combine([this, &oldNode, &newNode]() {
    if (!oldNode.isInMMContainer() || newNode.isInMMContainer()) {
      return false;
    }
    const auto updateTime = getUpdateTime(oldNode);
    queue_.replace(oldNode, newNode);
    oldNode.unmarkInMMContainer();
    newNode.markInMMContainer();
    setUpdateTime(newNode, updateTime);
    if (isAccessed(oldNode)) {
      markAccessed(newNode);
    } else {
      unmarkAccessed(newNode);
    }
    XDCHECK(!isTail(newNode));
    if (isTail(oldNode)) {
      markTail(newNode);
      unmarkTail(oldNode);
    } else {
      unmarkTail(newNode);
    }
    if (queue_.getTail()==nullptr)  std::cout << "MMSieve-remove(end)-tail is null"<<std::endl;
    return true;
  });
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
serialization::MMSieveObject MMSieve::Container<T, HookPtr>::saveState()
    const noexcept {
  serialization::MMSieveConfig configObject;
  *configObject.lruRefreshTime() =
      lruRefreshTime_.load(std::memory_order_relaxed);
  *configObject.lruRefreshRatio() = config_.lruRefreshRatio;
  *configObject.updateOnWrite() = config_.updateOnWrite;
  *configObject.updateOnRead() = config_.updateOnRead;
  *configObject.tryLockUpdate() = config_.tryLockUpdate;
  
  serialization::MMSieveObject object;
  *object.config() = configObject;
  *object.compressedHand() = 
      compressor_.compress(hand_).saveState();
  
  *object.queue() = queue_.saveState();
  return object;
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
MMContainerStat MMSieve::Container<T, HookPtr>::getStats() const noexcept {
  auto stat = sieveMutex_->lock_combine([this]() {
    auto* tail = queue_.getTail();

    // we return by array here because DistributedMutex is fastest when the
    // output data fits within 48 bytes.  And the array is exactly 48 bytes, so
    // it can get optimized by the implementation.
    //
    // the rest of the parameters are 0, so we don't need the critical section
    // to return them
    return folly::make_array(queue_.size(),
                             tail == nullptr ? 0 : getUpdateTime(*tail),
                             lruRefreshTime_.load(std::memory_order_relaxed));
  });
  return {stat[0] /* lru size */,
          stat[1] /* tail time */,
          stat[2] /* refresh time */,
          0,
          0,
          0,
          0};
}

template <typename T, MMSieve::Hook<T> T::*HookPtr>
void MMSieve::Container<T, HookPtr>::reconfigureLocked(const Time& currTime) {
  if (currTime < nextReconfigureTime_) {
    return;
  }
  nextReconfigureTime_ = currTime + config_.mmReconfigureIntervalSecs.count();

  // update LRU refresh time
  auto stat = getEvictionAgeStatLocked(0);
  auto lruRefreshTime = std::min(
      std::max(config_.defaultLruRefreshTime,
               static_cast<uint32_t>(stat.warmQueueStat.oldestElementAge *
                                     config_.lruRefreshRatio)),
      kLruRefreshTimeCap);
  lruRefreshTime_.store(lruRefreshTime, std::memory_order_relaxed);
}

// Iterator Context Implementation
template <typename T, MMSieve::Hook<T> T::*HookPtr>
MMSieve::Container<T, HookPtr>::LockedIterator::LockedIterator(
    LockHolder l, const Iterator& iter) noexcept
    : Iterator(iter), l_(std::move(l)) {}
} // namespace facebook::cachelib
