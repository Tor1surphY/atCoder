/*
整数Xと、長さNの整数列p1,…,pNが与えられます。

整数列 p1,…,pNに含まれない整数(正とは限らない)のうちXに最も近いもの、
つまりXとの差の絶対値が最小のものを求めてください。

そのような整数が複数存在する場合は、
そのうち最も小さいものを答えてください。
*/
#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    int p[102] = {0};
    int tmp;
    rep(i, n){
        cin >> tmp;
        ++p[tmp];
    }

    if(0 == n){
        cout << x << endl;
        return 0;
    }

    int ans;
    int left = 0, right = 101;
    int dif_left, dif_right;
    for(int i = x; i >= 0; --i){
        if(p[i] == 0){
            left = i;
            dif_left = abs(x-i);
            break;
        }
    }
    for(int i = x; i <= 101; ++i){
        if(p[i] == 0){
            right = i;
            dif_right = abs(x-i);
            break;
        }
    }
    if(dif_left <= dif_right) ans = left;
    else ans = right;

    cout << ans << endl;
    return 0;
}