#include <bits/stdc++.h>

using namespace std;

int res = 0;
int sumi(int x){
    cin >> x;
    res += x;
    if(x == 0) return res;
    return sumi(x);
}

int main(){
    int n;
    cout << sumi(n);
}