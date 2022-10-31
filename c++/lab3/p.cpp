#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int m = sqrt(n);
    if(pow(m, 2) == n) cout << "Yes";
    else cout << "No";
}