#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "FBThrift::thrift1" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::thrift1 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::thrift1 PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/thrift1"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::thrift1 )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::thrift1 "${_IMPORT_PREFIX}/bin/thrift1" )

# Import target "FBThrift::compiler_ast" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::compiler_ast APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::compiler_ast PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcompiler_ast.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libcompiler_ast.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::compiler_ast )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::compiler_ast "${_IMPORT_PREFIX}/lib/libcompiler_ast.so.1.0.0" )

# Import target "FBThrift::compiler_base" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::compiler_base APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::compiler_base PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcompiler_base.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::compiler_base )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::compiler_base "${_IMPORT_PREFIX}/lib/libcompiler_base.a" )

# Import target "FBThrift::compiler" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::compiler APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::compiler PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcompiler.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libcompiler.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::compiler )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::compiler "${_IMPORT_PREFIX}/lib/libcompiler.so.1.0.0" )

# Import target "FBThrift::mustache" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::mustache APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::mustache PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libmustache.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libmustache.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::mustache )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::mustache "${_IMPORT_PREFIX}/lib/libmustache.so.1.0.0" )

# Import target "FBThrift::thriftannotation" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::thriftannotation APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::thriftannotation PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libthriftannotation.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libthriftannotation.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::thriftannotation )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::thriftannotation "${_IMPORT_PREFIX}/lib/libthriftannotation.so.1.0.0" )

# Import target "FBThrift::thrift-core" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::thrift-core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::thrift-core PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libthrift-core.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libthrift-core.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::thrift-core )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::thrift-core "${_IMPORT_PREFIX}/lib/libthrift-core.so.1.0.0" )

# Import target "FBThrift::concurrency" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::concurrency APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::concurrency PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libconcurrency.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libconcurrency.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::concurrency )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::concurrency "${_IMPORT_PREFIX}/lib/libconcurrency.so.1.0.0" )

# Import target "FBThrift::transport" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::transport APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::transport PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libtransport.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libtransport.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::transport )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::transport "${_IMPORT_PREFIX}/lib/libtransport.so.1.0.0" )

# Import target "FBThrift::async" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::async APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::async PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libasync.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libasync.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::async )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::async "${_IMPORT_PREFIX}/lib/libasync.so.1.0.0" )

# Import target "FBThrift::rpcmetadata" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::rpcmetadata APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::rpcmetadata PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/librpcmetadata.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "librpcmetadata.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::rpcmetadata )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::rpcmetadata "${_IMPORT_PREFIX}/lib/librpcmetadata.so.1.0.0" )

# Import target "FBThrift::thriftmetadata" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::thriftmetadata APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::thriftmetadata PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libthriftmetadata.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libthriftmetadata.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::thriftmetadata )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::thriftmetadata "${_IMPORT_PREFIX}/lib/libthriftmetadata.so.1.0.0" )

# Import target "FBThrift::thriftfrozen2" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::thriftfrozen2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::thriftfrozen2 PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libthriftfrozen2.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libthriftfrozen2.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::thriftfrozen2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::thriftfrozen2 "${_IMPORT_PREFIX}/lib/libthriftfrozen2.so.1.0.0" )

# Import target "FBThrift::thrifttyperep" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::thrifttyperep APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::thrifttyperep PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libthrifttyperep.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libthrifttyperep.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::thrifttyperep )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::thrifttyperep "${_IMPORT_PREFIX}/lib/libthrifttyperep.so.1.0.0" )

# Import target "FBThrift::thrifttype" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::thrifttype APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::thrifttype PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libthrifttype.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libthrifttype.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::thrifttype )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::thrifttype "${_IMPORT_PREFIX}/lib/libthrifttype.so.1.0.0" )

# Import target "FBThrift::thriftanyrep" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::thriftanyrep APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::thriftanyrep PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libthriftanyrep.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libthriftanyrep.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::thriftanyrep )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::thriftanyrep "${_IMPORT_PREFIX}/lib/libthriftanyrep.so" )

# Import target "FBThrift::thriftprotocol" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::thriftprotocol APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::thriftprotocol PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libthriftprotocol.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libthriftprotocol.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::thriftprotocol )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::thriftprotocol "${_IMPORT_PREFIX}/lib/libthriftprotocol.so.1.0.0" )

# Import target "FBThrift::thriftcpp2" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::thriftcpp2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::thriftcpp2 PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libthriftcpp2.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libthriftcpp2.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::thriftcpp2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::thriftcpp2 "${_IMPORT_PREFIX}/lib/libthriftcpp2.so.1.0.0" )

# Import target "FBThrift::serverdbginfo" for configuration "RelWithDebInfo"
set_property(TARGET FBThrift::serverdbginfo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(FBThrift::serverdbginfo PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libserverdbginfo.so.1.0.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libserverdbginfo.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS FBThrift::serverdbginfo )
list(APPEND _IMPORT_CHECK_FILES_FOR_FBThrift::serverdbginfo "${_IMPORT_PREFIX}/lib/libserverdbginfo.so.1.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
