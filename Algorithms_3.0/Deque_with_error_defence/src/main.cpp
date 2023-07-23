#include <iostream>
#include <unordered_map>
#include <string_view>

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
class Deque_t
{
    class All_massives;
    All_massives* all_massives{nullptr};

    void reallocate_ptrs_massive(bool);
    void copy (T**, T**);
    void allocate_t_massives(T**, size_t);
public:
    Deque_t(): all_massives(new All_massives()) { }
    ~Deque_t() { delete all_massives; }
    const std::string_view push_front(const T&);
    const std::string_view push_back(const T&);

};

template <typename T>
class Deque_t<T>::All_massives
{
    class One_massive;
    inline static size_t increment{2};
    size_t curr_size;
    One_massive* front_begin{nullptr};
    One_massive* back_begin{nullptr};
    One_massive* front{nullptr};
    One_massive* back{nullptr};

};

template <typename T>
class Deque_t<T>::All_massives::One_massive
{
    inline static size_t size{2};
    T* begin{nullptr};
    T* current{nullptr};
    One_massive(): begin(new T[size]()), current(begin) { }
    ~One_massive() { delete [] begin; }
    bool add(T&);
    T& get() const { return *current; };


};

template <typename T>
bool Deque_t<T>::All_massives::One_massive::add(T& t)
{
    *current = t;
    if (current == begin + size)
    {
        return true;
    } else {
        return false;
    }
}

template <typename T>
Deque_t<T>::~Deque_t()
{
    auto temp_begin = ptr_to_front_mas - free_front_mas;
    for (size_t i = 0; i != size_ptrs_mas; ++i)
    {
        delete[] *(temp_begin + i);
    }
    delete[] temp_begin;
}

int main()
{
    Deque_t<int> deque_int;
    //Doesn't work
    /*deque_int.push_front(2);
    deque_int.push_front(1);
    deque_int.push_back(3);
    deque_int.push_back(4);*/

    /*deque_int.push_front(2);
    deque_int.push_back(3);
    deque_int.push_front(1);
    deque_int.push_back(4);*/

    /*deque_int.push_back(3);
    deque_int.push_front(2);
    deque_int.push_front(1);
    deque_int.push_back(4);*/

    //Work
    /*deque_int.push_front(2);
    deque_int.push_back(3);
    deque_int.push_back(4);
    deque_int.push_front(1);*/

    /*deque_int.push_back(3);
    deque_int.push_back(4);
    deque_int.push_front(2);
    deque_int.push_front(1);*/

    deque_int.push_front(2);
    deque_int.push_front(1);
    deque_int.push_back(4);
    return 0;
}
