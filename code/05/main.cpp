/*
 * @Author: chen
 * @Date: 2021-12-11 17:37:13
 * @LastEditors: chen
 * @LastEditTime: 2021-12-11 18:17:33
 * @FilePath: /cpptemplate/code/05/main.cpp
 */
#include<iostream>

namespace case1
{
    template<typename T>
    class Base
    {
        public:
        void Bar();
    };
    template<typename T>
    class Derived:Base<T>
    {
        public:
            void foo()
            {
                this->Bar();
            }

    };
    void test()
    {
        Derived<int> d;

    }
}


namespace case2
{
    template<typename T> 
    T val{};

    template<typename T>
    constexpr T Pi{3.14};
    void test()
    {
        val<int> =10;
        std::cout<<val<int><<std::endl;
        std::cout<<Pi<double><<std::endl;
        std::cout<<Pi<float><<std::endl;
    }


}

int main()
{
    case2::test();
    return 0;
}