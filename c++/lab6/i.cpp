#include <bits/stdc++.h>

using namespace std;

void capital(string t){
    bool res = true;
    for(int i = 0; i < t.size(); i++){
        if(i % 2 == 0) t[i] = t[i] - 32;
        cout << t[i];
    }
}
int main(){
    string s;
    cin >> s;
    capital(s);
}