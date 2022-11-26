// Задача №61. Дек с защитой от ошибок
// https://informatics.msk.ru/mod/statements/view.php?id=207&chapterid=61#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("c.txt", "r", stdin);
    deque<int> d;
    string s = "";
    while(s != "exit"){
        cin >> s;
        if(s == "push_front"){
            int a;
            cin >> a;
            d.push_front(a);
            cout << "ok\n";
        }
        if(s == "push_back"){
            int a;
            cin >> a;
            d.push_back(a);
            cout << "ok\n";
        }
        if(s == "pop_front"){
            if(!d.empty()){
                cout << d.front() << "\n";
                d.pop_front();
            }else cout << "error\n";
        }
        if(s == "pop_back"){
            if(!d.empty()){
                cout << d.back() << "\n";
                d.pop_back();
            }else cout << "error\n";
        }
        if(s == "front"){
            if(!d.empty()) cout << d.front() << "\n";
            else cout << "error\n";
        }
        if(s == "back"){
            if(!d.empty()) cout << d.back() << "\n";
            else cout << "error\n";
        }
        if(s == "size"){
            cout << d.size() << "\n";
        }
        if(s == "clear"){
            while(!d.empty()){
                d.pop_back();
            }
            cout << "ok\n";
        }
    }
    cout << "bye";
}