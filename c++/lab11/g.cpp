#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n;
    string s;
    map<string, set<int> > m;
    for(int i = 0; i < n; i++){
        cin >> s >> x;
        m[s].insert(x);
    }
    map<string, set<int> > :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
        if((*it).second.size() >= 3) cout << (*it).first << " " << "+1\n";
        else cout << (*it).first << " " << "NO BONUS\n";
    }
}