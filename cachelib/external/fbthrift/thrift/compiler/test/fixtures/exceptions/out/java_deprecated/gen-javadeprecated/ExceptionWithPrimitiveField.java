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
public class ExceptionWithPrimitiveField extends Exception implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("ExceptionWithPrimitiveField");
  private static final TField MESSAGE_FIELD_DESC = new TField("message", TType.STRING, (short)1);
  private static final TField ERROR_CODE_FIELD_DESC = new TField("error_code", TType.I32, (short)2);

  public String message;
  public int error_code;
  public static final int MESSAGE = 1;
  public static final int ERROR_CODE = 2;

  // isset id assignments
  private static final int __ERROR_CODE_ISSET_ID = 0;
  private BitSet __isset_bit_vector = new BitSet(1);

  public static final Map<Integer, FieldMetaData> metaDataMap;

  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(MESSAGE, new FieldMetaData("message", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    tmpMetaDataMap.put(ERROR_CODE, new FieldMetaData("error_code", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.I32)));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  static {
    FieldMetaData.addStructMetaDataMap(ExceptionWithPrimitiveField.class, metaDataMap);
  }

  public ExceptionWithPrimitiveField() {
  }

  public ExceptionWithPrimitiveField(
      String message,
      int error_code) {
    this();
    this.message = message;
    this.error_code = error_code;
    setError_codeIsSet(true);
  }

  public static class Builder {
    private String message;
    private int error_code;

    BitSet __optional_isset = new BitSet(1);

    public Builder() {
    }

    public Builder setMessage(final String message) {
      this.message = message;
      return this;
    }

    public Builder setError_code(final int error_code) {
      this.error_code = error_code;
      __optional_isset.set(__ERROR_CODE_ISSET_ID, true);
      return this;
    }

    public ExceptionWithPrimitiveField build() {
      ExceptionWithPrimitiveField result = new ExceptionWithPrimitiveField();
      result.setMessage(this.message);
      if (__optional_isset.get(__ERROR_CODE_ISSET_ID)) {
        result.setError_code(this.error_code);
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
  public ExceptionWithPrimitiveField(ExceptionWithPrimitiveField other) {
    __isset_bit_vector.clear();
    __isset_bit_vector.or(other.__isset_bit_vector);
    if (other.isSetMessage()) {
      this.message = TBaseHelper.deepCopy(other.message);
    }
    this.error_code = TBaseHelper.deepCopy(other.error_code);
  }

  public ExceptionWithPrimitiveField deepCopy() {
    return new ExceptionWithPrimitiveField(this);
  }

  public String getMessage() {
    return this.message;
  }

  public ExceptionWithPrimitiveField setMessage(String message) {
    this.message = message;
    return this;
  }

  public void unsetMessage() {
    this.message = null;
  }

  // Returns true if field message is set (has been assigned a value) and false otherwise
  public boolean isSetMessage() {
    return this.message != null;
  }

  public void setMessageIsSet(boolean __value) {
    if (!__value) {
      this.message = null;
    }
  }

  public int getError_code() {
    return this.error_code;
  }

  public ExceptionWithPrimitiveField setError_code(int error_code) {
    this.error_code = error_code;
    setError_codeIsSet(true);
    return this;
  }

  public void unsetError_code() {
    __isset_bit_vector.clear(__ERROR_CODE_ISSET_ID);
  }

  // Returns true if field error_code is set (has been assigned a value) and false otherwise
  public boolean isSetError_code() {
    return __isset_bit_vector.get(__ERROR_CODE_ISSET_ID);
  }

  public void setError_codeIsSet(boolean __value) {
    __isset_bit_vector.set(__ERROR_CODE_ISSET_ID, __value);
  }

  public void setFieldValue(int fieldID, Object __value) {
    switch (fieldID) {
    case MESSAGE:
      if (__value == null) {
        unsetMessage();
      } else {
        setMessage((String)__value);
      }
      break;

    case ERROR_CODE:
      if (__value == null) {
        unsetError_code();
      } else {
        setError_code((Integer)__value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case MESSAGE:
      return getMessage();

    case ERROR_CODE:
      return new Integer(getError_code());

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
    if (!(_that instanceof ExceptionWithPrimitiveField))
      return false;
    ExceptionWithPrimitiveField that = (ExceptionWithPrimitiveField)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetMessage(), that.isSetMessage(), this.message, that.message)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.error_code, that.error_code)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {message, error_code});
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
        case MESSAGE:
          if (__field.type == TType.STRING) {
            this.message = iprot.readString();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ERROR_CODE:
          if (__field.type == TType.I32) {
            this.error_code = iprot.readI32();
            setError_codeIsSet(true);
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
    if (this.message != null) {
      oprot.writeFieldBegin(MESSAGE_FIELD_DESC);
      oprot.writeString(this.message);
      oprot.writeFieldEnd();
    }
    oprot.writeFieldBegin(ERROR_CODE_FIELD_DESC);
    oprot.writeI32(this.error_code);
    oprot.writeFieldEnd();
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
    StringBuilder sb = new StringBuilder("ExceptionWithPrimitiveField");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    sb.append(indentStr);
    sb.append("message");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getMessage() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getMessage(), indent + 1, prettyPrint));
    }
    first = false;
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("error_code");
    sb.append(space);
    sb.append(":").append(space);
    sb.append(TBaseHelper.toString(this.getError_code(), indent + 1, prettyPrint));
    first = false;
    sb.append(newLine + TBaseHelper.reduceIndent(indentStr));
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws TException {
    // check for required fields
  }

}

