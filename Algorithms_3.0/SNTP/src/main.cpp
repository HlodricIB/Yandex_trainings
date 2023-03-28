#include <iostream>
#include <chrono>
#include <string>
#include <vector>

using vec_str = std::vector<std::string>;
using vec_long = std::vector<long int>;

vec_long parse_convert(vec_str& string_input)
{
    vec_long ms{3,0};


}

vec_long input_parse()
{
    vec_str string_input{9, "  "};
    for (vec_str::size_type i = 0; i != string_input.size(); ++i)
    {
        std::cin >> string_input[i][0];
        std::cin >> string_input[i][1];
        std::cin.ignore(1);
    }
    return parse_convert(string_input);
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
