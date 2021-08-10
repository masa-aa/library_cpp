# SortedList
`k`番目の要素に $O(\log(N))$ でアクセスできるmultisetのようなものである．  
以下のようにアクセスができる．  [実装例](https://github.com/masa-aa/library_cpp/blob/main/SortedList.hpp )
```cpp
int main() {
    SortedList<int> a = {1, 2, 1, 1, 4, 2};  
    cout << a[3] << endl; // 2  
    a.print(); // [1, 1, 1, 2, 2, 4]  
}
```
### コンストラクタ
```cpp
(1) SortedList<S> sl()
(2) SortedList<S> sl(vector<T> v)
(3) SortedList<S> sl(initializer_list<T> v)
``` 
* 比較可能な型 `T`
を定義する必要がある．

##### 計算量
$N$ を`v`の大きさとすると，$O(N\log(N))$ である．

### add
```cpp
void sl.add(T x)
```
`sl`に`x`を追加する．
##### 計算量
$O(\log(N))$ である．

### remove
```cpp
void sl.remove(T x)
```
`sl`から`x`を1つ削除する．
##### 制約
`sl`に`x`が存在する必要がある．存在しないと`x`より大きい最小の値を削除する．
##### 計算量
$O(\log(N))$ である．

### remove_if
```cpp
void sl.remove_if(T x)
```
`sl`に`x`が存在すれば，`sl`から`x`を1つ削除する．

##### 計算量
$O(\log(N))$ である．

### pop
```cpp
T sl.pop()
T sl.pop(int k)
```
`sl`の`k`番目を削除し取得する．`k`を指定しない時，一番大きい要素を1つ削除し取得する．

##### 計算量
$O(\log(N))$ である．

### bisect_left
```cpp
int sl.bisect_left(T x)
```
`x`以上で最小の数が何番目かを返す．つまり`x`未満の数が何個あるかわかる．

##### 計算量
$O(\log(N))$ である．

### bisect_right
```cpp
int sl.bisect_right(T x)
```
`x`より大きい数で最小の数が何番目かを返す．つまり`x`以下の数が何個あるかわかる．

##### 計算量
$O(\log(N))$ である．

### equal_range
```cpp
int sl.equal_range(T x)
```
`(sl.bisect_left(x), sl.bisect_right(x))`の組を返す．

##### 計算量
$O(\log(N))$ である．

### count
```cpp
int sl.count(T x)
```
`sl`内に`x`が何個含まれるか返す．

##### 計算量
$O(\log(N))$ である．

### operator[]
```cpp
T operator[](int k)
```
`sl`の`k`番目にアクセスする．

##### 制約
$0\leq k < N$

##### 計算量
$O(\log(N))$ である．

### update
```cpp
void sl.update(int k, T x)
```
`sl`の`k`番目を`x`に変更し並び替える．

##### 計算量
$O(\log(N))$ である．

### max
```cpp
T sl.max()
```
`sl`の最大値を返す．

##### 計算量
$O(1)$ である．

### min
```cpp
T sl.min()
```
`sl`の最小値を返す．

##### 計算量
$O(1)$ である．



### その他
* `bool empty()` : `sl`が空かどうか
* `void clear()` : `sl`の要素をすべて削除
* `T at(int k)` : `sl[k]`と同じ
* `inline void print()`
* `operator bool()` : list が空か否かで`false`，`true`を返す．

---

## 使用例
空の集合`S`がある．   
  
以下のクエリを処理する．    
  
* `1 x`: `S`に`x`を追加する．   
* `2`:`S`の中央値を出力する．  
  
中央値とは，`n = |S|`とした時，0から数えて`(n-1)/2`番目の要素   
  
<details><summary>解答例 (▶をクリックしてね) </summary><div>

```cpp
int main() {
    SortedList<int> sl;
    int q;
    cin >> q;
    while (q--) {
        int query;
        cin >> query;
        if (query == 1) {
            int x;
            cin >> x;
            sl.add(x);
        } else {
            // sl.print();
            int k = (sl.size - 1) / 2;
            cout << sl[k] << '\n';
        }
    }
}
```
</div></details>

---
### Remark
`insert`の回数が`unsigned int`の最大値以下で必要がある．  
`insert`の回数がこれより多くなる場合は`unsigned long long`等を用いる．
### ToDo 
`less<T>`を`greater<T>`のように変更すると`bisect`関連が壊れる．