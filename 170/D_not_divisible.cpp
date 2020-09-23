/*
長さNの数列 Aが与えられます。
次の性質を満たす整数i(1≤i≤N)の数を答えてください。

i≠jである任意の整数 
j(1≤j≤N)についてAiはAjで割り切れない
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (n); ++i)

const int M = 1000005;
typedef long long LL;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // 入力した数の倍数を計算する
    // もしある数の約数の数は1より大きいの場合は
    // その数は条件を満たさない
    // iの倍数の数は M/i です
    // Σ(1~M) M/i
    // O(NlogN)

    vector<int> cnt(M);
    for(int x : a){
        // 0じゃない場合は、既に現れたの状況です
        // その時は、その数の倍数を計算するのは無意味です
        if(cnt[x] != 0){
            cnt[x] = 2;
            continue;
        }
        // xの倍数
        for(int i = x; i < M; i += x) ++cnt[i];
    }

    int ans = 0;
    for(int x : a){
        if(1 == cnt[x]) ++ans;
    }
    cout << ans << endl;

    return 0;
}