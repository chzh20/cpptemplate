/*
 * @Author: chen
 * @Date: 2021-12-07 20:39:47
 * @LastEditors: chen
 * @LastEditTime: 2021-12-07 21:07:01
 * @FilePath: /cpptemplate/code/03/nontype.cpp
 */
#include <iostream>
#include <array>
#include<vector>
#include <cassert>
#include<algorithm>
using namespace std;

namespace case1
{
    template <typename T, size_t maxSize>
    class Stack
    {
    private:
        std::array<T, maxSize> container;
        size_t size;

    public:
        Stack();
        void push(const T &e);
        void pop();
        const T &top() const;
        bool empty() const { return size == 0; }
    };

    template <typename T, size_t maxSize>
    Stack<T, maxSize>::Stack() : size(0)
    {
    }

    template <typename T, size_t maxSize>
    void Stack<T, maxSize>::push(const T &e)
    {
        if (size < container.size())
            container[size++] = e;
    }

    template <typename T, size_t maxSize>
    void Stack<T, maxSize>::pop()
    {
        if (size > 0)
            size--;
    }
    template <typename T, size_t maxSize>
    const T &Stack<T, maxSize>::top() const
    {
        assert(!empty());
        return container[size - 1];
    }

    void test()
    {
        Stack<int, 20> S1;
        Stack<int, 30> S2;

        S1.push(1);
        S1.push(3);
        S2.push(2);
        std::cout << S2.top() << std::endl;
        std::cout << S1.top() << std::endl;
    }
}

namespace case2
{
    template <int N, typename T>
    T addValue(T x)
    {
        return x + N;
    }

    void test()
    {
        std::vector<int>  v1{1,2,34,5};
        std::vector<int> v2;
        v2.resize(v1.size());
        std::transform(v1.begin(),v1.end(),v2.begin(),addValue<3,int>);

        for(auto v: v2)
            std::cout<<v<<" ";
    }
}

int main()
{

    case2::test();
    return 0;
}
