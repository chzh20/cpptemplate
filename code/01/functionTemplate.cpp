/*
 * @Author: chen
 * @Date: 2021-12-05 18:40:55
 * @LastEditors: chen
 * @LastEditTime: 2021-12-05 22:52:07
 * @FilePath: /cpptemplate/code/01/functionTemplate.cpp
 */

#include <iostream>
#include <type_traits>
#include <string>
#include<cstring>

namespace FT_00
{

    template <typename T>
    T max(T a, T b)
    {
        return b < a ? a : b;
    }

    template <typename T>
    T max_1(T const &a, T const &b)
    {

        return b < a ? b : a;
    }

    void test()
    {
        std::cout << max(1, 2) << std::endl;
        std::cout << max("hello", "world") << std::endl;
    }

}

namespace FT_01
{
    template <typename T>
    T max(T a, T b)
    {
        std::cout << "is int: " << std::is_integral<decltype(a)>::value << std::endl;
        std::cout << "is const: " << std::is_const<decltype(a)>::value << std::endl;
        std::cout << "is pointer" << std::is_pointer<decltype(a)>::value << std::endl;
        std::cout << std::endl;
        return b < a ? a : b;
    }

    void test()
    {
        int const c = 42;
        int i = 1;
        max(i, c);
        max(c, c);

        int &ri = i;
        max(i, ri);

        int arr[4] = {2, 1, 3, 4};
        max(&i, arr);

        max(1.2, static_cast<double>(2));
        std::string s{"one"};
        //max("two",s);//error:
    }
}

namespace FT_02
{
    template <typename T1, typename T2, typename RT>
    RT max(T1 a, T2 b)
    {
        return b < a ? a : b;
    }

    template <typename T1, typename T2>
    auto max_1(T1 a, T2 b)
    {
        return b < a ? a : b;
    }

    template <typename T1, typename T2>
    std::common_type_t<T1, T2> max_2(T1 a, T2 b)
    {
        return b < a ? a : b;
    }

    void test()
    {
        std::cout << max<int, double, double>(1, 2.3) << std::endl;
        std::cout << max_1(1, 3.3) << std::endl;
        std::cout << max_2(2.3, 1) << std::endl;
    }

}

//Default Template Arguments
namespace FT_03
{
    template <typename T1, typename T2, typename RT = std::decay_t<decltype(true ? T1() : T2())>>
    RT max(T1 a, T2 b)
    {
        return b < a ? a : b;
    }

    template <typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
    RT max_1(T1 a, T2 b)
    {
        return b < a ? a : b;
    }

    void test()
    {
        std::cout << max(1, 3.3) << std::endl;
        std::cout << max_1(1, 2.5) << std::endl;
    }

}

namespace FT_04
{

// maximum of two values of any type:
template<typename T>
T max (T a, T b)
{
  return  b < a ? a : b;
}

// maximum of two pointers:
template<typename T>
T* max (T* a, T* b)
{
  return  *b < *a  ? a : b;
}

// maximum of two C-strings:
char const* max (char const* a, char const* b)
{
    return  std::strcmp(b,a) < 0  ? a : b;
}



    void test()
    {
        int a=1;
        int b=2;
        std::cout<<max(a,b)<<std::endl;


    
       std::string s1 = "hey";
       std::string s2 = "you";
       max(s1,s2);

        const char * s3 ="one";
        const char * s4="two";
        std::cout<<max(s3,s4)<<std::endl;

    }

}

int main()
{
    FT_03::test();
    return 0;
}