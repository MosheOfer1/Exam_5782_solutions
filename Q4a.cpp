#include <iostream>
#include <vector>

template <typename T, typename Functor>
int count_if(const std::vector<T> &vec, Functor functor)
{
    int count = 0;
    for (const T &item : vec)
    {
        if (functor(item))
        {
            count++;
        }
    }
    return count;
}

struct GreaterThan
{
    int threshold;

    GreaterThan(int threshold) : threshold(threshold) {}

    bool operator()(int value)
    {
        return value > threshold;
    }
};

int main()
{
    std::vector<int> numbers = {10, 20, 30, 40, 50};
    GreaterThan gt(30);
    int result = count_if(numbers, gt);
    std::cout << "Count: " << result << std::endl; // Output: Count: 2

    return 0;
}
