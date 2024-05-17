/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package test.fixtures.adapter;

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

@SuppressWarnings({ "unused", "serial" })
public class StructWithFieldAdapter implements TBase, java.io.Serializable, Cloneable, Comparable<StructWithFieldAdapter> {
  private static final TStruct STRUCT_DESC = new TStruct("StructWithFieldAdapter");
  private static final TField FIELD_FIELD_DESC = new TField("field", TType.I32, (short)1);
  private static final TField SHARED_FIELD_FIELD_DESC = new TField("shared_field", TType.I32, (short)2);
  private static final TField OPT_SHARED_FIELD_FIELD_DESC = new TField("opt_shared_field", TType.I32, (short)3);
  private static final TField OPT_BOXED_FIELD_FIELD_DESC = new TField("opt_boxed_field", TType.I32, (short)4);

  public int field;
  public int shared_field;
  public int opt_shared_field;
  public int opt_boxed_field;
  public static final int FIELD = 1;
  public static final int SHARED_FIELD = 2;
  public static final int OPT_SHARED_FIELD = 3;
  public static final int OPT_BOXED_FIELD = 4;

  // isset id assignments
  private static final int __FIELD_ISSET_ID = 0;
  private static final int __SHARED_FIELD_ISSET_ID = 1;
  private static final int __OPT_SHARED_FIELD_ISSET_ID = 2;
  private static final int __OPT_BOXED_FIELD_ISSET_ID = 3;
  private BitSet __isset_bit_vector = new BitSet(4);

  public static final Map<Integer, FieldMetaData> metaDataMap;

  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(FIELD, new FieldMetaData("field", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.I32)));
    tmpMetaDataMap.put(SHARED_FIELD, new FieldMetaData("shared_field", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.I32)));
    tmpMetaDataMap.put(OPT_SHARED_FIELD, new FieldMetaData("opt_shared_field", TFieldRequirementType.OPTIONAL, 
        new FieldValueMetaData(TType.I32)));
    tmpMetaDataMap.put(OPT_BOXED_FIELD, new FieldMetaData("opt_boxed_field", TFieldRequirementType.OPTIONAL, 
        new FieldValueMetaData(TType.I32)));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  static {
    FieldMetaData.addStructMetaDataMap(StructWithFieldAdapter.class, metaDataMap);
  }

  public StructWithFieldAdapter() {
  }

  public StructWithFieldAdapter(
      int field,
      int shared_field) {
    this();
    this.field = field;
    setFieldIsSet(true);
    this.shared_field = shared_field;
    setShared_fieldIsSet(true);
  }

  public StructWithFieldAdapter(
      int field,
      int shared_field,
      int opt_shared_field,
      int opt_boxed_field) {
    this();
    this.field = field;
    setFieldIsSet(true);
    this.shared_field = shared_field;
    setShared_fieldIsSet(true);
    this.opt_shared_field = opt_shared_field;
    setOpt_shared_fieldIsSet(true);
    this.opt_boxed_field = opt_boxed_field;
    setOpt_boxed_fieldIsSet(true);
  }

  public static class Builder {
    private int field;
    private int shared_field;
    private int opt_shared_field;
    private int opt_boxed_field;

    BitSet __optional_isset = new BitSet(4);

    public Builder() {
    }

    public Builder setField(final int field) {
      this.field = field;
      __optional_isset.set(__FIELD_ISSET_ID, true);
      return this;
    }

    public Builder setShared_field(final int shared_field) {
      this.shared_field = shared_field;
      __optional_isset.set(__SHARED_FIELD_ISSET_ID, true);
      return this;
    }

    public Builder setOpt_shared_field(final int opt_shared_field) {
      this.opt_shared_field = opt_shared_field;
      __optional_isset.set(__OPT_SHARED_FIELD_ISSET_ID, true);
      return this;
    }

    public Builder setOpt_boxed_field(final int opt_boxed_field) {
      this.opt_boxed_field = opt_boxed_field;
      __optional_isset.set(__OPT_BOXED_FIELD_ISSET_ID, true);
      return this;
    }

    public StructWithFieldAdapter build() {
      StructWithFieldAdapter result = new StructWithFieldAdapter();
      if (__optional_isset.get(__FIELD_ISSET_ID)) {
        result.setField(this.field);
      }
      if (__optional_isset.get(__SHARED_FIELD_ISSET_ID)) {
        result.setShared_field(this.shared_field);
      }
      if (__optional_isset.get(__OPT_SHARED_FIELD_ISSET_ID)) {
        result.setOpt_shared_field(this.opt_shared_field);
      }
      if (__optional_isset.get(__OPT_BOXED_FIELD_ISSET_ID)) {
        result.setOpt_boxed_field(this.opt_boxed_field);
      }
      return result;
    }
  }

  public static Builder builder() {
    return new Builder();
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public StructWithFieldAdapter(StructWithFieldAdapter other) {
    __isset_bit_vector.clear();
    __isset_bit_vector.or(other.__isset_bit_vector);
    this.field = TBaseHelper.deepCopy(other.field);
    this.shared_field = TBaseHelper.deepCopy(other.shared_field);
    this.opt_shared_field = TBaseHelper.deepCopy(other.opt_shared_field);
    this.opt_boxed_field = TBaseHelper.deepCopy(other.opt_boxed_field);
  }

  public StructWithFieldAdapter deepCopy() {
    return new StructWithFieldAdapter(this);
  }

  public int getField() {
    return this.field;
  }

  public StructWithFieldAdapter setField(int field) {
    this.field = field;
    setFieldIsSet(true);
    return this;
  }

  public void unsetField() {
    __isset_bit_vector.clear(__FIELD_ISSET_ID);
  }

  // Returns true if field field is set (has been assigned a value) and false otherwise
  public boolean isSetField() {
    return __isset_bit_vector.get(__FIELD_ISSET_ID);
  }

  public void setFieldIsSet(boolean __value) {
    __isset_bit_vector.set(__FIELD_ISSET_ID, __value);
  }

  public int getShared_field() {
    return this.shared_field;
  }

  public StructWithFieldAdapter setShared_field(int shared_field) {
    this.shared_field = shared_field;
    setShared_fieldIsSet(true);
    return this;
  }

  public void unsetShared_field() {
    __isset_bit_vector.clear(__SHARED_FIELD_ISSET_ID);
  }

  // Returns true if field shared_field is set (has been assigned a value) and false otherwise
  public boolean isSetShared_field() {
    return __isset_bit_vector.get(__SHARED_FIELD_ISSET_ID);
  }

  public void setShared_fieldIsSet(boolean __value) {
    __isset_bit_vector.set(__SHARED_FIELD_ISSET_ID, __value);
  }

  public int getOpt_shared_field() {
    return this.opt_shared_field;
  }

  public StructWithFieldAdapter setOpt_shared_field(int opt_shared_field) {
    this.opt_shared_field = opt_shared_field;
    setOpt_shared_fieldIsSet(true);
    return this;
  }

  public void unsetOpt_shared_field() {
    __isset_bit_vector.clear(__OPT_SHARED_FIELD_ISSET_ID);
  }

  // Returns true if field opt_shared_field is set (has been assigned a value) and false otherwise
  public boolean isSetOpt_shared_field() {
    return __isset_bit_vector.get(__OPT_SHARED_FIELD_ISSET_ID);
  }

  public void setOpt_shared_fieldIsSet(boolean __value) {
    __isset_bit_vector.set(__OPT_SHARED_FIELD_ISSET_ID, __value);
  }

  public int getOpt_boxed_field() {
    return this.opt_boxed_field;
  }

  public StructWithFieldAdapter setOpt_boxed_field(int opt_boxed_field) {
    this.opt_boxed_field = opt_boxed_field;
    setOpt_boxed_fieldIsSet(true);
    return this;
  }

  public void unsetOpt_boxed_field() {
    __isset_bit_vector.clear(__OPT_BOXED_FIELD_ISSET_ID);
  }

  // Returns true if field opt_boxed_field is set (has been assigned a value) and false otherwise
  public boolean isSetOpt_boxed_field() {
    return __isset_bit_vector.get(__OPT_BOXED_FIELD_ISSET_ID);
  }

  public void setOpt_boxed_fieldIsSet(boolean __value) {
    __isset_bit_vector.set(__OPT_BOXED_FIELD_ISSET_ID, __value);
  }

  public void setFieldValue(int fieldID, Object __value) {
    switch (fieldID) {
    case FIELD:
      if (__value == null) {
        unsetField();
      } else {
        setField((Integer)__value);
      }
      break;

    case SHARED_FIELD:
      if (__value == null) {
        unsetShared_field();
      } else {
        setShared_field((Integer)__value);
      }
      break;

    case OPT_SHARED_FIELD:
      if (__value == null) {
        unsetOpt_shared_field();
      } else {
        setOpt_shared_field((Integer)__value);
      }
      break;

    case OPT_BOXED_FIELD:
      if (__value == null) {
        unsetOpt_boxed_field();
      } else {
        setOpt_boxed_field((Integer)__value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case FIELD:
      return new Integer(getField());

    case SHARED_FIELD:
      return new Integer(getShared_field());

    case OPT_SHARED_FIELD:
      return new Integer(getOpt_shared_field());

    case OPT_BOXED_FIELD:
      return new Integer(getOpt_boxed_field());

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof StructWithFieldAdapter))
      return false;
    StructWithFieldAdapter that = (StructWithFieldAdapter)_that;

    if (!TBaseHelper.equalsNobinary(this.field, that.field)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.shared_field, that.shared_field)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOpt_shared_field(), that.isSetOpt_shared_field(), this.opt_shared_field, that.opt_shared_field)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOpt_boxed_field(), that.isSetOpt_boxed_field(), this.opt_boxed_field, that.opt_boxed_field)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {field, shared_field, opt_shared_field, opt_boxed_field});
  }

  @Override
  public int compareTo(StructWithFieldAdapter other) {
    if (other == null) {
      // See java.lang.Comparable docs
      throw new NullPointerException();
    }

    if (other == this) {
      return 0;
    }
    int lastComparison = 0;

    lastComparison = Boolean.valueOf(isSetField()).compareTo(other.isSetField());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(field, other.field);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetShared_field()).compareTo(other.isSetShared_field());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(shared_field, other.shared_field);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetOpt_shared_field()).compareTo(other.isSetOpt_shared_field());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(opt_shared_field, other.opt_shared_field);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetOpt_boxed_field()).compareTo(other.isSetOpt_boxed_field());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(opt_boxed_field, other.opt_boxed_field);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    return 0;
  }

  public void read(TProtocol iprot) throws TException {
    TField __field;
    iprot.readStructBegin(metaDataMap);
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        case FIELD:
          if (__field.type == TType.I32) {
            this.field = iprot.readI32();
            setFieldIsSet(true);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case SHARED_FIELD:
          if (__field.type == TType.I32) {
            this.shared_field = iprot.readI32();
            setShared_fieldIsSet(true);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPT_SHARED_FIELD:
          if (__field.type == TType.I32) {
            this.opt_shared_field = iprot.readI32();
            setOpt_shared_fieldIsSet(true);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPT_BOXED_FIELD:
          if (__field.type == TType.I32) {
            this.opt_boxed_field = iprot.readI32();
            setOpt_boxed_fieldIsSet(true);
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


    // check for required fields of primitive type, which can't be checked in the validate method
    validate();
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    oprot.writeFieldBegin(FIELD_FIELD_DESC);
    oprot.writeI32(this.field);
    oprot.writeFieldEnd();
    oprot.writeFieldBegin(SHARED_FIELD_FIELD_DESC);
    oprot.writeI32(this.shared_field);
    oprot.writeFieldEnd();
    if (isSetOpt_shared_field()) {
      oprot.writeFieldBegin(OPT_SHARED_FIELD_FIELD_DESC);
      oprot.writeI32(this.opt_shared_field);
      oprot.writeFieldEnd();
    }
    if (isSetOpt_boxed_field()) {
      oprot.writeFieldBegin(OPT_BOXED_FIELD_FIELD_DESC);
      oprot.writeI32(this.opt_boxed_field);
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
    String indentStr = prettyPrint ? TBaseHelper.getIndentedString(indent) : "";
    String newLine = prettyPrint ? "\n" : "";
    String space = prettyPrint ? " " : "";
    StringBuilder sb = new StringBuilder("StructWithFieldAdapter");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    sb.append(indentStr);
    sb.append("field");
    sb.append(space);
    sb.append(":").append(space);
    sb.append(TBaseHelper.toString(this.getField(), indent + 1, prettyPrint));
    first = false;
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("shared_field");
    sb.append(space);
    sb.append(":").append(space);
    sb.append(TBaseHelper.toString(this.getShared_field(), indent + 1, prettyPrint));
    first = false;
    if (isSetOpt_shared_field())
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("opt_shared_field");
      sb.append(space);
      sb.append(":").append(space);
      sb.append(TBaseHelper.toString(this.getOpt_shared_field(), indent + 1, prettyPrint));
      first = false;
    }
    if (isSetOpt_boxed_field())
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("opt_boxed_field");
      sb.append(space);
      sb.append(":").append(space);
      sb.append(TBaseHelper.toString(this.getOpt_boxed_field(), indent + 1, prettyPrint));
      first = false;
    }
    sb.append(newLine + TBaseHelper.reduceIndent(indentStr));
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws TException {
    // check for required fields
  }

}

