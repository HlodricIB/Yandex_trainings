#include <iostream>
#include <chrono>
#include <string>
#include <vector>

using vec_str = std::vector<std::string>;
using vec_durations = std::vector<std::chrono::milliseconds>;

std::chrono::hh_mm_ss<std::chrono::seconds> convert(vec_str& string_input)
{
    static std::chrono::seconds t_f_h{std::chrono::hours{24}};
    vec_durations d_ms;
    d_ms.reserve(3);
    for (vec_str::size_type i = 0; i <= string_input.size() - 3; i += 3)
    {
        std::chrono::hours h{std::stol(string_input[i])};
        std::chrono::minutes m{std::stol(string_input[i + 1])};
        std::chrono::seconds s{std::stol(string_input[i + 2])};
        auto sum_ms = std::chrono::duration_cast<std::chrono::milliseconds>(h) +
                std::chrono::duration_cast<std::chrono::milliseconds>(m) +
                std::chrono::duration_cast<std::chrono::milliseconds>(s);
        d_ms.emplace_back(std::chrono::milliseconds{sum_ms});
    }
    auto t = std::chrono::round<std::chrono::seconds>(d_ms[1] + (d_ms[2] - d_ms[0]) / 2 + std::chrono::milliseconds{1});
    return std::chrono::hh_mm_ss<std::chrono::seconds>{t};
}

std::chrono::hh_mm_ss<std::chrono::seconds> input_parse()
{
    vec_str string_input{9, "  "};
    for (vec_str::size_type i = 0; i != string_input.size(); ++i)
    {
        std::cin >> string_input[i][0];
        std::cin >> string_input[i][1];
        std::cin.ignore(1);
    }
    return convert(string_input);
}

void out(long i)
{
    if (i < 10)
    {
        std::cout << '0' << i;
    } else {
         std::cout << i;
    }
}

int main()
{
    auto h_m_s_s = input_parse();
    out(h_m_s_s.hours().count());
    std::cout << ':';
    out(h_m_s_s.minutes().count());
    std::cout << ':';
    out(h_m_s_s.seconds().count());
    std::cout << std::endl;
    return 0;
}
