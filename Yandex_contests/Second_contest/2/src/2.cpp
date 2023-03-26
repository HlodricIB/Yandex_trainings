#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<std::pair<std::string, std::string>> pairs;
    pairs.reserve(q);
    std::string f, s;
    std::getchar();
    for (int i = 0; i != q; ++i)
    {
        std::getline(std::cin, f, ' ');
        //std::cin.ignore(1);
        std::getline(std::cin, s);
        pairs.push_back(std::make_pair(f, s));
    }
    int count{0};
    for (auto& p : pairs)
    {
        for (int i = 0; i <= n; ++i)
        {
            ++count;
            if (p.first[i] == p.second[i])
            {
                std::cout << p.first[i];
            } else {
                auto c = count % 2 == 0 ? p.second[i] : p.first[i];
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
