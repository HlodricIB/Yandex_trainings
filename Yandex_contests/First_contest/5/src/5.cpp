#include <algorithm>
#include <string>
#include <iostream>

int main()
{
    std::string first, second;
    std::getline(std::cin, first);
    std::getline(std::cin, second);
    if (first.size() > 100000 || second.size() > 100000)
    {
        return 0;
    }
    if ((first.empty() && second.empty()))
    {
        std::cout << 1 << std::endl;
    }
    if (first.size() != second.size())
    {
        std::cout << 0 << std::endl;
    } else {
        std::sort(first.begin(), first.end());
        std::sort(second.begin(), second.end());
        if (first == second)
        {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    return 0;
}
