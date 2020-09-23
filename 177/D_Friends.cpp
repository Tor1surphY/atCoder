/*
人1から人NまでのN人の人がいます。
「人Aiと人Biは友達である」という情報がM個与えられます。
同じ情報が複数回与えられることもあります。

XとYが友達、かつ、YとZが友達ならば、XとZも友達です。
また、M個の情報から導くことができない友達関係は存在しません。

悪の高橋君は、このN人をいくつかのグループに分け、
全ての人について「同じグループの中に友達がいない」という状況を作ろうとしています。
最小でいくつのグループに分ければ良いでしょうか？
*/
#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>

#define rep(i ,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

class UnionFind{
public:
    //　友達集合をつくる
    //　各rの値はその人がいるの友達のrootです
    //　もしその人はrootの時、値はその友達関係の人数です
    //　人数はマイナスです
    UnionFind(int& n) { r = vector<int>(n+1, -1); }

    //　ｘのrootを探す
    int findRoot(int x){
        if(r[x] < 0) return x;
        else         return findRoot(r[x]);
    }

    //　ひとつのペアーについて、二人のrootを探す
    //　rootが同じなら、この二人は既に友達関係を分かる
    //　そのときは、次に進む
    //　もしrootが同じじゃない時、まず小さいの人は前に
    //　この時、小さいの方がその友達関係のrootを見られる
    //　で、二人がいるの友達関係を一つに合併する
    void unite(int& x, int& y){
        x = findRoot(x);
        y = findRoot(y);
        if (x == y)      return;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
    }

    //　rootのr[x]について、そのｘの友達の数を計算する
    int size(int& x) { return -r[findRoot(x)]; }

private:
    vector<int> r;
};


int main(){
    int n, m, a, b;
    cin >> n >> m;

    UnionFind uf(n);
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        uf.unite(a, b);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) ans = max(ans, uf.size(i));
    cout << ans << endl;
    return 0;
}

/*
并查集：
以亲戚关系为例，本质上是把有亲戚关系的人都放到一个集合里面
本题的实现形式为：
    创建和人数大小相同的数组
    每个人的下标都是-1，表示每个人都没有朋友
    每次出现一个pair，就把数字小的那一个当作这个关系的root
    首先把root的值相加，每个root代表这个关系圈子里的人的个数
    不是root的人的值就是他root的下标
    
    每次只需要找到pair中两个节点的根节点
    然后按照上述方法unite即可
*/