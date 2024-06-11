#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "wangle::wangle" for configuration "RelWithDebInfo"
set_property(TARGET wangle::wangle APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(wangle::wangle PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libwangle.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libwangle.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS wangle::wangle )
list(APPEND _IMPORT_CHECK_FILES_FOR_wangle::wangle "${_IMPORT_PREFIX}/lib/libwangle.so.1.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
