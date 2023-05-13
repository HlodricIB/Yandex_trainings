#include <iostream>
#include <stack>
#include <vector>

using stack_int = std::stack<uint_fast32_t>;
using vector_int = std::vector<int_fast32_t>;

void input(stack_int& s_input)
{
    stack_int::size_type n_c;
    std::cin >> n_c;
    std::cin.get();
    stack_int temp;
    uint64_t n;
    for (stack_int::size_type i = 0; i != n_c; ++i)
    {
        std::cin >> n;
        temp.push(n);
    }
    while (!temp.empty())
    {
        s_input.push(temp.top());
        temp.pop();
    }
}

void migrate(stack_int& s_input, vector_int& res)
{
    stack_int s_prev_prices, s_prev_towns_indexes;
    uint_fast32_t curr_avg_price;
    stack_int::size_type i{0}, i_last_migrate_to{0};
    while (s_input.size() != 1)
    {
        curr_avg_price = s_input.top();
        s_input.pop();
        if (curr_avg_price <= s_input.top())
        {
            s_prev_prices.push(curr_avg_price);
            s_prev_towns_indexes.push(i);
        } else {
            i_last_migrate_to = i + 1;
            res[i] = i_last_migrate_to;
            while (!s_prev_prices.empty() && s_prev_prices.top() > s_input.top())
            {
                res[s_prev_towns_indexes.top()] = i_last_migrate_to;
                s_prev_prices.pop();
                s_prev_towns_indexes.pop();
            }
        }
        ++i;
    }
}

int main()
{
    stack_int s_input;
    input(s_input);
    vector_int res(s_input.size(), -1);
    migrate(s_input, res);
    vector_int::size_type i = 0;
    for ( ; i != res.size() - 1; ++i)
    {
        std::cout << res[i] << ' ';
    }
    std::cout << res[i] << std::endl;
    return 0;
}
