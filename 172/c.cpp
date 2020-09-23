/*
二台の机A, Bがあります。
机AにはN冊の本が、机BにはM冊の本が、それぞれ縦に積まれています。

机Aに現在上からi番目に積まれている本(1≤i≤N)は読むのにAi分を要し、
机Bに現在上からi番目に積まれている本(1≤i≤M)は読むのにBi分を要します。

次の行為を考えます。

本が残っている机を選び、その机の最も上に積まれた本を読んで机から取り除く。
合計所要時間がK分を超えないようにこの行為を繰り返すとき、
最大で何冊の本を読むことができるでしょうか。
本を読むこと以外に要する時間は無視します。
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    vector<ll> b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    ll ttl = 0;
    rep(i, m) ttl += b[i];

    int j = m;
    int ans = 0;
    // iはAから選ぶ冊の数、つまり0-n
    rep(i, n+1){
        while(j > 0 && ttl > k){
            --j;
            ttl -= b[j];
        }
        // bの中に、一つ引く、Kより小さい時、
        // もしjが０になった時、ttlはｋより大きい場合は
        // このb[j]は条件を満たさないので、breakします
        if(ttl > k) break;
        // でなければ、この状況は条件を満たす
        // それで、もしansより大きい場合は、i✛ｊに変更
        ans = max(ans, i+j);
        // stackoverflowを避ける
        if(i == n) break;
        // 次のloopでaの一冊を既に読んだ、最初は0冊です
        ttl += a[i];
    }
    cout << ans << endl;
    return 0;
}