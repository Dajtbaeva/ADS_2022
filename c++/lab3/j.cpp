#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, index;
    cin >> n >> m;
    int a[n];
    bool flag = false;
    int pos = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] == m){
            index = i + 1;
            flag = true;
        }
    }
    if(flag){
        cout << index;
    }else{
        for(int i = 0; i < n; i++){
            if(m > a[i]){
                pos++;
            }
        }
        cout << pos;
    }
}