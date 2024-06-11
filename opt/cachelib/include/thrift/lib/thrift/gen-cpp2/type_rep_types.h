/**
 * Autogenerated by Thrift for /disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/type_rep.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_types_h.h>


#include "thrift/lib/thrift/gen-cpp2/id_types.h"
#include "thrift/lib/thrift/gen-cpp2/standard_types.h"

namespace apache {
namespace thrift {
namespace ident {
struct standard;
struct custom;
struct id;
struct name;
struct params;
} // namespace ident
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_standard
#define APACHE_THRIFT_ACCESSOR_standard
APACHE_THRIFT_DEFINE_ACCESSOR(standard);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_custom
#define APACHE_THRIFT_ACCESSOR_custom
APACHE_THRIFT_DEFINE_ACCESSOR(custom);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_id
#define APACHE_THRIFT_ACCESSOR_id
APACHE_THRIFT_DEFINE_ACCESSOR(id);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_name
#define APACHE_THRIFT_ACCESSOR_name
APACHE_THRIFT_DEFINE_ACCESSOR(name);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_params
#define APACHE_THRIFT_ACCESSOR_params
APACHE_THRIFT_DEFINE_ACCESSOR(params);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums

// END declare_enums
// BEGIN forward_declare
namespace apache::thrift::type {
class ProtocolUnion;
class TypeStruct;
} // namespace apache::thrift::type
// END forward_declare
namespace apache::thrift::detail::annotation {
} // namespace apache::thrift::detail::annotation

namespace apache::thrift::detail::qualifier {
} // namespace apache::thrift::detail::qualifier

// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace apache::thrift::type {
using ::apache::thrift::detail::operator!=;
using ::apache::thrift::detail::operator>;
using ::apache::thrift::detail::operator<=;
using ::apache::thrift::detail::operator>=;


class ProtocolUnion final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;
  template<class> friend struct ::apache::thrift::detail::invoke_reffer;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_is_runtime_annotation = false;
  static const char* __fbthrift_thrift_uri();
  static std::string_view __fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord);
  static std::string_view __fbthrift_get_class_name();
  using __fbthrift_reflection_ident_list = folly::tag_t<
    ::apache::thrift::ident::standard,
    ::apache::thrift::ident::custom,
    ::apache::thrift::ident::id
  >;

  static constexpr std::int16_t __fbthrift_reflection_field_id_list[] = {0,1,2,3};
  using __fbthrift_reflection_type_tags = folly::tag_t<
    ::apache::thrift::type::enum_t<::apache::thrift::type::StandardProtocol>,
    ::apache::thrift::type::string_t,
    ::apache::thrift::type::adapted<::apache::thrift::type::detail::StrongIntegerAdapter<::apache::thrift::type::ProtocolId>, ::apache::thrift::type::i64_t>
  >;

  static constexpr std::size_t __fbthrift_field_size_v = 3;

  template<class T>
  using __fbthrift_id = ::apache::thrift::type::field_id<__fbthrift_reflection_field_id_list[folly::to_underlying(T::value)]>;

  template<class T>
  using __fbthrift_type_tag = ::apache::thrift::detail::at<__fbthrift_reflection_type_tags, T::value>;

  template<class T>
  using __fbthrift_ident = ::apache::thrift::detail::at<__fbthrift_reflection_ident_list, T::value>;

  template<class T> using __fbthrift_ordinal = ::apache::thrift::type::ordinal_tag<
    ::apache::thrift::detail::getFieldOrdinal<T,
                                              __fbthrift_reflection_ident_list,
                                              __fbthrift_reflection_type_tags>(
      __fbthrift_reflection_field_id_list
    )
  >;
  void __fbthrift_clear();
  void __fbthrift_destruct();
  bool __fbthrift_is_empty() const;

 public:
  using __fbthrift_cpp2_type = ProtocolUnion;
  static constexpr bool __fbthrift_cpp2_is_union =
    true;


 public:
  enum Type : int {
    __EMPTY__ = 0,
    standard = 1,
    custom = 2,
    id = 3,
  } ;

  ProtocolUnion()
      : type_(folly::to_underlying(Type::__EMPTY__)) {}

  ProtocolUnion(ProtocolUnion&& rhs) noexcept
      : type_(folly::to_underlying(Type::__EMPTY__)) {
    if (this == &rhs) { return; }
    switch (rhs.getType()) {
      case Type::__EMPTY__:
      {
        return;
      }
      case Type::standard:
      {
        set_standard(std::move(rhs.value_.standard));
        break;
      }
      case Type::custom:
      {
        set_custom(std::move(rhs.value_.custom));
        break;
      }
      case Type::id:
      {
        set_id(std::move(rhs.value_.id));
        break;
      }
      default:
      {
        assert(false);
        break;
      }
    }
    apache::thrift::clear(rhs);
  }

  ProtocolUnion(const ProtocolUnion& rhs);

  ProtocolUnion& operator=(ProtocolUnion&& rhs) noexcept {
    if (this == &rhs) { return *this; }
    switch (rhs.getType()) {
      case Type::__EMPTY__:
      {
        __fbthrift_clear();
        return *this;
      }
      case Type::standard:
      {
        set_standard(std::move(rhs.value_.standard));
        break;
      }
      case Type::custom:
      {
        set_custom(std::move(rhs.value_.custom));
        break;
      }
      case Type::id:
      {
        set_id(std::move(rhs.value_.id));
        break;
      }
      default:
      {
        assert(false);
        __fbthrift_clear();
      }
    }
    apache::thrift::clear(rhs);
    return *this;
  }

  ProtocolUnion& operator=(const ProtocolUnion& rhs);

  ~ProtocolUnion();

  union storage_type {
    ::apache::thrift::type::StandardProtocol standard;
    ::std::string custom;
    ::apache::thrift::type::ProtocolId id;

    storage_type() {}
    ~storage_type() {}
  } ;

  bool operator==(const ProtocolUnion&) const;
  bool operator<(const ProtocolUnion&) const;

  template <typename... A, std::enable_if_t<!sizeof...(A), int> = 0>
  ::apache::thrift::type::StandardProtocol& set_standard(::apache::thrift::type::StandardProtocol t = ::apache::thrift::type::StandardProtocol()) {
    using T0 = ::apache::thrift::type::StandardProtocol;
    using T = folly::type_t<T0, A...>;
    __fbthrift_clear();
    type_ = folly::to_underlying(Type::standard);
    ::new (std::addressof(value_.standard)) T(t);
    return value_.standard;
  }


  template <typename... A, std::enable_if_t<!sizeof...(A), int> = 0>
  ::std::string& set_custom(::std::string const &t) {
    using T0 = ::std::string;
    using T = folly::type_t<T0, A...>;
    __fbthrift_clear();
    type_ = folly::to_underlying(Type::custom);
    ::new (std::addressof(value_.custom)) T(t);
    return value_.custom;
  }

  template <typename... A, std::enable_if_t<!sizeof...(A), int> = 0>
  ::std::string& set_custom(::std::string&& t) {
    using T0 = ::std::string;
    using T = folly::type_t<T0, A...>;
    __fbthrift_clear();
    type_ = folly::to_underlying(Type::custom);
    ::new (std::addressof(value_.custom)) T(std::move(t));
    return value_.custom;
  }

  template<typename... T, typename = ::apache::thrift::safe_overload_t<::std::string, T...>> ::std::string& set_custom(T&&... t) {
    __fbthrift_clear();
    type_ = folly::to_underlying(Type::custom);
    ::new (std::addressof(value_.custom)) ::std::string(std::forward<T>(t)...);
    return value_.custom;
  }


  template <typename... A, std::enable_if_t<!sizeof...(A), int> = 0>
  ::apache::thrift::type::ProtocolId& set_id(::apache::thrift::type::ProtocolId t = ::apache::thrift::type::ProtocolId()) {
    using T0 = ::apache::thrift::type::ProtocolId;
    using T = folly::type_t<T0, A...>;
    __fbthrift_clear();
    type_ = folly::to_underlying(Type::id);
    ::new (std::addressof(value_.id)) T(t);
    return value_.id;
  }


  ::apache::thrift::type::StandardProtocol const& get_standard() const {
    if (getType() != Type::standard) {
      ::apache::thrift::detail::throw_on_bad_union_field_access();
    }
    return value_.standard;
  }

  ::std::string const& get_custom() const {
    if (getType() != Type::custom) {
      ::apache::thrift::detail::throw_on_bad_union_field_access();
    }
    return value_.custom;
  }

  ::apache::thrift::type::ProtocolId const& get_id() const {
    if (getType() != Type::id) {
      ::apache::thrift::detail::throw_on_bad_union_field_access();
    }
    return value_.id;
  }

  ::apache::thrift::type::StandardProtocol& mutable_standard() {
    assert(getType() == Type::standard);
    return value_.standard;
  }

  ::std::string& mutable_custom() {
    assert(getType() == Type::custom);
    return value_.custom;
  }

  ::apache::thrift::type::ProtocolId& mutable_id() {
    assert(getType() == Type::id);
    return value_.id;
  }

  ::apache::thrift::type::StandardProtocol move_standard() {
    assert(getType() == Type::standard);
    return std::move(value_.standard);
  }

  ::std::string move_custom() {
    assert(getType() == Type::custom);
    return std::move(value_.custom);
  }

  ::apache::thrift::type::ProtocolId move_id() {
    assert(getType() == Type::id);
    return std::move(value_.id);
  }

  template <typename..., typename T = ::apache::thrift::type::StandardProtocol>
  FOLLY_ERASE ::apache::thrift::union_field_ref<const T&> standard_ref() const& {
    return {value_.standard, type_, folly::to_underlying(Type::standard), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = ::apache::thrift::type::StandardProtocol>
  FOLLY_ERASE ::apache::thrift::union_field_ref<const T&&> standard_ref() const&& {
    return {std::move(value_.standard), type_, folly::to_underlying(Type::standard), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = ::apache::thrift::type::StandardProtocol>
  FOLLY_ERASE ::apache::thrift::union_field_ref<T&> standard_ref() & {
    return {value_.standard, type_, folly::to_underlying(Type::standard), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = ::apache::thrift::type::StandardProtocol>
  FOLLY_ERASE ::apache::thrift::union_field_ref<T&&> standard_ref() && {
    return {std::move(value_.standard), type_, folly::to_underlying(Type::standard), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::union_field_ref<const T&> custom_ref() const& {
    return {value_.custom, type_, folly::to_underlying(Type::custom), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::union_field_ref<const T&&> custom_ref() const&& {
    return {std::move(value_.custom), type_, folly::to_underlying(Type::custom), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::union_field_ref<T&> custom_ref() & {
    return {value_.custom, type_, folly::to_underlying(Type::custom), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::union_field_ref<T&&> custom_ref() && {
    return {std::move(value_.custom), type_, folly::to_underlying(Type::custom), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }
  template <typename..., typename T = ::apache::thrift::type::ProtocolId>
  FOLLY_ERASE ::apache::thrift::union_field_ref<const T&> id_ref() const& {
    return {value_.id, type_, folly::to_underlying(Type::id), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = ::apache::thrift::type::ProtocolId>
  FOLLY_ERASE ::apache::thrift::union_field_ref<const T&&> id_ref() const&& {
    return {std::move(value_.id), type_, folly::to_underlying(Type::id), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = ::apache::thrift::type::ProtocolId>
  FOLLY_ERASE ::apache::thrift::union_field_ref<T&> id_ref() & {
    return {value_.id, type_, folly::to_underlying(Type::id), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = ::apache::thrift::type::ProtocolId>
  FOLLY_ERASE ::apache::thrift::union_field_ref<T&&> id_ref() && {
    return {std::move(value_.id), type_, folly::to_underlying(Type::id), this, ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }
  Type getType() const { return static_cast<Type>(type_); }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;
 protected:
  storage_type value_;
  std::underlying_type_t<Type> type_;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<ProtocolUnion>;
  friend void swap(ProtocolUnion& a, ProtocolUnion& b);
};

template <class Protocol_>
unsigned long ProtocolUnion::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}


class TypeStruct final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;
  template<class> friend struct ::apache::thrift::detail::invoke_reffer;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_is_runtime_annotation = false;
  static const char* __fbthrift_thrift_uri();
  static std::string_view __fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord);
  static std::string_view __fbthrift_get_class_name();
  using __fbthrift_reflection_ident_list = folly::tag_t<
    ::apache::thrift::ident::name,
    ::apache::thrift::ident::params
  >;

  static constexpr std::int16_t __fbthrift_reflection_field_id_list[] = {0,1,2};
  using __fbthrift_reflection_type_tags = folly::tag_t<
    ::apache::thrift::type::union_t<::apache::thrift::type::TypeName>,
    ::apache::thrift::type::list<::apache::thrift::type::struct_t<::apache::thrift::type::TypeStruct>>
  >;

  static constexpr std::size_t __fbthrift_field_size_v = 2;

  template<class T>
  using __fbthrift_id = ::apache::thrift::type::field_id<__fbthrift_reflection_field_id_list[folly::to_underlying(T::value)]>;

  template<class T>
  using __fbthrift_type_tag = ::apache::thrift::detail::at<__fbthrift_reflection_type_tags, T::value>;

  template<class T>
  using __fbthrift_ident = ::apache::thrift::detail::at<__fbthrift_reflection_ident_list, T::value>;

  template<class T> using __fbthrift_ordinal = ::apache::thrift::type::ordinal_tag<
    ::apache::thrift::detail::getFieldOrdinal<T,
                                              __fbthrift_reflection_ident_list,
                                              __fbthrift_reflection_type_tags>(
      __fbthrift_reflection_field_id_list
    )
  >;
  void __fbthrift_clear();
  void __fbthrift_clear_terse_fields();
  bool __fbthrift_is_empty() const;

 public:
  using __fbthrift_cpp2_type = TypeStruct;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  TypeStruct();

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  TypeStruct(apache::thrift::FragileConstructor, ::apache::thrift::type::TypeName name__arg, ::std::vector<::apache::thrift::type::TypeStruct> params__arg);

  TypeStruct(TypeStruct&&) noexcept;

  TypeStruct(const TypeStruct& src);


  TypeStruct& operator=(TypeStruct&&) noexcept;
  TypeStruct& operator=(const TypeStruct& src);

  ~TypeStruct();

 private:
  ::apache::thrift::type::TypeName __fbthrift_field_name;
 private:
  ::std::vector<::apache::thrift::type::TypeStruct> __fbthrift_field_params;
 private:
  apache::thrift::detail::isset_bitset<2, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const TypeStruct&) const;
  bool operator<(const TypeStruct&) const;

  template <typename..., typename T = ::apache::thrift::type::TypeName>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> name_ref() const& {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::apache::thrift::type::TypeName>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> name_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::apache::thrift::type::TypeName>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> name_ref() & {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::apache::thrift::type::TypeName>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> name_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::apache::thrift::type::TypeName>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> name() const& {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::apache::thrift::type::TypeName>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> name() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::apache::thrift::type::TypeName>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> name() & {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::apache::thrift::type::TypeName>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> name() && {
    return {static_cast<T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::vector<::apache::thrift::type::TypeStruct>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> params_ref() const& {
    return {this->__fbthrift_field_params, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::vector<::apache::thrift::type::TypeStruct>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> params_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_params), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::vector<::apache::thrift::type::TypeStruct>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> params_ref() & {
    return {this->__fbthrift_field_params, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::vector<::apache::thrift::type::TypeStruct>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> params_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_params), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::vector<::apache::thrift::type::TypeStruct>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> params() const& {
    return {this->__fbthrift_field_params, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::vector<::apache::thrift::type::TypeStruct>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> params() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_params), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::vector<::apache::thrift::type::TypeStruct>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> params() & {
    return {this->__fbthrift_field_params, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::vector<::apache::thrift::type::TypeStruct>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> params() && {
    return {static_cast<T&&>(this->__fbthrift_field_params), __isset.at(1), __isset.bit(1)};
  }
  const ::apache::thrift::type::TypeName& get_name() const&;
  ::apache::thrift::type::TypeName get_name() &&;

  template <typename T_TypeStruct_name_struct_setter = ::apache::thrift::type::TypeName>
  [[deprecated("Use `FOO.name_ref() = BAR;` instead of `FOO.set_name(BAR);`")]]
  ::apache::thrift::type::TypeName& set_name(T_TypeStruct_name_struct_setter&& name_) {
    name_ref() = std::forward<T_TypeStruct_name_struct_setter>(name_);
    return __fbthrift_field_name;
  }
  const ::std::vector<::apache::thrift::type::TypeStruct>& get_params() const&;
  ::std::vector<::apache::thrift::type::TypeStruct> get_params() &&;

  template <typename T_TypeStruct_params_struct_setter = ::std::vector<::apache::thrift::type::TypeStruct>>
  [[deprecated("Use `FOO.params_ref() = BAR;` instead of `FOO.set_params(BAR);`")]]
  ::std::vector<::apache::thrift::type::TypeStruct>& set_params(T_TypeStruct_params_struct_setter&& params_) {
    params_ref() = std::forward<T_TypeStruct_params_struct_setter>(params_);
    return __fbthrift_field_params;
  }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<TypeStruct>;
  friend void swap(TypeStruct& a, TypeStruct& b);
};

template <class Protocol_>
unsigned long TypeStruct::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}


} // namespace apache::thrift::type

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::apache::thrift::type::ProtocolUnion::Type>;

template <> struct TEnumTraits<::apache::thrift::type::ProtocolUnion::Type> {
  using type = ::apache::thrift::type::ProtocolUnion::Type;

  static constexpr std::size_t const size = 3;
  static folly::Range<type const*> const values;
  static folly::Range<std::string_view const*> const names;

  static bool findName(type value, std::string_view* out) noexcept;
  static bool findValue(std::string_view name, type* out) noexcept;

  static char const* findName(type value) noexcept {
    std::string_view ret;
    (void)findName(value, &ret);
    return ret.data();
  }
};
}} // apache::thrift
