#include <iostream>
#include <algorithm>
#include <vector>

bool is_digit(char ch)
{
    return std::isdigit(static_cast<unsigned char>(ch));
}

int main()
{
    std::string input;
    std::vector<int> digits;
    std::getline(std::cin, input);
    std::string temp_s;
    for (std::string::size_type i = 0; i != input.size(); ++i)
    {
        while (input[i] == '-' || is_digit(input[i]))
        {
            temp_s.push_back(input[i]);
            ++i;
        }
        if (!temp_s.empty())
        {
            digits.push_back(std::stoi(temp_s));
            temp_s.clear();
        }
    }
    std::sort(digits.begin(), digits.end());
    std::vector<int> counts;
    counts.reserve(input.size() - 1);
    int count;
    for (auto c : digits)
    {
        count = std::count(digits.begin(), digits.end(), c);
        counts.push_back(count);
    }
    auto max_iter = std::max_element(counts.begin(), counts.end());
    auto max_c = *max_iter;
    char temp{'a'};
    for (std::vector<int>::size_type i = 0; i != counts.size(); ++i)
    {
        if (counts[i] == max_c && digits[i] != temp)
        {
            std::cout << digits[i] << ' ';
            temp = digits[i];
        }
    }
    std::cout << std::endl;
    return 0;
}
