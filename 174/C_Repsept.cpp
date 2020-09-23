/*
高橋君はKの倍数と7が好きです。
7,77,777,…という数列の中に初めてKの倍数が登場するのは何項目ですか？
存在しない場合は代わりに-1を出力してください。

1 ≤ K ≤ 10^6
Kは整数である。
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
using namespace std;

int main(){
    int k = 0; cin >> k;
    int x = 7%k;
    for(int i = 1; i <= k; ++i){
        if(x == 0){
            cout << i << endl;
            return 0;
        }
        x = (x*10+7)%k;
    }
    cout << -1 << endl;
    return 0;
}