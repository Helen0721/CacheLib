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
CMAKE_SOURCE_DIR = /disk/CacheLib-M24/examples/my_cache_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /disk/CacheLib-M24/examples/my_cache_1/build

# Include any dependencies generated for this target.
include CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/flags.make

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.o: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/flags.make
CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.o: ../main.cpp
CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.o: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib-M24/examples/my_cache_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.o -MF CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.o.d -o CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.o -c /disk/CacheLib-M24/examples/my_cache_1/main.cpp

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib-M24/examples/my_cache_1/main.cpp > CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.i

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib-M24/examples/my_cache_1/main.cpp -o CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.s

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.o: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/flags.make
CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.o: ../Simulator.cpp
CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.o: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib-M24/examples/my_cache_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.o -MF CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.o.d -o CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.o -c /disk/CacheLib-M24/examples/my_cache_1/Simulator.cpp

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib-M24/examples/my_cache_1/Simulator.cpp > CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.i

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib-M24/examples/my_cache_1/Simulator.cpp -o CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.s

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.o: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/flags.make
CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.o: ../Reader/BinaryReader.cpp
CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.o: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib-M24/examples/my_cache_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.o -MF CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.o.d -o CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.o -c /disk/CacheLib-M24/examples/my_cache_1/Reader/BinaryReader.cpp

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib-M24/examples/my_cache_1/Reader/BinaryReader.cpp > CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.i

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib-M24/examples/my_cache_1/Reader/BinaryReader.cpp -o CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.s

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.o: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/flags.make
CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.o: ../Reader/ZstdReader.cpp
CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.o: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk/CacheLib-M24/examples/my_cache_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.o -MF CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.o.d -o CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.o -c /disk/CacheLib-M24/examples/my_cache_1/Reader/ZstdReader.cpp

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk/CacheLib-M24/examples/my_cache_1/Reader/ZstdReader.cpp > CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.i

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk/CacheLib-M24/examples/my_cache_1/Reader/ZstdReader.cpp -o CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.s

# Object files for target my_cache_TinyLFU_MarginalHits
my_cache_TinyLFU_MarginalHits_OBJECTS = \
"CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.o" \
"CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.o" \
"CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.o" \
"CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.o"

# External object files for target my_cache_TinyLFU_MarginalHits
my_cache_TinyLFU_MarginalHits_EXTERNAL_OBJECTS =

my_cache_TinyLFU_MarginalHits: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/main.cpp.o
my_cache_TinyLFU_MarginalHits: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Simulator.cpp.o
my_cache_TinyLFU_MarginalHits: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/BinaryReader.cpp.o
my_cache_TinyLFU_MarginalHits: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/Reader/ZstdReader.cpp.o
my_cache_TinyLFU_MarginalHits: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/build.make
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libcachelib_allocator.a
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libcachelib_shm.a
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libcachelib_navy.a
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libcachelib_common.a
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libthriftcpp2.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libthriftfrozen2.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libthriftmetadata.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libthriftanyrep.so
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libthrifttype.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libthrifttyperep.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libthriftannotation.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libserverdbginfo.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libthriftprotocol.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libasync.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libwangle.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libfizz.so.1.0.0
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libsodium.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/librt.a
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libtransport.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/librpcmetadata.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libthrift-core.so.1.0.0
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libconcurrency.so.1.0.0
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libz.so
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libfollybenchmark.so.0.58.0-dev
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libfolly_exception_counter.so.0.58.0-dev
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libfolly_exception_tracer.so.0.58.0-dev
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libfolly_exception_tracer_base.so.0.58.0-dev
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libfolly.so.0.58.0-dev
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libfmt.so.10.2.1
my_cache_TinyLFU_MarginalHits: /disk/CacheLib/opt/cachelib/lib/libglog.so
my_cache_TinyLFU_MarginalHits: /disk/CacheLib-M24/opt/cachelib/lib/libgflags.so.2.2.2
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libboost_context.so.1.74.0
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libboost_program_options.so.1.74.0
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.74.0
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.74.0
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.74.0
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libevent.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libdouble-conversion.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libz.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libssl.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libcrypto.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libbz2.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/liblzma.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/liblz4.so
my_cache_TinyLFU_MarginalHits: /disk/CacheLib/opt/cachelib/lib/libzstd.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libsnappy.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libdwarf.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libiberty.a
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libaio.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libsodium.so
my_cache_TinyLFU_MarginalHits: /usr/lib/x86_64-linux-gnu/libunwind.so
my_cache_TinyLFU_MarginalHits: CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/disk/CacheLib-M24/examples/my_cache_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable my_cache_TinyLFU_MarginalHits"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/build: my_cache_TinyLFU_MarginalHits
.PHONY : CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/build

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/clean

CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/depend:
	cd /disk/CacheLib-M24/examples/my_cache_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /disk/CacheLib-M24/examples/my_cache_1 /disk/CacheLib-M24/examples/my_cache_1 /disk/CacheLib-M24/examples/my_cache_1/build /disk/CacheLib-M24/examples/my_cache_1/build /disk/CacheLib-M24/examples/my_cache_1/build/CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_cache_TinyLFU_MarginalHits.dir/depend

