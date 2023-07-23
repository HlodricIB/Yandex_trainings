#include <iostream>
#include <unordered_map>
#include <string_view>
#include <variant>
#include <vector>

enum E : int
{
    PUSH,
    POP,
    FRONT,
    SIZE,
    CLEAR,
    EXIT
};
static const std::unordered_map<std::string_view, E> f{
    {"push", E::PUSH}, {"pop", E::POP}, {"front", E::FRONT}, {"size", E::SIZE}, {"clear", E::CLEAR}, {"exit", E::EXIT}};

const std::string_view parse(std::string& s, long& data)
{
    auto pos = s.rfind(' ');
    if (pos != std::string::npos)
    {
        data = std::stol(s.substr(pos + 1));
    }
    return std::string_view{s.substr(0, pos)};
}

template <typename T>
class Queue_t
{
    struct Node
    {
        Node() = default;
        Node* _m_next{nullptr};
        T _m_data;
    };
    Node* m_head;
    Node* m_tail;
    Node* m_current_array_begin;
    Node* m_current_array_end;
    size_t m_amount{0};
    size_t m_size_to_allocate{2};
    const size_t m_max_massive_size{100};
    const std::string_view push_helper();
public:
    Queue_t();
    ~Queue_t();
    std::string_view push(const T&);
    std::string_view push(const T&&) noexcept;
    std::variant<T, const std::string_view> front() const;
    std::variant<T, const std::string_view> pop();
    const std::string_view clear();
    size_t size() const { return m_amount; }
    const std::string_view exit() const { return "bye"; }
};

template <typename T>
Queue_t<T>::Queue_t()
{
    try
    {
        m_head = new Node[m_size_to_allocate]();
    }  catch (const std::bad_alloc& e) {
        std::cerr << e.what() << std::endl;
    }
    m_tail = m_head;
    m_current_array_begin = m_head;
    m_current_array_end = m_head + m_size_to_allocate - 1;
}

template <typename T>
Queue_t<T>::~Queue_t()
{
    while (m_head != m_tail)
    {
        if (m_head->_m_next)
        {
            m_head = m_head->_m_next;
            delete[] m_current_array_begin;
            m_current_array_begin = m_head;
        } else {
            ++m_head;
        }
    }
    delete[] m_current_array_begin;
}

template <typename T>
const std::string_view Queue_t<T>::push_helper()
{
    ++m_amount;
    if (m_tail != m_current_array_end && !m_tail->_m_next)
    {
        ++m_tail;
    } else {
        if (m_tail->_m_next)
        {
            m_tail = m_tail->_m_next;
        } else {
            m_size_to_allocate *= 2;
            m_size_to_allocate = m_size_to_allocate < m_max_massive_size ? m_size_to_allocate : m_max_massive_size;
            try
            {
                m_tail->_m_next = new Node[m_size_to_allocate]();
            } catch (const std::bad_alloc& e) {
                return e.what();
            }
            m_tail = m_tail->_m_next;
            m_current_array_end = m_tail + m_size_to_allocate - 1;
        }
    }
    return "ok";
}

template <typename T>
std::string_view Queue_t<T>::push(const T& data_)
{
    m_tail->_m_data = data_;
    return push_helper();
}

template <typename T>
std::string_view Queue_t<T>::push(const T&& data_) noexcept
{
    m_tail->_m_data = std::move(data_);
    return push_helper();
}

template<typename T>
std::variant<T, const std::string_view> Queue_t<T>::front() const
{
    if (m_amount != 0)
    {
        return std::variant<T, const std::string_view>{std::in_place_index<0>, m_head->_m_data};
    }
    return std::variant<T, const std::string_view>{std::in_place_index<1>, "error"};

}

template<typename T>
std::variant<T, const std::string_view> Queue_t<T>::pop()
{
    if (m_amount == 0)
    {
        return std::variant<T, const std::string_view>{std::in_place_index<1>, "error"};
    } else {
        auto var_pop = std::variant<T, const std::string_view>{std::in_place_index<0>, std::move(m_head->_m_data)};
        --m_amount;
        if (m_head != m_tail)
        {
            if (!m_head->_m_next)
            {
                ++m_head;
            } else {
                m_head = m_head->_m_next;
                delete[] m_current_array_begin;
                m_current_array_begin = m_head;
            }
        } else {
            m_amount = 0;
            m_head = m_tail = m_current_array_begin;
        }
        return var_pop;
    }
}

template<typename T>
const std::string_view Queue_t<T>::clear()
{
    m_head = m_tail = m_current_array_begin;
    m_amount = 0;
    return "ok";
}

int main()
{
    using T = long;
    Queue_t<T> q;
    std::vector<std::variant<T, const std::string_view>> q_v;
    std::string c;
    bool if_continue{true};
    T data{0};
    while (if_continue)
    {
        std::getline(std::cin, c);
        switch (f.find(parse(c, data))->second)
        {
        case PUSH:
            q_v.emplace_back(q.push(data));
            break;
        case POP:
            q_v.emplace_back(q.pop());
            break;
        case FRONT:
            q_v.emplace_back(q.front());
            break;
        case SIZE:
            q_v.emplace_back(static_cast<T>(q.size()));
            break;
        case CLEAR:
            q_v.emplace_back(q.clear());
            break;
        case EXIT:
            q_v.emplace_back(q.exit());
            if_continue = false;
            break;
        }
    }
    for (auto& v : q_v)
    {
        std::visit([] (auto&& arg) { std::cout << arg << std::endl;}, v);
    }
    return 0;
}
