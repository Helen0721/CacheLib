/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#pragma once
#if __has_include(<thrift/compiler/test/fixtures/py3/gen-py3cpp/SimpleService.h>)
#include <thrift/compiler/test/fixtures/py3/gen-py3cpp/SimpleService.h>
#else
#include <thrift/compiler/test/fixtures/py3/gen-py3cpp/module_handlers.h>
#endif
#if __has_include(<thrift/compiler/test/fixtures/py3/gen-py3cpp/DerivedService.h>)
#include <thrift/compiler/test/fixtures/py3/gen-py3cpp/DerivedService.h>
#else
#include <thrift/compiler/test/fixtures/py3/gen-py3cpp/module_handlers.h>
#endif
#if __has_include(<thrift/compiler/test/fixtures/py3/gen-py3cpp/RederivedService.h>)
#include <thrift/compiler/test/fixtures/py3/gen-py3cpp/RederivedService.h>
#else
#include <thrift/compiler/test/fixtures/py3/gen-py3cpp/module_handlers.h>
#endif
#include <folly/python/futures.h>
#include <Python.h>

#include <memory>

namespace py3 {
namespace simple {

class SimpleServiceWrapper : virtual public SimpleServiceSvIf {
  protected:
    PyObject *if_object;
    folly::Executor *executor;
  public:
    explicit SimpleServiceWrapper(PyObject *if_object, folly::Executor *exc);
    void async_tm_get_five(apache::thrift::HandlerCallbackPtr<int32_t> callback) override;
    void async_tm_add_five(apache::thrift::HandlerCallbackPtr<int32_t> callback
        , int32_t num
    ) override;
    void async_tm_do_nothing(apache::thrift::HandlerCallbackPtr<void> callback) override;
    void async_tm_concat(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::string>> callback
        , std::unique_ptr<std::string> first
        , std::unique_ptr<std::string> second
    ) override;
    void async_tm_get_value(apache::thrift::HandlerCallbackPtr<int32_t> callback
        , std::unique_ptr<::py3::simple::SimpleStruct> simple_struct
    ) override;
    void async_tm_negate(apache::thrift::HandlerCallbackPtr<bool> callback
        , bool input
    ) override;
    void async_tm_tiny(apache::thrift::HandlerCallbackPtr<int8_t> callback
        , int8_t input
    ) override;
    void async_tm_small(apache::thrift::HandlerCallbackPtr<int16_t> callback
        , int16_t input
    ) override;
    void async_tm_big(apache::thrift::HandlerCallbackPtr<int64_t> callback
        , int64_t input
    ) override;
    void async_tm_two(apache::thrift::HandlerCallbackPtr<double> callback
        , double input
    ) override;
    void async_tm_expected_exception(apache::thrift::HandlerCallbackPtr<void> callback) override;
    void async_tm_unexpected_exception(apache::thrift::HandlerCallbackPtr<int32_t> callback) override;
    void async_tm_sum_i16_list(apache::thrift::HandlerCallbackPtr<int32_t> callback
        , std::unique_ptr<std::vector<int16_t>> numbers
    ) override;
    void async_tm_sum_i32_list(apache::thrift::HandlerCallbackPtr<int32_t> callback
        , std::unique_ptr<std::vector<int32_t>> numbers
    ) override;
    void async_tm_sum_i64_list(apache::thrift::HandlerCallbackPtr<int32_t> callback
        , std::unique_ptr<std::vector<int64_t>> numbers
    ) override;
    void async_tm_concat_many(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::string>> callback
        , std::unique_ptr<std::vector<std::string>> words
    ) override;
    void async_tm_count_structs(apache::thrift::HandlerCallbackPtr<int32_t> callback
        , std::unique_ptr<std::vector<::py3::simple::SimpleStruct>> items
    ) override;
    void async_tm_sum_set(apache::thrift::HandlerCallbackPtr<int32_t> callback
        , std::unique_ptr<std::set<int32_t>> numbers
    ) override;
    void async_tm_contains_word(apache::thrift::HandlerCallbackPtr<bool> callback
        , std::unique_ptr<std::set<std::string>> words
        , std::unique_ptr<std::string> word
    ) override;
    void async_tm_get_map_value(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::string>> callback
        , std::unique_ptr<std::map<std::string,std::string>> words
        , std::unique_ptr<std::string> key
    ) override;
    void async_tm_map_length(apache::thrift::HandlerCallbackPtr<int16_t> callback
        , std::unique_ptr<std::map<std::string,::py3::simple::SimpleStruct>> items
    ) override;
    void async_tm_sum_map_values(apache::thrift::HandlerCallbackPtr<int16_t> callback
        , std::unique_ptr<std::map<std::string,int16_t>> items
    ) override;
    void async_tm_complex_sum_i32(apache::thrift::HandlerCallbackPtr<int32_t> callback
        , std::unique_ptr<::py3::simple::ComplexStruct> counter
    ) override;
    void async_tm_repeat_name(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::string>> callback
        , std::unique_ptr<::py3::simple::ComplexStruct> counter
    ) override;
    void async_tm_get_struct(apache::thrift::HandlerCallbackPtr<std::unique_ptr<::py3::simple::SimpleStruct>> callback) override;
    void async_tm_fib(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::vector<int32_t>>> callback
        , int16_t n
    ) override;
    void async_tm_unique_words(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::set<std::string>>> callback
        , std::unique_ptr<std::vector<std::string>> words
    ) override;
    void async_tm_words_count(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::map<std::string,int16_t>>> callback
        , std::unique_ptr<std::vector<std::string>> words
    ) override;
    void async_tm_set_enum(apache::thrift::HandlerCallbackPtr<::py3::simple::AnEnum> callback
        , ::py3::simple::AnEnum in_enum
    ) override;
    void async_tm_list_of_lists(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::vector<std::vector<int32_t>>>> callback
        , int16_t num_lists
        , int16_t num_items
    ) override;
    void async_tm_word_character_frequency(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::map<std::string,std::map<std::string,int32_t>>>> callback
        , std::unique_ptr<std::string> sentence
    ) override;
    void async_tm_list_of_sets(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::vector<std::set<std::string>>>> callback
        , std::unique_ptr<std::string> some_words
    ) override;
    void async_tm_nested_map_argument(apache::thrift::HandlerCallbackPtr<int32_t> callback
        , std::unique_ptr<std::map<std::string,std::vector<::py3::simple::SimpleStruct>>> struct_map
    ) override;
    void async_tm_make_sentence(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::string>> callback
        , std::unique_ptr<std::vector<std::vector<std::string>>> word_chars
    ) override;
    void async_tm_get_union(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::set<int32_t>>> callback
        , std::unique_ptr<std::vector<std::set<int32_t>>> sets
    ) override;
    void async_tm_get_keys(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::set<std::string>>> callback
        , std::unique_ptr<std::vector<std::map<std::string,std::string>>> string_map
    ) override;
    void async_tm_lookup_double(apache::thrift::HandlerCallbackPtr<double> callback
        , int32_t key
    ) override;
    void async_tm_retrieve_binary(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::string>> callback
        , std::unique_ptr<std::string> something
    ) override;
    void async_tm_contain_binary(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::set<std::string>>> callback
        , std::unique_ptr<std::vector<std::string>> binaries
    ) override;
    void async_tm_contain_enum(apache::thrift::HandlerCallbackPtr<std::unique_ptr<std::vector<::py3::simple::AnEnum>>> callback
        , std::unique_ptr<std::vector<::py3::simple::AnEnum>> the_enum
    ) override;
    void async_tm_get_binary_union_struct(apache::thrift::HandlerCallbackPtr<std::unique_ptr<::py3::simple::BinaryUnionStruct>> callback
        , std::unique_ptr<::py3::simple::BinaryUnion> u
    ) override;
folly::SemiFuture<folly::Unit> semifuture_onStartServing() override;
folly::SemiFuture<folly::Unit> semifuture_onStopRequested() override;
};

std::shared_ptr<apache::thrift::ServerInterface> SimpleServiceInterface(PyObject *if_object, folly::Executor *exc);


class DerivedServiceWrapper : public ::py3::simple::SimpleServiceWrapper, virtual public DerivedServiceSvIf {
  public:
    explicit DerivedServiceWrapper(PyObject *if_object, folly::Executor *exc);
    void async_tm_get_six(apache::thrift::HandlerCallbackPtr<int32_t> callback) override;
folly::SemiFuture<folly::Unit> semifuture_onStartServing() override;
folly::SemiFuture<folly::Unit> semifuture_onStopRequested() override;
};

std::shared_ptr<apache::thrift::ServerInterface> DerivedServiceInterface(PyObject *if_object, folly::Executor *exc);


class RederivedServiceWrapper : public ::py3::simple::DerivedServiceWrapper, virtual public RederivedServiceSvIf {
  public:
    explicit RederivedServiceWrapper(PyObject *if_object, folly::Executor *exc);
    void async_tm_get_seven(apache::thrift::HandlerCallbackPtr<int32_t> callback) override;
folly::SemiFuture<folly::Unit> semifuture_onStartServing() override;
folly::SemiFuture<folly::Unit> semifuture_onStopRequested() override;
};

std::shared_ptr<apache::thrift::ServerInterface> RederivedServiceInterface(PyObject *if_object, folly::Executor *exc);
} // namespace py3
} // namespace simple
