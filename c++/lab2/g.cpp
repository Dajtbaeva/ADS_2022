#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int maxi = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > maxi) maxi = a[i];
    }
    cout << maxi;
}