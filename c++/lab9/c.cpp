#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, cnt = 0;
    cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(m.find(x) == m.end()) m[x] = 1;
        else m[x]++;
    }
    map<int, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        if((*it).second > 1) cnt++; 
    }
    cout << cnt;
}