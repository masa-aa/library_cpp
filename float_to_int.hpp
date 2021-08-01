#include <string>

std::pair<long long, int> float_to_int(const std::string &f) {
    int k = f.find('.');
    if (k == -1)
        return {f.size(), 0};
    else {
        std::string res = "";
        for (char c : f)
            if (c != '.')
                res += c;
        return {stoll(res), f.size() - k - 1};
    }
}