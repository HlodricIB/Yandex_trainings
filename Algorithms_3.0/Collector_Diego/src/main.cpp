#include <iostream>
//#include <set>
#include <vector>
#include <algorithm>

int search(std::vector<int>& numbers, int n_to_find, std::vector<int>::size_type actual_size)
{
    using v_size = std::vector<int>::size_type;
    v_size r = actual_size - 1;
    v_size l = 0;
    v_size curr_pos;
    if (numbers[r] < n_to_find)
    {
        return actual_size;
    }
    if (numbers[l] >= n_to_find)
    {
        return 0;
    }
    while (l < r)
    {
        curr_pos = (r + l) / 2;
        if (numbers[curr_pos] < n_to_find)
        {
            l = curr_pos + 1;
        } else {
            r = curr_pos;
        }
    }
    return r;
}

int main()
{
    std::vector<int>::size_type n, k, i{0};
    std::cin >> n;
    std::vector<int> numbers;
    numbers.reserve(n);
    int number;
    for ( ; i != n; ++i)
    {
        std::cin >> number;
        numbers.push_back(number);
    }
    std::cin >> k;
    std::vector<int> p;
    p.reserve(k);
    for (i = 0; i != k; ++i)
    {
        std::cin >> number;
        p.push_back(number);
    }
    std::sort(numbers.begin(), numbers.end());
    auto border = std::unique(numbers.begin(), numbers.end());
    auto new_size = border - numbers.begin();
    int ans;
    for (const auto n_to_find : p)
    {
        ans = search(numbers, n_to_find, new_size);
        std::cout << ans << std::endl;
    }
    return 0;
}


/*int main()
{
    std::set<int>::size_type n, i_s{0};
    std::set<int> numbers;
    int number;
    std::cin >> n;
    for ( ; i_s != n; ++i_s)
    {
        std::cin >> number;
        numbers.insert(number);
    }
    std::vector<int>::size_type k, i_v{0};
    std::cin >> k;
    std::vector<int> p;
    p.reserve(k);
    for ( ; i_v != k; ++i_v)
    {
        std::cin >> number;
        p.push_back(number);
    }
    int ans{0};
    for (const auto n_to_find : p)
    {
        auto bound = numbers.lower_bound(n_to_find);
        for (auto iter = numbers.begin(); iter != bound; ++iter)
        {
            ++ans;
        }
        std::cout << ans << std::endl;
        ans = 0;
    }
    return 0;
}*/
