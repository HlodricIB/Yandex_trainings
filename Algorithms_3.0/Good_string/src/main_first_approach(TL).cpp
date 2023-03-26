#include <iostream>
#include <vector>

int main()
{
    std::vector<unsigned long> letters(26, 0);
    unsigned n;
    std::cin >> n;
    for (unsigned i = 0; i != n; ++i)
    {
        std::cin >> letters[i];
    }
    int ans{0};
    std::vector<unsigned long>::size_type l{0}, r{1};
    while (l != (letters.size() - 1))
    {
        while (letters[l] != 0)
        {
            if (letters[r] == 0)
            {
                l += 2;
                r = l + 1;
            } else {
                while (letters[r] != 0 && r != letters.size())
                {
                    --letters[r];
                    ++ans;
                    ++r;
                }
                r = l + 1;
                --letters[l];
            }
        }
        ++l;
        r = l + 1;
    }
    std::cout << ans << std::endl;
    return 0;
}
