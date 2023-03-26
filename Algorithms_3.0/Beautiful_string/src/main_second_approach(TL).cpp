#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cstdio>
#include <chrono>
#include <string>
#include <fstream>

int count(std::string& s, int k)
{
    using size_s = std::string::size_type;
    size_s left_border{0}, right_border{s.size()}, curr_left_border, curr_right_border, right_border_minus_one{right_border - 1};
    int ans{0}, k_temp, count;
    char c;
    bool stop_left, stop_right;
    for (size_s i = 0; i != right_border; ++i)
    {
        c = s[i];
        curr_left_border = i;
        k_temp = k;
        count = 0;
        stop_left = stop_right = false;
        while (!stop_left)
        {
            if (curr_left_border >= left_border && s[curr_left_border] == c)
            {
                ++count;
                --curr_left_border;
            } else {
                stop_left = true;
            }
        }
        curr_right_border = i;
        while (!stop_right)
        {
            if (curr_right_border != right_border_minus_one)
            {
                ++curr_right_border;
                if (s[curr_right_border] == c)
                {
                    ++count;
                } else {
                    if (k_temp > 0)
                    {
                        ++count;
                        --k_temp;
                    } else {
                        stop_right = true;
                    }
                }
            } else {
                stop_right = true;
            }
        }
        ans = std::max<int>(ans, (count + k_temp));
    }
    return std::min<int>(ans, right_border);
}

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();

int main()
{
    int k;
    std::cin >> k;
    if (k < 0)
    {
        k = 0;
    }
    std::string s;
    std::cin.ignore(max_size, '\n');
    //std::getline(std::cin, s);
    std::ifstream str("/home/nikita/Downloads/Telegram Desktop/09stringonly");
    std::getline(str, s);
    auto ans = count(s, k);
    std::cout << ans << std::endl;
    return 0;
}
