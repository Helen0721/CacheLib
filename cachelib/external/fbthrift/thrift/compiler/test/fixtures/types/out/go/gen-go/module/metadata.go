// @generated by Thrift for [[[ program path ]]]
// This file is probably not the place you want to edit!

package module // [[[ program thrift source path ]]]

import (
    included "included"
    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift"
    metadata "github.com/facebook/fbthrift/thrift/lib/thrift/metadata"
)

// mapsCopy is a copy of maps.Copy from Go 1.21
// TODO: remove mapsCopy once we can safely upgrade to Go 1.21 without requiring any rollback.
func mapsCopy[M1 ~map[K]V, M2 ~map[K]V, K comparable, V any](dst M1, src M2) {
	for k, v := range src {
		dst[k] = v
	}
}

var _ = included.GoUnusedProtection__
// (needed to ensure safety because of naive import list construction)
var _ = thrift.ZERO
// TODO: uncomment when can safely upgrade to Go 1.21 without requiring any rollback.
// var _ = maps.Copy[map[int]int, map[int]int]
var _ = metadata.GoUnusedProtection__

// Premade Thrift types
var (
    premadeThriftType_string = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_STRING_TYPE.Ptr(),
            )
    premadeThriftType_i32 = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_I32_TYPE.Ptr(),
            )
    premadeThriftType_list_i32 = metadata.NewThriftType().SetTList(
        metadata.NewThriftListType().
            SetValueType(premadeThriftType_i32),
            )
    premadeThriftType_set_i32 = metadata.NewThriftType().SetTSet(
        metadata.NewThriftSetType().
            SetValueType(premadeThriftType_i32),
            )
    premadeThriftType_module_set_i32_7194 = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.set_i32_7194").
            SetUnderlyingType(premadeThriftType_set_i32),
            )
    premadeThriftType_map_i32_string = metadata.NewThriftType().SetTMap(
        metadata.NewThriftMapType().
            SetKeyType(premadeThriftType_i32).
            SetValueType(premadeThriftType_string),
            )
    premadeThriftType_module_map_i32_string_1261 = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.map_i32_string_1261").
            SetUnderlyingType(premadeThriftType_map_i32_string),
            )
    premadeThriftType_included_SomeMap = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("included.SomeMap").
            SetUnderlyingType(premadeThriftType_map_i32_string),
            )
    premadeThriftType_i64 = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_I64_TYPE.Ptr(),
            )
    premadeThriftType_module_MyForwardRefEnum = metadata.NewThriftType().SetTEnum(
        metadata.NewThriftEnumType().
            SetName("module.MyForwardRefEnum"),
            )
    premadeThriftType_bool = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_BOOL_TYPE.Ptr(),
            )
    premadeThriftType_module_TrivialNumeric = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.TrivialNumeric"),
            )
    premadeThriftType_map_string_i32 = metadata.NewThriftType().SetTMap(
        metadata.NewThriftMapType().
            SetKeyType(premadeThriftType_string).
            SetValueType(premadeThriftType_i32),
            )
    premadeThriftType_module_ComplexString = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.ComplexString"),
            )
    premadeThriftType_byte = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_BYTE_TYPE.Ptr(),
            )
    premadeThriftType_i16 = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_I16_TYPE.Ptr(),
            )
    premadeThriftType_module_MyDataItem = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.MyDataItem"),
            )
    premadeThriftType_binary = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_BINARY_TYPE.Ptr(),
            )
    premadeThriftType_module_TBinary = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.TBinary").
            SetUnderlyingType(premadeThriftType_binary),
            )
    premadeThriftType_module_TBinary_8623 = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.TBinary_8623").
            SetUnderlyingType(premadeThriftType_module_TBinary),
            )
    premadeThriftType_list_included_SomeMap = metadata.NewThriftType().SetTList(
        metadata.NewThriftListType().
            SetValueType(premadeThriftType_included_SomeMap),
            )
    premadeThriftType_included_SomeListOfTypeMap = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("included.SomeListOfTypeMap").
            SetUnderlyingType(premadeThriftType_list_included_SomeMap),
            )
    premadeThriftType_module_SomeListOfTypeMap_2468 = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.SomeListOfTypeMap_2468").
            SetUnderlyingType(premadeThriftType_included_SomeListOfTypeMap),
            )
    premadeThriftType_module_ForwardUsageStruct = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.ForwardUsageStruct"),
            )
    premadeThriftType_module_ForwardUsageByRef = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.ForwardUsageByRef"),
            )
    premadeThriftType_module_ForwardUsageRoot = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.ForwardUsageRoot"),
            )
    premadeThriftType_module_IncompleteMapDep = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.IncompleteMapDep"),
            )
    premadeThriftType_map_i32_module_IncompleteMapDep = metadata.NewThriftType().SetTMap(
        metadata.NewThriftMapType().
            SetKeyType(premadeThriftType_i32).
            SetValueType(premadeThriftType_module_IncompleteMapDep),
            )
    premadeThriftType_module_CompleteMapDep = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.CompleteMapDep"),
            )
    premadeThriftType_map_i32_module_CompleteMapDep = metadata.NewThriftType().SetTMap(
        metadata.NewThriftMapType().
            SetKeyType(premadeThriftType_i32).
            SetValueType(premadeThriftType_module_CompleteMapDep),
            )
    premadeThriftType_module_IncompleteListDep = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.IncompleteListDep"),
            )
    premadeThriftType_list_module_IncompleteListDep = metadata.NewThriftType().SetTList(
        metadata.NewThriftListType().
            SetValueType(premadeThriftType_module_IncompleteListDep),
            )
    premadeThriftType_module_CompleteListDep = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.CompleteListDep"),
            )
    premadeThriftType_list_module_CompleteListDep = metadata.NewThriftType().SetTList(
        metadata.NewThriftListType().
            SetValueType(premadeThriftType_module_CompleteListDep),
            )
    premadeThriftType_module_AdaptedListDep = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.AdaptedListDep"),
            )
    premadeThriftType_list_module_AdaptedListDep = metadata.NewThriftType().SetTList(
        metadata.NewThriftListType().
            SetValueType(premadeThriftType_module_AdaptedListDep),
            )
    premadeThriftType_module_AdaptedList = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.AdaptedList"),
            )
    premadeThriftType_module_DependentAdaptedListDep = metadata.NewThriftType().SetTStruct(
        metadata.NewThriftStructType().
            SetName("module.DependentAdaptedListDep"),
            )
    premadeThriftType_list_module_DependentAdaptedListDep = metadata.NewThriftType().SetTList(
        metadata.NewThriftListType().
            SetValueType(premadeThriftType_module_DependentAdaptedListDep),
            )
    premadeThriftType_module_list_i32_9187 = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.list_i32_9187").
            SetUnderlyingType(premadeThriftType_list_i32),
            )
    premadeThriftType_module_set_i32_7070 = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.set_i32_7070").
            SetUnderlyingType(premadeThriftType_set_i32),
            )
    premadeThriftType_map_i32_i32 = metadata.NewThriftType().SetTMap(
        metadata.NewThriftMapType().
            SetKeyType(premadeThriftType_i32).
            SetValueType(premadeThriftType_i32),
            )
    premadeThriftType_module_map_i32_i32_9565 = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.map_i32_i32_9565").
            SetUnderlyingType(premadeThriftType_map_i32_i32),
            )
    premadeThriftType_module_string_5252 = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.string_5252").
            SetUnderlyingType(premadeThriftType_string),
            )
    premadeThriftType_module_i32_9314 = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.i32_9314").
            SetUnderlyingType(premadeThriftType_i32),
            )
    premadeThriftType_module_IntTypedef = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.IntTypedef").
            SetUnderlyingType(premadeThriftType_i32),
            )
    premadeThriftType_module_UintTypedef = metadata.NewThriftType().SetTTypedef(
        metadata.NewThriftTypedefType().
            SetName("module.UintTypedef").
            SetUnderlyingType(premadeThriftType_module_IntTypedef),
            )
    premadeThriftType_map_module_TBinary_i64 = metadata.NewThriftType().SetTMap(
        metadata.NewThriftMapType().
            SetKeyType(premadeThriftType_module_TBinary).
            SetValueType(premadeThriftType_i64),
            )
    premadeThriftType_list_i64 = metadata.NewThriftType().SetTList(
        metadata.NewThriftListType().
            SetValueType(premadeThriftType_i64),
            )
)

var structMetadatas = []*metadata.ThriftStruct{
    metadata.NewThriftStruct().
    SetName("module.empty_struct").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("module.decorated_struct").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("field").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.ContainerStruct").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(2).
    SetName("fieldB").
    SetIsOptional(false).
    SetType(premadeThriftType_list_i32),
            metadata.NewThriftField().
    SetId(3).
    SetName("fieldC").
    SetIsOptional(false).
    SetType(premadeThriftType_list_i32),
            metadata.NewThriftField().
    SetId(4).
    SetName("fieldD").
    SetIsOptional(false).
    SetType(premadeThriftType_list_i32),
            metadata.NewThriftField().
    SetId(5).
    SetName("fieldE").
    SetIsOptional(false).
    SetType(premadeThriftType_list_i32),
            metadata.NewThriftField().
    SetId(6).
    SetName("fieldF").
    SetIsOptional(false).
    SetType(premadeThriftType_module_set_i32_7194),
            metadata.NewThriftField().
    SetId(7).
    SetName("fieldG").
    SetIsOptional(false).
    SetType(premadeThriftType_module_map_i32_string_1261),
            metadata.NewThriftField().
    SetId(8).
    SetName("fieldH").
    SetIsOptional(false).
    SetType(premadeThriftType_included_SomeMap),
            metadata.NewThriftField().
    SetId(12).
    SetName("fieldA").
    SetIsOptional(false).
    SetType(premadeThriftType_list_i32),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.CppTypeStruct").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("fieldA").
    SetIsOptional(false).
    SetType(premadeThriftType_list_i32),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.VirtualStruct").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("MyIntField").
    SetIsOptional(false).
    SetType(premadeThriftType_i64),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.MyStructWithForwardRefEnum").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("a").
    SetIsOptional(false).
    SetType(premadeThriftType_module_MyForwardRefEnum),
            metadata.NewThriftField().
    SetId(2).
    SetName("b").
    SetIsOptional(false).
    SetType(premadeThriftType_module_MyForwardRefEnum),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.TrivialNumeric").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("a").
    SetIsOptional(false).
    SetType(premadeThriftType_i32),
            metadata.NewThriftField().
    SetId(2).
    SetName("b").
    SetIsOptional(false).
    SetType(premadeThriftType_bool),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.TrivialNestedWithDefault").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("z").
    SetIsOptional(false).
    SetType(premadeThriftType_i32),
            metadata.NewThriftField().
    SetId(2).
    SetName("n").
    SetIsOptional(false).
    SetType(premadeThriftType_module_TrivialNumeric),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.ComplexString").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("a").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
            metadata.NewThriftField().
    SetId(2).
    SetName("b").
    SetIsOptional(false).
    SetType(premadeThriftType_map_string_i32),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.ComplexNestedWithDefault").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("z").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
            metadata.NewThriftField().
    SetId(2).
    SetName("n").
    SetIsOptional(false).
    SetType(premadeThriftType_module_ComplexString),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.MinPadding").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("small").
    SetIsOptional(false).
    SetType(premadeThriftType_byte),
            metadata.NewThriftField().
    SetId(2).
    SetName("big").
    SetIsOptional(false).
    SetType(premadeThriftType_i64),
            metadata.NewThriftField().
    SetId(3).
    SetName("medium").
    SetIsOptional(false).
    SetType(premadeThriftType_i16),
            metadata.NewThriftField().
    SetId(4).
    SetName("biggish").
    SetIsOptional(false).
    SetType(premadeThriftType_i32),
            metadata.NewThriftField().
    SetId(5).
    SetName("tiny").
    SetIsOptional(false).
    SetType(premadeThriftType_byte),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.MinPaddingWithCustomType").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("small").
    SetIsOptional(false).
    SetType(premadeThriftType_byte),
            metadata.NewThriftField().
    SetId(2).
    SetName("big").
    SetIsOptional(false).
    SetType(premadeThriftType_i64),
            metadata.NewThriftField().
    SetId(3).
    SetName("medium").
    SetIsOptional(false).
    SetType(premadeThriftType_i16),
            metadata.NewThriftField().
    SetId(4).
    SetName("biggish").
    SetIsOptional(false).
    SetType(premadeThriftType_i32),
            metadata.NewThriftField().
    SetId(5).
    SetName("tiny").
    SetIsOptional(false).
    SetType(premadeThriftType_byte),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.MyStruct").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("MyIntField").
    SetIsOptional(false).
    SetType(premadeThriftType_i64),
            metadata.NewThriftField().
    SetId(2).
    SetName("MyStringField").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
            metadata.NewThriftField().
    SetId(3).
    SetName("majorVer").
    SetIsOptional(false).
    SetType(premadeThriftType_i64),
            metadata.NewThriftField().
    SetId(4).
    SetName("data").
    SetIsOptional(false).
    SetType(premadeThriftType_module_MyDataItem),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.MyDataItem").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("module.Renaming").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("foo").
    SetIsOptional(false).
    SetType(premadeThriftType_i64),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.AnnotatedTypes").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("binary_field").
    SetIsOptional(false).
    SetType(premadeThriftType_module_TBinary_8623),
            metadata.NewThriftField().
    SetId(2).
    SetName("list_field").
    SetIsOptional(false).
    SetType(premadeThriftType_module_SomeListOfTypeMap_2468),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.ForwardUsageRoot").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("ForwardUsageStruct").
    SetIsOptional(true).
    SetType(premadeThriftType_module_ForwardUsageStruct),
            metadata.NewThriftField().
    SetId(2).
    SetName("ForwardUsageByRef").
    SetIsOptional(true).
    SetType(premadeThriftType_module_ForwardUsageByRef),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.ForwardUsageStruct").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("foo").
    SetIsOptional(true).
    SetType(premadeThriftType_module_ForwardUsageRoot),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.ForwardUsageByRef").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("foo").
    SetIsOptional(true).
    SetType(premadeThriftType_module_ForwardUsageRoot),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.IncompleteMap").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("field").
    SetIsOptional(true).
    SetType(premadeThriftType_map_i32_module_IncompleteMapDep),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.IncompleteMapDep").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("module.CompleteMap").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("field").
    SetIsOptional(true).
    SetType(premadeThriftType_map_i32_module_CompleteMapDep),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.CompleteMapDep").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("module.IncompleteList").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("field").
    SetIsOptional(true).
    SetType(premadeThriftType_list_module_IncompleteListDep),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.IncompleteListDep").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("module.CompleteList").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("field").
    SetIsOptional(true).
    SetType(premadeThriftType_list_module_CompleteListDep),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.CompleteListDep").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("module.AdaptedList").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("field").
    SetIsOptional(true).
    SetType(premadeThriftType_list_module_AdaptedListDep),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.AdaptedListDep").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("field").
    SetIsOptional(false).
    SetType(premadeThriftType_module_AdaptedList),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.DependentAdaptedList").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("field").
    SetIsOptional(true).
    SetType(premadeThriftType_list_module_DependentAdaptedListDep),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.DependentAdaptedListDep").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("field").
    SetIsOptional(true).
    SetType(premadeThriftType_i16),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.AllocatorAware").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("aa_list").
    SetIsOptional(false).
    SetType(premadeThriftType_module_list_i32_9187),
            metadata.NewThriftField().
    SetId(2).
    SetName("aa_set").
    SetIsOptional(false).
    SetType(premadeThriftType_module_set_i32_7070),
            metadata.NewThriftField().
    SetId(3).
    SetName("aa_map").
    SetIsOptional(false).
    SetType(premadeThriftType_module_map_i32_i32_9565),
            metadata.NewThriftField().
    SetId(4).
    SetName("aa_string").
    SetIsOptional(false).
    SetType(premadeThriftType_module_string_5252),
            metadata.NewThriftField().
    SetId(5).
    SetName("not_a_container").
    SetIsOptional(false).
    SetType(premadeThriftType_i32),
            metadata.NewThriftField().
    SetId(6).
    SetName("aa_unique").
    SetIsOptional(false).
    SetType(premadeThriftType_module_i32_9314),
            metadata.NewThriftField().
    SetId(7).
    SetName("aa_shared").
    SetIsOptional(false).
    SetType(premadeThriftType_module_i32_9314),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.AllocatorAware2").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("not_a_container").
    SetIsOptional(false).
    SetType(premadeThriftType_i32),
            metadata.NewThriftField().
    SetId(2).
    SetName("box_field").
    SetIsOptional(true).
    SetType(premadeThriftType_i32),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.TypedefStruct").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("i32_field").
    SetIsOptional(false).
    SetType(premadeThriftType_i32),
            metadata.NewThriftField().
    SetId(2).
    SetName("IntTypedef_field").
    SetIsOptional(false).
    SetType(premadeThriftType_module_IntTypedef),
            metadata.NewThriftField().
    SetId(3).
    SetName("UintTypedef_field").
    SetIsOptional(false).
    SetType(premadeThriftType_module_UintTypedef),
        },
    ),
    metadata.NewThriftStruct().
    SetName("module.StructWithDoubleUnderscores").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("__field").
    SetIsOptional(false).
    SetType(premadeThriftType_i32),
        },
    ),
}

var exceptionMetadatas = []*metadata.ThriftException{
}

var enumMetadatas = []*metadata.ThriftEnum{
    metadata.NewThriftEnum().
    SetName("module.has_bitwise_ops").
    SetElements(
        map[int32]string{
            0: "none",
            1: "zero",
            2: "one",
            4: "two",
            8: "three",
        },
    ),
    metadata.NewThriftEnum().
    SetName("module.is_unscoped").
    SetElements(
        map[int32]string{
            0: "hello",
            1: "world",
        },
    ),
    metadata.NewThriftEnum().
    SetName("module.MyForwardRefEnum").
    SetElements(
        map[int32]string{
            0: "ZERO",
            12: "NONZERO",
        },
    ),
}

var serviceMetadatas = []*metadata.ThriftService{
    metadata.NewThriftService().
    SetName("module.SomeService").
    SetFunctions(
        []*metadata.ThriftFunction{
            metadata.NewThriftFunction().
    SetName("bounce_map").
    SetIsOneway(false).
    SetReturnType(premadeThriftType_included_SomeMap).
    SetArguments(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("m").
    SetIsOptional(false).
    SetType(premadeThriftType_included_SomeMap),
        },
    ),
            metadata.NewThriftFunction().
    SetName("binary_keyed_map").
    SetIsOneway(false).
    SetReturnType(premadeThriftType_map_module_TBinary_i64).
    SetArguments(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("r").
    SetIsOptional(false).
    SetType(premadeThriftType_list_i64),
        },
    ),
        },
    ),
}

// GetThriftMetadata returns complete Thrift metadata for current and imported packages.
func GetThriftMetadata() *metadata.ThriftMetadata {
    allEnums := GetEnumsMetadata()
    allStructs := GetStructsMetadata()
    allExceptions := GetExceptionsMetadata()
    allServices := GetServicesMetadata()

    return metadata.NewThriftMetadata().
        SetEnums(allEnums).
        SetStructs(allStructs).
        SetExceptions(allExceptions).
        SetServices(allServices)
}

// GetEnumsMetadata returns Thrift metadata for enums in the current and recursively included packages.
func GetEnumsMetadata() map[string]*metadata.ThriftEnum {
    allEnumsMap := make(map[string]*metadata.ThriftEnum)

    // Add enum metadatas from the current program...
    for _, enumMetadata := range enumMetadatas {
        allEnumsMap[enumMetadata.GetName()] = enumMetadata
    }

    // ...now add enum metadatas from recursively included programs.
    mapsCopy(allEnumsMap, included.GetEnumsMetadata())

    return allEnumsMap
}

// GetStructsMetadata returns Thrift metadata for structs in the current and recursively included packages.
func GetStructsMetadata() map[string]*metadata.ThriftStruct {
    allStructsMap := make(map[string]*metadata.ThriftStruct)

    // Add struct metadatas from the current program...
    for _, structMetadata := range structMetadatas {
        allStructsMap[structMetadata.GetName()] = structMetadata
    }

    // ...now add struct metadatas from recursively included programs.
    mapsCopy(allStructsMap, included.GetStructsMetadata())

    return allStructsMap
}

// GetExceptionsMetadata returns Thrift metadata for exceptions in the current and recursively included packages.
func GetExceptionsMetadata() map[string]*metadata.ThriftException {
    allExceptionsMap := make(map[string]*metadata.ThriftException)

    // Add exception metadatas from the current program...
    for _, exceptionMetadata := range exceptionMetadatas {
        allExceptionsMap[exceptionMetadata.GetName()] = exceptionMetadata
    }

    // ...now add exception metadatas from recursively included programs.
    mapsCopy(allExceptionsMap, included.GetExceptionsMetadata())

    return allExceptionsMap
}

// GetServicesMetadata returns Thrift metadata for services in the current and recursively included packages.
func GetServicesMetadata() map[string]*metadata.ThriftService {
    allServicesMap := make(map[string]*metadata.ThriftService)

    // Add service metadatas from the current program...
    for _, serviceMetadata := range serviceMetadatas {
        allServicesMap[serviceMetadata.GetName()] = serviceMetadata
    }

    // ...now add service metadatas from recursively included programs.
    mapsCopy(allServicesMap, included.GetServicesMetadata())

    return allServicesMap
}

// GetThriftMetadataForService returns Thrift metadata for the given service.
func GetThriftMetadataForService(scopedServiceName string) *metadata.ThriftMetadata {
    thriftMetadata := GetThriftMetadata()

    allServicesMap := thriftMetadata.GetServices()
    relevantServicesMap := make(map[string]*metadata.ThriftService)

    serviceMetadata := allServicesMap[scopedServiceName]
    // Visit and record all recursive parents of the target service.
    for serviceMetadata != nil {
        relevantServicesMap[serviceMetadata.GetName()] = serviceMetadata
        if serviceMetadata.IsSetParent() {
            serviceMetadata = allServicesMap[serviceMetadata.GetParent()]
        } else {
            serviceMetadata = nil
        }
    }

    thriftMetadata.SetServices(relevantServicesMap)

    return thriftMetadata
}
