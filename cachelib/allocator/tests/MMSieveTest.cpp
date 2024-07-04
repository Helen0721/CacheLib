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

#include <folly/Random.h>
#include <folly/logging/xlog.h>

#include "cachelib/allocator/MMSieve.h"
#include "cachelib/allocator/tests/MMTypeTest.h"

namespace facebook {
namespace cachelib {
using MMSieveTest = MMTypeTest<MMSieve>;

/**
 * Test Suits for Sieve implementation. 
 * SieveAddBasic and SieveRemoveBasic copied from MMTypeTest.h 
 * The difference is Sieve has a cyclic iterator that will not return NULL
 */

/**
 * Check: 
 * 1. newly created nodes isn't marked in container,
 * 2. Adding new nodes return True
 * 3. re-adding nodes return False
 * 4. container node sizes consistent w/ unique nodes being added 
 */
TEST_F(MMSieveTest, SieveAddBasic){ 
  //Create Sieve Config
  MMSieve::Config config{/* lruRefreshTime */ 0,
                    /* updateOnWrite */ false,
                    /* updateOnRead */ false};
  Container c{config,{}};
  
  // Create nodes and don't add to container yet
  std::vector<std::unique_ptr<Node>> nodes; 
  const int numNodes = 10;
  for (int i = 0; i < numNodes; i++){
    nodes.emplace_back(new Node{i});
    ASSERT_FALSE(nodes.back()->isInMMContainer());
  }
  
  // Ensure nothing is in the cache container
  ASSERT_EQ(c.getStats().size,0);
 
  // Now add to cache container
  for (auto& node : nodes) {
    ASSERT_TRUE(c.add(*node));
    ASSERT_TRUE(node->isInMMContainer());
    ASSERT_FALSE(c.add(*node));
  }
  ASSERT_EQ(c.getStats().size, nodes.size()); 
}


TEST_F(MMSieveTest, SieveRemoveBasic){
  //Create Sieve Config
  MMSieve::Config config{/* lruRefreshTime */ 0,
                    /* updateOnWrite */ false,
                    /* updateOnRead */ false};
  Container c{config,{}};
  
  // Create nodes and don't add to container yet
  std::vector<std::unique_ptr<Node>> nodes; 
  const int numNodes = 10;
  for (int i = 0; i < numNodes; i++){
    nodes.emplace_back(new Node{i});
    ASSERT_FALSE(nodes.back()->isInMMContainer());
  }
  
  // Ensure nothing is in the cache container
  ASSERT_EQ(c.getStats().size,0);
  
  // Now add to cache container
  for (auto& node : nodes) {
    ASSERT_TRUE(c.add(*node));
    ASSERT_TRUE(node->isInMMContainer());
    ASSERT_FALSE(c.add(*node));
  }
  ASSERT_EQ(c.getStats().size, nodes.size()); 

  std::vector<std::unique_ptr<Node>> removedNodes;
  for (unsigned int i = 0; i < numNodes / 3; i++) {
    auto iter = nodes.begin() + folly::Random::rand32() % nodes.size();
    auto node = std::move(*iter);
    ASSERT_TRUE(node->isInMMContainer());
    ASSERT_TRUE(c.remove(*node));
    ASSERT_FALSE(node->isInMMContainer());
    nodes.erase(iter);
    removedNodes.push_back(std::move(node));
  }

  // removing nodes that are not in the container should just error out.
  for (auto& node : removedNodes) {
    ASSERT_FALSE(node->isInMMContainer());
    ASSERT_FALSE(c.remove(*node));
  }
  std::cout << "nodes.size: " << nodes.size() << std::endl;
  std::cout << "removedNodes.size: " << removedNodes.size() << std::endl;

  c.inspectSieveList();

  // Checking we can't access the removed Nodes from the iterator 
  std::set<int> foundNodes;  
  for (auto itr = c.getEvictionIterator(); foundNodes.size() + removedNodes.size()!= numNodes;) {
    if (!itr) {std::cout<<"itr is null\n"; continue;}
    auto id = itr->getId();
    std::cout << "evicted id: " << id << std::endl;
    ASSERT_EQ(foundNodes.find(id),foundNodes.end());
    foundNodes.insert(id);
    c.inspectSieveList();
    std::cout << "foundNodes size: " << foundNodes.size() << std::endl;
    std::cout << std::endl;
    if (foundNodes.size() + removedNodes.size()!= numNodes) ++itr;
  }
  for (const auto& node : removedNodes) {
    ASSERT_EQ(foundNodes.find(node->getId()), foundNodes.end());
  }

  // trying to remove through iterator should work as expected as well.
  // no need of iter++ since remove will do that.
  std::cout<<"Verifying Iterator..." << std::endl;
  for (auto iter = c.getEvictionIterator(); iter;) {
    auto& node = *iter;
    std::cout << "id to be removed: " << iter->getId() << std::endl;
    ASSERT_TRUE(node.isInMMContainer()); 
    
    // this will move the iter. 
    c.remove(iter);
    ASSERT_FALSE(node.isInMMContainer());
    std::cout << "after removing...";
    c.inspectSieveList();
    /*
    if (iter) {
      std::cout << "next node to be evicted from iter: " << iter->getId() << std::endl;
      if (c->getHead() != node) ASSERT_NE((*iter).getId(), node.getId());
    }*/
    std::cout << std::endl;
  }
}




/*
void verifyIterationVariants_Sieve(Container& c, int numNodes) {
  std::vector<Node*> nodes;
  std::set<int> foundNodeIds;
  
  for (auto iter = c.getEvictionIterator(); iter; ++iter) {
    nodes.push_back(&(*iter));
    foundNodes.insert(itr->getId());
    if (foundNodes.size() == c.getStats().size)
  }

  size_t i = 0;
  c.withEvictionIterator([&nodes, &i](auto&& iter) {
    while (iter) {
      auto& node = *iter;
      ASSERT_EQ(&node, nodes[i]);

      ++iter;
      ++i;
    }

    ASSERT_EQ(i, nodes.size());
  });
}
*/




/*TEST_F(MMSieveTest, RecordAccessBasic) {
  MMSieve::Config c;
  // Change lruRefreshTime to make sure only the first recordAccess bumps
  // the node and subsequent recordAccess invocations do not.
  c.lruRefreshTime = 100;
  testRecordAccessBasic(std::move(c));
}
*/
} // namespace cachelib
} // namespace facebook
