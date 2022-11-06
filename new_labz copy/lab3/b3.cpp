#include <bits/stdc++.h>
using namespace std;

vector <unsigned long long> v;
unsigned long long n;

bool check(vector <unsigned long long> &v, unsigned long long mid, unsigned long long k){
    unsigned long long cnt = 1;
    unsigned long long sumi = 0;
    for(unsigned long long i = 0; i < n; i++){
        sumi += v[i];
        if(sumi > mid){
            cnt++;
            if(cnt > k){
                return false;
            }
            sumi = v[i];
        }
    
    }
    return true;
}




int main(){
    unsigned long long k;  cin >> n >> k;

    unsigned long long x;
    for(unsigned long long i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    unsigned long long ans = -1;
    unsigned long long l = 0, r = 0;
    for(unsigned long long i = 0; i < n; i++){
        l = max(l, v[i]);
        r += v[i];
    }

    while(l <= r){
        unsigned long long m = l + (r - l) / 2;

        if(check(v, m, k)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }

    cout << ans;
}