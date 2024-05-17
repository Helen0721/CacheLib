#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations

import apache.thrift.metadata.thrift_types as _fbthrift_metadata


# TODO (ffrancet): This general pattern can be optimized by using tuples and dicts
# instead of re-generating thrift structs
def _fbthrift_gen_metadata_exception_CustomException(metadata_struct: _fbthrift_metadata.ThriftMetadata) -> _fbthrift_metadata.ThriftMetadata:
    qualified_name = "module.CustomException"

    if qualified_name in metadata_struct.exceptions:
        return metadata_struct
    fields = [
        _fbthrift_metadata.ThriftField(id=1, type=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_STRING_TYPE), name="message", is_optional=False, structured_annotations=[
        ]),
    ]
    struct_dict = dict(metadata_struct.exceptions)
    struct_dict[qualified_name] = _fbthrift_metadata.ThriftException(name=qualified_name, fields=fields,
        structured_annotations=[
        ])
    new_struct = metadata_struct(exceptions=struct_dict)

     # message

    return new_struct
def gen_metadata_exception_CustomException() -> _fbthrift_metadata.ThriftMetadata:
    return _fbthrift_gen_metadata_exception_CustomException(_fbthrift_metadata.ThriftMetadata(structs={}, enums={}, exceptions={}, services={}))


def gen_metadata_service_MyService() -> _fbthrift_metadata.ThriftMetadata:
    return _fbthrift_gen_metadata_service_MyService(_fbthrift_metadata.ThriftMetadata(structs={}, enums={}, exceptions={}, services={}))

def _fbthrift_gen_metadata_service_MyService(metadata_struct: _fbthrift_metadata.ThriftMetadata) -> _fbthrift_metadata.ThriftMetadata:
    qualified_name = "module.MyService"
    
    if qualified_name in metadata_struct.services:
        return metadata_struct
    
    functions = [
        _fbthrift_metadata.ThriftFunction(name="foo", return_type=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_VOID_TYPE), arguments=[
        ], exceptions = [
        ], is_oneway=False, structured_annotations=[
        ]),
        _fbthrift_metadata.ThriftFunction(name="interact", return_type=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_VOID_TYPE), arguments=[
            _fbthrift_metadata.ThriftField(id=1, type=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_I32_TYPE), name="arg", is_optional=False, structured_annotations=[
            ]),
        ], exceptions = [
        ], is_oneway=False, structured_annotations=[
        ]),
        _fbthrift_metadata.ThriftFunction(name="interactFast", return_type=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_I32_TYPE), arguments=[
        ], exceptions = [
        ], is_oneway=False, structured_annotations=[
        ]),
        _fbthrift_metadata.ThriftFunction(name="serialize", return_type=_fbthrift_metadata.ThriftType(t_stream=_fbthrift_metadata.ThriftStreamType(elemType=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_I32_TYPE),initialResponseType=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_I32_TYPE))), arguments=[
        ], exceptions = [
        ], is_oneway=False, structured_annotations=[
        ]),
    ]
    
    service_dict = dict(metadata_struct.services)
    service_dict[qualified_name] = _fbthrift_metadata.ThriftService(name=qualified_name, functions=functions,  structured_annotations=[
    ])
    new_struct = metadata_struct(services=service_dict)
    
    
    
     # return value
    
    
     # arg
    
    
     # return value
    
    
    
    
     # return value
    
    
    
    
     # elem
     # response  # return value
    
    
    return new_struct
def gen_metadata_service_MyService_MyInteraction() -> _fbthrift_metadata.ThriftMetadata:
    return _fbthrift_gen_metadata_service_MyService_MyInteraction(_fbthrift_metadata.ThriftMetadata(structs={}, enums={}, exceptions={}, services={}))

def _fbthrift_gen_metadata_service_MyService_MyInteraction(metadata_struct: _fbthrift_metadata.ThriftMetadata) -> _fbthrift_metadata.ThriftMetadata:
    qualified_name = "module.MyInteraction"
    
    if qualified_name in metadata_struct.services:
        return metadata_struct
    
    functions = [
        _fbthrift_metadata.ThriftFunction(name="frobnicate", return_type=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_I32_TYPE), arguments=[
        ], exceptions = [
            _fbthrift_metadata.ThriftField(id=1, type=_fbthrift_metadata.ThriftType(t_struct=_fbthrift_metadata.ThriftStructType(name="module.CustomException")), name="ex", is_optional=False, structured_annotations=[
            ]),
        ], is_oneway=False, structured_annotations=[
        ]),
        _fbthrift_metadata.ThriftFunction(name="ping", return_type=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_VOID_TYPE), arguments=[
        ], exceptions = [
        ], is_oneway=True, structured_annotations=[
        ]),
        _fbthrift_metadata.ThriftFunction(name="truthify", return_type=_fbthrift_metadata.ThriftType(t_stream=_fbthrift_metadata.ThriftStreamType(elemType=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_BOOL_TYPE))), arguments=[
        ], exceptions = [
        ], is_oneway=False, structured_annotations=[
        ]),
        _fbthrift_metadata.ThriftFunction(name="encode", return_type=_fbthrift_metadata.ThriftType(t_sink=_fbthrift_metadata.ThriftSinkType(elemType=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_STRING_TYPE),finalResponseType=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_BINARY_TYPE),initialResponseType=_fbthrift_metadata.ThriftType(t_set=_fbthrift_metadata.ThriftSetType(valueType=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_I32_TYPE))))), arguments=[
        ], exceptions = [
        ], is_oneway=False, structured_annotations=[
        ]),
    ]
    
    service_dict = dict(metadata_struct.services)
    service_dict[qualified_name] = _fbthrift_metadata.ThriftService(name=qualified_name, functions=functions,  structured_annotations=[
    ])
    new_struct = metadata_struct(services=service_dict)
    
    
    new_struct = _fbthrift_gen_metadata_exception_CustomException(new_struct) # ex
    
     # return value
    
    
    
    
     # return value
    
    
    
    
     # elem
     # response  # return value
    
    
    
    
     # elem
     # final response
     # first response  # return value
    
    
    return new_struct
def gen_metadata_service_MyService_MyInteractionFast() -> _fbthrift_metadata.ThriftMetadata:
    return _fbthrift_gen_metadata_service_MyService_MyInteractionFast(_fbthrift_metadata.ThriftMetadata(structs={}, enums={}, exceptions={}, services={}))

def _fbthrift_gen_metadata_service_MyService_MyInteractionFast(metadata_struct: _fbthrift_metadata.ThriftMetadata) -> _fbthrift_metadata.ThriftMetadata:
    qualified_name = "module.MyInteractionFast"
    
    if qualified_name in metadata_struct.services:
        return metadata_struct
    
    functions = [
        _fbthrift_metadata.ThriftFunction(name="frobnicate", return_type=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_I32_TYPE), arguments=[
        ], exceptions = [
        ], is_oneway=False, structured_annotations=[
        ]),
        _fbthrift_metadata.ThriftFunction(name="ping", return_type=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_VOID_TYPE), arguments=[
        ], exceptions = [
        ], is_oneway=True, structured_annotations=[
        ]),
        _fbthrift_metadata.ThriftFunction(name="truthify", return_type=_fbthrift_metadata.ThriftType(t_stream=_fbthrift_metadata.ThriftStreamType(elemType=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_BOOL_TYPE))), arguments=[
        ], exceptions = [
        ], is_oneway=False, structured_annotations=[
        ]),
        _fbthrift_metadata.ThriftFunction(name="encode", return_type=_fbthrift_metadata.ThriftType(t_sink=_fbthrift_metadata.ThriftSinkType(elemType=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_STRING_TYPE),finalResponseType=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_BINARY_TYPE),initialResponseType=_fbthrift_metadata.ThriftType(t_set=_fbthrift_metadata.ThriftSetType(valueType=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_I32_TYPE))))), arguments=[
        ], exceptions = [
        ], is_oneway=False, structured_annotations=[
        ]),
    ]
    
    service_dict = dict(metadata_struct.services)
    service_dict[qualified_name] = _fbthrift_metadata.ThriftService(name=qualified_name, functions=functions,  structured_annotations=[
    ])
    new_struct = metadata_struct(services=service_dict)
    
    
    
     # return value
    
    
    
    
     # return value
    
    
    
    
     # elem
     # response  # return value
    
    
    
    
     # elem
     # final response
     # first response  # return value
    
    
    return new_struct
def gen_metadata_service_MyService_SerialInteraction() -> _fbthrift_metadata.ThriftMetadata:
    return _fbthrift_gen_metadata_service_MyService_SerialInteraction(_fbthrift_metadata.ThriftMetadata(structs={}, enums={}, exceptions={}, services={}))

def _fbthrift_gen_metadata_service_MyService_SerialInteraction(metadata_struct: _fbthrift_metadata.ThriftMetadata) -> _fbthrift_metadata.ThriftMetadata:
    qualified_name = "module.SerialInteraction"
    
    if qualified_name in metadata_struct.services:
        return metadata_struct
    
    functions = [
        _fbthrift_metadata.ThriftFunction(name="frobnicate", return_type=_fbthrift_metadata.ThriftType(t_primitive=_fbthrift_metadata.ThriftPrimitiveType.THRIFT_VOID_TYPE), arguments=[
        ], exceptions = [
        ], is_oneway=False, structured_annotations=[
        ]),
    ]
    
    service_dict = dict(metadata_struct.services)
    service_dict[qualified_name] = _fbthrift_metadata.ThriftService(name=qualified_name, functions=functions,  structured_annotations=[
    ])
    new_struct = metadata_struct(services=service_dict)
    
    
    
     # return value
    
    
    return new_struct

def _fbthrift_metadata_service_response_MyService() -> _fbthrift_metadata.ThriftServiceMetadataResponse:
    metadata = gen_metadata_service_MyService()
    context = _fbthrift_metadata.ThriftServiceContext(service_info=metadata.services["module.MyService"], module=_fbthrift_metadata.ThriftModuleContext(name="module"))
    services = [_fbthrift_metadata.ThriftServiceContextRef(module=_fbthrift_metadata.ThriftModuleContext(name=name.split('.')[0]), service_name=name) for name in metadata.services]
    return _fbthrift_metadata.ThriftServiceMetadataResponse(metadata=metadata,context=context,services=services)




def getThriftModuleMetadata() -> _fbthrift_metadata.ThriftMetadata:
    meta = _fbthrift_metadata.ThriftMetadata(structs={}, enums={}, exceptions={}, services={})
    meta = _fbthrift_gen_metadata_exception_CustomException(meta)
    meta = _fbthrift_gen_metadata_service_MyService(meta)
    return meta
