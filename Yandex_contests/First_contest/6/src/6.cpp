/*#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

struct V
{
private:
    std::pair<int_least32_t, int_least32_t> coord{0, 0};
public:
    V(int_least32_t x, int_least32_t y): coord{x, y} { }
    std::pair<int_least32_t, int_least32_t> get_coord() const { return coord; }
};

class G
{
    using v_index = std::vector<V>::size_type;
private:
    std::vector<V> vertexes;
    std::vector<int_least32_t> roads_counts;
    std::vector<bool> path_v;
    int_least32_t max_dist;
    void road_count(v_index, v_index);
public:
    G() = default;
    explicit G(v_index s) { vertexes.reserve(s); }
    void add_vertex(int_least32_t x, int_least32_t y) { vertexes.emplace_back(V(x, y)); }
    int dist_count(v_index, v_index);
    std::vector<int_least32_t> get_roads_counts(v_index, v_index, int_least32_t);
};

std::vector<int_least32_t> G::get_roads_counts(v_index src, v_index dest, int_least32_t max_dist_)
{
    const v_index dest_v = vertexes.size() - 1;
    if (dest > dest_v)
    {
        roads_counts.clear();
        return roads_counts;
    }
    std::swap(vertexes[0], vertexes[src]);
    std::swap(vertexes[dest_v], vertexes[dest]);
    max_dist = max_dist_;
    if (dist_count(0, dest_v) == 0)
    {
        roads_counts.push_back(0);
        return roads_counts;
    }
    path_v = std::vector<bool>(vertexes.size(), false);
    road_count(0, 0);
    return roads_counts;
}

int G::dist_count(v_index from, v_index to)
{
    return std::abs(vertexes[from].get_coord().first - vertexes[to].get_coord().first) +
            std::abs(vertexes[from].get_coord().second - vertexes[to].get_coord().second);
}

void G::road_count(v_index curr_v, v_index count)
{
    static const v_index dest_v = vertexes.size() - 1;
    ++count;
    path_v[curr_v] = true;
    if (dist_count(curr_v, dest_v) <= max_dist)
    {
        roads_counts.push_back(count);
        path_v[curr_v] = false;
        return;
    }
    for (v_index next_v = 1; next_v != dest_v; ++next_v)
    {
        auto d_c = dist_count(curr_v, next_v);
        if (curr_v != next_v && !path_v[next_v] && d_c <= max_dist && d_c != 0)
        {
            road_count(next_v, count);
        }
    }
    path_v[curr_v] = false;
    return;
}

int main()
{

    std::vector<V>::size_type towns_number{0};
    std::cin >> towns_number;
    if (towns_number < 2 || towns_number > 1000)
    {
        return 0;
    }
    G graph{towns_number};
    int_least32_t coord_x, coord_y, max_dist, source, destination;
    for (std::vector<V>::size_type i = 0; i != towns_number; ++i)
    {
        std::cin >> coord_x;
        std::cin.ignore(1);
        std::cin >> coord_y;
        if (std::abs(coord_x) <= 1000000000 && std::abs(coord_y) <= 1000000000)
        {
            graph.add_vertex(coord_x, coord_y);
        }
    }
    std::cin >> max_dist;
    if (max_dist > 2000000000 || max_dist < 0)
    {
        return 0;
    }
    std::cin >> source;
    std::cin.ignore(1);
    std::cin >> destination;
    auto road_counts = graph.get_roads_counts(source - 1, destination - 1, max_dist);
    if (!road_counts.empty())
    {
        std::cout << *std::min_element(road_counts.begin(), road_counts.end()) << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}*/

#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>

struct V
{
private:
    std::pair<int_least32_t, int_least32_t> coord{0, 0};
public:
    V(int_least32_t x, int_least32_t y): coord{x, y} { }
    std::pair<int_least32_t, int_least32_t> get_coord() const { return coord; }
};

class G
{
private:
    std::vector<std::pair<int_least32_t, int_least32_t>> vertexes;
    std::set<int_least32_t> set_v;
    int_least32_t max_dist;
public:
    G() = default;
    explicit G(v_index s) { vertexes.reserve(s); }
};

std::vector<int_least32_t> G::get_roads_counts(v_index src, v_index dest, int_least32_t max_dist_)
{
    const v_index dest_v = vertexes.size() - 1;
    if (dest > dest_v)
    {
        roads_counts.clear();
        return roads_counts;
    }
    std::swap(vertexes[0], vertexes[src]);
    std::swap(vertexes[dest_v], vertexes[dest]);
    max_dist = max_dist_;
    if (dist_count(0, dest_v) == 0)
    {
        roads_counts.push_back(0);
        return roads_counts;
    }
    path_v = std::vector<bool>(vertexes.size(), false);
    road_count(0, 0);
    return roads_counts;
}

int G::dist_count(v_index from, v_index to)
{
    return std::abs(vertexes[from].get_coord().first - vertexes[to].get_coord().first) +
            std::abs(vertexes[from].get_coord().second - vertexes[to].get_coord().second);
}

void G::road_count(v_index curr_v, v_index count)
{
    static const v_index dest_v = vertexes.size() - 1;
    ++count;
    path_v[curr_v] = true;
    if (dist_count(curr_v, dest_v) <= max_dist)
    {
        roads_counts.push_back(count);
        path_v[curr_v] = false;
        return;
    }
    for (v_index next_v = 1; next_v != dest_v; ++next_v)
    {
        auto d_c = dist_count(curr_v, next_v);
        if (curr_v != next_v && !path_v[next_v] && d_c <= max_dist && d_c != 0)
        {
            road_count(next_v, count);
        }
    }
    path_v[curr_v] = false;
    return;
}

int main()
{

    std::vector<V>::size_type towns_number{0};
    std::cin >> towns_number;
    if (towns_number < 2 || towns_number > 1000)
    {
        return 0;
    }
    G graph{towns_number};
    int_least32_t coord_x, coord_y, max_dist, source, destination;
    for (std::vector<V>::size_type i = 0; i != towns_number; ++i)
    {
        std::cin >> coord_x;
        std::cin.ignore(1);
        std::cin >> coord_y;
        if (std::abs(coord_x) <= 1000000000 && std::abs(coord_y) <= 1000000000)
        {
            graph.add_vertex(coord_x, coord_y);
        }
    }
    std::cin >> max_dist;
    if (max_dist > 2000000000 || max_dist < 0)
    {
        return 0;
    }
    std::cin >> source;
    std::cin.ignore(1);
    std::cin >> destination;
    auto road_counts = graph.get_roads_counts(source - 1, destination - 1, max_dist);
    if (!road_counts.empty())
    {
        std::cout << *std::min_element(road_counts.begin(), road_counts.end()) << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}

