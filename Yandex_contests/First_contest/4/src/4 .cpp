#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*int main()
{
    int n{0};
    std::cin >> n;
    if (n < 0 || n > 11)
    {
        return 0;
    }
    std::string s, t_middle, middle, t_middle2, middle2, t_whole_line;
    auto double_n = 2 * n;
    s.reserve(double_n);
    for (int i = 0; i != n; ++i)
    {
        s.push_back('(');
        s.push_back(')');
    }
    std::vector<std::string> final{1, s};
    if (n > 1)
    {
        std::string t_outer{s};
        bool whole_line{false};
        for (int j_outer = 2; j_outer < double_n - 1; j_outer += 2)
        {
            //final.push_back("Outer");
            std::swap(t_outer[j_outer - 1], t_outer[j_outer]);
            final.push_back(std::move(t_outer));
            middle = final.back();
            for (int j_middle = j_outer + 2; j_middle < double_n - 1; j_middle += 2)
            {
                //final.push_back("Middle");
                t_middle = middle;
                std::swap(t_middle[j_middle - 1], t_middle[j_middle]);
                final.push_back(std::move(t_middle));
                t_whole_line = final.back();
                middle2 = final.back();
                if (j_middle + 2 < double_n - 2)
                {
                    whole_line = true;
                }
                for (int j_middle2 = j_middle + 2; j_middle2 < double_n - 1; j_middle2 += 2)
                {
                    //final.push_back("Middle2");
                    t_middle2 = middle2;
                    std::swap(t_middle2[j_middle2 - 1], t_middle2[j_middle2]);
                    if (whole_line)
                    {
                        std::swap(t_whole_line[j_middle2 - 1], t_whole_line[j_middle2]);
                    }
                    final.push_back(std::move(t_middle2));
                }
                if (whole_line)
                {
                    //final.push_back("T_whole_line");
                    final.push_back(std::move(t_whole_line));
                    whole_line = false;
                }
            }
            t_outer = s;
        }
        for (int j_outer = 4; j_outer < double_n - 1; j_outer += 2)
        {
            //final.push_back("Outer");
            std::swap(t_outer[j_outer - 3], t_outer[j_outer]);
            final.push_back(std::move(t_outer));
            middle = final.back();
            for (int j_middle = j_outer + 2; j_middle < double_n - 1; j_middle += 2)
            {
                //final.push_back("Middle");
                t_middle = middle;
                std::swap(t_middle[j_middle - 3], t_middle[j_middle]);
                final.push_back(std::move(t_middle));
                t_whole_line = final.back();
                middle2 = final.back();
                if (j_middle + 2 < double_n - 2)
                {
                    whole_line = true;
                }
                for (int j_middle2 = j_middle + 2; j_middle2 < double_n - 1; j_middle2 += 2)
                {
                    //final.push_back("Middle2");
                    t_middle2 = middle2;
                    std::swap(t_middle2[j_middle2 - 3], t_middle2[j_middle2]);
                    if (whole_line)
                    {
                        std::swap(t_whole_line[j_middle2 - 3], t_whole_line[j_middle2]);
                    }
                    final.push_back(std::move(t_middle2));
                }
                if (whole_line)
                {
                    //final.push_back("T_whole_line");
                    final.push_back(std::move(t_whole_line));
                    whole_line = false;
                }
            }
            t_outer = s;
        }
        int i_a{1}, j_a{double_n - 2};
        if (n > 4)
        {
            std::swap(t_outer[i_a], t_outer[j_a]);
            i_a += 2;
            j_a -= 2;
            while (i_a < j_a)
            {
                std::swap(t_outer[i_a], t_outer[j_a]);
                //std::cout << t << std::endl;
                final.push_back(t_outer);
                i_a += 2;
                j_a -= 2;
            }
        }
        for (int i_left = 1; i_left < double_n - 4; i_left += 2)
        {
            for (int j_left = i_left + 5; j_left < double_n - 1; j_left += 2)
            {
                t_outer = s;
                std::swap(t_outer[i_left], t_outer[j_left]);
                final.push_back(t_outer);
            }
        }
    }
    std::sort(final.begin(), final.end());
    for (auto& string : final)
    {
        std::cout << string << std::endl;
    }
    std::cout << final.size() << std::endl;

    std::string s_p(n, '(');
    s_p.append(std::string(n, ')'));
    //std::cout << s << std::endl;
    int count = 1;
    std::vector<std::string> permutated{s_p};
    std::cout << std::endl;
    std::cout << s_p << std::endl;
    while (std::next_permutation(s_p.begin(), s_p.end()))
    {
        if (*s_p.begin() != ')' && *s_p.rbegin() != '(')
        {
            ++count;
            std::cout << s_p << std::endl;
            permutated.push_back(s_p);
        }
    }
    std::cout << count << std::endl;
    std::vector<std::string> difference;
    std::set_difference(permutated.begin(), permutated.end(), final.begin(), final.end(), std::back_inserter(difference));
    for (auto& string : difference)
    {
        std::cout << string << std::endl;
    }
    return 0;
}*/

bool if_out(std::string& s)
{
    if (s.starts_with(')') || s.ends_with('('))
    {
        return false;
    }
    for(std::string::size_type b = 0; b != s.size();)
    {
        auto i = s.find("()", b);
        if (i == b)
        {
            b += 2;
            if (s[i + 2] == ')')
            {
                return false;
            }
        } else {
             break;
        }
    }
    std::string _s = s;
    std::string::size_type len = _s.size();
    while (!_s.empty())
    {
        if (_s.ends_with("()"))
        {
            _s.resize(len - 2);
            len -= 2;
            if (_s.ends_with('('))
            {
                return false;
            }
        } else {
            break;
        }
    }
    return true;
}

int main()
{
    int n{0};
    std::cin >> n;
    if (n < 0 || n > 11)
    {
        return 0;
    }
    std::string s(n, '(');
    s.append(std::string(n, ')'));
    std::cout << s << std::endl;
    int count = 1;
    std::vector<std::string> permutated{s};
    while (std::next_permutation(s.begin(), s.end()))
    {
        if (if_out(s))
        {
            ++count;
            std::cout << s << std::endl;
            permutated.push_back(s);
        }
    }
    std::cout << count << std::endl;
    return 0;
}
