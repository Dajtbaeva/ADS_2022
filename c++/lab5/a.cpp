#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int b = 0;
    int m = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(65 <= char(s[i]) <= 90) b++;
        else if(97 <= char(s[i]) <= 122) m++;
    }
    cout << m << " " << b;
}