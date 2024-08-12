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
include quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/compiler_depend.make

# Include the progress variables for this target.
include quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/progress.make

# Include the compile flags for this target's objects.
include quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/flags.make

quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.o: quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/flags.make
quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.o: /disk/CacheLib/cachelib/external/mvfst/quic/state/QuicPacingFunctions.cpp
quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.o: quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.o"
	cd /disk/CacheLib/build-mvfst/quic/state && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.o -MF CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.o.d -o CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.o -c /disk/CacheLib/cachelib/external/mvfst/quic/state/QuicPacingFunctions.cpp

quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.i"
	cd /disk/CacheLib/build-mvfst/quic/state && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib/cachelib/external/mvfst/quic/state/QuicPacingFunctions.cpp > CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.i

quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.s"
	cd /disk/CacheLib/build-mvfst/quic/state && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib/cachelib/external/mvfst/quic/state/QuicPacingFunctions.cpp -o CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.s

# Object files for target mvfst_state_pacing_functions
mvfst_state_pacing_functions_OBJECTS = \
"CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.o"

# External object files for target mvfst_state_pacing_functions
mvfst_state_pacing_functions_EXTERNAL_OBJECTS =

quic/state/libmvfst_state_pacing_functions.so.0: quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/QuicPacingFunctions.cpp.o
quic/state/libmvfst_state_pacing_functions.so.0: quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/build.make
quic/state/libmvfst_state_pacing_functions.so.0: quic/state/libmvfst_state_machine.so.0
quic/state/libmvfst_state_pacing_functions.so.0: quic/codec/libmvfst_codec.so.0
quic/state/libmvfst_state_pacing_functions.so.0: quic/handshake/libmvfst_handshake.so.0
quic/state/libmvfst_state_pacing_functions.so.0: quic/codec/libmvfst_codec_packet_number_cipher.so.0
quic/state/libmvfst_state_pacing_functions.so.0: quic/codec/libmvfst_codec_decode.so.0
quic/state/libmvfst_state_pacing_functions.so.0: quic/codec/libmvfst_codec_types.so.0
quic/state/libmvfst_state_pacing_functions.so.0: quic/common/libmvfst_bufutil.so.0
quic/state/libmvfst_state_pacing_functions.so.0: quic/libmvfst_constants.so.0
quic/state/libmvfst_state_pacing_functions.so.0: quic/libmvfst_exception.so.0
quic/state/libmvfst_state_pacing_functions.so.0: /disk/CacheLib/opt/cachelib/lib/libfizz.so.1.0.0
quic/state/libmvfst_state_pacing_functions.so.0: /disk/CacheLib/opt/cachelib/lib/libfolly.so.0.58.0-dev
quic/state/libmvfst_state_pacing_functions.so.0: /disk/CacheLib/opt/cachelib/lib/libfmt.so.10.2.1
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libboost_context.so.1.74.0
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libboost_program_options.so.1.74.0
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.74.0
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.74.0
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.74.0
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libdouble-conversion.so
quic/state/libmvfst_state_pacing_functions.so.0: /disk/CacheLib/opt/cachelib/lib/libglog.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libevent.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libz.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libbz2.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/liblzma.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/liblz4.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libsnappy.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libdwarf.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libiberty.a
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libaio.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libsodium.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libunwind.so
quic/state/libmvfst_state_pacing_functions.so.0: /disk/CacheLib/opt/cachelib/lib/libgflags.so.2.2.2
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libssl.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libcrypto.so
quic/state/libmvfst_state_pacing_functions.so.0: /disk/CacheLib/opt/cachelib/lib/libzstd.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libsodium.so
quic/state/libmvfst_state_pacing_functions.so.0: /usr/lib/x86_64-linux-gnu/libz.so
quic/state/libmvfst_state_pacing_functions.so.0: quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/disk/CacheLib/build-mvfst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmvfst_state_pacing_functions.so"
	cd /disk/CacheLib/build-mvfst/quic/state && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mvfst_state_pacing_functions.dir/link.txt --verbose=$(VERBOSE)
	cd /disk/CacheLib/build-mvfst/quic/state && $(CMAKE_COMMAND) -E cmake_symlink_library libmvfst_state_pacing_functions.so.0 libmvfst_state_pacing_functions.so.0 libmvfst_state_pacing_functions.so

quic/state/libmvfst_state_pacing_functions.so: quic/state/libmvfst_state_pacing_functions.so.0
	@$(CMAKE_COMMAND) -E touch_nocreate quic/state/libmvfst_state_pacing_functions.so

# Rule to build all files generated by this target.
quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/build: quic/state/libmvfst_state_pacing_functions.so
.PHONY : quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/build

quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/clean:
	cd /disk/CacheLib/build-mvfst/quic/state && $(CMAKE_COMMAND) -P CMakeFiles/mvfst_state_pacing_functions.dir/cmake_clean.cmake
.PHONY : quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/clean

quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/depend:
	cd /disk/CacheLib/build-mvfst && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /disk/CacheLib/cachelib/external/mvfst /disk/CacheLib/cachelib/external/mvfst/quic/state /disk/CacheLib/build-mvfst /disk/CacheLib/build-mvfst/quic/state /disk/CacheLib/build-mvfst/quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : quic/state/CMakeFiles/mvfst_state_pacing_functions.dir/depend

