/*
a-zに使って、26進数を実装せよ
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    long long n;
    cin >> n;
    char a[26] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'
    };
    string ans = "";
    long long mod = 0;
    while(n != 0){
        --n;
        mod = n%26;
        ans += a[mod];
        n /= 26;
    }
    for(int i = ans.length()-1; i >= 0; --i){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}