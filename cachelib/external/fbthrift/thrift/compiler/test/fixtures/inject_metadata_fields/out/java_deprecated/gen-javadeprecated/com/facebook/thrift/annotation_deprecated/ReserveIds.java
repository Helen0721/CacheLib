/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package com.facebook.thrift.annotation_deprecated;

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
 * Annotate a thrift structured or enum to indicate if ids or values should not
 * be used.
 * 
 * For example, you may want to mark ids as deprecated, or these ids
 * might be reserved for other use cases or annotations.
 * 
 * The resolved set of disallowed ids is the union of the values in `ids` and
 * the range of values represented in `id_ranges`. Example:
 * 
 *  // These ids are not allowed: 3, 8, half-open ranges [10, 15), [20, 30)
 *  @thrift.ReserveIds{ids = [3, 8], id_ranges = {10: 15, 20: 30}}
 *  struct Foo {
 *    ...
 *    3: i64 f; // Build failure: 3 cannot be used
 *  }
 */
@SuppressWarnings({ "unused", "serial" })
public class ReserveIds implements TBase, java.io.Serializable, Cloneable, Comparable<ReserveIds> {
  private static final TStruct STRUCT_DESC = new TStruct("ReserveIds");
  private static final TField IDS_FIELD_DESC = new TField("ids", TType.LIST, (short)1);
  private static final TField ID_RANGES_FIELD_DESC = new TField("id_ranges", TType.MAP, (short)2);

  /**
   * Individual ids that cannot be used.
   */
  public List<Integer> ids;
  /**
   * Represents ranges of ids that cannot be used.
   * 
   * Each (key: value) pair represents the half-open range `[key, value)`,
   * where `key` is included and `value` is not. For example, the map
   * `{10: 15, 20: 30}` represents the union of id/value ranges `[10, 15)` and
   * `[20, 30)`.
   */
  public Map<Integer,Integer> id_ranges;
  public static final int IDS = 1;
  public static final int ID_RANGES = 2;

  // isset id assignments

  public static final Map<Integer, FieldMetaData> metaDataMap;

  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(IDS, new FieldMetaData("ids", TFieldRequirementType.DEFAULT, 
        new ListMetaData(TType.LIST, 
            new FieldValueMetaData(TType.I32))));
    tmpMetaDataMap.put(ID_RANGES, new FieldMetaData("id_ranges", TFieldRequirementType.DEFAULT, 
        new MapMetaData(TType.MAP, 
            new FieldValueMetaData(TType.I32), 
            new FieldValueMetaData(TType.I32))));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  static {
    FieldMetaData.addStructMetaDataMap(ReserveIds.class, metaDataMap);
  }

  public ReserveIds() {
  }

  public ReserveIds(
      List<Integer> ids,
      Map<Integer,Integer> id_ranges) {
    this();
    this.ids = ids;
    this.id_ranges = id_ranges;
  }

  public static class Builder {
    private List<Integer> ids;
    private Map<Integer,Integer> id_ranges;

    public Builder() {
    }

    public Builder setIds(final List<Integer> ids) {
      this.ids = ids;
      return this;
    }

    public Builder setId_ranges(final Map<Integer,Integer> id_ranges) {
      this.id_ranges = id_ranges;
      return this;
    }

    public ReserveIds build() {
      ReserveIds result = new ReserveIds();
      result.setIds(this.ids);
      result.setId_ranges(this.id_ranges);
      return result;
    }
  }

  public static Builder builder() {
    return new Builder();
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public ReserveIds(ReserveIds other) {
    if (other.isSetIds()) {
      this.ids = TBaseHelper.deepCopy(other.ids);
    }
    if (other.isSetId_ranges()) {
      this.id_ranges = TBaseHelper.deepCopy(other.id_ranges);
    }
  }

  public ReserveIds deepCopy() {
    return new ReserveIds(this);
  }

  /**
   * Individual ids that cannot be used.
   */
  public List<Integer> getIds() {
    return this.ids;
  }

  /**
   * Individual ids that cannot be used.
   */
  public ReserveIds setIds(List<Integer> ids) {
    this.ids = ids;
    return this;
  }

  public void unsetIds() {
    this.ids = null;
  }

  // Returns true if field ids is set (has been assigned a value) and false otherwise
  public boolean isSetIds() {
    return this.ids != null;
  }

  public void setIdsIsSet(boolean __value) {
    if (!__value) {
      this.ids = null;
    }
  }

  /**
   * Represents ranges of ids that cannot be used.
   * 
   * Each (key: value) pair represents the half-open range `[key, value)`,
   * where `key` is included and `value` is not. For example, the map
   * `{10: 15, 20: 30}` represents the union of id/value ranges `[10, 15)` and
   * `[20, 30)`.
   */
  public Map<Integer,Integer> getId_ranges() {
    return this.id_ranges;
  }

  /**
   * Represents ranges of ids that cannot be used.
   * 
   * Each (key: value) pair represents the half-open range `[key, value)`,
   * where `key` is included and `value` is not. For example, the map
   * `{10: 15, 20: 30}` represents the union of id/value ranges `[10, 15)` and
   * `[20, 30)`.
   */
  public ReserveIds setId_ranges(Map<Integer,Integer> id_ranges) {
    this.id_ranges = id_ranges;
    return this;
  }

  public void unsetId_ranges() {
    this.id_ranges = null;
  }

  // Returns true if field id_ranges is set (has been assigned a value) and false otherwise
  public boolean isSetId_ranges() {
    return this.id_ranges != null;
  }

  public void setId_rangesIsSet(boolean __value) {
    if (!__value) {
      this.id_ranges = null;
    }
  }

  @SuppressWarnings("unchecked")
  public void setFieldValue(int fieldID, Object __value) {
    switch (fieldID) {
    case IDS:
      if (__value == null) {
        unsetIds();
      } else {
        setIds((List<Integer>)__value);
      }
      break;

    case ID_RANGES:
      if (__value == null) {
        unsetId_ranges();
      } else {
        setId_ranges((Map<Integer,Integer>)__value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case IDS:
      return getIds();

    case ID_RANGES:
      return getId_ranges();

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
    if (!(_that instanceof ReserveIds))
      return false;
    ReserveIds that = (ReserveIds)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetIds(), that.isSetIds(), this.ids, that.ids)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetId_ranges(), that.isSetId_ranges(), this.id_ranges, that.id_ranges)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {ids, id_ranges});
  }

  @Override
  public int compareTo(ReserveIds other) {
    if (other == null) {
      // See java.lang.Comparable docs
      throw new NullPointerException();
    }

    if (other == this) {
      return 0;
    }
    int lastComparison = 0;

    lastComparison = Boolean.valueOf(isSetIds()).compareTo(other.isSetIds());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(ids, other.ids);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetId_ranges()).compareTo(other.isSetId_ranges());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(id_ranges, other.id_ranges);
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
        case IDS:
          if (__field.type == TType.LIST) {
            {
              TList _list0 = iprot.readListBegin();
              this.ids = new ArrayList<Integer>(Math.max(0, _list0.size));
              for (int _i1 = 0; 
                   (_list0.size < 0) ? iprot.peekList() : (_i1 < _list0.size); 
                   ++_i1)
              {
                int _elem2;
                _elem2 = iprot.readI32();
                this.ids.add(_elem2);
              }
              iprot.readListEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ID_RANGES:
          if (__field.type == TType.MAP) {
            {
              TMap _map3 = iprot.readMapBegin();
              this.id_ranges = new HashMap<Integer,Integer>(Math.max(0, 2*_map3.size));
              for (int _i4 = 0; 
                   (_map3.size < 0) ? iprot.peekMap() : (_i4 < _map3.size); 
                   ++_i4)
              {
                int _key5;
                int _val6;
                _key5 = iprot.readI32();
                _val6 = iprot.readI32();
                this.id_ranges.put(_key5, _val6);
              }
              iprot.readMapEnd();
            }
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
    if (this.ids != null) {
      oprot.writeFieldBegin(IDS_FIELD_DESC);
      {
        oprot.writeListBegin(new TList(TType.I32, this.ids.size()));
        for (int _iter7 : this.ids)        {
          oprot.writeI32(_iter7);
        }
        oprot.writeListEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.id_ranges != null) {
      oprot.writeFieldBegin(ID_RANGES_FIELD_DESC);
      {
        oprot.writeMapBegin(new TMap(TType.I32, TType.I32, this.id_ranges.size()));
        for (Map.Entry<Integer, Integer> _iter8 : this.id_ranges.entrySet())        {
          oprot.writeI32(_iter8.getKey());
          oprot.writeI32(_iter8.getValue());
        }
        oprot.writeMapEnd();
      }
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
    StringBuilder sb = new StringBuilder("ReserveIds");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    sb.append(indentStr);
    sb.append("ids");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getIds() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getIds(), indent + 1, prettyPrint));
    }
    first = false;
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("id_ranges");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getId_ranges() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getId_ranges(), indent + 1, prettyPrint));
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

