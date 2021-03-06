/*
あなたはオンラインゲーム「ATChat」のチュートリアルを終え、
その場に居合わせたプレイヤーN人で早速とある場所を訪ねることにしました。
このN人には1からNの番号が振られており、人 i(1 ≤ i ≤ N)のフレンドリーさはAiです。

訪ねる際、N人は好きな順番で1人ずつ到着します。
あなたたちは迷子にならないために、既に到着した人たちで環状に並び、
新たに到着した人は好きな位置に割り込んで加わるというルールを決めました。

最初に到着した人以外の各人は、割り込んだ位置から到着した時点で
「時計回りで最も近い人」と「反時計回りで最も近い人」
のフレンドリーさのうち小さい方に等しい心地よさを感じます
最初に到着した人の心地よさは0です。

N人が到着する順番や割り込む位置を適切に決めたとき、
N人の心地よさの合計の最大値はいくらになるでしょう？
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    int t = n-1;
    rep(i, n){
        int cnt = 2;
        if(0 == i) cnt = 1;
        rep(j, cnt){
            if(t > 0){
                ans += a[i];
                --t;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
总结：
    循环还是从小到大循环的好，所以排序的时候要注意
    特殊情况不一定要拿到循环外单独实现，在循环内设置条件也可以
    多思考哪里是可以优化的部分，减轻思考的负担
*/