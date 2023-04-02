#include <iostream>
#include <string>
#include <map>

int main()
{
    std::string word;
    std::getline(std::cin, word);
    uint_fast32_t size = word.size(), prev = size, count;
    std::map<char, uint_fast32_t> m;
    m[word[0]] = size;
    for (uint_fast32_t i = 1; i != size; ++i)
    {
        count = size + prev - 2 * i;
        m[word[i]] += count;
        prev = count;
    }
    for (auto& p : m)
    {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    return 0;
}
