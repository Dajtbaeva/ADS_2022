#include <bits/stdc++.h>

using namespace std;

int fib(int x){
    if(x == 1) return 0;
    if(x == 2) return 1;
    if(x == 3) return 1;
    return fib(x - 1) + fib(x - 2); 
}

int main(){
    int n;
    cin >> n;
    cout << fib(n);
}