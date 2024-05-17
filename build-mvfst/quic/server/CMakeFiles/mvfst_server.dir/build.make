# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /disk/CacheLib/cachelib/external/mvfst

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /disk/CacheLib/build-mvfst

# Include any dependencies generated for this target.
include quic/server/CMakeFiles/mvfst_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.make

# Include the progress variables for this target.
include quic/server/CMakeFiles/mvfst_server.dir/progress.make

# Include the compile flags for this target's objects.
include quic/server/CMakeFiles/mvfst_server.dir/flags.make

quic/server/CMakeFiles/mvfst_server.dir/QuicServer.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/QuicServer.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServer.cpp
quic/server/CMakeFiles/mvfst_server.dir/QuicServer.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/QuicServer.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/QuicServer.cpp.o -MF CMakeFiles/mvfst_server.dir/QuicServer.cpp.o.d -o CMakeFiles/mvfst_server.dir/QuicServer.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServer.cpp

quic/server/CMakeFiles/mvfst_server.dir/QuicServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/QuicServer.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServer.cpp > CMakeFiles/mvfst_server.dir/QuicServer.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/QuicServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/QuicServer.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServer.cpp -o CMakeFiles/mvfst_server.dir/QuicServer.cpp.s

quic/server/CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerBackend.cpp
quic/server/CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.o -MF CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.o.d -o CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerBackend.cpp

quic/server/CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerBackend.cpp > CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerBackend.cpp -o CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.s

quic/server/CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerPacketRouter.cpp
quic/server/CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.o -MF CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.o.d -o CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerPacketRouter.cpp

quic/server/CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerPacketRouter.cpp > CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerPacketRouter.cpp -o CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.s

quic/server/CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerTransport.cpp
quic/server/CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.o -MF CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.o.d -o CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerTransport.cpp

quic/server/CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerTransport.cpp > CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerTransport.cpp -o CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.s

quic/server/CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerWorker.cpp
quic/server/CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.o -MF CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.o.d -o CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerWorker.cpp

quic/server/CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerWorker.cpp > CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/server/QuicServerWorker.cpp -o CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.s

quic/server/CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/server/SlidingWindowRateLimiter.cpp
quic/server/CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.o -MF CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.o.d -o CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/server/SlidingWindowRateLimiter.cpp

quic/server/CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/server/SlidingWindowRateLimiter.cpp > CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/server/SlidingWindowRateLimiter.cpp -o CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.s

quic/server/CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/server/handshake/DefaultAppTokenValidator.cpp
quic/server/CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.o -MF CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.o.d -o CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/server/handshake/DefaultAppTokenValidator.cpp

quic/server/CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/server/handshake/DefaultAppTokenValidator.cpp > CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/server/handshake/DefaultAppTokenValidator.cpp -o CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.s

quic/server/CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/server/handshake/TokenGenerator.cpp
quic/server/CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.o -MF CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.o.d -o CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/server/handshake/TokenGenerator.cpp

quic/server/CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/server/handshake/TokenGenerator.cpp > CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/server/handshake/TokenGenerator.cpp -o CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.s

quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/AppToken.cpp
quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.o -MF CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.o.d -o CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/AppToken.cpp

quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/AppToken.cpp > CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/AppToken.cpp -o CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.s

quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp
quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.o -MF CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.o.d -o CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp

quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp > CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp -o CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.s

quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/flags.make
quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/FizzServerHandshake.cpp
quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.o: quic/server/CMakeFiles/mvfst_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.o -MF CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.o.d -o CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/FizzServerHandshake.cpp

quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/FizzServerHandshake.cpp > CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.i

quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/fizz/server/handshake/FizzServerHandshake.cpp -o CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.s

# Object files for target mvfst_server
mvfst_server_OBJECTS = \
"CMakeFiles/mvfst_server.dir/QuicServer.cpp.o" \
"CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.o" \
"CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.o" \
"CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.o" \
"CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.o" \
"CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.o" \
"CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.o" \
"CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.o" \
"CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.o" \
"CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.o" \
"CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.o"

# External object files for target mvfst_server
mvfst_server_EXTERNAL_OBJECTS =

quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/QuicServer.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/QuicServerBackend.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/QuicServerPacketRouter.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/QuicServerTransport.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/QuicServerWorker.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/SlidingWindowRateLimiter.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/handshake/DefaultAppTokenValidator.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/handshake/TokenGenerator.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/AppToken.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerQuicHandshakeContext.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/__/fizz/server/handshake/FizzServerHandshake.cpp.o
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/build.make
quic/server/libmvfst_server.so.0: quic/server/libmvfst_server_state.so.0
quic/server/libmvfst_server.so.0: quic/api/libmvfst_transport.so.0
quic/server/libmvfst_server.so.0: quic/common/libmvfst_transport_knobs.so.0
quic/server/libmvfst_server.so.0: quic/state/libmvfst_transport_settings_functions.so.0
quic/server/libmvfst_server.so.0: quic/dsr/libmvfst_dsr_frontend.so.0
quic/server/libmvfst_server.so.0: quic/dsr/libmvfst_dsr_types.so.0
quic/server/libmvfst_server.so.0: quic/fizz/handshake/libmvfst_fizz_handshake.so.0
quic/server/libmvfst_server.so.0: quic/common/libmvfst_buf_accessor.so.0
quic/server/libmvfst_server.so.0: quic/state/libmvfst_state_datagram_handler.so.0
quic/server/libmvfst_server.so.0: quic/api/libmvfst_batch_writer.so.0
quic/server/libmvfst_server.so.0: quic/congestion_control/libmvfst_cc_algo.so.0
quic/server/libmvfst_server.so.0: quic/codec/libmvfst_codec_pktrebuilder.so.0
quic/server/libmvfst_server.so.0: quic/happyeyeballs/libmvfst_happyeyeballs.so.0
quic/server/libmvfst_server.so.0: quic/common/udpsocket/libmvfst_async_udp_socket.so.0
quic/server/libmvfst_server.so.0: quic/common/events/libmvfst_events.so.0
quic/server/libmvfst_server.so.0: quic/common/libmvfst_looper.so.0
quic/server/libmvfst_server.so.0: quic/observer/libmvfst_observer.so.0
quic/server/libmvfst_server.so.0: quic/state/libmvfst_state_ack_handler.so.0
quic/server/libmvfst_server.so.0: quic/loss/libmvfst_loss.so.0
quic/server/libmvfst_server.so.0: quic/state/libmvfst_state_pacing_functions.so.0
quic/server/libmvfst_server.so.0: quic/state/libmvfst_state_simple_frame_functions.so.0
quic/server/libmvfst_server.so.0: quic/state/libmvfst_state_functions.so.0
quic/server/libmvfst_server.so.0: quic/codec/libmvfst_codec_pktbuilder.so.0
quic/server/libmvfst_server.so.0: quic/state/libmvfst_state_stream.so.0
quic/server/libmvfst_server.so.0: quic/flowcontrol/libmvfst_flowcontrol.so.0
quic/server/libmvfst_server.so.0: quic/logging/libmvfst_qlogger.so.0
quic/server/libmvfst_server.so.0: quic/state/libmvfst_state_stream_functions.so.0
quic/server/libmvfst_server.so.0: quic/state/libmvfst_state_machine.so.0
quic/server/libmvfst_server.so.0: quic/codec/libmvfst_codec.so.0
quic/server/libmvfst_server.so.0: quic/handshake/libmvfst_handshake.so.0
quic/server/libmvfst_server.so.0: quic/codec/libmvfst_codec_packet_number_cipher.so.0
quic/server/libmvfst_server.so.0: quic/codec/libmvfst_codec_decode.so.0
quic/server/libmvfst_server.so.0: quic/codec/libmvfst_codec_types.so.0
quic/server/libmvfst_server.so.0: quic/libmvfst_exception.so.0
quic/server/libmvfst_server.so.0: /disk/CacheLib/opt/cachelib/lib/libfizz.so.1.0.0
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libsodium.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libz.so
quic/server/libmvfst_server.so.0: quic/common/libmvfst_bufutil.so.0
quic/server/libmvfst_server.so.0: quic/libmvfst_constants.so.0
quic/server/libmvfst_server.so.0: /disk/CacheLib/opt/cachelib/lib/libfolly.so.0.58.0-dev
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libboost_context.so.1.74.0
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libboost_program_options.so.1.74.0
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.74.0
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.74.0
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.74.0
quic/server/libmvfst_server.so.0: /disk/CacheLib/opt/cachelib/lib/libfmt.so.10.2.1
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libdouble-conversion.so
quic/server/libmvfst_server.so.0: /disk/CacheLib/opt/cachelib/lib/libgflags.so.2.2.2
quic/server/libmvfst_server.so.0: /disk/CacheLib/opt/cachelib/lib/libglog.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libevent.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libz.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libssl.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libcrypto.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libbz2.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/liblzma.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/liblz4.so
quic/server/libmvfst_server.so.0: /disk/CacheLib/opt/cachelib/lib/libzstd.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libsnappy.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libdwarf.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libiberty.a
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libaio.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libsodium.so
quic/server/libmvfst_server.so.0: /usr/lib/x86_64-linux-gnu/libunwind.so
quic/server/libmvfst_server.so.0: quic/server/CMakeFiles/mvfst_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX shared library libmvfst_server.so"
	cd /disk/CacheLib/build-mvfst/quic/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mvfst_server.dir/link.txt --verbose=$(VERBOSE)
	cd /disk/CacheLib/build-mvfst/quic/server && $(CMAKE_COMMAND) -E cmake_symlink_library libmvfst_server.so.0 libmvfst_server.so.0 libmvfst_server.so

quic/server/libmvfst_server.so: quic/server/libmvfst_server.so.0
	@$(CMAKE_COMMAND) -E touch_nocreate quic/server/libmvfst_server.so

# Rule to build all files generated by this target.
quic/server/CMakeFiles/mvfst_server.dir/build: quic/server/libmvfst_server.so
.PHONY : quic/server/CMakeFiles/mvfst_server.dir/build

quic/server/CMakeFiles/mvfst_server.dir/clean:
	cd /disk/CacheLib/build-mvfst/quic/server && $(CMAKE_COMMAND) -P CMakeFiles/mvfst_server.dir/cmake_clean.cmake
.PHONY : quic/server/CMakeFiles/mvfst_server.dir/clean

quic/server/CMakeFiles/mvfst_server.dir/depend:
	cd /disk/CacheLib/build-mvfst && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /disk/CacheLib/cachelib/external/mvfst /disk/CacheLib/cachelib/external/mvfst/quic/server /disk/CacheLib/build-mvfst /disk/CacheLib/build-mvfst/quic/server /disk/CacheLib/build-mvfst/quic/server/CMakeFiles/mvfst_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : quic/server/CMakeFiles/mvfst_server.dir/depend

