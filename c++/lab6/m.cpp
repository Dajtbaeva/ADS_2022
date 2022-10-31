#include <bits/stdc++.h>

using namespace std;

void rever(int n, int b[]){
    for(int i = n - 1; i >= 0; i--){
        cout << b[i] << " ";
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    rever(n, a);
}