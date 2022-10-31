#include <bits/stdc++.h>

using namespace std;

int deg(int x){
    if(x == 0) return 1;
    return 2 * deg(x - 1); 
}

int main(){
    int n;
    cin >> n;
    cout << deg(n);
}