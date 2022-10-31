#include <bits/stdc++.h>

using namespace std;

void books(int n, int x[], int y){
    bool ok = false;
    for(int i = 0; i < n; i++){
        if(x[i] == y){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
int main(){
    int n, x;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;
    books(n, a, x);
}