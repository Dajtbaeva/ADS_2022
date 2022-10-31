// Задача №58. Очередь с защитой от ошибок
// https://informatics.msk.ru/mod/statements/view.php?id=207&chapterid=58#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("b.txt", "r", stdin);
    queue<int> q;
    string s = "";
    while(s != "exit"){
        cin >> s;
        if(s == "push"){
            int a;
            cin >> a;
            q.push(a);
            cout << "ok\n";
        }
        if(s == "pop"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            }else cout << "error\n";
        }
        if(s == "front"){
            if(!q.empty()) cout << q.front() << "\n";
            else cout << "error\n";
        }
        if(s == "size"){
            cout << q.size() << "\n";
        }
        if(s == "clear"){
            while(!q.empty()){
                q.pop();
            }
            cout << "ok\n";
        }
    }
    cout << "bye";
}