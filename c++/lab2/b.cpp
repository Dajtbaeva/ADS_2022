#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n % 2 == 0){
        if(n <= 5 && n >= 2) cout << "Not Super";
        else if(n <= 20 && n >= 6) cout << "Super";
        else cout << "Not Super";
    }
    else cout << "Super";
}