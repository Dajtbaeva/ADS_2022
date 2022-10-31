#include <bits/stdc++.h>

using namespace std;

bool isprime(int a){
    if(a == 0 || a == 1 || a == -1) return false;
    for(int i = 2; i <= sqrt(abs(a)); i++){
        if(abs(a) % i == 0) return false;
    }
    return true;
}

int main(){
    int n, k;
    cin >> n;
    vector<int> v;
    while(n--){
        cin >> k;
        v.push_back(k);
    }
    int res = count_if(v.begin(), v.end(), isprime);
    cout << res;
}