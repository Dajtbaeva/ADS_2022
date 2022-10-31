#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, k, cnt = 0;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    cin >> k;
    sort(v.begin(), v.end());
    for(int i = 0; i < k; i++){
        cout << v[i] << " ";
    }
}