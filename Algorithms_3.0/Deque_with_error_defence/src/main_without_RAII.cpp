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
    inline static size_t inc_ptrs_mas{2}, one_mas_size{2};
    T** ptr_to_front_mas{nullptr};
    T** ptr_to_back_mas{nullptr};
    T* front{nullptr};
    T* back{nullptr};
    size_t size_ptrs_mas{inc_ptrs_mas}, free_front_mas{0}, free_back_mas{0}, free_front_elems{one_mas_size}, free_back_elems{one_mas_size};
    void reallocate_ptrs_massive(bool);
    void copy (T**, T**);
    void allocate_t_massives(T**, size_t);
public:
    Deque_t();
    ~Deque_t();
    const std::string_view push_front(const T&);
    const std::string_view push_back(const T&);

};

template <typename T>
Deque_t<T>::Deque_t()
{
    ptr_to_front_mas = new T*[inc_ptrs_mas]();
    allocate_t_massives(ptr_to_front_mas, 0);
    ptr_to_back_mas = ptr_to_front_mas + 1;
    front = *ptr_to_front_mas + (one_mas_size - 1);
    back = *ptr_to_back_mas;
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

template <typename T>
void Deque_t<T>::allocate_t_massives(T** ptr, size_t offset)
{
    ptr += offset;
    for (size_t i = 0; i != inc_ptrs_mas; ++i)
    {
        *(ptr + i) = new T[one_mas_size]();
    }
}

template <typename T>
void Deque_t<T>::copy(T** src, T** dest)
{
    for (size_t i = 0; i != size_ptrs_mas; ++i)
    {
        *(dest + i) = *(src + i);
    }
}

template <typename T>
void Deque_t<T>::reallocate_ptrs_massive(bool if_front_alloc)
{
    auto ptr_to_front_mas_with_offset = ptr_to_front_mas - free_front_mas;
    auto new_allocation_size = size_ptrs_mas + inc_ptrs_mas;
    T** temp = new T*[new_allocation_size]();
    if (if_front_alloc)
    {
        allocate_t_massives(temp, 0);
        T** ptr_to_front_mas_in_new_allocated = temp + inc_ptrs_mas;
        copy(ptr_to_front_mas, ptr_to_front_mas_in_new_allocated);
        ptr_to_front_mas = ptr_to_front_mas_in_new_allocated - 1;
        ptr_to_back_mas = ptr_to_front_mas_in_new_allocated + size_ptrs_mas;
        free_front_mas = inc_ptrs_mas - 1;
    } else {
        allocate_t_massives(temp, size_ptrs_mas);
        T** ptr_to_front_mas_in_new_allocated = temp;
        copy(ptr_to_front_mas_with_offset, ptr_to_front_mas_in_new_allocated);
        ptr_to_front_mas = ptr_to_front_mas_in_new_allocated + free_front_mas;
        ptr_to_back_mas = ptr_to_front_mas_in_new_allocated + size_ptrs_mas;
        free_back_mas = inc_ptrs_mas - 1;
    }
    size_ptrs_mas += inc_ptrs_mas;
    delete[] ptr_to_front_mas_with_offset;
}

template <typename T>
const std::string_view Deque_t<T>::push_front(const T& data_)
{
    *front = data_;
    --free_front_elems;
    if (free_front_elems >= 1)
    {
        --front;
    } else {
        if (free_front_mas == 0)
        {
            try {
                reallocate_ptrs_massive(true);
            }  catch (const std::bad_alloc& e)
            {
                return e.what();
            }

        } else {
            --ptr_to_front_mas;
            --free_front_mas;
        }
        front = *ptr_to_front_mas + one_mas_size - 1;
    }
    return "ok";
}

template <typename T>
const std::string_view Deque_t<T>::push_back(const T& data_)
{
    *back = data_;
    --free_back_elems;
    if (free_back_elems >= 1)
    {
        ++back;
    } else {
        if (free_back_mas == 0)
        {
            try {
                reallocate_ptrs_massive(false);
            }  catch (const std::bad_alloc& e)
            {
                return e.what();
            }
        } else {
            ++ptr_to_back_mas;
            --free_back_mas;
        }
        back = *ptr_to_back_mas;
    }
    return "ok";
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
