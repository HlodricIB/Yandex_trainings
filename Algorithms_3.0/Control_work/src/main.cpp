#include <iostream>

int v_row_calc(int v_index)
{
    auto v_index_div = v_index / 2;
    auto v_index_modulo = v_index % 2;
    return v_index_div + v_index_modulo;;
}

int main()
{
    int n, k, row, place;
    std::cin >> n >> k >> row >> place;
    int index{-1};
    switch (place)
    {
    case 1:
        index = 2 * row - 1;
        break;
    case 2:
        index = 2 * row;
        break;
    default:
        std::cout << "Wrong place!" << std::endl;
        break;
    }
    int v_index, v_row;
    int v_index_plus = index + k;
    int v_index_minus = index - k;
    if (v_index_plus <= n && v_index_minus >= 1)
    {
        auto v_row_plus = v_row_calc(v_index_plus);
        auto v_row_minus = v_row_calc(v_index_minus);
        v_row = (v_row_plus - row) <= (row - v_row_minus) ? v_row_plus : v_row_minus;
        v_index = v_row == v_row_plus ? v_index_plus : v_index_minus;
    } else {
        if (v_index_plus <= n)
        {
            v_row = v_row_calc(v_index_plus);
            v_index = v_index_plus;
        } else {
            if (v_index_minus >= 1)
            {
                v_row = v_row_calc(v_index_minus);
                v_index = v_index_minus;
            } else {
                std::cout << -1 << std::endl;
                return 0;
            }
        }
    }
    int v_place;
    if (static_cast<bool>(v_index % 2))
    {
        v_place = 1;
    } else {
        v_place = 2;
    }
    std::cout << v_row << ' ' << v_place << std::endl;
    return 0;
}
