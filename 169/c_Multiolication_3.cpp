/*
A×Bの小数点以下を切り捨て、結果を整数として出力してください。

0 ≤ A ≤ 1e15
0 ≤ B < 10 
Aは整数
Bは小数第2位まで与えられる
*/
#include <iostream>
using namespace std;

typedef long long LL;

int main(){
    LL a;
    double b;
    cin >> a >> b;
    b = b * 100 + 1e-3;
    cout << a*(LL)b/100 << endl;
    return 0;
}

/*
Bを100倍して整数に変換する際にも誤差に注意してください。
*/

// 为什么要+ 1e-3?
// 精度丢失，比如5实际上是4.9999999，保留两位小数情况下的误差就是1e-3?