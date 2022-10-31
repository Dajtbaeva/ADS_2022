#include <bits/stdc++.h>

using namespace std;

int n, x;
bool bin(int a[], int i){
    if(i == n) return false;
    if(a[i] == x) return true;
    return bin(a, i + 1); 
}

int main(){
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;
    bin(a, 0) ? cout << "Yes" : cout << "No";
}