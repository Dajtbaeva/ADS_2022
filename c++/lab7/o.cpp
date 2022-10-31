#include <bits/stdc++.h>

using namespace std;

string res = "";
string kinary(int n, int k){
    if(n == 0) return res;
    if((n % k) > 9) res = char((n % k) + 55) + res;
    else res = char((n % k) + 48) + res;
    return kinary(n / k, k);
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << kinary(n, k);
}