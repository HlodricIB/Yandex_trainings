#include <iostream>
#include <vector>
#include <algorithm>



unsigned long count(std::vector<unsigned long>::iterator b, std::vector<unsigned long>::iterator e)
{
    unsigned long ans{0}, i_count;
    auto l = b;
    while (l != (e - 1))
    {
        for ( ; *l == 0 && l < (e - 1); ++l);
        auto r = l + 1;
        if (l > (e - 1) || *r == 0)
        {
            return ans;
        }
        i_count = 0;
        for ( ; *r != 0 && r != e; ++r, ++i_count);
        auto min_iter = std::min_element(l, r);
        auto min = *min_iter;
        ans += min * i_count;
        for (auto i = l; i != r; ++i)
        {
            *i -= min;
        }
        ans += count(l, min_iter);
        l = min_iter + 1;
    }
    return ans;
}

int main()
{
    std::vector<unsigned long> letters(26, 0);
    unsigned n;
    std::cin >> n;
    for (unsigned i = 0; i != n; ++i)
    {
        std::cin >> letters[i];
    }
    auto ans = count(letters.begin(), letters.begin() + n);
    std::cout << ans << std::endl;
    return 0;
}
