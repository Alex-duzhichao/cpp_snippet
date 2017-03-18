#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using std::string;
template<typename T>
class Bar
{

};

template<typename T>
class Foo
{
public:
    std::string fun()
    {
        return "Foo";
    }
};

template<>
class Foo<int>
{
public:
    std::string fun()
    {
        return "Foo int";
    }
};

template<>
class Foo<const int>
{
public:
    std::string fun()
    {
        return "Foo const int";
    }
};

template<>
class Foo<float>
{
public:
    std::string fun()
    {
        return "Foo float";
    }
};

// template<>
// class Foo<const float>
// {
// public:
// std::string fun()
// {
// return "Foo const float";
// }
// };

template<typename T>
class Foo<Bar<T> >
{
public:
    std::string fun()
    {
        return "Foo Bar";
    }
};

template<typename T>
std::string fun(T)
{
    return "fun";
}

template<>
std::string fun<int>(int)
{
    return "fun int";
}

template<>
std::string fun(double)
{
    return "fun double";
}

// function template partial specialization ‘fun<Bar<T> >’ is not allowed
// std::string fun<Bar<T> >(Bar<T>)    //特化
template<typename T>
std::string fun(Bar<T>)    //重载
{
    return "fun Bar";
}

TEST(TemplateTest, ClassPartialSpecialization)
{
    Foo<int> fi;
    Foo<const int> fci;
    Foo<double> fd;
    Foo<float> fl;
    Foo<const float> fcl;
    Foo<Bar<int> > fb;
    EXPECT_EQ(fi.fun(), "Foo int");
    EXPECT_EQ(fci.fun(), "Foo const int");
    EXPECT_EQ(fd.fun(), "Foo");
    EXPECT_EQ(fl.fun(), "Foo float");
    EXPECT_EQ(fcl.fun(), "Foo");
    EXPECT_EQ(fb.fun(), "Foo Bar");
}

TEST(TemplateTest, FunctionPartialSpecialization)
{
    EXPECT_EQ(fun(int(1)), "fun int");
    // EXPECT_EQ(fun(1), "fun int");
    // EXPECT_EQ(fun(double(1.0)), "fun double");
    EXPECT_EQ(fun(1.0), "fun double");
    EXPECT_EQ(fun(float(1.0)), "fun");
    // EXPECT_EQ(fun(1.0), "fun");

    Bar<int> tmp;
    EXPECT_EQ(fun(tmp), "fun Bar");
}


void Function(int &num)
{
    num *= 2;
}

class Functor
{
public:
    void operator() (int &num)
    {
        num *= 2;
    }
}; // class Functor

template<typename T>    //重载
std::string fun(T *)
{
    return "fun pointer";
}

TEST(TemplateTest, FunctionAndFuntor)
{
    EXPECT_EQ(fun(Function), "fun pointer");
    EXPECT_EQ(fun(Functor()), "fun");
}

template<typename T>
class Base
{
public:
    std::string baseFun()
    {
        return "baseFun";
    }

}; // class Base

template<typename T>
class Derive : public Base<T>
{
public:
    std::string deriveFun()
    {
        this->baseFun();
        // baseFun();
        return "deriveFun";
    }
}; // class Derive : public Base<T>

template<typename T>
class Rational
{
public:
    Rational(const T &num = 0) {};
    // template<typename U>
    // friend const Rational<U> operator* (const Rational<U>& lhs, const Rational<U>& rhs)
    // http://stackoverflow.com/questions/9787593/c-implicit-type-conversion-with-template
    friend const Rational operator* (const Rational &lhs, const Rational &rhs)
    {
        return Rational();
    }
}; // class Rational

// template<typename U>
// const Rational<U> operator* (const Rational<U>& lhs, const Rational<U>& rhs)
// {
// return Rational<U>();
// }

TEST(TemplateTest, NonMemberConversion)
{
    Rational<int> oneHalf(1);
    Rational<int> result = oneHalf * 2;
    (void) result;
}

string normalFun(int)
{
    return "normalFun int" ;
}

//top-level const qualifier
//http://stackoverflow.com/questions/7914444/what-are-top-level-const-qualifiers
//Top-level const doesn't influence a function signature
//http://stackoverflow.com/questions/17208570/top-level-const-doesnt-influence-a-function-signature
//A top-level const qualifier affects the object itself. Others are only relevant with pointers and references
// string normalFun(const int)
// {
    // return "normalFun const int" ;
// }

string normalFun(int &)
{
    return "normalFun int&" ;
}

// string normalFun(const int&)
// {
    // return "normalFun const int&" ;
// }

TEST(TemplateTest, NormalFun)
{
    // int i = 0;
    // int& ri = i;
    // const int ci = 0;
    // const int& cri = 0;
    // EXPECT_EQ(normalFun(0), "normalFun int");
    // EXPECT_EQ(normalFun(i), "normalFun int");
    // EXPECT_EQ(normalFun(ri), "normalFun int");
    // EXPECT_EQ(normalFun(ci), "normalFun int");
    // EXPECT_EQ(normalFun(cri), "normalFun int");

    // EXPECT_EQ(normalFun(i), "normalFun const int");
    // EXPECT_EQ(normalFun(ci), "normalFun const int");
    // EXPECT_EQ(normalFun(i), "normalFun const int");
    // EXPECT_EQ(normalFun(ci), "normalFun const int");

    // EXPECT_EQ(normalFun(i), "normalFun int&");
    // EXPECT_EQ(normalFun(ci), "normalFun const int&");
    // EXPECT_EQ(normalFun(ri), "normalFun int&");
    // EXPECT_EQ(normalFun(cri), "normalFun const int&");
}

string print(int i)
{
     return "print int";
}

// string print(short i)
// {
     // return "print short";
// }

string print(long i)
{
     return "print long";
}

string print(long long i)
{
     return "print long long";
}

string print(double i)
{
     return "print double";
}

TEST(TemplateTest, Print)
{
    char c;
    short s;
    int i;
    // unsigned int ui;
    long l;
    double d;

    EXPECT_EQ(print(c), "print int");
    EXPECT_EQ(print(s), "print int");    //Integral promotion https://zh.wikipedia.org/wiki/%E6%95%B4%E5%9E%8B%E6%8F%90%E5%8D%87
    EXPECT_EQ(print(i), "print int");
    // EXPECT_EQ(print(ui), "print int");    //call of overloaded ‘print(unsigned int&)’ is ambiguous
    EXPECT_EQ(print(l), "print long");
    EXPECT_EQ(print(d), "print double");
}




