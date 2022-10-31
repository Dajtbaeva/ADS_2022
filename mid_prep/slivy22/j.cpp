#include <bits/stdc++.h>

using namespace std;

int main(){
    int m; cin >> m;
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        int l = i + 1, r = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            // cout << mid << " " << v[mid] << "\n";
            if(v[i] + v[mid] == m){
                cout << v[i] << " " << v[mid];
                return 0;
            }else if(v[i] + v[mid] < m) l = mid + 1;
            else r = mid - 1;
        }
    }
}