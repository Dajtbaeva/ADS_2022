#include <bits/stdc++.h>

using namespace std;

void lucky(string t){
    int res = 0;
    for(int i = 0; i < t.size(); i++){
        res += t[i] - 48;
    }
    if(res % 4 == 0) cout << "Yes";
    else cout << "No";
}
int main(){
    string s;
    cin >> s;
    lucky(s);
}