#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int even = 0;
    int odd = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) even += 1;
        else odd += 1;
    }
    cout << even << " " << odd;
}