/*
給湯器が1つあり、毎分Wリットルのお湯を供給することができます。
N人の人がいます。
i番目の人は時刻SiからTiまでの間(時刻Tiちょうどを除く)、
この湯沸かし器で沸かしたお湯を毎分Piリットル使おうと計画しています。
お湯はすぐ冷めてしまうので、溜めておくことはできません。
すべての人に計画通りにお湯を供給することはできますか？

典型的なDP問題
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll; 

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> volume(200005, 0);
    for(int i = 0; i < n; ++i) {
        int s, t, p;
        cin >> s >> t >> p;
        volume[s] += p;
        volume[t] -= p;
    }
    ll heater = 0;
    for(auto& elem: volume) {
        heater += elem;
        if(heater > w) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl; 
    return 0;
}