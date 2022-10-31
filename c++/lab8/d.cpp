#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, k;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    cin >> k;
    v.erase(v.begin() + k);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

}