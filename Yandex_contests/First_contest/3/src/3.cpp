#include <set>
#include <iostream>
#include <cstdint>

int main()
{
    int n{0};
    int_fast32_t input;
    std::set<int_fast32_t> numbers;
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> input;
        numbers.insert(input);
    }
    for (auto& stored : numbers)
    {
        std::cout << stored << std::endl;
    }
    return 0;
}
