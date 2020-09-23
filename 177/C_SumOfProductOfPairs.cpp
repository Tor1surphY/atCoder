/*
N個の整数 A1,…,AN が与えられます。
1 ≤ i < j ≤ N を満たす全ての組(i,j)についての
Ai×Ajの和をmod(1e9+7)で求めてください。
2 ≤ N ≤ 2×1e5
0 ≤ Ai ≤ 1e9
*/

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>

#define rep(i ,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 1e9+7;

int main(){
    int n = 0;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    ll ans = 0, x = 0;
    rep(i, n){
        ans = (ans + a[i]*x)%mod;
        x = (x + a[i])%mod;
    }
    cout << ans%mod << endl;
    return 0;
}

/*
順番を考慮させない場合は、正順と逆順の効果が同じです
modを使う場合は、いつ、どこでもmodを取るのは構いません
でも、より少ないmodを取れば、結果はもっと精確になる。
*/