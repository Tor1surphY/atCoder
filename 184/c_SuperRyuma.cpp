/*
無限に広がる2次元グリッドがあり、マス(r1,c1)に駒「超竜馬」が置かれています。
この駒は、1手で次のような動きができます。

より正確には、超竜馬がマス(a,b)にあるとき、
以下のいずれかの条件を満たすマス(c,d)に動かすことができます。

a+b=c+d
a−b=c−d
|a−c|+|b−d|≤3

超竜馬を(r1,c1)から(r2,c2)に動かすのに必要な最小手数を求めてください。

この問題について、この解説は使える
重要なポイントは、Xの経路は、空白の点はたどり着いていけないので
最小は3手になる
https://atcoder.jp/contests/abc184/editorial/339?lang=ja
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    /*
    三つの条件の数式をださればいい
    そして、手数について、いくつの組み合わせを出す。
    */
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int ans = 3;
    if(r1 == r2 && c1 == c2) ans = 0;
    else if(
        r1+c1 == r2+c2 ||
        r1-c1 == r2-c2 || 
        abs(r1-r2) + abs(c1-c2) <= 3
    )                        ans = 1;
    else if(
        abs(r1-r2) + abs(c1-c2) <= 6 || /*CC*/
        (r1+c1)%2 == (r2+c2)%2       || /*AB*/
        abs((r2-r1) + (c2-c1)) <= 3  || 
        abs((r2-r1) - (c2-c1)) <= 3     /*AC&BC*/
    )                        ans = 2;
    cout << ans << endl;
    return 0;
}