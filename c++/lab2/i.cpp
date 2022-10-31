#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int sev = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 10 == 7) sev += 1;
    }
    cout << sev;
}