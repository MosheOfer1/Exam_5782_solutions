#include <iostream>

template <int N>
struct PrintDescending
{
    static void print()
    {
        std::cout << N << std::endl;
        PrintDescending<N - 1>::print();
    }
};

template <>
struct PrintDescending<0>
{
    static void print() {}
};

int main()
{
    PrintDescending<100>::print();
    return 0;
}
