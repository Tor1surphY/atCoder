/*
A,T,C,Gから成る長さNの文字列Sがあります。
長さの等しい文字列T1,T2が相補的とは、
    |T1|=lとしたとき、どの1 ≤ i ≤ lについても
    T1,T2のi文字目の組み合わせが
        (AとT),または(CとG)の組み合わせのいずれかであることを指します。
    (例えばAとTの組み合わせのとき、どちらの文字がT1に属してもよいです)

Sの連続する空でない部分文字列Tであって、次の条件を満たすものの個数を求めてください。

Tと相補的であるような、Tの文字を並び替えた文字列が存在する。
ただし、文字列として同じであってもS内の位置が異なれば違う部分列とみなします。
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    int a, t, c, g;
    for(int i = 0; i < n; ++i) {
        a = t = c = g = 0;
        for(int j = i; j < n; ++j) {
            if     (s[j] == 'A') ++a;
            else if(s[j] == 'T') ++t;
            else if(s[j] == 'C') ++c;
            else                 ++g;
            if((a == t) && (c == g)) ++ans;
        }
    }
    cout << ans << endl;
}