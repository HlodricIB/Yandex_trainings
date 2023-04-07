#include <iostream>
#include <exception>
#include <variant>
#include <string_view>
#include <unordered_map>
#include <vector>

enum E : int
{
    PUSH,
    POP,
    BACK,
    SIZE,
    CLEAR,
    EXIT
};
static const std::unordered_map<std::string_view, E> f{
    {"push", E::PUSH}, {"pop", E::POP}, {"back", E::BACK}, {"size", E::SIZE}, {"clear", E::CLEAR}, {"exit", E::EXIT}};

std::string_view parse(std::string& s, long& data)
{
    auto pos = s.rfind(' ');
    if (pos != std::string::npos)
    {
        data = std::stol(s.substr(pos + 1));
    }
    return std::string_view{s.substr(0, pos)};
}

template<typename T>
class Stack_t
{
private:
    struct Node
    {
        Node* next{nullptr};
        T data;
        Node (Node* next_, T data_): next(next_), data(data_) { }
    };
    Node* head{nullptr};
    size_t amount{0};
    void clear_node();
public:
    Stack_t() = default;
    ~Stack_t() { clear(); }
    const std::string_view push(T);
    std::variant<T, const std::string_view> pop();
    std::variant<T, const std::string_view> back() const;
    size_t size() const { return amount; }
    const std::string_view clear();
    const std::string_view exit() const { return "bye"; }
};

template <typename T> void Stack_t<T>::clear_node()
{
    Node* temp = head->next;
    delete head;
    head = temp;
    --amount;
}

template<typename T> const std::string_view Stack_t<T>::clear()
{
    while (static_cast<bool>(head))
    {
        clear_node();
    }
    return "ok";
}

template<typename T> const std::string_view Stack_t<T>::push(T data_)
{
    Node* temp = head;
    try
    {
    head = new Node(temp, data_);
    } catch (const std::bad_alloc& e) {
        return "push error";
    }
    ++amount;
    return "ok";
}

template<typename T> std::variant<T, const std::string_view> Stack_t<T>::pop()
{
    auto variant = back();
    if (static_cast<bool>(std::get_if<0>(&variant)))
    {
        clear_node();
    }
    return variant;

}

template<typename T> std::variant<T, const std::string_view> Stack_t<T>::back() const
{
    T _data;
    if (static_cast<bool>(head))
    {
        _data = head->data;
        return std::variant<T, const std::string_view>{std::in_place_index<0>, _data};
    }
    return std::variant<T, const std::string_view>{std::in_place_index<1>, "error"};

}

void pop_back_handling(std::vector<std::string>& s_v, std::variant<long, const std::string_view> var)
{
    static std::string_view s;
    if (const long* d = std::get_if<long>(&var))
    {
        s_v.emplace_back(std::to_string(*d));
    } else {
        s = std::get<const std::string_view>(var);
        s_v.emplace_back(std::string{s.data(), s.size()});
    }
}

int main()
{
    Stack_t<long> s;
    std::vector<std::string> s_v;
    std::string c;
    bool if_continue{true};
    long data{0};
    std::string_view temp;
    while (if_continue)
    {
        std::getline(std::cin, c);
        switch (f.find(parse(c, data))->second)
        {
        case PUSH:
            temp = s.push(data);
            s_v.emplace_back(std::string{temp.data(), temp.size()});
            break;
        case POP:
            pop_back_handling(s_v, s.pop());
            break;
        case BACK:
            pop_back_handling(s_v, s.back());
            break;
        case SIZE:
            temp = std::to_string(s.size());
            s_v.emplace_back(std::string{temp.data(), temp.size()});
            break;
        case CLEAR:
            temp = s.clear();
            s_v.emplace_back(std::string{temp.data(), temp.size()});
            break;
        case EXIT:
            temp = s.exit();
            s_v.emplace_back(std::string{temp.data(), temp.size()});
            if_continue = false;
            break;
        }
    }
    for (std::vector<std::string>::size_type i = 0; i != s_v.size(); ++i)
    {
        std::cout << s_v[i] << std::endl;

    }
    //This is for Stack_t
    /*while (s_v.size() != 0)
    {
        std::visit([] (auto&& arg) { std::cout << arg << std::endl;}, s_v.pop());
    }*/
    return 0;
}
