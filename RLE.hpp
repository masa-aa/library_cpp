#include <vector>

template <class T> std::vector<int> RLE(T &arr) {
    int n = arr.size();
    if (n == 1)
        return {1};
    if (n == 0)
        return {};
    std::vector<int> res;
    int count = 1;
    auto prev = arr[0];
    for (int i = 1; i < n; i++) {
        if (prev == arr[i])
            count++;
        else {
            prev = arr[i];
            res.emplace_back(count);
            count = 1;
        }
    }
    res.emplace_back(count);
    return res;
}