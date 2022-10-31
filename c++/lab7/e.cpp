#include <bits/stdc++.h>

using namespace std;

int res = 0;
int divide(int x){
    if(x == 1) return true;
    if(x % 2 != 0) return false;
    return divide(x / 2);
}

int main(){
    int n;
    cin >> n;
    divide(n) ? cout << "Yes" : cout << "No";
}