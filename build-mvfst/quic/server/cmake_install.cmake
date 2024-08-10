# Install script for directory: /mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/mnt/cfs/CacheLib/opt/cachelib")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/AcceptObserver.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/QuicHandshakeSocketHolder.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/QuicReusePortUDPSocketFactory.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/QuicServer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/QuicServerPacketRouter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/QuicServerTransport.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/QuicServerTransportFactory.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/QuicServerWorker.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/QuicSharedUDPSocketFactory.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/QuicUDPSocketFactory.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/RateLimiter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/SlidingWindowRateLimiter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/async_tran" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/async_tran/QuicAsyncTransportAcceptor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/async_tran" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/async_tran/QuicAsyncTransportServer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/async_tran" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/async_tran/QuicServerAsyncTransport.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/handshake" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/handshake/AppToken.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/handshake" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/handshake/DefaultAppTokenValidator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/handshake" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/handshake/ServerHandshake.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/handshake" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/handshake/ServerHandshakeFactory.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/handshake" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/handshake/ServerTransportParametersExtension.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/handshake" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/handshake/StatelessResetGenerator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/handshake" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/handshake/TokenGenerator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/state/ServerConnectionIdRejector.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/state/ServerStateMachine.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/server/third-party" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/server/third-party/siphash.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/server/libmvfst_server.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/server:/mnt/cfs/CacheLib/build-mvfst/quic/api:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/dsr:/mnt/cfs/CacheLib/build-mvfst/quic/fizz/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/congestion_control:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/happyeyeballs:/mnt/cfs/CacheLib/build-mvfst/quic/common/udpsocket:/mnt/cfs/CacheLib/build-mvfst/quic/common/events:/mnt/cfs/CacheLib/build-mvfst/quic/observer:/mnt/cfs/CacheLib/build-mvfst/quic/loss:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/server/libmvfst_server.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/server:/mnt/cfs/CacheLib/build-mvfst/quic/api:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/dsr:/mnt/cfs/CacheLib/build-mvfst/quic/fizz/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/congestion_control:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/happyeyeballs:/mnt/cfs/CacheLib/build-mvfst/quic/common/udpsocket:/mnt/cfs/CacheLib/build-mvfst/quic/common/events:/mnt/cfs/CacheLib/build-mvfst/quic/observer:/mnt/cfs/CacheLib/build-mvfst/quic/loss:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/server/libmvfst_server_state.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/dsr:/mnt/cfs/CacheLib/build-mvfst/quic/fizz/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/api:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic/congestion_control:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/happyeyeballs:/mnt/cfs/CacheLib/build-mvfst/quic/common/udpsocket:/mnt/cfs/CacheLib/build-mvfst/quic/common/events:/mnt/cfs/CacheLib/build-mvfst/quic/observer:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/loss:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/server/libmvfst_server_state.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/dsr:/mnt/cfs/CacheLib/build-mvfst/quic/fizz/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/api:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic/congestion_control:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/happyeyeballs:/mnt/cfs/CacheLib/build-mvfst/quic/common/udpsocket:/mnt/cfs/CacheLib/build-mvfst/quic/common/events:/mnt/cfs/CacheLib/build-mvfst/quic/observer:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/loss:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_state.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/server/libmvfst_server_async_tran.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/server:/mnt/cfs/CacheLib/build-mvfst/quic/api:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic/dsr:/mnt/cfs/CacheLib/build-mvfst/quic/fizz/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/congestion_control:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/happyeyeballs:/mnt/cfs/CacheLib/build-mvfst/quic/common/udpsocket:/mnt/cfs/CacheLib/build-mvfst/quic/common/events:/mnt/cfs/CacheLib/build-mvfst/quic/observer:/mnt/cfs/CacheLib/build-mvfst/quic/loss:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/server/libmvfst_server_async_tran.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/server:/mnt/cfs/CacheLib/build-mvfst/quic/api:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic/dsr:/mnt/cfs/CacheLib/build-mvfst/quic/fizz/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/congestion_control:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/happyeyeballs:/mnt/cfs/CacheLib/build-mvfst/quic/common/udpsocket:/mnt/cfs/CacheLib/build-mvfst/quic/common/events:/mnt/cfs/CacheLib/build-mvfst/quic/observer:/mnt/cfs/CacheLib/build-mvfst/quic/loss:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_server_async_tran.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/mnt/cfs/CacheLib/build-mvfst/quic/server/test/cmake_install.cmake")
  include("/mnt/cfs/CacheLib/build-mvfst/quic/server/handshake/test/cmake_install.cmake")

endif()

