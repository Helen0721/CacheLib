/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package com.facebook.thrift.annotation.python_deprecated;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;
import com.facebook.thrift.*;
import com.facebook.thrift.annotations.*;
import com.facebook.thrift.async.*;
import com.facebook.thrift.meta_data.*;
import com.facebook.thrift.server.*;
import com.facebook.thrift.transport.*;
import com.facebook.thrift.protocol.*;

/**
 * Controls cpp <-> python FFI for a struct or union
 * By default, struct uses marshal C API unless cpp.Type or cpp.Adapter is present
 * on a field or a type
 * Use this annotation to opt-in struct to marshal in spite of cpp.Type or cpp.Adapter
 * Alternatively, use this struct with serialize = false to use serialization for FFI.
 */
@SuppressWarnings({ "unused", "serial" })
public class UseCAPI implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("UseCAPI");
  private static final TField SERIALIZE_FIELD_DESC = new TField("serialize", TType.BOOL, (short)1);

  public final Boolean serialize;
  public static final int SERIALIZE = 1;

  public UseCAPI(
      Boolean serialize) {
    this.serialize = serialize;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public UseCAPI(UseCAPI other) {
    if (other.isSetSerialize()) {
      this.serialize = TBaseHelper.deepCopy(other.serialize);
    } else {
      this.serialize = null;
    }
  }

  public UseCAPI deepCopy() {
    return new UseCAPI(this);
  }

  public Boolean isSerialize() {
    return this.serialize;
  }

  // Returns true if field serialize is set (has been assigned a value) and false otherwise
  public boolean isSetSerialize() {
    return this.serialize != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof UseCAPI))
      return false;
    UseCAPI that = (UseCAPI)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetSerialize(), that.isSetSerialize(), this.serialize, that.serialize)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {serialize});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static UseCAPI deserialize(TProtocol iprot) throws TException {
    Boolean tmp_serialize = null;
    TField __field;
    iprot.readStructBegin();
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        case SERIALIZE:
          if (__field.type == TType.BOOL) {
            tmp_serialize = iprot.readBool();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(iprot, __field.type);
          break;
      }
      iprot.readFieldEnd();
    }
    iprot.readStructEnd();

    UseCAPI _that;
    _that = new UseCAPI(
      tmp_serialize
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.serialize != null) {
      oprot.writeFieldBegin(SERIALIZE_FIELD_DESC);
      oprot.writeBool(this.serialize);
      oprot.writeFieldEnd();
    }
    oprot.writeFieldStop();
    oprot.writeStructEnd();
  }

  @Override
  public String toString() {
    return toString(1, true);
  }

  @Override
  public String toString(int indent, boolean prettyPrint) {
    return TBaseHelper.toStringHelper(this, indent, prettyPrint);
  }

  public void validate() throws TException {
    // check for required fields
  }

}

