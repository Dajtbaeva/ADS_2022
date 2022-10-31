#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[m];
    for(int j = 0; j < m; j++){
        cin >> b[j];
    }
    int k = n + m;
    int c[k];
    for(int i = 0; i < n; i++){
        c[i] = a[i];
    }
    int q = 0;
    for(int i = n; i < k; i++){
        c[i] = b[q];
        q++;
    }
    sort(c, c + k);
    for(int i = 0; i < k; ++i){
        cout << c[i] << " "; 
    }

}