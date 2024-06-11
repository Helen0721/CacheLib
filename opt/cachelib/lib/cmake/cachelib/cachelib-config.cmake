# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# CMake package configuration file for cachelib
#
# Defines the target "cachelib"
# Add this to your target_link_libraries() call to depend on cachelib.
#
# Also sets the variables CACHELIB_INCLUDE_DIR and CACHELIB_LIBRARIES.
# However, in most cases using the cachelib::cachelib target is sufficient,
# and you won't need these variables.
#


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was cachelib-config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

include(CMakeFindDependencyMacro)

set_and_check(CACHELIB_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include/cachelib")
set_and_check(CACHELIB_CMAKE_DIR "${PACKAGE_PREFIX_DIR}/lib/cmake/cachelib")

find_dependency(Gflags)
find_dependency(folly )
find_dependency(fizz )
find_dependency(wangle)
find_dependency(FBThrift)

if (NOT TARGET cachelib)
	include("${CACHELIB_CMAKE_DIR}/cachelib-targets.cmake")
endif()

set(CACHELIB_LIBRARIES cachelib)

if (NOT cachelib_FIND_QUIETLY)
  message(STATUS "Found cachelib: ${PACKAGE_PREFIX_DIR}")
endif()
