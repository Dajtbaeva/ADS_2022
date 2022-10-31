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
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int sumi = 0;
    for(int i = 0; i < k; i++){
        sumi += v[i];
    }
    cout << sumi;
}