#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int z = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        while(a[i] != 0){
            if(a[i] % 10 == 0) z += 1;
            a[i] /= 10;
        }
    }
    cout << z;
}