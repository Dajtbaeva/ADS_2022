#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, cnt = 0;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < v.size(); i++){
        int a = 0;
        for(int j = i + 1; j < v.size(); j++){
            a = v[i] ^ v[j];
            if(find(v.begin(), v.end(), a) != v.end()) cnt++;
        }
    }
    cout << cnt;
}