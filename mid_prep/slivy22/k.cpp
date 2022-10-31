#include <bits/stdc++.h>

using namespace std;

#define ull long long 

int main(){
    ull n; cin >> n;
    deque<ull> d;
    string c = "head";
    for(int i = 0; i < n; i++){
        ull x; cin >> x;
        if(x == 1){
            ull z; cin >> z;
            if(c == "head") d.push_front(z);
            else d.push_back(z);
        }else{
            c = (c == "head") ? "tail" : "head";
        }
    }
    if(c == "tail"){
        for(int i = 0; i < d.size(); i++){
            cout << d[i] << " ";
        }
    }else{
        for(int i = d.size() - 1; i >= 0; i--){
            cout << d[i] << " ";
        }

    }
}