/**
 * Autogenerated by Thrift for /disk/CacheLib/cachelib/external/fbthrift/thrift/annotation/python.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_types_h.h>



namespace apache {
namespace thrift {
namespace ident {
struct name;
struct name;
struct typeHint;
struct serialize;
} // namespace ident
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_name
#define APACHE_THRIFT_ACCESSOR_name
APACHE_THRIFT_DEFINE_ACCESSOR(name);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_name
#define APACHE_THRIFT_ACCESSOR_name
APACHE_THRIFT_DEFINE_ACCESSOR(name);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_typeHint
#define APACHE_THRIFT_ACCESSOR_typeHint
APACHE_THRIFT_DEFINE_ACCESSOR(typeHint);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_serialize
#define APACHE_THRIFT_ACCESSOR_serialize
APACHE_THRIFT_DEFINE_ACCESSOR(serialize);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums

// END declare_enums
// BEGIN forward_declare
namespace facebook::thrift::annotation::python {
class Py3Hidden;
class Flags;
class Name;
class Adapter;
class UseCAPI;
} // namespace facebook::thrift::annotation::python
// END forward_declare
namespace apache::thrift::detail::annotation {
} // namespace apache::thrift::detail::annotation

namespace apache::thrift::detail::qualifier {
} // namespace apache::thrift::detail::qualifier

// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace facebook::thrift::annotation::python {
using ::apache::thrift::detail::operator!=;
using ::apache::thrift::detail::operator>;
using ::apache::thrift::detail::operator<=;
using ::apache::thrift::detail::operator>=;


class Py3Hidden final  {
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
  >;

  static constexpr std::int16_t __fbthrift_reflection_field_id_list[] = {0};
  using __fbthrift_reflection_type_tags = folly::tag_t<
  >;

  static constexpr std::size_t __fbthrift_field_size_v = 0;

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
  using __fbthrift_cpp2_type = Py3Hidden;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  Py3Hidden() {
  }
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Py3Hidden(apache::thrift::FragileConstructor);

  Py3Hidden(Py3Hidden&&) = default;

  Py3Hidden(const Py3Hidden&) = default;


  Py3Hidden& operator=(Py3Hidden&&) = default;

  Py3Hidden& operator=(const Py3Hidden&) = default;

 public:

  bool operator==(const Py3Hidden&) const;
  bool operator<(const Py3Hidden&) const;

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

  friend class ::apache::thrift::Cpp2Ops<Py3Hidden>;
  friend void swap(Py3Hidden& a, Py3Hidden& b);
};

template <class Protocol_>
unsigned long Py3Hidden::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}


class Flags final  {
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
  >;

  static constexpr std::int16_t __fbthrift_reflection_field_id_list[] = {0};
  using __fbthrift_reflection_type_tags = folly::tag_t<
  >;

  static constexpr std::size_t __fbthrift_field_size_v = 0;

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
  using __fbthrift_cpp2_type = Flags;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  Flags() {
  }
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Flags(apache::thrift::FragileConstructor);

  Flags(Flags&&) = default;

  Flags(const Flags&) = default;


  Flags& operator=(Flags&&) = default;

  Flags& operator=(const Flags&) = default;

 public:

  bool operator==(const Flags&) const;
  bool operator<(const Flags&) const;

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

  friend class ::apache::thrift::Cpp2Ops<Flags>;
  friend void swap(Flags& a, Flags& b);
};

template <class Protocol_>
unsigned long Flags::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}


class Name final  {
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
    ::apache::thrift::ident::name
  >;

  static constexpr std::int16_t __fbthrift_reflection_field_id_list[] = {0,1};
  using __fbthrift_reflection_type_tags = folly::tag_t<
    ::apache::thrift::type::string_t
  >;

  static constexpr std::size_t __fbthrift_field_size_v = 1;

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
  using __fbthrift_cpp2_type = Name;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  Name();

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Name(apache::thrift::FragileConstructor, ::std::string name__arg);

  Name(Name&&) noexcept;

  Name(const Name& src);


  Name& operator=(Name&&) noexcept;
  Name& operator=(const Name& src);

  ~Name();

 private:
  ::std::string __fbthrift_field_name;
 private:
  apache::thrift::detail::isset_bitset<1, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const Name&) const;
  bool operator<(const Name&) const;

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> name_ref() const& {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> name_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> name_ref() & {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> name_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> name() const& {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> name() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> name() & {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> name() && {
    return {static_cast<T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  const ::std::string& get_name() const& {
    return __fbthrift_field_name;
  }

  ::std::string get_name() && {
    return std::move(__fbthrift_field_name);
  }

  template <typename T_Name_name_struct_setter = ::std::string>
  [[deprecated("Use `FOO.name_ref() = BAR;` instead of `FOO.set_name(BAR);`")]]
  ::std::string& set_name(T_Name_name_struct_setter&& name_) {
    name_ref() = std::forward<T_Name_name_struct_setter>(name_);
    return __fbthrift_field_name;
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

  friend class ::apache::thrift::Cpp2Ops<Name>;
  friend void swap(Name& a, Name& b);
};

template <class Protocol_>
unsigned long Name::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}


class Adapter final  {
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
    ::apache::thrift::ident::typeHint
  >;

  static constexpr std::int16_t __fbthrift_reflection_field_id_list[] = {0,1,2};
  using __fbthrift_reflection_type_tags = folly::tag_t<
    ::apache::thrift::type::string_t,
    ::apache::thrift::type::string_t
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
  using __fbthrift_cpp2_type = Adapter;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  Adapter();

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Adapter(apache::thrift::FragileConstructor, ::std::string name__arg, ::std::string typeHint__arg);

  Adapter(Adapter&&) noexcept;

  Adapter(const Adapter& src);


  Adapter& operator=(Adapter&&) noexcept;
  Adapter& operator=(const Adapter& src);

  ~Adapter();

 private:
  ::std::string __fbthrift_field_name;
 private:
  ::std::string __fbthrift_field_typeHint;
 private:
  apache::thrift::detail::isset_bitset<2, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const Adapter&) const;
  bool operator<(const Adapter&) const;

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> name_ref() const& {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> name_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> name_ref() & {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> name_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> name() const& {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> name() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> name() & {
    return {this->__fbthrift_field_name, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> name() && {
    return {static_cast<T&&>(this->__fbthrift_field_name), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> typeHint_ref() const& {
    return {this->__fbthrift_field_typeHint, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> typeHint_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_typeHint), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> typeHint_ref() & {
    return {this->__fbthrift_field_typeHint, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> typeHint_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_typeHint), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> typeHint() const& {
    return {this->__fbthrift_field_typeHint, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> typeHint() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_typeHint), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> typeHint() & {
    return {this->__fbthrift_field_typeHint, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> typeHint() && {
    return {static_cast<T&&>(this->__fbthrift_field_typeHint), __isset.at(1), __isset.bit(1)};
  }

  const ::std::string& get_name() const& {
    return __fbthrift_field_name;
  }

  ::std::string get_name() && {
    return std::move(__fbthrift_field_name);
  }

  template <typename T_Adapter_name_struct_setter = ::std::string>
  [[deprecated("Use `FOO.name_ref() = BAR;` instead of `FOO.set_name(BAR);`")]]
  ::std::string& set_name(T_Adapter_name_struct_setter&& name_) {
    name_ref() = std::forward<T_Adapter_name_struct_setter>(name_);
    return __fbthrift_field_name;
  }

  const ::std::string& get_typeHint() const& {
    return __fbthrift_field_typeHint;
  }

  ::std::string get_typeHint() && {
    return std::move(__fbthrift_field_typeHint);
  }

  template <typename T_Adapter_typeHint_struct_setter = ::std::string>
  [[deprecated("Use `FOO.typeHint_ref() = BAR;` instead of `FOO.set_typeHint(BAR);`")]]
  ::std::string& set_typeHint(T_Adapter_typeHint_struct_setter&& typeHint_) {
    typeHint_ref() = std::forward<T_Adapter_typeHint_struct_setter>(typeHint_);
    return __fbthrift_field_typeHint;
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

  friend class ::apache::thrift::Cpp2Ops<Adapter>;
  friend void swap(Adapter& a, Adapter& b);
};

template <class Protocol_>
unsigned long Adapter::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}


class UseCAPI final  {
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
    ::apache::thrift::ident::serialize
  >;

  static constexpr std::int16_t __fbthrift_reflection_field_id_list[] = {0,1};
  using __fbthrift_reflection_type_tags = folly::tag_t<
    ::apache::thrift::type::bool_t
  >;

  static constexpr std::size_t __fbthrift_field_size_v = 1;

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
  using __fbthrift_cpp2_type = UseCAPI;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  UseCAPI() :
      __fbthrift_field_serialize(false) {
  }
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  UseCAPI(apache::thrift::FragileConstructor, bool serialize__arg);

  UseCAPI(UseCAPI&&) = default;

  UseCAPI(const UseCAPI&) = default;


  UseCAPI& operator=(UseCAPI&&) = default;

  UseCAPI& operator=(const UseCAPI&) = default;
 private:
  bool __fbthrift_field_serialize;
 private:
  apache::thrift::detail::isset_bitset<1, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const UseCAPI&) const;
  bool operator<(const UseCAPI&) const;

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> serialize_ref() const& {
    return {this->__fbthrift_field_serialize, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> serialize_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_serialize), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> serialize_ref() & {
    return {this->__fbthrift_field_serialize, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> serialize_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_serialize), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> serialize() const& {
    return {this->__fbthrift_field_serialize, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> serialize() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_serialize), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> serialize() & {
    return {this->__fbthrift_field_serialize, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> serialize() && {
    return {static_cast<T&&>(this->__fbthrift_field_serialize), __isset.at(0), __isset.bit(0)};
  }

  bool get_serialize() const {
    return __fbthrift_field_serialize;
  }

  [[deprecated("Use `FOO.serialize_ref() = BAR;` instead of `FOO.set_serialize(BAR);`")]]
  bool& set_serialize(bool serialize_) {
    serialize_ref() = serialize_;
    return __fbthrift_field_serialize;
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

  friend class ::apache::thrift::Cpp2Ops<UseCAPI>;
  friend void swap(UseCAPI& a, UseCAPI& b);
};

template <class Protocol_>
unsigned long UseCAPI::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}


} // namespace facebook::thrift::annotation::python
