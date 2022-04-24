#include <algorithm>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>

unsigned long long hilbert_order(unsigned int x, unsigned int y) {
    constexpr unsigned int LOG = 20;
    constexpr unsigned int MAXN = 1 << LOG;
    unsigned int s = 1 << (LOG - 1);
    unsigned long long d = 0;

    while (s) {
        bool rx = (x & s) > 0, ry = (y & s) > 0;
        s >>= 1;
        d = (d << 2) | ((rx * 3) ^ ry);

        if (ry)
            continue;
        if (rx) {
            x = MAXN - x;
            y = MAXN - y;
        }
        std::swap(x, y);
    }

    return d;
}

struct StaticQueries {
    // [l, r) のクエリを答える．
    using Ar = std::pair<unsigned int, unsigned int>;

  public:
    StaticQueries(const unsigned int &q) {
        queries.resize(q);
        hilbert.resize(q);
    }

    void add_queries(const unsigned int &l, const unsigned int &r) {
        auto &[a, b] = queries[k];
        a = l;
        b = r;
        hilbert[k++] = hilbert_order(l, r);
    }

    template <typename AL, typename AR, typename EL, typename ER, typename O>
    void solve(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {

        std::vector<int> ord(k);
        std::iota(ord.begin(), ord.end(), 0);

        std::sort(ord.begin(), ord.end(),
                  [&](const unsigned int &lh, const unsigned int &rh) { return hilbert[rh] > hilbert[lh]; });

        unsigned int current_L = 0, current_R = 0;
        for (unsigned int i : ord) {
            auto &[l, r] = queries[i];
            while (current_R < r)
                add_right(current_R++);
            while (l < current_L)
                add_left(--current_L);
            while (r < current_R)
                erase_right(--current_R);
            while (current_L < l)
                erase_left(current_L++);
            out(i);
        }
    }
    template <typename A, typename E, typename O> void solve(const A &add, const E &erase, const O &out) {
        solve(add, add, erase, erase, out);
    }

  private:
    unsigned int k = 0;
    std::vector<Ar> queries;
    std::vector<unsigned long long> hilbert;
};
