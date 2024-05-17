/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
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
public class FieldsInjectedWithIncludedStruct implements TBase, java.io.Serializable, Cloneable, Comparable<FieldsInjectedWithIncludedStruct> {
  private static final TStruct STRUCT_DESC = new TStruct("FieldsInjectedWithIncludedStruct");
  private static final TField STRING_FIELD_FIELD_DESC = new TField("string_field", TType.STRING, (short)1);
  private static final TField INJECTED_FIELD_FIELD_DESC = new TField("injected_field", TType.STRING, (short)-1100);
  private static final TField INJECTED_STRUCTURED_ANNOTATION_FIELD_FIELD_DESC = new TField("injected_structured_annotation_field", TType.STRING, (short)-1101);
  private static final TField INJECTED_UNSTRUCTURED_ANNOTATION_FIELD_FIELD_DESC = new TField("injected_unstructured_annotation_field", TType.STRING, (short)-1102);

  public String string_field;
  public String injected_field;
  public String injected_structured_annotation_field;
  public String injected_unstructured_annotation_field;
  public static final int STRING_FIELD = 1;
  public static final int INJECTED_FIELD = -1100;
  public static final int INJECTED_STRUCTURED_ANNOTATION_FIELD = -1101;
  public static final int INJECTED_UNSTRUCTURED_ANNOTATION_FIELD = -1102;

  // isset id assignments

  public static final Map<Integer, FieldMetaData> metaDataMap;

  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(STRING_FIELD, new FieldMetaData("string_field", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    tmpMetaDataMap.put(INJECTED_FIELD, new FieldMetaData("injected_field", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    tmpMetaDataMap.put(INJECTED_STRUCTURED_ANNOTATION_FIELD, new FieldMetaData("injected_structured_annotation_field", TFieldRequirementType.OPTIONAL, 
        new FieldValueMetaData(TType.STRING)));
    tmpMetaDataMap.put(INJECTED_UNSTRUCTURED_ANNOTATION_FIELD, new FieldMetaData("injected_unstructured_annotation_field", TFieldRequirementType.OPTIONAL, 
        new FieldValueMetaData(TType.STRING)));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  static {
    FieldMetaData.addStructMetaDataMap(FieldsInjectedWithIncludedStruct.class, metaDataMap);
  }

  public FieldsInjectedWithIncludedStruct() {
  }

  public FieldsInjectedWithIncludedStruct(
      String string_field,
      String injected_field) {
    this();
    this.string_field = string_field;
    this.injected_field = injected_field;
  }

  public FieldsInjectedWithIncludedStruct(
      String string_field,
      String injected_field,
      String injected_structured_annotation_field,
      String injected_unstructured_annotation_field) {
    this();
    this.string_field = string_field;
    this.injected_field = injected_field;
    this.injected_structured_annotation_field = injected_structured_annotation_field;
    this.injected_unstructured_annotation_field = injected_unstructured_annotation_field;
  }

  public static class Builder {
    private String string_field;
    private String injected_field;
    private String injected_structured_annotation_field;
    private String injected_unstructured_annotation_field;

    public Builder() {
    }

    public Builder setString_field(final String string_field) {
      this.string_field = string_field;
      return this;
    }

    public Builder setInjected_field(final String injected_field) {
      this.injected_field = injected_field;
      return this;
    }

    public Builder setInjected_structured_annotation_field(final String injected_structured_annotation_field) {
      this.injected_structured_annotation_field = injected_structured_annotation_field;
      return this;
    }

    public Builder setInjected_unstructured_annotation_field(final String injected_unstructured_annotation_field) {
      this.injected_unstructured_annotation_field = injected_unstructured_annotation_field;
      return this;
    }

    public FieldsInjectedWithIncludedStruct build() {
      FieldsInjectedWithIncludedStruct result = new FieldsInjectedWithIncludedStruct();
      result.setString_field(this.string_field);
      result.setInjected_field(this.injected_field);
      result.setInjected_structured_annotation_field(this.injected_structured_annotation_field);
      result.setInjected_unstructured_annotation_field(this.injected_unstructured_annotation_field);
      return result;
    }
  }

  public static Builder builder() {
    return new Builder();
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public FieldsInjectedWithIncludedStruct(FieldsInjectedWithIncludedStruct other) {
    if (other.isSetString_field()) {
      this.string_field = TBaseHelper.deepCopy(other.string_field);
    }
    if (other.isSetInjected_field()) {
      this.injected_field = TBaseHelper.deepCopy(other.injected_field);
    }
    if (other.isSetInjected_structured_annotation_field()) {
      this.injected_structured_annotation_field = TBaseHelper.deepCopy(other.injected_structured_annotation_field);
    }
    if (other.isSetInjected_unstructured_annotation_field()) {
      this.injected_unstructured_annotation_field = TBaseHelper.deepCopy(other.injected_unstructured_annotation_field);
    }
  }

  public FieldsInjectedWithIncludedStruct deepCopy() {
    return new FieldsInjectedWithIncludedStruct(this);
  }

  public String getString_field() {
    return this.string_field;
  }

  public FieldsInjectedWithIncludedStruct setString_field(String string_field) {
    this.string_field = string_field;
    return this;
  }

  public void unsetString_field() {
    this.string_field = null;
  }

  // Returns true if field string_field is set (has been assigned a value) and false otherwise
  public boolean isSetString_field() {
    return this.string_field != null;
  }

  public void setString_fieldIsSet(boolean __value) {
    if (!__value) {
      this.string_field = null;
    }
  }

  public String getInjected_field() {
    return this.injected_field;
  }

  public FieldsInjectedWithIncludedStruct setInjected_field(String injected_field) {
    this.injected_field = injected_field;
    return this;
  }

  public void unsetInjected_field() {
    this.injected_field = null;
  }

  // Returns true if field injected_field is set (has been assigned a value) and false otherwise
  public boolean isSetInjected_field() {
    return this.injected_field != null;
  }

  public void setInjected_fieldIsSet(boolean __value) {
    if (!__value) {
      this.injected_field = null;
    }
  }

  public String getInjected_structured_annotation_field() {
    return this.injected_structured_annotation_field;
  }

  public FieldsInjectedWithIncludedStruct setInjected_structured_annotation_field(String injected_structured_annotation_field) {
    this.injected_structured_annotation_field = injected_structured_annotation_field;
    return this;
  }

  public void unsetInjected_structured_annotation_field() {
    this.injected_structured_annotation_field = null;
  }

  // Returns true if field injected_structured_annotation_field is set (has been assigned a value) and false otherwise
  public boolean isSetInjected_structured_annotation_field() {
    return this.injected_structured_annotation_field != null;
  }

  public void setInjected_structured_annotation_fieldIsSet(boolean __value) {
    if (!__value) {
      this.injected_structured_annotation_field = null;
    }
  }

  public String getInjected_unstructured_annotation_field() {
    return this.injected_unstructured_annotation_field;
  }

  public FieldsInjectedWithIncludedStruct setInjected_unstructured_annotation_field(String injected_unstructured_annotation_field) {
    this.injected_unstructured_annotation_field = injected_unstructured_annotation_field;
    return this;
  }

  public void unsetInjected_unstructured_annotation_field() {
    this.injected_unstructured_annotation_field = null;
  }

  // Returns true if field injected_unstructured_annotation_field is set (has been assigned a value) and false otherwise
  public boolean isSetInjected_unstructured_annotation_field() {
    return this.injected_unstructured_annotation_field != null;
  }

  public void setInjected_unstructured_annotation_fieldIsSet(boolean __value) {
    if (!__value) {
      this.injected_unstructured_annotation_field = null;
    }
  }

  public void setFieldValue(int fieldID, Object __value) {
    switch (fieldID) {
    case STRING_FIELD:
      if (__value == null) {
        unsetString_field();
      } else {
        setString_field((String)__value);
      }
      break;

    case INJECTED_FIELD:
      if (__value == null) {
        unsetInjected_field();
      } else {
        setInjected_field((String)__value);
      }
      break;

    case INJECTED_STRUCTURED_ANNOTATION_FIELD:
      if (__value == null) {
        unsetInjected_structured_annotation_field();
      } else {
        setInjected_structured_annotation_field((String)__value);
      }
      break;

    case INJECTED_UNSTRUCTURED_ANNOTATION_FIELD:
      if (__value == null) {
        unsetInjected_unstructured_annotation_field();
      } else {
        setInjected_unstructured_annotation_field((String)__value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case STRING_FIELD:
      return getString_field();

    case INJECTED_FIELD:
      return getInjected_field();

    case INJECTED_STRUCTURED_ANNOTATION_FIELD:
      return getInjected_structured_annotation_field();

    case INJECTED_UNSTRUCTURED_ANNOTATION_FIELD:
      return getInjected_unstructured_annotation_field();

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
    if (!(_that instanceof FieldsInjectedWithIncludedStruct))
      return false;
    FieldsInjectedWithIncludedStruct that = (FieldsInjectedWithIncludedStruct)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetString_field(), that.isSetString_field(), this.string_field, that.string_field)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetInjected_field(), that.isSetInjected_field(), this.injected_field, that.injected_field)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetInjected_structured_annotation_field(), that.isSetInjected_structured_annotation_field(), this.injected_structured_annotation_field, that.injected_structured_annotation_field)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetInjected_unstructured_annotation_field(), that.isSetInjected_unstructured_annotation_field(), this.injected_unstructured_annotation_field, that.injected_unstructured_annotation_field)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {string_field, injected_field, injected_structured_annotation_field, injected_unstructured_annotation_field});
  }

  @Override
  public int compareTo(FieldsInjectedWithIncludedStruct other) {
    if (other == null) {
      // See java.lang.Comparable docs
      throw new NullPointerException();
    }

    if (other == this) {
      return 0;
    }
    int lastComparison = 0;

    lastComparison = Boolean.valueOf(isSetString_field()).compareTo(other.isSetString_field());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(string_field, other.string_field);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetInjected_field()).compareTo(other.isSetInjected_field());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(injected_field, other.injected_field);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetInjected_structured_annotation_field()).compareTo(other.isSetInjected_structured_annotation_field());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(injected_structured_annotation_field, other.injected_structured_annotation_field);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetInjected_unstructured_annotation_field()).compareTo(other.isSetInjected_unstructured_annotation_field());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(injected_unstructured_annotation_field, other.injected_unstructured_annotation_field);
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
        case STRING_FIELD:
          if (__field.type == TType.STRING) {
            this.string_field = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case INJECTED_FIELD:
          if (__field.type == TType.STRING) {
            this.injected_field = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case INJECTED_STRUCTURED_ANNOTATION_FIELD:
          if (__field.type == TType.STRING) {
            this.injected_structured_annotation_field = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case INJECTED_UNSTRUCTURED_ANNOTATION_FIELD:
          if (__field.type == TType.STRING) {
            this.injected_unstructured_annotation_field = iprot.readString();
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
    if (this.injected_unstructured_annotation_field != null) {
      if (isSetInjected_unstructured_annotation_field()) {
        oprot.writeFieldBegin(INJECTED_UNSTRUCTURED_ANNOTATION_FIELD_FIELD_DESC);
        oprot.writeString(this.injected_unstructured_annotation_field);
        oprot.writeFieldEnd();
      }
    }
    if (this.injected_structured_annotation_field != null) {
      if (isSetInjected_structured_annotation_field()) {
        oprot.writeFieldBegin(INJECTED_STRUCTURED_ANNOTATION_FIELD_FIELD_DESC);
        oprot.writeString(this.injected_structured_annotation_field);
        oprot.writeFieldEnd();
      }
    }
    if (this.injected_field != null) {
      oprot.writeFieldBegin(INJECTED_FIELD_FIELD_DESC);
      oprot.writeString(this.injected_field);
      oprot.writeFieldEnd();
    }
    if (this.string_field != null) {
      oprot.writeFieldBegin(STRING_FIELD_FIELD_DESC);
      oprot.writeString(this.string_field);
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
    StringBuilder sb = new StringBuilder("FieldsInjectedWithIncludedStruct");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    sb.append(indentStr);
    sb.append("string_field");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getString_field() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getString_field(), indent + 1, prettyPrint));
    }
    first = false;
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("injected_field");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getInjected_field() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getInjected_field(), indent + 1, prettyPrint));
    }
    first = false;
    if (isSetInjected_structured_annotation_field())
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("injected_structured_annotation_field");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getInjected_structured_annotation_field() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getInjected_structured_annotation_field(), indent + 1, prettyPrint));
      }
      first = false;
    }
    if (isSetInjected_unstructured_annotation_field())
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("injected_unstructured_annotation_field");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getInjected_unstructured_annotation_field() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getInjected_unstructured_annotation_field(), indent + 1, prettyPrint));
      }
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

