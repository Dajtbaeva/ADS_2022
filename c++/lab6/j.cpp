#include <bits/stdc++.h>

using namespace std;

void maxi(int b[]){
    int res = pow(-10, 5);
    for(int i = 0; i < 4; i++){
        if(b[i] > res) res = b[i];
    }
    cout << res;
}
int main(){
    int a[4];
    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }
    maxi(a);
}