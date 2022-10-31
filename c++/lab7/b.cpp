#include <bits/stdc++.h>

using namespace std;

string s;
string tobinary(int x){
    if(x == 0) return s;
    s = char(x % 2 + 48) + s;
    return tobinary(x / 2); 
}

int main(){
    int n;
    cin >> n;
    cout << tobinary(n);
}