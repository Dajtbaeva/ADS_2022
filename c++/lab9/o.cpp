#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    string l, p, l1, p1;
    map<string, string> m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> l >> p;
        m[l] = p;
    }
    cin >> x;
    for(int i = 0; i < x; i++){
        cin >> l1 >> p1;
        if(m.find(l1) != m.end()){
            if(m[l1] == p1) cout << "correct password\n";
            else cout << "password error\n";
        }else cout << "login error\n";
    }
}