/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package test.fixtures.patch;

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
public class MyStructField29Patch implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("MyStructField29Patch");
  private static final TField ASSIGN_FIELD_DESC = new TField("assign", TType.LIST, (short)1);
  private static final TField CLEAR_FIELD_DESC = new TField("clear", TType.BOOL, (short)2);
  private static final TField PREPEND_FIELD_DESC = new TField("prepend", TType.LIST, (short)8);
  private static final TField APPEND_FIELD_DESC = new TField("append", TType.LIST, (short)9);

  /**
   * Assigns to a (set) value.
   * 
   * If set, all other operations are ignored.
   * 
   * Note: Optional and union fields must be set before assigned.
   * 
   */
  public final List<Map<String,Integer>> assign;
  /**
   * Clears a value. Applies first.
   */
  public final Boolean clear;
  /**
   * Prepends to the front of a given list.
   */
  public final List<Map<String,Integer>> prepend;
  /**
   * Appends to the back of a given list.
   */
  public final List<Map<String,Integer>> append;
  public static final int ASSIGN = 1;
  public static final int CLEAR = 2;
  public static final int PREPEND = 8;
  public static final int APPEND = 9;

  public MyStructField29Patch(
      List<Map<String,Integer>> assign,
      Boolean clear,
      List<Map<String,Integer>> prepend,
      List<Map<String,Integer>> append) {
    this.assign = assign;
    this.clear = clear;
    this.prepend = prepend;
    this.append = append;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public MyStructField29Patch(MyStructField29Patch other) {
    if (other.isSetAssign()) {
      this.assign = TBaseHelper.deepCopy(other.assign);
    } else {
      this.assign = null;
    }
    if (other.isSetClear()) {
      this.clear = TBaseHelper.deepCopy(other.clear);
    } else {
      this.clear = null;
    }
    if (other.isSetPrepend()) {
      this.prepend = TBaseHelper.deepCopy(other.prepend);
    } else {
      this.prepend = null;
    }
    if (other.isSetAppend()) {
      this.append = TBaseHelper.deepCopy(other.append);
    } else {
      this.append = null;
    }
  }

  public MyStructField29Patch deepCopy() {
    return new MyStructField29Patch(this);
  }

  /**
   * Assigns to a (set) value.
   * 
   * If set, all other operations are ignored.
   * 
   * Note: Optional and union fields must be set before assigned.
   * 
   */
  public List<Map<String,Integer>> getAssign() {
    return this.assign;
  }

  // Returns true if field assign is set (has been assigned a value) and false otherwise
  public boolean isSetAssign() {
    return this.assign != null;
  }

  /**
   * Clears a value. Applies first.
   */
  public Boolean isClear() {
    return this.clear;
  }

  // Returns true if field clear is set (has been assigned a value) and false otherwise
  public boolean isSetClear() {
    return this.clear != null;
  }

  /**
   * Prepends to the front of a given list.
   */
  public List<Map<String,Integer>> getPrepend() {
    return this.prepend;
  }

  // Returns true if field prepend is set (has been assigned a value) and false otherwise
  public boolean isSetPrepend() {
    return this.prepend != null;
  }

  /**
   * Appends to the back of a given list.
   */
  public List<Map<String,Integer>> getAppend() {
    return this.append;
  }

  // Returns true if field append is set (has been assigned a value) and false otherwise
  public boolean isSetAppend() {
    return this.append != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof MyStructField29Patch))
      return false;
    MyStructField29Patch that = (MyStructField29Patch)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetAssign(), that.isSetAssign(), this.assign, that.assign)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetClear(), that.isSetClear(), this.clear, that.clear)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetPrepend(), that.isSetPrepend(), this.prepend, that.prepend)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAppend(), that.isSetAppend(), this.append, that.append)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {assign, clear, prepend, append});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static MyStructField29Patch deserialize(TProtocol iprot) throws TException {
    List<Map<String,Integer>> tmp_assign = null;
    Boolean tmp_clear = null;
    List<Map<String,Integer>> tmp_prepend = null;
    List<Map<String,Integer>> tmp_append = null;
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
        case ASSIGN:
          if (__field.type == TType.LIST) {
            {
              TList _list130 = iprot.readListBegin();
              tmp_assign = new ArrayList<Map<String,Integer>>(Math.max(0, _list130.size));
              for (int _i131 = 0; 
                   (_list130.size < 0) ? iprot.peekList() : (_i131 < _list130.size); 
                   ++_i131)
              {
                Map<String,Integer> _elem132;
                {
                  TMap _map133 = iprot.readMapBegin();
                  _elem132 = new HashMap<String,Integer>(Math.max(0, 2*_map133.size));
                  for (int _i134 = 0; 
                       (_map133.size < 0) ? iprot.peekMap() : (_i134 < _map133.size); 
                       ++_i134)
                  {
                    String _key135;
                    Integer _val136;
                    _key135 = iprot.readString();
                    _val136 = iprot.readI32();
                    _elem132.put(_key135, _val136);
                  }
                  iprot.readMapEnd();
                }
                tmp_assign.add(_elem132);
              }
              iprot.readListEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case CLEAR:
          if (__field.type == TType.BOOL) {
            tmp_clear = iprot.readBool();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case PREPEND:
          if (__field.type == TType.LIST) {
            {
              TList _list137 = iprot.readListBegin();
              tmp_prepend = new ArrayList<Map<String,Integer>>(Math.max(0, _list137.size));
              for (int _i138 = 0; 
                   (_list137.size < 0) ? iprot.peekList() : (_i138 < _list137.size); 
                   ++_i138)
              {
                Map<String,Integer> _elem139;
                {
                  TMap _map140 = iprot.readMapBegin();
                  _elem139 = new HashMap<String,Integer>(Math.max(0, 2*_map140.size));
                  for (int _i141 = 0; 
                       (_map140.size < 0) ? iprot.peekMap() : (_i141 < _map140.size); 
                       ++_i141)
                  {
                    String _key142;
                    Integer _val143;
                    _key142 = iprot.readString();
                    _val143 = iprot.readI32();
                    _elem139.put(_key142, _val143);
                  }
                  iprot.readMapEnd();
                }
                tmp_prepend.add(_elem139);
              }
              iprot.readListEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case APPEND:
          if (__field.type == TType.LIST) {
            {
              TList _list144 = iprot.readListBegin();
              tmp_append = new ArrayList<Map<String,Integer>>(Math.max(0, _list144.size));
              for (int _i145 = 0; 
                   (_list144.size < 0) ? iprot.peekList() : (_i145 < _list144.size); 
                   ++_i145)
              {
                Map<String,Integer> _elem146;
                {
                  TMap _map147 = iprot.readMapBegin();
                  _elem146 = new HashMap<String,Integer>(Math.max(0, 2*_map147.size));
                  for (int _i148 = 0; 
                       (_map147.size < 0) ? iprot.peekMap() : (_i148 < _map147.size); 
                       ++_i148)
                  {
                    String _key149;
                    Integer _val150;
                    _key149 = iprot.readString();
                    _val150 = iprot.readI32();
                    _elem146.put(_key149, _val150);
                  }
                  iprot.readMapEnd();
                }
                tmp_append.add(_elem146);
              }
              iprot.readListEnd();
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

    MyStructField29Patch _that;
    _that = new MyStructField29Patch(
      tmp_assign
      ,tmp_clear
      ,tmp_prepend
      ,tmp_append
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.assign != null) {
      if (isSetAssign()) {
        oprot.writeFieldBegin(ASSIGN_FIELD_DESC);
        {
          oprot.writeListBegin(new TList(TType.MAP, this.assign.size()));
          for (Map<String,Integer> _iter151 : this.assign)          {
            {
              oprot.writeMapBegin(new TMap(TType.STRING, TType.I32, _iter151.size()));
              for (Map.Entry<String, Integer> _iter152 : _iter151.entrySet())              {
                oprot.writeString(_iter152.getKey());
                oprot.writeI32(_iter152.getValue());
              }
              oprot.writeMapEnd();
            }
          }
          oprot.writeListEnd();
        }
        oprot.writeFieldEnd();
      }
    }
    if (this.clear != null) {
      oprot.writeFieldBegin(CLEAR_FIELD_DESC);
      oprot.writeBool(this.clear);
      oprot.writeFieldEnd();
    }
    if (this.prepend != null) {
      oprot.writeFieldBegin(PREPEND_FIELD_DESC);
      {
        oprot.writeListBegin(new TList(TType.MAP, this.prepend.size()));
        for (Map<String,Integer> _iter153 : this.prepend)        {
          {
            oprot.writeMapBegin(new TMap(TType.STRING, TType.I32, _iter153.size()));
            for (Map.Entry<String, Integer> _iter154 : _iter153.entrySet())            {
              oprot.writeString(_iter154.getKey());
              oprot.writeI32(_iter154.getValue());
            }
            oprot.writeMapEnd();
          }
        }
        oprot.writeListEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.append != null) {
      oprot.writeFieldBegin(APPEND_FIELD_DESC);
      {
        oprot.writeListBegin(new TList(TType.MAP, this.append.size()));
        for (Map<String,Integer> _iter155 : this.append)        {
          {
            oprot.writeMapBegin(new TMap(TType.STRING, TType.I32, _iter155.size()));
            for (Map.Entry<String, Integer> _iter156 : _iter155.entrySet())            {
              oprot.writeString(_iter156.getKey());
              oprot.writeI32(_iter156.getValue());
            }
            oprot.writeMapEnd();
          }
        }
        oprot.writeListEnd();
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
    return TBaseHelper.toStringHelper(this, indent, prettyPrint);
  }

  public void validate() throws TException {
    // check for required fields
  }

}

