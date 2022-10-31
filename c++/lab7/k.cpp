#include <bits/stdc++.h>

using namespace std;

int maxx = 0;
int maxi(string t, int i){
    if(i == t.size()) return maxx;
    if((t[i] - 48) > maxx) maxx = t[i] - 48;
    return maxi(t, i + 1);
}

int main(){
    string s;
    cin >> s;
    cout << maxi(s, 0);
}