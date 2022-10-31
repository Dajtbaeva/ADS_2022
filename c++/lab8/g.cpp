#include <bits/stdc++.h>

using namespace std;

bool isprime(int a){
    for(int i = 2; i < sqrt(a); i++){
        if(a % i == 0) return false;
    }
    return true; 
}

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
        if(isprime && v[i] > k) cnt++;
    }
    cout << cnt;
}