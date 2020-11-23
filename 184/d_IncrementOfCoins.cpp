/*
袋の中に金貨がA枚、銀貨がB枚、銅貨がC枚入っています。
袋の中にあるいずれかの種類の硬貨が100枚になるまで以下の操作を繰り返します。

操作：袋の中から硬貨をランダムに1枚取り出す。
(どの硬貨も等確率で選ばれる。)
取り出した硬貨と同じ種類の硬貨を2枚袋に戻す。
操作回数の期待値を求めてください。

この問題は確率DPと呼ばれるジャンルの問題です。
解説の中が関数があります。
https://atcoder.jp/contests/abc184/editorial/152
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
double dp[MAX+1][MAX+1][MAX+1];

double f(int a, int b, int c) {
    if(dp[a][b][c]) return dp[a][b][c];
    if(a == 100 || b == 100 || c == 100) return 0;
    double ans = 0;
    ans += (f(a+1, b,   c  )+1)*a/(a+b+c);
    ans += (f(a,   b+1, c  )+1)*b/(a+b+c);
    ans += (f(a,   b,   c+1)+1)*c/(a+b+c);
    dp[a][b][c] = ans;
    return ans;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
#if 0
    for(int i = MAX-1; i >= 0; --i) {
        for(int j = MAX-1; j >= 0; --j) {
            for(int k = MAX-1; k >= 0; --k) {
                if(i+j+k == 0) continue;
                double current_exp = 0;
                current_exp += dp[i+1][j][k]*i;
                current_exp += dp[i][j+1][k]*j;
                current_exp += dp[i][j][k+1]*k;
                dp[i][j][k] = current_exp/(i+j+k) + 1;
            }
        }
    }
    double ans = dp[a][b][c];
    printf("%.9f\n", ans);
#endif
    printf("%.9f\n", f(a, b, c));
    return 0;
}