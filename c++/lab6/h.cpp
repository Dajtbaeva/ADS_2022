#include <bits/stdc++.h>

using namespace std;

void valid(string t){
    bool res = true;
    for(int i = 0; i < t.size(); i++){
        if((t[i] - 48) % 2 != 0) res = false;
    }
    if(res) cout << "Valid";
    else cout << "Not valid";
}
int main(){
    string s;
    cin >> s;
    valid(s);
}