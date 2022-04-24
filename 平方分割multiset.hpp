#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#pragma GCC optimize("O3")
using ll = long long;

template <class T> struct SortedList {

  public:
    SortedList(vector<T> init = vector<T>()) {
        for (int i = 0; i < ((int)init.size()) - 1; ++i) {
            if (init[i] > init[i + 1]) {
                sort(init.begin(), init.end());
                break;
            }
        }
        build(init);
    }

    SortedList(initializer_list<T> &init) {
        vector<T> b = init;
        for (int i = 0; i < ((int)init.size()) - 1; ++i) {
            if (b[i] > b[i + 1]) {
                sort(b.begin(), b.end());
                break;
            }
        }
        build(b);
    }

    size_t size() {
        return _size;
    };

    T at(int x) {
        if (x < 0)
            x += _size;
        if (x < 0)
            cerr << "Index out of range" << endl;
        for (vector<T> &b : a) {
            if (x < b.size())
                return b[x];
            x -= b.size();
        }
        cerr << "Index out of range" << endl;
        return -1;
    }

    bool contain(T x) {
        if (!_size)
            return false;
        vector<T> &b = find_bucket(x);
        auto itr = lower_bound(b.begin(), b.end(), x);
        return b.end() == itr and *itr == x;
    }

    int count(T x) {
        return bisect_right(x) - bisect_left(x);
    }

    void add(T x) {
        if (!size()) {
            a = {{x}};
            _size = 1;
            return;
        }
        vector<T> &b = find_bucket(x);
        b.insert(lower_bound(b.begin(), b.end(), x), x);
        _size++;
        if (b.size() > a.size() * REBUILD_RATIO)
            rebuild();
    }

    bool remove(T x) {
        if (!_size)
            return false;
        vector<T> &b = find_bucket(x);
        auto itr = lower_bound(b.begin(), b.end(), x);
        if (itr == b.end() or *itr != x)
            return false;
        b.erase(itr);
        _size--;
        if (!b.size()) {
            rebuild();
        }
        return true;
    }

    int bisect_left(T x) {
        int idx = 0;
        for (vector<T> &b : a) {
            if (b[b.size() - 1] >= x)
                return idx + (lower_bound(b.begin(), b.end(), x) - b.begin());
            idx += b.size();
        }
        return idx;
    }

    int bisect_right(T x) {
        int idx = 0;
        for (vector<T> &b : a) {
            if (b[b.size() - 1] > x)
                return idx + (upper_bound(b.begin(), b.end(), x) - b.begin());
            idx += b.size();
        }
        return idx;
    }

    void pprint() {
        cout << "[";
        for (vector<T> &b : a) {
            for (T &val : b)
                cout << val << ", ";
        }
        cout << "]";

        cout << "\n";
    }

  private:
    size_t BUCKET_RATIO = 50, REBUILD_RATIO = 170, _size;
    vector<vector<T>> a;

    void build(vector<T> &_a) {
        _size = _a.size();
        size_t bucket_size = ceil(sqrt((double)_size / BUCKET_RATIO));
        a = vector<vector<T>>(bucket_size);
        for (int i = 0; i < bucket_size; ++i) {
            for (int j = _size * i / bucket_size; j < min(_size * (i + 1) / bucket_size, _size); j++) {
                a[i].emplace_back(_a[j]);
            }
        }
    }
    void rebuild() {
        vector<T> _a(_size);
        size_t k = 0;
        for (vector<T> &b : a) {
            for (T &val : b)
                _a[k++] = val;
        }
        build(_a);
    }

    vector<T> &find_bucket(T x) {
        // Find the bucket which should contain x. self must not be empty.
        for (vector<T> &b : a) {
            if (x <= b[b.size() - 1])
                return b;
        }
        return a[a.size() - 1];
    }
};
