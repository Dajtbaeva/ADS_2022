#include <bits/stdc++.h>

using namespace std;

int to_int(string s){
    int res = 0;
    int one = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        res += (s[i] - 48) * one;
        one *= 10;
    }
    return res;
}

int main(){
    string k = "123";
    int res = to_int(k);
    cout << res + 2;

}