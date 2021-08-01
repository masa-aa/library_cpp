#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> struct SortedList {
    size_t size = 0;
    ordered_set<pair<T, unsigned int>> data;
    map<T, unsigned int> counter;

    SortedList() {
    }
    SortedList(vector<T> &a) {
        for (T const &v : a) {
            add(v);
        }
    }
    SortedList(initializer_list<T> a) {
        for (T const &v : a) {
            add(v);
        }
    }
    void add(const T &x) {
        data.insert({x, counter[x]++});
        size++;
    }
    void remove(const T &x) {
        if (counter[x] == 0) {
            cerr << "!! Error " << x << " is not exist" << endl;
            exit(0);
        };
        data.erase({x, --counter[x]});
        size--;
    }
    void remove_if(const T &x) {
        if (counter[x] == 0)
            return;
        data.erase({x, --counter[x]});
        size--;
    }
    int bisect_left(const T &x) {
        return data.order_of_key({x, 0});
    }
    int bisect_right(const T &x) {
        return data.order_of_key({x, numeric_limits<unsigned int>::max()});
    }
    pair<int, int> equal_range(const T &x) {
        // [l, r)
        return {bisect_left(x), bisect_right(x)};
    }
    int count(const T &x) {
        return bisect_right(x) - bisect_left(x);
    }
    T max() {
        return (*data.rbegin()).first;
    }
    T min() {
        return (*data.begin()).first;
    }
    bool empty() {
        return size == 0;
    }
    void clear() {
        size = 0;
        data.clear();
        counter.clear();
    }
    T at(const T &k) {
        assert(0 <= k and k < size);
        return (*data.find_by_order(k)).first;
    }
    T operator[](const T &k) {
        return (*data.find_by_order(k)).first;
    }
    inline void print() {
        cout << "[";
        for (int i = 0; i < size; ++i) {
            if (i)
                cout << ", ";
            cout << (*data.find_by_order(i)).first;
        }
        cout << "]\n";
    }
};