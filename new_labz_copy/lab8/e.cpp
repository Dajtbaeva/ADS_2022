#include <bits/stdc++.h>

using namespace std;
/*
order(si) * pow(2, i)
order(a) = 0
7 15 59 147 371 -> hello
hi = hi - 1 + ord(si) * pow(2,i)

ord(si) = (hi - h(i-1)) / pow(2, i)
char('a' + 7)
*/

string rabinKarp(vector<long long> v){
    long long curX = 2;
    string res = "";
    res += char('a' + v[0]);
    for(int i = 1; i < v.size(); i++){
        
        res += char('a' + ((v[i] - v[i - 1]) / curX));
        curX *= 2;
    }
    return res;
}

int main(){
    long long n; // 1 <= n <= 50
    cin >> n;
    vector<long long> v;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        v.push_back(x);
    }
    cout << rabinKarp(v);
}