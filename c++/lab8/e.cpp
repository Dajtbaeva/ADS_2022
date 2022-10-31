#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, l, r;
    cin >> n;
    vector<int> v;

    while(n--){
        cin >> x;
        v.push_back(x);
    }
    cin >> l >> r;

    v.erase(v.begin() + l, v.begin() + r + 1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}