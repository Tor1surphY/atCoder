/*
正整数 Xに対し、Xの正の約数の個数をf(X)とします。
正整数Nが与えられるので、∑N~(K=1) K×f(K)を求めてください。
*/
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += i*(n/i)*(n/i + 1)/2;
    }
    cout << ans << endl;
    return 0;
}

/*
方法：
1からNまで、
1の倍数になった数の数量はN
2の倍数になった数の数量はN/2
…
Nの倍数になった数の数量はN/Nつまり1です
それを分解すると、
1の倍数は1からNまで、N個があります
2の倍数は2からNまで、2、4、6、8...っとなります
…
それが全部等差数列です、っで、数列の和を求めて
その上に全ての和の和は結果として出力する
計算量はO(N)です
*/ 