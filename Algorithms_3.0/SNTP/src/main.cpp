#include <iostream>
#include <chrono>

int main()
{
    std::chrono::duration<double> d1{59};
    std::chrono::duration<double> d2{2};
    d1 += d2;
    std::chrono::hh_mm_ss<std::chrono::duration<double>> t{d1};
    auto hours = t.hours();
    std::chrono::<<(t);
    std::cout << t.hours();

    return 0;
}
