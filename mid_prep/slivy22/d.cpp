#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main(){
    ull n; cin >> n; ull cnt = 0;
    set<ull> s;
    int i = 2;
    while(i <= n){
        if(n % i == 0){
            n /= i;
            s.insert(i);
        }else i++;
    }
    cout << s.size();
}