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
public class Bar implements TBase, java.io.Serializable, Cloneable, Comparable<Bar> {
  private static final TStruct STRUCT_DESC = new TStruct("Bar");
  private static final TField STRUCT_FIELD_FIELD_DESC = new TField("structField", TType.STRUCT, (short)1);
  private static final TField OPTIONAL_STRUCT_FIELD_FIELD_DESC = new TField("optionalStructField", TType.STRUCT, (short)2);
  private static final TField STRUCT_LIST_FIELD_FIELD_DESC = new TField("structListField", TType.LIST, (short)3);
  private static final TField OPTIONAL_STRUCT_LIST_FIELD_FIELD_DESC = new TField("optionalStructListField", TType.LIST, (short)4);
  private static final TField UNION_FIELD_FIELD_DESC = new TField("unionField", TType.STRUCT, (short)5);
  private static final TField OPTIONAL_UNION_FIELD_FIELD_DESC = new TField("optionalUnionField", TType.STRUCT, (short)6);
  private static final TField ADAPTED_STRUCT_FIELD_FIELD_DESC = new TField("adaptedStructField", TType.STRUCT, (short)7);

  public Foo structField;
  public Foo optionalStructField;
  public List<Foo> structListField;
  public List<Foo> optionalStructListField;
  public Baz unionField;
  public Baz optionalUnionField;
  public DirectlyAdapted adaptedStructField;
  public static final int STRUCTFIELD = 1;
  public static final int OPTIONALSTRUCTFIELD = 2;
  public static final int STRUCTLISTFIELD = 3;
  public static final int OPTIONALSTRUCTLISTFIELD = 4;
  public static final int UNIONFIELD = 5;
  public static final int OPTIONALUNIONFIELD = 6;
  public static final int ADAPTEDSTRUCTFIELD = 7;

  // isset id assignments

  public static final Map<Integer, FieldMetaData> metaDataMap;

  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(STRUCTFIELD, new FieldMetaData("structField", TFieldRequirementType.DEFAULT, 
        new StructMetaData(TType.STRUCT, Foo.class)));
    tmpMetaDataMap.put(OPTIONALSTRUCTFIELD, new FieldMetaData("optionalStructField", TFieldRequirementType.OPTIONAL, 
        new StructMetaData(TType.STRUCT, Foo.class)));
    tmpMetaDataMap.put(STRUCTLISTFIELD, new FieldMetaData("structListField", TFieldRequirementType.DEFAULT, 
        new ListMetaData(TType.LIST, 
            new StructMetaData(TType.STRUCT, Foo.class))));
    tmpMetaDataMap.put(OPTIONALSTRUCTLISTFIELD, new FieldMetaData("optionalStructListField", TFieldRequirementType.OPTIONAL, 
        new ListMetaData(TType.LIST, 
            new StructMetaData(TType.STRUCT, Foo.class))));
    tmpMetaDataMap.put(UNIONFIELD, new FieldMetaData("unionField", TFieldRequirementType.DEFAULT, 
        new StructMetaData(TType.STRUCT, Baz.class)));
    tmpMetaDataMap.put(OPTIONALUNIONFIELD, new FieldMetaData("optionalUnionField", TFieldRequirementType.OPTIONAL, 
        new StructMetaData(TType.STRUCT, Baz.class)));
    tmpMetaDataMap.put(ADAPTEDSTRUCTFIELD, new FieldMetaData("adaptedStructField", TFieldRequirementType.DEFAULT, 
        new StructMetaData(TType.STRUCT, DirectlyAdapted.class)));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  static {
    FieldMetaData.addStructMetaDataMap(Bar.class, metaDataMap);
  }

  public Bar() {
  }

  public Bar(
      Foo structField,
      List<Foo> structListField,
      Baz unionField,
      DirectlyAdapted adaptedStructField) {
    this();
    this.structField = structField;
    this.structListField = structListField;
    this.unionField = unionField;
    this.adaptedStructField = adaptedStructField;
  }

  public Bar(
      Foo structField,
      Foo optionalStructField,
      List<Foo> structListField,
      List<Foo> optionalStructListField,
      Baz unionField,
      Baz optionalUnionField,
      DirectlyAdapted adaptedStructField) {
    this();
    this.structField = structField;
    this.optionalStructField = optionalStructField;
    this.structListField = structListField;
    this.optionalStructListField = optionalStructListField;
    this.unionField = unionField;
    this.optionalUnionField = optionalUnionField;
    this.adaptedStructField = adaptedStructField;
  }

  public static class Builder {
    private Foo structField;
    private Foo optionalStructField;
    private List<Foo> structListField;
    private List<Foo> optionalStructListField;
    private Baz unionField;
    private Baz optionalUnionField;
    private DirectlyAdapted adaptedStructField;

    public Builder() {
    }

    public Builder setStructField(final Foo structField) {
      this.structField = structField;
      return this;
    }

    public Builder setOptionalStructField(final Foo optionalStructField) {
      this.optionalStructField = optionalStructField;
      return this;
    }

    public Builder setStructListField(final List<Foo> structListField) {
      this.structListField = structListField;
      return this;
    }

    public Builder setOptionalStructListField(final List<Foo> optionalStructListField) {
      this.optionalStructListField = optionalStructListField;
      return this;
    }

    public Builder setUnionField(final Baz unionField) {
      this.unionField = unionField;
      return this;
    }

    public Builder setOptionalUnionField(final Baz optionalUnionField) {
      this.optionalUnionField = optionalUnionField;
      return this;
    }

    public Builder setAdaptedStructField(final DirectlyAdapted adaptedStructField) {
      this.adaptedStructField = adaptedStructField;
      return this;
    }

    public Bar build() {
      Bar result = new Bar();
      result.setStructField(this.structField);
      result.setOptionalStructField(this.optionalStructField);
      result.setStructListField(this.structListField);
      result.setOptionalStructListField(this.optionalStructListField);
      result.setUnionField(this.unionField);
      result.setOptionalUnionField(this.optionalUnionField);
      result.setAdaptedStructField(this.adaptedStructField);
      return result;
    }
  }

  public static Builder builder() {
    return new Builder();
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public Bar(Bar other) {
    if (other.isSetStructField()) {
      this.structField = TBaseHelper.deepCopy(other.structField);
    }
    if (other.isSetOptionalStructField()) {
      this.optionalStructField = TBaseHelper.deepCopy(other.optionalStructField);
    }
    if (other.isSetStructListField()) {
      this.structListField = TBaseHelper.deepCopy(other.structListField);
    }
    if (other.isSetOptionalStructListField()) {
      this.optionalStructListField = TBaseHelper.deepCopy(other.optionalStructListField);
    }
    if (other.isSetUnionField()) {
      this.unionField = TBaseHelper.deepCopy(other.unionField);
    }
    if (other.isSetOptionalUnionField()) {
      this.optionalUnionField = TBaseHelper.deepCopy(other.optionalUnionField);
    }
    if (other.isSetAdaptedStructField()) {
      this.adaptedStructField = TBaseHelper.deepCopy(other.adaptedStructField);
    }
  }

  public Bar deepCopy() {
    return new Bar(this);
  }

  public Foo getStructField() {
    return this.structField;
  }

  public Bar setStructField(Foo structField) {
    this.structField = structField;
    return this;
  }

  public void unsetStructField() {
    this.structField = null;
  }

  // Returns true if field structField is set (has been assigned a value) and false otherwise
  public boolean isSetStructField() {
    return this.structField != null;
  }

  public void setStructFieldIsSet(boolean __value) {
    if (!__value) {
      this.structField = null;
    }
  }

  public Foo getOptionalStructField() {
    return this.optionalStructField;
  }

  public Bar setOptionalStructField(Foo optionalStructField) {
    this.optionalStructField = optionalStructField;
    return this;
  }

  public void unsetOptionalStructField() {
    this.optionalStructField = null;
  }

  // Returns true if field optionalStructField is set (has been assigned a value) and false otherwise
  public boolean isSetOptionalStructField() {
    return this.optionalStructField != null;
  }

  public void setOptionalStructFieldIsSet(boolean __value) {
    if (!__value) {
      this.optionalStructField = null;
    }
  }

  public List<Foo> getStructListField() {
    return this.structListField;
  }

  public Bar setStructListField(List<Foo> structListField) {
    this.structListField = structListField;
    return this;
  }

  public void unsetStructListField() {
    this.structListField = null;
  }

  // Returns true if field structListField is set (has been assigned a value) and false otherwise
  public boolean isSetStructListField() {
    return this.structListField != null;
  }

  public void setStructListFieldIsSet(boolean __value) {
    if (!__value) {
      this.structListField = null;
    }
  }

  public List<Foo> getOptionalStructListField() {
    return this.optionalStructListField;
  }

  public Bar setOptionalStructListField(List<Foo> optionalStructListField) {
    this.optionalStructListField = optionalStructListField;
    return this;
  }

  public void unsetOptionalStructListField() {
    this.optionalStructListField = null;
  }

  // Returns true if field optionalStructListField is set (has been assigned a value) and false otherwise
  public boolean isSetOptionalStructListField() {
    return this.optionalStructListField != null;
  }

  public void setOptionalStructListFieldIsSet(boolean __value) {
    if (!__value) {
      this.optionalStructListField = null;
    }
  }

  public Baz getUnionField() {
    return this.unionField;
  }

  public Bar setUnionField(Baz unionField) {
    this.unionField = unionField;
    return this;
  }

  public void unsetUnionField() {
    this.unionField = null;
  }

  // Returns true if field unionField is set (has been assigned a value) and false otherwise
  public boolean isSetUnionField() {
    return this.unionField != null;
  }

  public void setUnionFieldIsSet(boolean __value) {
    if (!__value) {
      this.unionField = null;
    }
  }

  public Baz getOptionalUnionField() {
    return this.optionalUnionField;
  }

  public Bar setOptionalUnionField(Baz optionalUnionField) {
    this.optionalUnionField = optionalUnionField;
    return this;
  }

  public void unsetOptionalUnionField() {
    this.optionalUnionField = null;
  }

  // Returns true if field optionalUnionField is set (has been assigned a value) and false otherwise
  public boolean isSetOptionalUnionField() {
    return this.optionalUnionField != null;
  }

  public void setOptionalUnionFieldIsSet(boolean __value) {
    if (!__value) {
      this.optionalUnionField = null;
    }
  }

  public DirectlyAdapted getAdaptedStructField() {
    return this.adaptedStructField;
  }

  public Bar setAdaptedStructField(DirectlyAdapted adaptedStructField) {
    this.adaptedStructField = adaptedStructField;
    return this;
  }

  public void unsetAdaptedStructField() {
    this.adaptedStructField = null;
  }

  // Returns true if field adaptedStructField is set (has been assigned a value) and false otherwise
  public boolean isSetAdaptedStructField() {
    return this.adaptedStructField != null;
  }

  public void setAdaptedStructFieldIsSet(boolean __value) {
    if (!__value) {
      this.adaptedStructField = null;
    }
  }

  @SuppressWarnings("unchecked")
  public void setFieldValue(int fieldID, Object __value) {
    switch (fieldID) {
    case STRUCTFIELD:
      if (__value == null) {
        unsetStructField();
      } else {
        setStructField((Foo)__value);
      }
      break;

    case OPTIONALSTRUCTFIELD:
      if (__value == null) {
        unsetOptionalStructField();
      } else {
        setOptionalStructField((Foo)__value);
      }
      break;

    case STRUCTLISTFIELD:
      if (__value == null) {
        unsetStructListField();
      } else {
        setStructListField((List<Foo>)__value);
      }
      break;

    case OPTIONALSTRUCTLISTFIELD:
      if (__value == null) {
        unsetOptionalStructListField();
      } else {
        setOptionalStructListField((List<Foo>)__value);
      }
      break;

    case UNIONFIELD:
      if (__value == null) {
        unsetUnionField();
      } else {
        setUnionField((Baz)__value);
      }
      break;

    case OPTIONALUNIONFIELD:
      if (__value == null) {
        unsetOptionalUnionField();
      } else {
        setOptionalUnionField((Baz)__value);
      }
      break;

    case ADAPTEDSTRUCTFIELD:
      if (__value == null) {
        unsetAdaptedStructField();
      } else {
        setAdaptedStructField((DirectlyAdapted)__value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case STRUCTFIELD:
      return getStructField();

    case OPTIONALSTRUCTFIELD:
      return getOptionalStructField();

    case STRUCTLISTFIELD:
      return getStructListField();

    case OPTIONALSTRUCTLISTFIELD:
      return getOptionalStructListField();

    case UNIONFIELD:
      return getUnionField();

    case OPTIONALUNIONFIELD:
      return getOptionalUnionField();

    case ADAPTEDSTRUCTFIELD:
      return getAdaptedStructField();

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
    if (!(_that instanceof Bar))
      return false;
    Bar that = (Bar)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetStructField(), that.isSetStructField(), this.structField, that.structField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOptionalStructField(), that.isSetOptionalStructField(), this.optionalStructField, that.optionalStructField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetStructListField(), that.isSetStructListField(), this.structListField, that.structListField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOptionalStructListField(), that.isSetOptionalStructListField(), this.optionalStructListField, that.optionalStructListField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetUnionField(), that.isSetUnionField(), this.unionField, that.unionField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetOptionalUnionField(), that.isSetOptionalUnionField(), this.optionalUnionField, that.optionalUnionField)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdaptedStructField(), that.isSetAdaptedStructField(), this.adaptedStructField, that.adaptedStructField)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {structField, optionalStructField, structListField, optionalStructListField, unionField, optionalUnionField, adaptedStructField});
  }

  @Override
  public int compareTo(Bar other) {
    if (other == null) {
      // See java.lang.Comparable docs
      throw new NullPointerException();
    }

    if (other == this) {
      return 0;
    }
    int lastComparison = 0;

    lastComparison = Boolean.valueOf(isSetStructField()).compareTo(other.isSetStructField());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(structField, other.structField);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetOptionalStructField()).compareTo(other.isSetOptionalStructField());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(optionalStructField, other.optionalStructField);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetStructListField()).compareTo(other.isSetStructListField());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(structListField, other.structListField);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetOptionalStructListField()).compareTo(other.isSetOptionalStructListField());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(optionalStructListField, other.optionalStructListField);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetUnionField()).compareTo(other.isSetUnionField());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(unionField, other.unionField);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetOptionalUnionField()).compareTo(other.isSetOptionalUnionField());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(optionalUnionField, other.optionalUnionField);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetAdaptedStructField()).compareTo(other.isSetAdaptedStructField());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(adaptedStructField, other.adaptedStructField);
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
        case STRUCTFIELD:
          if (__field.type == TType.STRUCT) {
            this.structField = new Foo();
            this.structField.read(iprot);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPTIONALSTRUCTFIELD:
          if (__field.type == TType.STRUCT) {
            this.optionalStructField = new Foo();
            this.optionalStructField.read(iprot);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case STRUCTLISTFIELD:
          if (__field.type == TType.LIST) {
            {
              TList _list42 = iprot.readListBegin();
              this.structListField = new ArrayList<Foo>(Math.max(0, _list42.size));
              for (int _i43 = 0; 
                   (_list42.size < 0) ? iprot.peekList() : (_i43 < _list42.size); 
                   ++_i43)
              {
                Foo _elem44;
                _elem44 = new Foo();
                _elem44.read(iprot);
                this.structListField.add(_elem44);
              }
              iprot.readListEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPTIONALSTRUCTLISTFIELD:
          if (__field.type == TType.LIST) {
            {
              TList _list45 = iprot.readListBegin();
              this.optionalStructListField = new ArrayList<Foo>(Math.max(0, _list45.size));
              for (int _i46 = 0; 
                   (_list45.size < 0) ? iprot.peekList() : (_i46 < _list45.size); 
                   ++_i46)
              {
                Foo _elem47;
                _elem47 = new Foo();
                _elem47.read(iprot);
                this.optionalStructListField.add(_elem47);
              }
              iprot.readListEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case UNIONFIELD:
          if (__field.type == TType.STRUCT) {
            this.unionField = new Baz();
            this.unionField.read(iprot);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case OPTIONALUNIONFIELD:
          if (__field.type == TType.STRUCT) {
            this.optionalUnionField = new Baz();
            this.optionalUnionField.read(iprot);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADAPTEDSTRUCTFIELD:
          if (__field.type == TType.STRUCT) {
            this.adaptedStructField = new DirectlyAdapted();
            this.adaptedStructField.read(iprot);
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
    if (this.structField != null) {
      oprot.writeFieldBegin(STRUCT_FIELD_FIELD_DESC);
      this.structField.write(oprot);
      oprot.writeFieldEnd();
    }
    if (this.optionalStructField != null) {
      if (isSetOptionalStructField()) {
        oprot.writeFieldBegin(OPTIONAL_STRUCT_FIELD_FIELD_DESC);
        this.optionalStructField.write(oprot);
        oprot.writeFieldEnd();
      }
    }
    if (this.structListField != null) {
      oprot.writeFieldBegin(STRUCT_LIST_FIELD_FIELD_DESC);
      {
        oprot.writeListBegin(new TList(TType.STRUCT, this.structListField.size()));
        for (Foo _iter48 : this.structListField)        {
          _iter48.write(oprot);
        }
        oprot.writeListEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.optionalStructListField != null) {
      if (isSetOptionalStructListField()) {
        oprot.writeFieldBegin(OPTIONAL_STRUCT_LIST_FIELD_FIELD_DESC);
        {
          oprot.writeListBegin(new TList(TType.STRUCT, this.optionalStructListField.size()));
          for (Foo _iter49 : this.optionalStructListField)          {
            _iter49.write(oprot);
          }
          oprot.writeListEnd();
        }
        oprot.writeFieldEnd();
      }
    }
    if (this.unionField != null) {
      oprot.writeFieldBegin(UNION_FIELD_FIELD_DESC);
      this.unionField.write(oprot);
      oprot.writeFieldEnd();
    }
    if (this.optionalUnionField != null) {
      if (isSetOptionalUnionField()) {
        oprot.writeFieldBegin(OPTIONAL_UNION_FIELD_FIELD_DESC);
        this.optionalUnionField.write(oprot);
        oprot.writeFieldEnd();
      }
    }
    if (this.adaptedStructField != null) {
      oprot.writeFieldBegin(ADAPTED_STRUCT_FIELD_FIELD_DESC);
      this.adaptedStructField.write(oprot);
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
    StringBuilder sb = new StringBuilder("Bar");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    sb.append(indentStr);
    sb.append("structField");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getStructField() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getStructField(), indent + 1, prettyPrint));
    }
    first = false;
    if (isSetOptionalStructField())
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("optionalStructField");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getOptionalStructField() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getOptionalStructField(), indent + 1, prettyPrint));
      }
      first = false;
    }
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("structListField");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getStructListField() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getStructListField(), indent + 1, prettyPrint));
    }
    first = false;
    if (isSetOptionalStructListField())
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("optionalStructListField");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getOptionalStructListField() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getOptionalStructListField(), indent + 1, prettyPrint));
      }
      first = false;
    }
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("unionField");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getUnionField() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getUnionField(), indent + 1, prettyPrint));
    }
    first = false;
    if (isSetOptionalUnionField())
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("optionalUnionField");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getOptionalUnionField() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getOptionalUnionField(), indent + 1, prettyPrint));
      }
      first = false;
    }
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("adaptedStructField");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getAdaptedStructField() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getAdaptedStructField(), indent + 1, prettyPrint));
    }
    first = false;
    sb.append(newLine + TBaseHelper.reduceIndent(indentStr));
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws TException {
    // check for required fields
  }

}

