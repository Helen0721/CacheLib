/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package com.facebook.thrift.annotation.cpp_deprecated;

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
 * Causes C++ handler code to run inline on the EventBase thread.
 * Disables overload protection, use with caution.
 * Cannot be applied to individual functions in interactions.
 * 
 * Causes the request to be executed on the event base thread directly instead of rescheduling onto a thread manager thread, provided the async_eb_ handler method is implemented.
 * You should only execute the request on the event base thread if it is very fast and you have measured that rescheduling is a substantial chunk of your service's CPU usage.
 * If a request executing on the event base thread blocks or takes a long time, all other requests sharing the same event base are affected and latency will increase significantly.
 * We strongly discourage the use of this annotation unless strictly necessary. You will have to implement the harder-to-use async_eb_ handler method.
 * This also disables queue timeouts, an important form of overload protection.
 */
@SuppressWarnings({ "unused", "serial" })
public class ProcessInEbThreadUnsafe implements TBase, java.io.Serializable, Cloneable, Comparable<ProcessInEbThreadUnsafe> {
  private static final TStruct STRUCT_DESC = new TStruct("ProcessInEbThreadUnsafe");

  public static final Map<Integer, FieldMetaData> metaDataMap;

  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  static {
    FieldMetaData.addStructMetaDataMap(ProcessInEbThreadUnsafe.class, metaDataMap);
  }

  public ProcessInEbThreadUnsafe() {
  }

  public static class Builder {

    public Builder() {
    }

    public ProcessInEbThreadUnsafe build() {
      ProcessInEbThreadUnsafe result = new ProcessInEbThreadUnsafe();
      return result;
    }
  }

  public static Builder builder() {
    return new Builder();
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public ProcessInEbThreadUnsafe(ProcessInEbThreadUnsafe other) {
  }

  public ProcessInEbThreadUnsafe deepCopy() {
    return new ProcessInEbThreadUnsafe(this);
  }

  public void setFieldValue(int fieldID, Object __value) {
    switch (fieldID) {
    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
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
    if (!(_that instanceof ProcessInEbThreadUnsafe))
      return false;
    ProcessInEbThreadUnsafe that = (ProcessInEbThreadUnsafe)_that;

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {});
  }

  @Override
  public int compareTo(ProcessInEbThreadUnsafe other) {
    if (other == null) {
      // See java.lang.Comparable docs
      throw new NullPointerException();
    }

    if (other == this) {
      return 0;
    }
    int lastComparison = 0;

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
    StringBuilder sb = new StringBuilder("ProcessInEbThreadUnsafe");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    sb.append(newLine + TBaseHelper.reduceIndent(indentStr));
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws TException {
    // check for required fields
  }

}

