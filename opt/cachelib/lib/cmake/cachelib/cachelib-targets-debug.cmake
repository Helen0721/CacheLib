#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cachelib_common" for configuration "Debug"
set_property(TARGET cachelib_common APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cachelib_common PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libcachelib_common.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cachelib_common )
list(APPEND _IMPORT_CHECK_FILES_FOR_cachelib_common "${_IMPORT_PREFIX}/lib/libcachelib_common.a" )

# Import target "cachelib_shm" for configuration "Debug"
set_property(TARGET cachelib_shm APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cachelib_shm PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libcachelib_shm.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cachelib_shm )
list(APPEND _IMPORT_CHECK_FILES_FOR_cachelib_shm "${_IMPORT_PREFIX}/lib/libcachelib_shm.a" )

# Import target "cachelib_navy" for configuration "Debug"
set_property(TARGET cachelib_navy APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cachelib_navy PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libcachelib_navy.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cachelib_navy )
list(APPEND _IMPORT_CHECK_FILES_FOR_cachelib_navy "${_IMPORT_PREFIX}/lib/libcachelib_navy.a" )

# Import target "cachelib_allocator" for configuration "Debug"
set_property(TARGET cachelib_allocator APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cachelib_allocator PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libcachelib_allocator.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cachelib_allocator )
list(APPEND _IMPORT_CHECK_FILES_FOR_cachelib_allocator "${_IMPORT_PREFIX}/lib/libcachelib_allocator.a" )

# Import target "cachelib_datatype" for configuration "Debug"
set_property(TARGET cachelib_datatype APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cachelib_datatype PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libcachelib_datatype.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cachelib_datatype )
list(APPEND _IMPORT_CHECK_FILES_FOR_cachelib_datatype "${_IMPORT_PREFIX}/lib/libcachelib_datatype.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
