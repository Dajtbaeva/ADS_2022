// Задача №49. Списки по классам
// https://informatics.msk.ru/mod/statements/view.php?chapterid=49#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    queue<string> q1, q2, q3;
    int n;
    string s;
    while(cin >> n >> s){
        if(n == 9) q1.push(s);
        else if(n == 10) q2.push(s);
        else if(n == 11) q3.push(s);
    }
    while(!q1.empty()){
        cout << "9 " << q1.front() << "\n";
        q1.pop();
    }
    while(!q2.empty()){
        cout << "10 " << q2.front() << "\n";
        q2.pop();
    }
    while(!q3.empty()){
        cout << "11 " << q3.front() << "\n";
        q3.pop();
    }
}