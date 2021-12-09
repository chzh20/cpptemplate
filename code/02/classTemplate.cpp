/*
 * @Author: chen
 * @Date: 2021-12-06 20:24:55
 * @LastEditors: chen
 * @LastEditTime: 2021-12-06 22:09:53
 * @FilePath: /cpptemplate/code/02/classTemplate.cpp
 */
#include <iostream>
#include<cassert>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> contianer;

public:
    Stack();
    Stack(const Stack<T> &);
    Stack<T> &operator=(const Stack<T> &);
    void push(const T &);
    void pop();
    const T &top() const;
    bool empty() const;

    void printon(std::ostream &os) const;
    
    template<typename U>
    friend std::ostream&  operator<<(std::ostream &os,const Stack<U>& s);
   

};


template<typename U>
std::ostream& operator<<(std::ostream &os, const Stack<U> &s)
{
    s.printon(os);
    return os;
}


template<typename T> 
void Stack<T>::printon(std::ostream &os)const
{
    for(const  T& v: contianer) 
             os<<v<<" ";
}



template<typename T>
Stack<T>::Stack()
{

}

template<typename T>
Stack<T>::Stack(const Stack<T> &rhs):contianer(rhs.contianer)
{
    ;
}

template<typename T>
void Stack<T>::push(const T &v)
{
        contianer.push_back(v);
}

template<typename T>
void Stack<T>::pop()
{
    assert(!contianer.empty());
    contianer.pop_back();

}

template<typename T>
const T & Stack<T>::top() const
{
    assert(!contianer.empty());
    return    contianer.back();
}
template<typename T>
bool Stack<T>::empty()const
{
    return contianer.empty();
}


namespace  CT_00
{

    void test()
    {
        Stack<int>  StackInt;
        for(int i=0;i<5;++i)
             StackInt.push(i);
        std::cout<<StackInt<<std::endl;

        Stack StackInt3=StackInt;
    }

}


namespace CT_01
{
    template<typename T>
    struct A
    {
        /* data */
        T x;
        std::string s;
    };

    A(const char *, const char *)->A<std::string>;

    void test()
    {
        A a={"hei","word"};
        std::cout<<a.x<<std::endl;
    }
    
    
}


int main()
{

    CT_01::test();
    return 0;
}