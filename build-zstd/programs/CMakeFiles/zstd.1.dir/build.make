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
CMAKE_SOURCE_DIR = /disk/CacheLib/cachelib/external/zstd/build/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /disk/CacheLib/build-zstd

# Utility rule file for zstd.1.

# Include any custom commands dependencies for this target.
include programs/CMakeFiles/zstd.1.dir/compiler_depend.make

# Include the progress variables for this target.
include programs/CMakeFiles/zstd.1.dir/progress.make

programs/CMakeFiles/zstd.1:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/disk/CacheLib/build-zstd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying manpage zstd.1"
	cd /disk/CacheLib/build-zstd/programs && /usr/bin/cmake -E copy /disk/CacheLib/cachelib/external/zstd/build/cmake/../../programs/zstd.1 .

zstd.1: programs/CMakeFiles/zstd.1
zstd.1: programs/CMakeFiles/zstd.1.dir/build.make
.PHONY : zstd.1

# Rule to build all files generated by this target.
programs/CMakeFiles/zstd.1.dir/build: zstd.1
.PHONY : programs/CMakeFiles/zstd.1.dir/build

programs/CMakeFiles/zstd.1.dir/clean:
	cd /disk/CacheLib/build-zstd/programs && $(CMAKE_COMMAND) -P CMakeFiles/zstd.1.dir/cmake_clean.cmake
.PHONY : programs/CMakeFiles/zstd.1.dir/clean

programs/CMakeFiles/zstd.1.dir/depend:
	cd /disk/CacheLib/build-zstd && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /disk/CacheLib/cachelib/external/zstd/build/cmake /disk/CacheLib/cachelib/external/zstd/build/cmake/programs /disk/CacheLib/build-zstd /disk/CacheLib/build-zstd/programs /disk/CacheLib/build-zstd/programs/CMakeFiles/zstd.1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/CMakeFiles/zstd.1.dir/depend

