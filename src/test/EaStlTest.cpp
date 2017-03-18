#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GTestColorPrint.h"
#include "../eastl/type_traits.h"


using std::string;
// using namespace eastl;
TEST(EaStlTest, TrueAndFalseType)
{
    EXPECT_TRUE(eastl::true_type::value == true);
    EXPECT_FALSE(eastl::false_type::value == true);
}

class Base
{
public:
    typedef int wrapped_iterator_type;
};

template <typename T, T v>
struct cpp_integral_constant {
    static const T value = v;
    typedef T value_type;
    typedef cpp_integral_constant<T, v> type;
};

// template <typename T, T v>
// const T cpp_integral_constant<T, v>::value;

template <typename T>
struct cpp_is_class : public cpp_integral_constant<bool, __is_class(T)> {};

template<bool B, typename T = void>
struct cpp_enable_if {};

template <typename T>
struct cpp_enable_if<true, T> {
    typedef T type;
};

template<typename>
static eastl::no_type cpp_test(...);

template<typename U>
static eastl::yes_type cpp_test(typename U::wrapped_iterator_type *, typename eastl::enable_if<cpp_is_class<U>::value>::type * = 0);

TEST(EaStlTest, EnableIf)
{
    EXPECT_TRUE(cpp_is_class<Base>::value == true);
    EXPECT_TRUE(cpp_is_class<int>::value == false);

    typename eastl::enable_if<cpp_is_class<Base>::value>::type *tmp = 0;
    (void)tmp;
    // typename eastl::enable_if<cpp_is_class<int>::value>::type * tmp1 = 0;
    // (void)tmp1;

    cpp_enable_if<true>::type *tmp1;
    (void)tmp1;
    // cpp_enable_if<false>::type* tmp2;
    // (void)tmp2;

    bool value = (sizeof(cpp_test<Base>(NULL)) == sizeof(eastl::yes_type));
    EXPECT_TRUE(value == true);
}

template<typename Iterator>
class is_iterator_wrapper
{
    template<typename>
    static eastl::no_type test(...);

    template<typename U>
    static eastl::yes_type test(typename U::wrapped_iterator_type *, typename eastl::enable_if<cpp_is_class<U>::value>::type * = 0);

public:
    // EA_DISABLE_VC_WARNING(6334)
    static const bool value = (sizeof(test<Iterator>(NULL)) == sizeof(eastl::yes_type));
    // EA_RESTORE_VC_WARNING()
};

// template <typename Iterator>
class cpp_generic_iterator
{
public:
    typedef int                                                wrapped_iterator_type;   // This is not in the C++ Standard; it's used by use to identify it as a wrapping iterator type.
}; // class generic_iterator


char functionReturnChar();
int functionReturnInt();
TEST(EaStlTest, SizeOfFunction)
{
    EXPECT_EQ(sizeof(functionReturnChar()), sizeof(char));
    EXPECT_EQ(sizeof(functionReturnInt()), sizeof(int));
    // GCOUT << is_iterator_wrapper<Base>::value << std::endl;
    // GCOUT << is_iterator_wrapper<cpp_generic_iterator>::value << std::endl;
}

template <typename T> struct cpp_is_const_value                    : public eastl::false_type {};
template <typename T> struct cpp_is_const_value<const T *>          : public eastl::true_type {};
template <typename T> struct cpp_is_const_value<const volatile T *> : public eastl::true_type {};

template <typename T> struct cpp_is_const : public eastl::is_const_value<T *>
{
    string fun()
    {
        return "cpp_is_const";
    }
};

template <typename T> struct cpp_is_const<T &> : public eastl::false_type
{
    string fun()
    {
        return "cpp_is_const<T &>";
    }
};

TEST(EastlTest, IsConst)
{
    EXPECT_TRUE(cpp_is_const<const int>::value == true);
    EXPECT_TRUE(cpp_is_const<int>::value == false);
    EXPECT_TRUE(cpp_is_const_value<const int>::value == false);
    EXPECT_TRUE(cpp_is_const_value<int>::value == false);

    EXPECT_TRUE(cpp_is_const<const int*>::value == false);
    EXPECT_TRUE(cpp_is_const<int*>::value == false);
    EXPECT_TRUE(cpp_is_const_value<const int*>::value == true);
    EXPECT_TRUE(cpp_is_const_value<int*>::value == false);

    EXPECT_TRUE(cpp_is_const<int* const>::value == true);
    EXPECT_TRUE(cpp_is_const_value<int* const>::value == false);

    EXPECT_TRUE(cpp_is_const<const int&>::value == false);
    EXPECT_TRUE(cpp_is_const<int&>::value == false);
    EXPECT_TRUE(cpp_is_const_value<int&>::value == false);
    EXPECT_TRUE(cpp_is_const_value<const int&>::value == false);

    // cpp_is_const<int&> ref;
    // EXPECT_EQ(ref.fun(), "cpp_is_const");
    // cpp_is_const<const int&> constRef;
    // EXPECT_EQ(constRef.fun(), "cpp_is_const<T &>");

}

// template <typename T> struct is_reference     : public eastl::false_type {};
// template <typename T> struct is_reference<T &> : public eastl::true_type {};







