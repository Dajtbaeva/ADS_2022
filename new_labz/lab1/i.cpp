#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    queue<int> s, k;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'S') s.push(i);
        else if(str[i] == 'K') k.push(i);
    }
    while(!s.empty() && !k.empty()){
        if(s.front() < k.front()){
            k.pop();
            int a = s.front() + n;
            s.pop();
            s.push(a);
        }else if(k.front() < s.front()){
            s.pop();
            int a = k.front() + n;
            k.pop();
            k.push(a);
        }
    }
    if(s.empty()) cout << "KATSURAGI";
    else cout << "SAKAYANAGI";

}