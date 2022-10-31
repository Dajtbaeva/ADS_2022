#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    string s;
    cin >> n;
    map<string, int> m;
    for(int i = 0; i < n; i++){
        cin >> s >> x;
        if(m.find(s) == m.end()) m[s] = x;
        else m[s] += x;
    }
    map<string, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout << (*it).first << " " << (*it).second << "\n";
    }
}