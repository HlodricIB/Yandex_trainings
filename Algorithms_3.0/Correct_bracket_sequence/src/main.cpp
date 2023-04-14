#include <iostream>
#include <stack>
#include <unordered_map>
#include <string_view>
#include <vector>

using v_counter = std::vector<int_fast32_t>;

enum : v_counter::size_type
{
    MOST_OUTER = 0,
    OUTER = 1,
    INNER = 2
};

bool update(v_counter& counter, std::string_view key, int_fast32_t a)
{
    static std::unordered_map<std::string_view, int_fast8_t> m{ {"square", -1}, {"round", -1}, {"brace", -1}};
    static v_counter::size_type p = MOST_OUTER;
    auto i = m.find(key);
    auto& curr_counter_index = i->second;
    if (curr_counter_index < 0)
    {
        curr_counter_index = p;
        ++p;
    }
    counter[curr_counter_index] += a;
    auto curr_counter = counter[curr_counter_index];
    if (curr_counter < 0)
    {
        return false;
    } else {
        if (curr_counter == 0)
        {
            if (p != 3 && counter[curr_counter_index + 1] != 0)
            {
                return false;
            } else {
                --p;
                curr_counter_index = -1;
            }
        }
    }
    return true;
}

int main()
{
    std::stack<char> s;
    char c;
    std::cin.get(c);
    while (c != '\n')
    {
        s.push(c);
        std::cin.get(c);
    }
    bool if_continue = true;
    v_counter counter(3, 0);
    char curr_char;
    while (if_continue && static_cast<bool>(s.size()))
    {
        curr_char = s.top();
        s.pop();
        switch (curr_char)
        {
        case ']':
            if_continue = update(counter, std::string_view{"square"}, 1);
            break;
        case '[':
            if_continue = update(counter, std::string_view{"square"}, -1);
            break;
        case ')':
            if_continue = update(counter, std::string_view{"round"}, 1);
            break;
        case '(':
            if_continue = update(counter, std::string_view{"round"}, -1);
            break;
        case '}':
            if_continue = update(counter, std::string_view{"brace"}, 1);
            break;
        case '{':
            if_continue = update(counter, std::string_view{"brace"}, -1);
            break;
        default:
            if_continue = false;
            break;
        }
    }
    std::string_view ans;
    if (counter[0] == 0 && counter[1] == 0 && counter[2] == 0)
    {
        ans = "yes";
    } else {
        ans = "no";
    }
    std::cout << ans << std::endl;
    return 0;
}
