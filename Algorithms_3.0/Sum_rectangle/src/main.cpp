#include <iostream>
#include <vector>

int main()
{
    uint_fast16_t n, m, x1, y1, x2, y2;
    int_fast16_t temp;
    uint_fast32_t k;
    int_fast32_t ans;
    std::cin >> n >> m >> k;
    using v_m_o_n = std::vector<std::vector<uint_fast16_t>>;
    using v_s_o_n = std::vector<uint_fast16_t>;
    v_s_o_n s_o_n(m + 1, 0);
    v_s_o_n t_s_o_n(m + 1, 0);
    v_m_o_n m_o_n;
    m_o_n.reserve(n);
    m_o_n.push_back(s_o_n);
    for (uint_fast16_t i = 0; i != n; ++i)
    {
        for (uint_fast16_t j = 1; j != m + 1; ++j)
        {
            std::cin >> temp;
            t_s_o_n[j] = temp + t_s_o_n[j - 1];
            s_o_n[j] = t_s_o_n[j] + m_o_n[i][j];
        }
        m_o_n.push_back(s_o_n);
    }
    for (uint_fast32_t i = 0; i != k; ++i)
    {
        std::cin >> x1 >> y1 >> x2 >> y2;
        ans = (m_o_n[x2][y2] - m_o_n[x1 - 1][y2]) - (m_o_n[x2][y1 - 1] - m_o_n[x1 - 1][y1 - 1]);
        std::cout << ans << std::endl;
    }
    return 0;
}
