// @generated by Thrift for [[[ program path ]]]
// This file is probably not the place you want to edit!

package module // [[[ program thrift source path ]]]

import (
    "fmt"
    "strings"

    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift"
)

// (needed to ensure safety because of naive import list construction)
var _ = fmt.Printf
var _ = strings.Split
var _ = thrift.ZERO


type Foo struct {
    MyInt int64 `thrift:"MyInt,1" json:"MyInt" db:"MyInt"`
}
// Compile time interface enforcer
var _ thrift.Struct = &Foo{}

func NewFoo() *Foo {
    return (&Foo{}).
        SetMyIntNonCompat(0)
}

func (x *Foo) GetMyIntNonCompat() int64 {
    return x.MyInt
}

func (x *Foo) GetMyInt() int64 {
    return x.MyInt
}

func (x *Foo) SetMyIntNonCompat(value int64) *Foo {
    x.MyInt = value
    return x
}

func (x *Foo) SetMyInt(value int64) *Foo {
    x.MyInt = value
    return x
}

func (x *Foo) writeField1(p thrift.Format) error {  // MyInt
    if err := p.WriteFieldBegin("MyInt", thrift.I64, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetMyIntNonCompat()
    if err := p.WriteI64(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *Foo) readField1(p thrift.Format) error {  // MyInt
    result, err := p.ReadI64()
if err != nil {
    return err
}

    x.SetMyIntNonCompat(result)
    return nil
}

func (x *Foo) toString1() string {  // MyInt
    return fmt.Sprintf("%v", x.GetMyIntNonCompat())
}


// Deprecated: Use "New" constructor and setters to build your structs.
// e.g NewFoo().Set<FieldNameFoo>().Set<FieldNameBar>()
type FooBuilder struct {
    obj *Foo
}

// Deprecated: Use "New" constructor and setters to build your structs.
// e.g NewFoo().Set<FieldNameFoo>().Set<FieldNameBar>()
func NewFooBuilder() *FooBuilder {
    return &FooBuilder{
        obj: NewFoo(),
    }
}

// Deprecated: Use "New" constructor and setters to build your structs.
// e.g NewFoo().Set<FieldNameFoo>().Set<FieldNameBar>()
func (x *FooBuilder) MyInt(value int64) *FooBuilder {
    x.obj.MyInt = value
    return x
}

// Deprecated: Use "New" constructor and setters to build your structs.
// e.g NewFoo().Set<FieldNameFoo>().Set<FieldNameBar>()
func (x *FooBuilder) Emit() *Foo {
    var objCopy Foo = *x.obj
    return &objCopy
}

func (x *Foo) Write(p thrift.Format) error {
    if err := p.WriteStructBegin("Foo"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *Foo) Read(p thrift.Format) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch {
        case (id == 1 && wireType == thrift.Type(thrift.I64)):  // MyInt
            if err := x.readField1(p); err != nil {
                return err
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *Foo) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("Foo({")
    sb.WriteString(fmt.Sprintf("MyInt:%s", x.toString1()))
    sb.WriteString("})")

    return sb.String()
}

// RegisterTypes registers types found in this file that have a thrift_uri with the passed in registry.
func RegisterTypes(registry interface {
  RegisterType(name string, initializer func() any)
}) {
    registry.RegisterType("test.dev/namespace_from_package_without_module_name/Foo", func() any { return NewFoo() })

}
