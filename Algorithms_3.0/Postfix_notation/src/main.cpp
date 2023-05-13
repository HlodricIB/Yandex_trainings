#include <iostream>
#include <stack>
#include <cctype>
#include <exception>

using stack_char = std::stack<char>;
using stack_int = std::stack<int_fast32_t>;

int_fast32_t operation(char op, int_fast32_t operand1, int_fast32_t operand2)
{
    switch (op)
    {
    case '+':
        operand1 += operand2;
        break;
    case '-':
        operand1 -= operand2;
        break;
    case '*':
        operand1 *= operand2;
        break;
    default:
        throw std::logic_error("Bad input sequence");
        break;
    }
    return operand1;
}

void s_operands_handle(stack_char& s_operators, stack_int& s_operands)
{
    int_fast32_t i_temp;
    i_temp = s_operands.top();
    s_operands.pop();
    try
    {
        i_temp = operation(s_operators.top(), s_operands.top(), i_temp);
    }  catch (const std::logic_error& e) {
        throw e;
    }
    s_operands.pop();
    s_operands.push(i_temp);
    if (s_operators.size() > 1)
    {
        s_operators.pop();
    }
}

int_fast32_t count(stack_char& s_input)
{
    stack_int s_operands;
    stack_char s_operators;
    char c_temp;
    while (!s_input.empty())
    {
        c_temp = s_input.top();
        s_input.pop();
        if (std::isalnum(c_temp))
        {
            s_operands.push(c_temp - '0');
        } else {
            s_operators.push(c_temp);
            if (s_operands.size() >= 2)
            {
                try
                {
                    s_operands_handle(s_operators, s_operands);
                }  catch (const std::logic_error& e) {
                    throw e;
                }
            }
        }
    }
    while (s_operands.size() > 1)
    {
        try
        {
            s_operands_handle(s_operators, s_operands);
        }  catch (const std::logic_error& e) {
            throw e;
        }
    }
    return s_operands.top();
}

void input(stack_char& s_input)
{
    std::string s;
    std::getline(std::cin, s);
    auto iter = s.rbegin();
    while (*iter == '\n')
    {
        --iter;
    }
    for ( ; iter != s.rend(); ++iter)
    {
        if (*iter != ' ')
        {
            s_input.push(*iter);
        }
    }
}

int main()
{
    stack_char s_input;
    input(s_input);
    if (s_input.size() == 1 && std::isalnum(s_input.top()))
    {
        std::cout << s_input.top();
    } else {
        try
        {
            std::cout << count(s_input) << std::endl;
        } catch (const std::logic_error& e)
        {
            std::cout << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }
    return 0;
}
