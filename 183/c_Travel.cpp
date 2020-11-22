/*
N個の都市があります。都市iから都市jへ移動するにはTi,jの時間がかかります。
都市1を出発し、全ての都市をちょうど1度ずつ訪問してから都市1に戻るような経路のうち、
移動時間の合計がちょうどKになるようなものはいくつありますか？

(2 <= N <= 8)
1-8の数列は8!個の組み合わせがある
だから時間内で計算できる
*/
#include<bits/stdc++.h>

using namespace std;

// next_permutaion(计算排列组合)
void testNextPermutation() {
    vector<int> a = {1, 2, 3, 4};
    do {
        for(int i = 0; i < 4; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    } while(next_permutation(a.begin(), a.end()));
}

int main() {
    // testNextPermutation();
#if 1
    int n, k;
    cin >> n >> k;
    int city[8][8];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> city[i][j];
        }
    }
    vector<int> p;
    for(int i = 1; i < n; ++i) {
        p.push_back(i);
    }
    int ans = 0;
    // あらゆるの組み合わせをついて
    do {
        // 順番に経路の値をダス
        int total = city[0][p[0]];
        for(int i = 0; i < n-2; ++i) {
            total += city[p[i]][p[i+1]];
        }
        // 最後の町から最初の町までの値をダス
        total += city[p.back()][0];
        if(total == k) ++ans;
    } while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
#endif
    return 0;
}