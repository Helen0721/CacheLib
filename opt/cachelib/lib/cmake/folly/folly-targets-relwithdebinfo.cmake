#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Folly::folly" for configuration "RelWithDebInfo"
set_property(TARGET Folly::folly APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Folly::folly PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libfolly.so.0.58.0-dev"
  IMPORTED_SONAME_RELWITHDEBINFO "libfolly.so.0.58.0-dev"
  )

list(APPEND _IMPORT_CHECK_TARGETS Folly::folly )
list(APPEND _IMPORT_CHECK_FILES_FOR_Folly::folly "${_IMPORT_PREFIX}/lib/libfolly.so.0.58.0-dev" )

# Import target "Folly::folly_test_util" for configuration "RelWithDebInfo"
set_property(TARGET Folly::folly_test_util APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Folly::folly_test_util PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libfolly_test_util.so.0.58.0-dev"
  IMPORTED_SONAME_RELWITHDEBINFO "libfolly_test_util.so.0.58.0-dev"
  )

list(APPEND _IMPORT_CHECK_TARGETS Folly::folly_test_util )
list(APPEND _IMPORT_CHECK_FILES_FOR_Folly::folly_test_util "${_IMPORT_PREFIX}/lib/libfolly_test_util.so.0.58.0-dev" )

# Import target "Folly::follybenchmark" for configuration "RelWithDebInfo"
set_property(TARGET Folly::follybenchmark APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Folly::follybenchmark PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libfollybenchmark.so.0.58.0-dev"
  IMPORTED_SONAME_RELWITHDEBINFO "libfollybenchmark.so.0.58.0-dev"
  )

list(APPEND _IMPORT_CHECK_TARGETS Folly::follybenchmark )
list(APPEND _IMPORT_CHECK_FILES_FOR_Folly::follybenchmark "${_IMPORT_PREFIX}/lib/libfollybenchmark.so.0.58.0-dev" )

# Import target "Folly::folly_exception_tracer_base" for configuration "RelWithDebInfo"
set_property(TARGET Folly::folly_exception_tracer_base APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Folly::folly_exception_tracer_base PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libfolly_exception_tracer_base.so.0.58.0-dev"
  IMPORTED_SONAME_RELWITHDEBINFO "libfolly_exception_tracer_base.so.0.58.0-dev"
  )

list(APPEND _IMPORT_CHECK_TARGETS Folly::folly_exception_tracer_base )
list(APPEND _IMPORT_CHECK_FILES_FOR_Folly::folly_exception_tracer_base "${_IMPORT_PREFIX}/lib/libfolly_exception_tracer_base.so.0.58.0-dev" )

# Import target "Folly::folly_exception_tracer" for configuration "RelWithDebInfo"
set_property(TARGET Folly::folly_exception_tracer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Folly::folly_exception_tracer PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libfolly_exception_tracer.so.0.58.0-dev"
  IMPORTED_SONAME_RELWITHDEBINFO "libfolly_exception_tracer.so.0.58.0-dev"
  )

list(APPEND _IMPORT_CHECK_TARGETS Folly::folly_exception_tracer )
list(APPEND _IMPORT_CHECK_FILES_FOR_Folly::folly_exception_tracer "${_IMPORT_PREFIX}/lib/libfolly_exception_tracer.so.0.58.0-dev" )

# Import target "Folly::folly_exception_counter" for configuration "RelWithDebInfo"
set_property(TARGET Folly::folly_exception_counter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Folly::folly_exception_counter PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libfolly_exception_counter.so.0.58.0-dev"
  IMPORTED_SONAME_RELWITHDEBINFO "libfolly_exception_counter.so.0.58.0-dev"
  )

list(APPEND _IMPORT_CHECK_TARGETS Folly::folly_exception_counter )
list(APPEND _IMPORT_CHECK_FILES_FOR_Folly::folly_exception_counter "${_IMPORT_PREFIX}/lib/libfolly_exception_counter.so.0.58.0-dev" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
