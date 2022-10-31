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
    cout << s.size();
}