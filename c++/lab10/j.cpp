#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m;
    vector<int> v;
    while(n--){
        cin >> k;
        v.push_back(k);
    }
    rotate(v.begin(), v.begin() + m, v.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}