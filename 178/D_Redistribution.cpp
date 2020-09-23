/*
整数Sが与えられます。
すべての項が3以上の整数で、
その総和がSであるような数列がいくつあるか求めてください。
ただし、答えは非常に大きくなる可能性があるので、 
1e9+7で割った余りを出力してください。
*/
#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>

#define rep(i ,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

#if 0
void backTracking(ll& ans, ll dif, ll& cmp) {
    if(cmp < 3 && cmp != 0){
        return;
    }
    if(cmp == 0) {
        ++ans;
        return;
    }
    while(dif <= cmp) {
        cmp -= dif;
        backTracking(ans, dif, cmp);
        cmp += dif;
        dif++;
    }
}

void test() {
    ll mod = 1e9+7;
    ll s = 0;
    cin >> s;

    if(s < 3) {
        cout << 0 << endl;
        return 0;
    }

    ll _dif = 3;
    ll ans = 0;
    while(_dif <= s) {
        ll cmp = s - _dif;
        backTracking(ans, 3, cmp);
        ans %= mod;
        ++_dif;
    }
    cout << ans << endl;
}

#endif

int main() {
    ll s = 0;
    cin >> s;
    if(s < 3){
        cout << 0 << endl;
        return 0;
    }
    vector<ll> dp(s+1, 0);
    dp[3] = 1;
    for(int i = 4; i <= s; i++) 
        dp[i] = (dp[i-1] + dp[i-3]) % 1000000007;
    cout << dp[s] << endl;
    return 0;
}

/*
数学の問題です。
もし具体的な結果を出力すれば、back trackingの方法ができる

この問題について、関数の方が大事
A(n) = A(n-3) + A(n-4) + ... + A(n-(n-1)) + A(0)
                A(n-4) + ... + A(n-(n-1)) + A(0) = A(n-4+3) = A(n-1)
つまり A(n) = A(n-1) + A(n-3)

こうすると、A(0~3)の値をあればいい
A(0) = 0
A(1) = 0
A(2) = 0
A(3) = 1
はきまりです

所以说在很多穷举类问题中
寻找公式也是一种不错的方法
*/