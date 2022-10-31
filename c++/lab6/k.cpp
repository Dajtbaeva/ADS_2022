#include <bits/stdc++.h>

using namespace std;

void sumi(string t){
    int res = 0;
    for(int i = 0; i < t.size(); i++){
        res += t[i] - 48;
    }
    cout << res;
}
int main(){
    string s;
    cin >> s;
    sumi(s);
}