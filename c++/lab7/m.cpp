#include <bits/stdc++.h>

using namespace std;

int rec(int x){
    if(x > 1) rec(x - 1);
    cout << x << " "; 
}

int main(){
    int n;
    cin >> n;
    rec(n);
}