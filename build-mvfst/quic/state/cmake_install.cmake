# Install script for directory: /mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/AckEvent.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/AckHandlers.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/AckStates.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/DatagramHandlers.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/LossState.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/OutstandingPacket.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/PacketEvent.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/PendingPathRateLimiter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicAckFrequencyFunctions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicConnectionStats.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicPacingFunctions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicPriorityQueue.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicStateFunctions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicStreamFunctions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicStreamGroupRetransmissionPolicy.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicStreamManager.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicStreamPrioritiesObserver.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicStreamUtilities.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/QuicTransportStatsCallback.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/SimpleFrameFunctions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/StateData.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/StreamData.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/TransportSettings.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/TransportSettingsFunctions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state/stream" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/stream/StreamReceiveHandlers.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state/stream" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/stream/StreamSendHandlers.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state/stream" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/stream/StreamStateFunctions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state/test" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/test/AckEventTestUtil.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state/test" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/test/MockQuicStats.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/quic/state/test" TYPE FILE FILES "/mnt/cfs/CacheLib/cachelib/external/mvfst/quic/state/test/Mocks.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_machine.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_machine.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_machine.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_ack_handler.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/loss:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_ack_handler.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/loss:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_ack_handler.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_datagram_handler.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/loss:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_datagram_handler.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/loss:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_datagram_handler.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_stream_functions.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_stream_functions.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream_functions.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_pacing_functions.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_pacing_functions.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_pacing_functions.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_functions.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_functions.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_functions.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_simple_frame_functions.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_simple_frame_functions.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_simple_frame_functions.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_stream.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_state_stream.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so"
         OLD_RPATH "/mnt/cfs/CacheLib/build-mvfst/quic/flowcontrol:/mnt/cfs/CacheLib/build-mvfst/quic/state:/mnt/cfs/CacheLib/build-mvfst/quic/logging:/mnt/cfs/CacheLib/build-mvfst/quic/codec:/mnt/cfs/CacheLib/build-mvfst/quic/handshake:/mnt/cfs/CacheLib/build-mvfst/quic/common:/mnt/cfs/CacheLib/build-mvfst/quic:/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_state_stream.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so.0"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_transport_settings_functions.so.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so.0"
         OLD_RPATH "/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/mnt/cfs/CacheLib/build-mvfst/quic/state/libmvfst_transport_settings_functions.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so"
         OLD_RPATH "/mnt/cfs/CacheLib/opt/cachelib/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmvfst_transport_settings_functions.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/mnt/cfs/CacheLib/build-mvfst/quic/state/test/cmake_install.cmake")
  include("/mnt/cfs/CacheLib/build-mvfst/quic/state/stream/test/cmake_install.cmake")

endif()

