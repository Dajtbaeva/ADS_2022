#include <bits/stdc++.h>

using namespace std;

int pos(int a){
    if(a < 0) return a * (-1);
    else return a;
}
int main(){
    int x;
    cin >> x;
    cout << pos(x);
}