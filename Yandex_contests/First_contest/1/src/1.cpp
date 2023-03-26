#include <string>
#include <iostream>

int main()
{
    std::string stones, jewelry;
    std::getline(std::cin, stones);
    std::getline(std::cin, jewelry);
    int count{0};
    for (std::string::size_type i = 0; i != stones.size(); ++i)
    {
        std::string::const_iterator j = jewelry.begin();
        while (j != jewelry.end())
        {
            if (stones[i] == *j)
            {
                count++;
                jewelry.erase(j);
            } else {
                ++j;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}
