#include <iostream>

int main()
{
    int_least32_t l_x, r_x, b_y, t_y, x, y;
    short k;
    std::cin >> k;
    std::cin >> x >> y;
    l_x = r_x = x;
    b_y = t_y = y;
    for (short i = 1; i != k; ++i)
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
