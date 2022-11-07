#include <bits/stdc++.h>
using namespace std;

int n, f;


bool checker(int a[], int n, int k, int x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
       cnt += (a[i] + x - 1) / x;
    }
    return cnt <= k;
}

int binsearch(int a[], int n, int f){
    int l = 0;
    int r = 1000000001;
    
    while(l + 1 < r){
        int m = l + (r - l) / 2;
        if(checker(a, n, f, m)){
            r = m;
        }
        else{
            l = m;
        }
        //cout << l << " " << r << endl;
    }


    return r;
}

int main(){
    cin >> n >> f;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << binsearch(a, n, f);
    
}