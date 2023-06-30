#include <iostream>

class greater_than_n
{
private:
    int n;

public:
    greater_than_n(int n) : n(n) {}

    bool operator()(int value)
    {
        return value > n;
    }
};

int main()
{
    greater_than_n g(100);
    std::cout << std::boolalpha;
    std::cout << g(50) << std::endl;  // false
    std::cout << g(150) << std::endl; // true

    return 0;
}
