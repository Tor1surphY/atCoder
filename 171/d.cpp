/*
あなたは、N個の正整数A1,A2,⋯,ANからなる数列Aを持っています。

あなたは、これから以下の操作をQ回、続けて行います。

i回目の操作では、値がBiである要素すべてをCiに置き換えます。
すべてのi(1 ≤ i ≤ Q)に対して、
i回目の操作が行われた後の数列Aのすべての要素の和、Siを求めてください。
*/
#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll s = 0;
    ll n, tmp;
    ll a[100001] = {0};
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        cin >> tmp;
        ++a[tmp];
        s += tmp;
    }

    ll q;
    cin >> q;
    ll b, c;
    for(ll i = 0; i < q; ++i){
        cin >> b >> c;
        s = s - a[b]*b + a[b]*c;
        a[c] += a[b];
        a[b] = 0;
        cout << s << endl;
    }
    return 0;
}

/*
总结：
    下标计数用的数组注意大小
        比如1-100用来计数
        那么0是不可用的，所以该数组的大小应该是a[101]
    注意初始化，因为内存可能随机分配数值
        例：int a[101] = {0};
*/