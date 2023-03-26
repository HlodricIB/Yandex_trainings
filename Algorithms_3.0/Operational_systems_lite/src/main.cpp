#include <iostream>
#include <list>
#include <utility>

using sectors_list = std::list<std::pair<unsigned long, unsigned long>>;

void sectors_fill(sectors_list& sectors, int n)
{
    unsigned long first, second;
    for (auto i = n; i != 0; --i)
    {
        std::cin >> first >> second;
        sectors.emplace_back(std::make_pair(first, second));
    }
}

int count(sectors_list& sectors)
{
    sectors_list::iterator iter_temp;
    auto iter1 = sectors.begin();
    bool is_break(false);
    while (iter1 != --sectors.end())
    {
        auto iter2 = iter1;
        ++iter2;
        for ( ; iter2 != sectors.end(); ++iter2)
        {
            if ((iter1->first >= iter2->first && iter1->first <= iter2->second) ||
                    (iter1->second >= iter2->first && iter1->second <= iter2->second) ||
                    (iter1->first <= iter2->first && iter1->second >= iter2->second))
            {
                auto temp = iter1;
                ++iter1;
                sectors.erase(temp);
                is_break = true;
                break;
            }
        }
        if (!is_break)
        {
            ++iter1;
        } else {
            is_break = false;
        }

    }
    return sectors.size();
}

int main()
{
    unsigned long m;
    sectors_list::size_type n;
    std::cin >> m >> n;
    sectors_list sectors;
    sectors_fill(sectors, n);
    std::cout << count(sectors) << std::endl;
    return 0;
}
