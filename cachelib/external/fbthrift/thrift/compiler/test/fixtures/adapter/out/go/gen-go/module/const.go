// @generated by Thrift for [[[ program path ]]]
// This file is probably not the place you want to edit!

package module // [[[ program thrift source path ]]]

import (
    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift"
)

// (needed to ensure safety because of naive import list construction)
var _ = thrift.ZERO

var GoUnusedProtection__ int

const Var1 int32 = 10
const Var2 string = "20"
var Var3 *MyStruct = NewMyStruct().
    SetFieldNonCompat(30).
    SetSetStringNonCompat(
        []string{
    "10",
    "20",
},
    )
const Var4 int32 = 40
const Var5 string = "50"
var Var6 *MyStruct = NewMyStruct().
    SetFieldNonCompat(60).
    SetSetStringNonCompat(
        []string{
    "30",
    "40",
},
    )
const Timeout int32 = 42
const Msg string = "hello, world"
var Person *Person2 = NewPerson2().
    SetNameNonCompat("DefaultName")
const TimeoutNoTransitive int32 = 420
const MsgNoTransitive string = "hello, world 2"
var PersonNoTransitive *Person2 = NewPerson2().
    SetNameNonCompat("DefaultName 2")
const TypeAdapted AdaptedBool = true
var NestedAdapted *MoveOnly = NewMoveOnly().
    SetPtrNonCompat(
        *NewHeapAllocated(),
    )
var ContainerOfAdapted []AdaptedByte = []AdaptedByte{
    1,
    2,
    3,
}
