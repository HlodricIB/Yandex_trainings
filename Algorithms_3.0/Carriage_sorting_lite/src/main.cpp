#include <iostream>
#include <stack>
#include <limits>

using stack_int = std::stack<uint_fast64_t>;

bool carriage_sorting(stack_int& s_1)
{
    stack_int s_dock;
    uint_fast64_t last_out{0}, first_in;
    while (!s_1.empty())
    {
        s_dock.push(s_1.top());
        s_1.pop();
        while (!s_1.empty() && (s_dock.top() >= s_1.top()))
        {
            s_dock.push(s_1.top());
            s_1.pop();
        }
        if (s_dock.top() < last_out)
        {
            return false;
        }
        if (!s_1.empty())
        {
            first_in = s_1.top();
        } else {
            first_in = std::numeric_limits<uint64_t>::max();
        }
        while (!s_dock.empty() && s_dock.top() < first_in)
        {
            last_out = s_dock.top();
            s_dock.pop();
        }
    }
    return true;
}

void input(stack_int& s_1)
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
        s_1.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack_int s_1;
    input(s_1);
    if (carriage_sorting(s_1))
    {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
