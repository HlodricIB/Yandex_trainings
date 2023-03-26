#include <iostream>
#include <map>

int main()
{
    std::map<char, int> counted_sorted;
    int counter{0};
    char c;
    while (std::cin >> c)
    {
        if (c != ' ' && c != '\r')
        {
            counter = std::max<int>(counter, ++counted_sorted[c]);
        }
    }
    for (int i = counter; i != 0; --i)
    {
        for (auto& p : counted_sorted)
        {
            if (p.second < i)
            {
                std::cout << ' ' << std::flush;
            } else {
                std::cout << '#' << std::flush;
            }
        }
        std::cout << std::endl;
    }
    for (auto& p : counted_sorted)
    {
        std::cout << p.first;
    }
    std::cout << std::endl;
    return 0;
}
