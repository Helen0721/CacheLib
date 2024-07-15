cmake_minimum_required (VERSION 3.12)

project (cachelib-cmake-test-project VERSION 0.1)

find_package(cachelib CONFIG REQUIRED)

add_executable(testSieve testSieve.cpp)

target_link_libraries(testSieve cachelib)
