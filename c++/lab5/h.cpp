#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int maxi = 0;
    int ok = 0;
    for(int i = 0; i < s.size(); i++){
        a[s[i] - 48]++;
    }
    for(int i = 0; i < 10; i++){
        if(a[i] > maxi) maxi = a[i];
    }
    for(int i = 0; i < 10; i++){
        if(a[i] == maxi || a[i] == 0) ok++;
    }
    if(ok == 10) cout << "YES";
    else cout << "NO";
}