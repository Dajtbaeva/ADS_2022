#include <bits/stdc++.h>

using namespace std;

int girls(int a, int b){
    return (b * 100) / a;
}
int main(){
    int x, g;
    cin >> x >> g;
    cout << girls(x, g);
}