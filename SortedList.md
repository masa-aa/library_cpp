# SortedList
ランダムアクセスが可能なmultisetのようなものである．  
以下のようにアクセスができる．   
```cpp
int main() {
    SortedList<int> a = {1, 2, 1, 1, 4, 2};  
    cout << a[3] << endl; // 2  
    a.print(); // [1, 1, 1, 2, 2, 4]  
}
```
### コンストラクタ
```
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
`sl`に`x`が存在する必要がある．
##### 計算量
$O(\log(N))$ である．

### remove_if
```cpp
void sl.remove_if(T x)
```
`sl`に`x`が存在すれば，`sl`から`x`を1つ削除する．

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

### operator[]
```cpp
T operator[](int k)
```
`sl`の`k`番目にアクセスする．

##### 制約
$0\leq k < N$

##### 計算量
$O(\log(N))$ である．

### その他
* `bool empty()` : `sl`が空かどうか
* `void clear()` : `sl`の要素をすべて削除
* `T at(int k)` : `sl[k]`と同じ
* `inline void print()`