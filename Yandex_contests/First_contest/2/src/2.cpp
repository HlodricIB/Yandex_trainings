#include <vector>
#include <iostream>

/*int main()
{
    int n{0}, count{0}, count_current{0};
    std::vector<int> numbers;
    std::vector<int>::size_type i_1 = 0;
    while (std::cin >> n)
    {
        numbers.push_back(n);
        if (numbers.size() > 10000)
        {
            return 1;
        }
    }
    for (std::vector<int>::size_type i = 0; i != numbers.size(); ++i)
    {
        if (numbers[i] == 1 && (i == 0 || i_1 == i - 1))
        {
            ++count_current;
            i_1 = i;
        } else {
            if (numbers[i] == 1)
            {
                i_1 = i;
                count = std::max<int>(count, count_current);
                count_current = 1;
            }
        }
    }
    count = std::max<int>(count, count_current);
    std::cout << count << std::endl;
    return 0;
}*/

int main()
{
    int n{0}, count{0}, count_current{0}, n_count{0}, n_count_current{0};
    std::cin >> n_count;
    while (n_count_current++ < n_count)
    {
        std::cin >> n;
        if (n == 1)
        {
            ++count_current;
        } else {
            if (count_current > count)
            {
                count = count_current;
            }
            count_current = 0;
        }
    }
    if (count_current > count)
    {
        count = count_current;
    }
    std::cout << count << std::endl;
    return 0;
}

