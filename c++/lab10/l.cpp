#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        vector<int> v(i);
        fill(v.begin(), v.end(), i);
        for(int j = 0; j < v.size(); j++){
            cout << v[j] << " ";
        }
    }
}