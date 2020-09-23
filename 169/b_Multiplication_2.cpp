/*
N個の整数 A1,...,ANが与えられます。

A1×...×ANを求めてください。

ただし、結果が1e18を超える場合は、代わりに-1を出力してください。
*/
#include <iostream>
#include <stdio.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long LL;

const LL M = 1e18;

int main(){
    int n;
    cin >> n;
    LL a[n];
    LL ans = 1;

    rep(i, n){
        cin >> a[i];
        if (0 == a[i]){
            cout << 0 << endl;
            return 0;
        }
    }

    rep(i, n){
        if (a[i] > M / ans)
        {
            cout << -1 << endl;
            return 0;
        }
        ans *= a[i];
    }
    cout << ans << endl;
    return 0;
}

/*
1e18を超えると、マイナスになります
だから、*より/の方がいい
条件は　a[i]*ans <= 1e18
つまり　a[i] <= 1e18/ans

pythonの場合は、128bitsの整数が使える、その方う簡単
*/