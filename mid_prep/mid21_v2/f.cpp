#include <bits/stdc++.h>

using namespace std;

unsigned long long n, a1, a2, a3;

bool check(unsigned long long mid){
    int cnt = mid / a1 + mid / a2 + mid / a3;
    return cnt >= n;
}

int main(){
    cin >> n >> a1 >> a2 >> a3;
    unsigned long long l = 0, r = 1e12 / 3, res = 0;
    while(r - l > 1){
        unsigned long long mid = l + (r - l) / 2;
        if(check(mid)){
            r = mid;
        }else l = mid + 1;
    }
    cout << r;
}