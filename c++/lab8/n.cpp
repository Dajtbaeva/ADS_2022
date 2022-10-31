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

    set<int> :: iterator it;
    for(it = s.begin(); it != s.end(); it++){
        if((*it) % 2 != 0) cout << (*it) << " ";
    }
}