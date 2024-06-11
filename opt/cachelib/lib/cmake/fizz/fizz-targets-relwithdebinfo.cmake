#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "fizz::fizz" for configuration "RelWithDebInfo"
set_property(TARGET fizz::fizz APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(fizz::fizz PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "gflags_shared"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libfizz.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libfizz.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS fizz::fizz )
list(APPEND _IMPORT_CHECK_FILES_FOR_fizz::fizz "${_IMPORT_PREFIX}/lib/libfizz.so.1.0.0" )

# Import target "fizz::fizz_test_support" for configuration "RelWithDebInfo"
set_property(TARGET fizz::fizz_test_support APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(fizz::fizz_test_support PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libfizz_test_support.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libfizz_test_support.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS fizz::fizz_test_support )
list(APPEND _IMPORT_CHECK_FILES_FOR_fizz::fizz_test_support "${_IMPORT_PREFIX}/lib/libfizz_test_support.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
