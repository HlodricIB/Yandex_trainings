#include <iostream>

int main()
{
    int_least32_t l_x{0}, r_x{0}, b_y{0}, t_y{0}, x, y;
    short k;
    std::cin >> k;
    for (short i = 0; i != k; ++i)
    {
        std::cin >> x >> y;
        if (l_x > x)
        {
            l_x = x;
        }
        if (r_x < x)
        {
            r_x = x;
        }
        if (b_y > y)
        {
            b_y = y;
        }
        if (t_y < y)
        {
            t_y = y;
        }
    }
    std::cout << l_x << ' ' << b_y << ' ' << r_x << ' ' << t_y << std::endl;
    return 0;
}
