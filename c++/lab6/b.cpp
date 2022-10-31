#include <bits/stdc++.h>

using namespace std;

void dif(int n, int x[], int y[]){
    for(int i = 0; i < n; i++){
        cout << abs(x[i] - y[i]) << " ";
    }
}
int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int j = 0; j < n; j++){
        cin >> b[j];
    }
    dif(n, a, b);
}