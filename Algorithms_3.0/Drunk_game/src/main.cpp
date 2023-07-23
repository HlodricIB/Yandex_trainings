#include <iostream>
#include <queue>
#include <tuple>
#include <string_view>

void input(std::queue<uint_fast16_t>& q)
{
    for (auto i = 0; i != 4; ++i)
    {
        q.push(std::cin.get() - '0');
        std::cin.get();
    }
    q.push(std::cin.get() - '0');
    if (!std::isalnum(std::cin.peek()))
    {
        while (std::cin.get() != '\n');
    }
    return;
}

std::tuple<const std::string_view, int32_t> play(std::queue<uint_fast16_t>& q1, std::queue<uint_fast16_t>& q2)
{
    static int32_t botva{1000000};
    int32_t number_of_moves{0};
    uint16_t card1, card2, max_card{9}, min_card{0};
    bool if_first_takes;
    while ((!q1.empty() && !q2.empty()) && number_of_moves <= botva)
    {
        card1 = q1.front();
        q1.pop();
        card2 = q2.front();
        q2.pop();
        if ((card1 == max_card && card2 == min_card) || (card1 == min_card && card2 == max_card))
        {
            if (card2 > card1)
            {
                if_first_takes = true;
            } else {
                if_first_takes = false;
            }
        } else {
            if (card2 > card1)
            {
                if_first_takes = false;
            } else {
                if_first_takes = true;
            }
        }
        if (!if_first_takes)
        {
            q2.push(card1);
            q2.push(card2);
        } else {
            q1.push(card1);
            q1.push(card2);
        }
        ++number_of_moves;
    }
    if (number_of_moves > botva)
    {
        return {"botva", -1};
    }
    return (q1.empty()? std::make_tuple("second", number_of_moves) : std::make_tuple("first", number_of_moves));
}

int main()
{
    std::queue<uint_fast16_t> q1, q2;
    input(q1);
    input(q2);
    auto res = play(q1, q2);
    if (std::get<1>(res) == -1)
    {
        std::cout << std::get<0>(res) << std::endl;
    } else {
        std::cout << std::get<0>(res) << ' ' << std::get<1>(res) << std::endl;
    }
    return 0;
}
