#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s = "";
    while(n != 0){
        s += char(n % 2 + 48);
        n /= 2;
    }
    int res = 0;
    int k = 1;
    for(int i = 0; i < s.size(); i++){
        res += int(s[i] - 48) * pow(2, s.size() - k);
        k += 1;
    }
    cout << res;
}