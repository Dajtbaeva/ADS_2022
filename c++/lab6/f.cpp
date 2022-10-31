#include <bits/stdc++.h>

using namespace std;

void valid(string t, int a){
    int res = 0;
    for(int i = 0; i < t.size(); i++){
        if(char(t[i]) >= 48 && char(t[i]) <= 57) res++;
    }
    if(res >= a) cout << "YES";
    else cout << "NO";
}
int main(){
    string s;
    int n;
    cin >> s >> n;
    valid(s, n);
} 