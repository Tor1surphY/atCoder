/*
正整数Nが与えられます。
A × B + C = Nを満たす正整数の組(A, B, C)はいくつありますか？
制約
2 ≤ N ≤ 10^6
*/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int n; cin >> n;
    vector<int> mlt_cnt(n, 0);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; i*j <= n; ++j)
            mlt_cnt[i*j]++;
    
    for(int i = 0; i < n; ++i) 
        mlt_cnt[i+1] += mlt_cnt[i];
    cout << mlt_cnt[n-1] << endl;
    return 0;
}
/*
A*B+CはA*BとCの二つの数字が見れれる。
こうすると、A*BとCの組合はn‐1個です
で、着目点はA*Bので、ここはDにしましょう。
Dの組合の数は、自身の素約数の数です。
1からnまで全ての数の素約数の数を、
sieve of Eratosthenesとうゆうアルゴリズムを使って、
O(N*sqrt(N))の時間内で出来ます。
そして、
各数字の素約数をオーバーレイ計算すると、
O(N)内で目標を計算する。
*/