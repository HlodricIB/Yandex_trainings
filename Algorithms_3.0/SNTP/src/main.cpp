#include <iostream>
#include <chrono>
#include <string>
#include <vector>

using vec_str = std::vector<std::string>;
using vec_hh_mm_ss = std::vector<std::chrono::hh_mm_ss<std::chrono::milliseconds>>;

vec_hh_mm_ss convert(vec_str& string_input)
{
    vec_hh_mm_ss ms;
    ms.reserve(3);
    for (vec_str::size_type i = 0; i != string_input.size() - 3; i += 3)
    {
        std::chrono::hours h{std::stol(string_input[i])};
        std::chrono::minutes m{std::stol(string_input[i + 1])};
        std::chrono::seconds s{std::stol(string_input[i + 2])};
        auto sum_ms = std::chrono::duration_cast<std::chrono::milliseconds>(h) +
                std::chrono::duration_cast<std::chrono::milliseconds>(m) +
                std::chrono::duration_cast<std::chrono::milliseconds>(s);
        ms.emplace_back(std::chrono::hh_mm_ss<std::chrono::milliseconds>{sum_ms});
        std::chrono::hh_mm_ss h_m_s{sum_ms};
    }
    auto hours = h_m_s.hours().count();
    if (hours % 10 == 0)

}

vec_hh_mm_ss input_parse()
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

int main()
{
    auto string_input = input_parse();

    long int ms = 57.4 * 1000;
    std::chrono::milliseconds d1{ms};
    std::chrono::duration<double> d2{2};
    //d1 += d2;
    std::chrono::hh_mm_ss<std::chrono::duration<double>> t{d1};
    auto hours = t.seconds();
    std::cout << std::chrono::round<std::chrono::seconds>(d1).count();
    //std::cout << t;

    return 0;
}
