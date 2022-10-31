#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n;
    set<int> s;

    while(n--){
        cin >> x;
        s.insert(x);
    }
    int sumi = 0;
    set<int> :: iterator it;
    for(it = s.begin(); it != s.end(); it++){
        sumi += (*it);
    }
    cout << sumi;
}