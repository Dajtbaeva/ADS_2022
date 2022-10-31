#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cnt = 0;
    string s;
    cin >> n;
    map<string, int> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(m.find(s) == m.end()) m[s] = 1;
        else m[s]++;
    }
    map<string, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        if((*it).second == 3) cnt++; 
    }
    cout << cnt;
}