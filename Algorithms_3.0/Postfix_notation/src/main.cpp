#include <iostream>
#include <stack>
//#include <deque>
#include <cctype>

int main()
{
    std::stack<char> s_input, s_operands, s_to_ans;
    //std::deque<char> d;
    bool if_continue{true};
    char c;
    std::cin.get(c);
    while (if_continue && c != '\n')
    {
        s_input.push(c);
        std::cin.get(c);
        if (c == ' ' && s_input.top() == ' ')
        {
            if_continue = false;
            s_input.pop();
        } else {
            if (c == ' ')
            {
                std::cin.get(c);
            }
        }
    }
    while (s_input.size())
    {
        c = s_input.top();
        s_input.pop();
        if (std::isalpha(c))
        {
            s_to_ans.push(c);
        } else {
            char temp = s_to_ans.top();
            if (std::isalpha(temp))
            {
                s_to_ans.push(temp);
            }
            s_to_ans.push(')');
            s_operands.push(c);
        }

    }
    return 0;
}
