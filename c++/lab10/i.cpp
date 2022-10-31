#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n;
    vector<int> v, w;
    while(n--){
        cin >> k;
        v.push_back(k);
        w.push_back(k);
    }
    reverse(w.begin(), w.end());
    for(int i = 0; i < v.size(); i++){
        if(v[i] == w[i]) cout << "OK\n";
        else cout << "Instead of " << v[i] << " here was " << w[i] << "\n";
    }
}