vector<vector<int>> multiple_loops(const vector<int> &loops) {
    //各 k 対して,loops[k] 回ループする.itertools.productに似ている.

    int loop_count = 1;
    for (int i : loops)
        loop_count *= i;

    if (loop_count == 0)
        return {};

    int n = (int)loops.size();
    vector<int> d(n);
    vector<vector<int>> res = {d};
    for (int _ = 0; _ < loop_count - 1; ++_) {
        d[0]++;
        int i = 0;
        while (i < n and d[i] == loops[i]) {
            d[i] = 0;
            i++;
            d[i]++;
        }
        res.emplace_back(d);
    }
    return res;
}