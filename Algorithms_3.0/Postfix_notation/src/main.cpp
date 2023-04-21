#include <iostream>
#include <stack>
#include <cctype>

void restore(std::stack<char>& s_input, std::stack<char>& s_to_ans)
{
    std::stack<char> s_operands;
    while (s_input.size())
    {
        if (std::isalnum(s_input.top()))
        {
            while (s_operands.size())
            {
                s_to_ans.push(s_operands.top());
                s_operands.pop();
                if (s_input.size())
                {
                    s_to_ans.push(s_input.top());
                    s_input.pop();
                }
            }
        } else {
            s_operands.push('(');
            s_operands.push(s_input.top());
            s_operands.push(')');
            s_input.pop();
        }
    }
}

int main()
{
    std::stack<char> s_input, s_to_ans;
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
    restore(s_input, s_to_ans);
    while (s_to_ans.size())
    {
        std::cout << s_to_ans.top();
        s_to_ans.pop();
    }
    std::cout << std::endl;
    return 0;
}
