/*
Ｈ行Ｗ列のマスＣがあります。
Ｃ[i][j]が'.'のときが白
`＃`のときが黒

行を何行か選び(0行でもよい)、列を何列か選ぶ(0列でもよい)
そして、選んだ行に含まれるマスと、選んだ列に含まれるマスをすべて赤く塗る

正の整数Kが与えられます。
操作後に黒いマスがちょうどK個残るような行と列の選び方は何通りでしょうか

条件を満たす行と列の選び方の個数を表す整数を出力せよ
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(){
    int h ,w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int ans = 0;
    rep(is, 1<<h)rep(js, 1<<w){
        int cnt = 0;
        rep(i, h)rep(j ,w){
            if(is>>i & 1) continue;
            if(js>>j & 1) continue;
            if('#' == s[i][j]) ++cnt;
        }
        if(k == cnt) ++ans;
    }
    cout << ans << endl;
    return 0;
}