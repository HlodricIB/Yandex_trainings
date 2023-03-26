#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cstdio>
#include <chrono>
#include <string>
#include <fstream>
#include <queue>

std::pair<int, int> input(std::unordered_map<char, std::vector<int>>& map)
{
    int k;
    std::cin >> k;
    if (k < 0)
    {
        k = 0;
    }
    static constexpr auto max_size = std::numeric_limits<std::streamsize>::max();
    std::cin.ignore(max_size, '\n');
    std::ifstream in("/home/nikita/Downloads/Telegram Desktop/08stringonly");
    //std::istream& in = std::cin;
    char c;
    int counter{0};
    for (c = in.get(); c != '\n'; c = in.get())
    {
        map[c].push_back(counter);
        ++counter;
    }
    return std::make_pair(k, counter);
}

int count(std::unordered_map<char, std::vector<int>>& map, int k, int counter)
{
    std::queue<std::pair<int, int>> jumps;  //index, difference
    std::vector<int>::size_type i;
    int k_left, prev, diff{0}, count_outer{0}, count_inner, curr_count_inner;
    for (const auto& pair : map)
    {
        const auto& vec_int = pair.second;

        if (vec_int.size() == 1)
        {
            count_inner = 1 + k;
        } else {
            while (!jumps.empty())
            {
                jumps.pop();
            }
            count_inner = 0;
            i = 0;
            k_left = k;
            prev = i;
            ++i;
            curr_count_inner = 1;
            while (i != vec_int.size())
            {
                diff = vec_int[i] - vec_int[prev] - 1;
                if (diff > k)
                {
                    count_inner = std::max<int>(count_inner, curr_count_inner + k_left);
                    curr_count_inner = 1;
                    k_left = k;
                    while (!jumps.empty())
                    {
                        jumps.pop();
                    }
                } else {
                    if (diff > 0 && diff <= k_left)
                    {
                        jumps.emplace(std::make_pair(vec_int[i], diff));
                        k_left -= diff;
                        curr_count_inner += diff + 1;
                    } else {
                        if (diff > k_left)
                        {
                            count_inner = std::max<int>(count_inner, curr_count_inner + k_left);
                            auto& p = jumps.front();
                            --i;
                            curr_count_inner = vec_int[i] - p.first + 1;
                            k_left += p.second;
                            jumps.pop();
                        } else {
                            ++curr_count_inner;
                        }
                    }
                }
                prev = i;
                ++i;
            }
            count_inner = std::max<int>(count_inner, curr_count_inner + k_left);
        }
        count_inner = std::min<int>(counter, count_inner);
        count_outer = std::max<int>(count_outer, count_inner);
    }
    return count_outer;
}

int main()
{
    std::unordered_map<char, std::vector<int>> map;
    auto p = input(map);
    auto ans = count(map, p.first, p.second);
    std::cout << ans << std::endl;
    return 0;
}
