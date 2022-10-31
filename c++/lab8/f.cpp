#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, j, k;
    cin >> n;
    vector<int> v;

    while(n--){
        cin >> x;
        v.push_back(x);
    }
    cin >> j >> k;
    v.insert(v.begin() + j, k);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}