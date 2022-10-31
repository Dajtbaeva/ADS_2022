#include <bits/stdc++.h>
// ne pravilnyi kod
using namespace std;

int res = 0;
int even(string t, int i){
    if(i == t.size()) return res;
    if((t[i] - 48) % 2 == 0) return res++;
    return even(t, i + 1);
}

int main(){
    string s;
    cin >> s;
    cout << even(s, 0);
}