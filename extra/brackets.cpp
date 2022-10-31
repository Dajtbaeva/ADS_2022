// Brackets sequence
#include <bits/stdc++.h>

using namespace std;

string t;
bool brackets(string t){
    stack<char> a;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '(' || t[i] == '{' || t[i] == '['){
            a.push(t[i]);
        }
        else if(a.empty()) return false;
        else{
            char top = a.top();
            a.pop();
            if((t[i] != ')' && top == '(') || (t[i] != '}' && top == '{') || (t[i] != ']' && top == '[')){
                return false;
            }
            
        }
    }
    return a.empty();
}

int main(){
    string s;
    cin >> s;
    brackets(s) ? cout << "Yes" : cout << "No";
}
/*
([{])({})([]) NO
([{])({})([]) YES
*/