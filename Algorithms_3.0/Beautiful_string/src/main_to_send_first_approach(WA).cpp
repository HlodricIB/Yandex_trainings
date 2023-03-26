#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cstdio>
#include <chrono>

class Counter
{
private:
    int k;
    int current_max{0};
public:
    Counter(int k_): k(k_) { }
    int operator()(std::vector<std::pair<int, int>>& vector)
    {
        return std::max<int>(from_back(vector), from_front(vector));
    }
    int from_front(std::vector<std::pair<int, int>>& vector)
        {
            using v_size_type = std::vector<std::pair<int, int>>::size_type;
            current_max = 0;
            int k_left{0}, diff{0}, prev_amount{0}, prev_position{0}, curr_max{0};
            v_size_type i{0};
            for (v_size_type outer_i = 0; outer_i != vector.size(); ++outer_i)
            {
                k_left = k;
                i = outer_i;
                prev_amount = vector[i].first;
                prev_position = vector[i].second;
                curr_max = prev_amount;
                ++i;
                while (i != vector.size())
                {
                    diff = vector[i].second - (prev_amount + prev_position);
                    if (diff <= k_left)
                    {
                        curr_max += diff + vector[i].first;
                        k_left -= diff;
                    }
                    prev_amount = vector[i].first;
                    prev_position = vector[i].second;
                    ++i;
                    if (diff > k_left)
                    {
                        break;
                    }
                }
                curr_max += k_left;
                current_max = std::max<int>(current_max, curr_max);
            }
            return current_max;
        }
    int from_back(std::vector<std::pair<int, int>>& vector)
        {
            current_max = 0;
            int k_left{0}, diff{0}, prev_amount{0}, prev_position{0}, curr_max{0}, next_amount{0}, next_position{0};
            int i{0};
            for (int outer_i = vector.size() - 1; outer_i >= 0; --outer_i)
            {
                k_left = k;
                i = outer_i;
                prev_amount = vector[i].first;
                prev_position = vector[i].second;
                curr_max = prev_amount;
                --i;
                next_amount = vector[i].first;
                next_position = vector[i].second;
                while (i >= 0)
                {
                    diff = prev_position - (next_amount + next_position);
                    if (diff <= k_left)
                    {
                        curr_max += diff + next_amount;
                        k_left -= diff;
                    }
                    prev_position = next_position;
                    --i;
                    next_amount = vector[i].first;
                    next_position = vector[i].second;
                    if (diff > k_left)
                    {
                        break;
                    }
                }
                curr_max += k_left;
                current_max = std::max<int>(current_max, curr_max);
            }
            return current_max;
        }
};

int fill_map(std::unordered_map<char, std::vector<std::pair<int, int>>>& chars_map)
{
    using vector_pair = std::vector<std::pair<int, int>>;   //Amount of consequent chars, position of char
    char c, prev_c;
    std::unordered_map<char, vector_pair>::iterator chars_map_iter;
    std::cin >> prev_c;
    int count{0};
    chars_map.emplace(prev_c, vector_pair{std::make_pair(1, count)});
    for (c = std::cin.get(); c != '\n'; c = std::cin.get())
    {
        ++count;
        if (c == prev_c)
        {
            ++chars_map[c].back().first;
        } else {
            prev_c = c;
            chars_map_iter = chars_map.find(c);
            if (chars_map_iter == chars_map.end())
            {
                chars_map.emplace(c, vector_pair{std::make_pair(1, count)});
            } else {
                auto& curr_vec = chars_map_iter->second;
                curr_vec.emplace_back(std::make_pair(1, count));
            }
        }
    }
    return count;
}

int main()
{
    int k;
    std::cin >> k;
    if (k < 0)
    {
        k = 0;
    }
    std::cin.get();
    using vector_pair = std::vector<std::pair<int, int>>;   //Amount of consequent chars, position of char
    std::unordered_map<char, vector_pair> chars_map;
    int ans{1};
    auto count = fill_map(chars_map);
    ++count;
    if (k >= count)
    {
        ans = count;
    } else {
        Counter counter{k};
        for (auto& i : chars_map)
        {
            ans = std::max<int>(ans, counter(i.second));
        }
        ans = std::min<int>(ans, count);
    }
    std::cout << ans << std::endl;
    return 0;
}
