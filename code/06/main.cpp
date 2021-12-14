/*
 * @Author: chen
 * @Date: 2021-12-12 21:15:11
 * @LastEditors: chen
 * @LastEditTime: 2021-12-14 22:06:01
 * @FilePath: /cpptemplate/code/06/main.cpp
 */
#include <iostream>
#include <utility>
#include <string>
#include <typeinfo>
#include <type_traits>

template <typename T>
using EnableIfString = std::enable_if_t<std::is_convertible_v<T, std::string>>;

namespace case1
{

    class Person
    {
    private:
        std::string name;

    public:
        template <typename T, typename = std::enable_if_t<std::is_convertible_v<T, std::string>>>
       // template<typename T>
       // requires std::is_convertible_v<T,std::string>
        explicit Person(T &&n) : name(std::forward<T>(n))
        {
            std::cout << typeid(T).name() << std::endl;
            std::cout << "Template-CONSTR for " << name << std::endl;
        }
        Person(const Person &p) : name(p.name)
        {
            std::cout << "Copy-CONSTR Person " << name << std::endl;
        }
        Person(Person &&p) : name(std::move(p.name))
        {
            std::cout << "Move-CONSTR Person " << name << std::endl;
        }
    };

    void test()
    {
        std::string s = "chen";
        Person p1(s);
        Person p2("temp");
        Person p3(p1); // error
        Person p4(std::move(p1));
        Person const p2c("ctmmp");
        Person p5(p2c);
    }

}

namespace case2
{
    template<typename T>
    class C
    {
        public:
            C(C const volatile &)=delete;
            C()=default;
            template<typename U,
            typename= std::enable_if_t<!std::is_integral<T>::value>>
            C(C<U> const &)
            {
                std::cout<<"template copy constructor"<<std::endl;
            }
    };

    void test()
    {
        C<double> c1;
       
        C<double> c2{c1};
    }
}

int main()
{
    case1::test();
    return 0;
}