#include <numeric>
#include <utility>
#include <vector>

struct MinPrimeFactor {
  public:
    MinPrimeFactor(unsigned MAXN) {
        min_factor.resize(MAXN + 1);
        std::iota(min_factor.begin(), min_factor.end(), 0);
        for (unsigned i = 2; i * i <= MAXN; i++) {
            if (min_factor[i] == i) {
                for (unsigned j = i * i; j <= MAXN; j += i)
                    if (min_factor[j] > i)
                        min_factor[j] = i;
            }
        }
    }
    std::vector<unsigned> factorization(unsigned k) {
        std::vector<unsigned> res;
        while (k > 1) {
            res.emplace_back(min_factor[k]);
            k /= min_factor[k];
        }
        return res;
    }
    std::vector<std::pair<unsigned, unsigned>> factorization_pair(unsigned k) {
        std::vector<std::pair<unsigned, unsigned>> res;
        unsigned cur = min_factor[k], cnt = 0;
        while (k > 1) {
            if (cur == min_factor[k]) {
                cnt++;
                k /= min_factor[k];
            } else {
                res.emplace_back(cur, cnt);
                cur = min_factor[k];
                k /= min_factor[k];
                cnt = 1;
            }
        }

        if (cur > 1)
            res.emplace_back(cur, cnt);
        return res;
    }

  private:
    std::vector<unsigned> min_factor;
};