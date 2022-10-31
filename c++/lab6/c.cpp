#include <bits/stdc++.h>

using namespace std;

int same(int n, int x[], int y[]){
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(x[i] == y[j] && y[j] != 0){
                res++;
                y[j] = 0;
            } 
        }
    }
    cout << res;
}
int main(){
    int n, x;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    cin >> x;
    same(n, a, b);
}