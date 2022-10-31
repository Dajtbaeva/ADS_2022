#include <bits/stdc++.h>

using namespace std;

long long gen(int x){
    return pow(x, x);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        cout << gen(i) << " ";
    }
}