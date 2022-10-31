#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string longest = "";
    while(ss >> s){
        if(s.size() > longest.size()) longest = s;
    }
    cout << longest << "\n" << longest.size();
    return 0;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') cnt++;
        else cnt++;
    }
    cout << cnt + 1;
}