/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package com.facebook.thrift.test.terse_write;

import com.facebook.thrift.type.TypeList;
import java.util.ArrayList;
import java.util.List;

public class __fbthrift_TypeList_5d5a805a implements TypeList {

  private static List<TypeMapping> list = new ArrayList<>();

  private static void add(String uri, String className) {
    list.add(new TypeList.TypeMapping(uri, className));
  }

  private static void addToList0() {
    add("facebook.com/thrift/test/terse_write/MyStruct", "com.facebook.thrift.test.terse_write.MyStruct");
    add("facebook.com/thrift/test/terse_write/MyUnion", "com.facebook.thrift.test.terse_write.MyUnion");
    add("facebook.com/thrift/test/terse_write/MyStructWithCustomDefault", "com.facebook.thrift.test.terse_write.MyStructWithCustomDefault");
    add("facebook.com/thrift/test/terse_write/StructLevelTerseStruct", "com.facebook.thrift.test.terse_write.StructLevelTerseStruct");
    add("facebook.com/thrift/test/terse_write/FieldLevelTerseStruct", "com.facebook.thrift.test.terse_write.FieldLevelTerseStruct");
    add("facebook.com/thrift/test/terse_write/TerseStructWithCustomDefault", "com.facebook.thrift.test.terse_write.TerseStructWithCustomDefault");
    add("facebook.com/thrift/test/terse_write/AdaptedFields", "com.facebook.thrift.test.terse_write.AdaptedFields");
    add("facebook.com/thrift/test/terse_write/WrappedFields", "com.facebook.thrift.test.terse_write.WrappedFields");
    add("facebook.com/thrift/test/terse_write/TerseException", "com.facebook.thrift.test.terse_write.TerseException");
    add("facebook.com/thrift/test/terse_write/MyEnum", "com.facebook.thrift.test.terse_write.MyEnum");
  }

  static {
    addToList0();
  }

  @java.lang.Override
  public List<TypeList.TypeMapping> getTypes() {
    return list;
  }
}
