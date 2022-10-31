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
    for(int i = 0; i < v.size(); i++){
        if(v[i] == k){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}