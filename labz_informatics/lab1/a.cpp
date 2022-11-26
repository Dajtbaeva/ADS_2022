// Задача №55. Стек с защитой от ошибок
// https://informatics.msk.ru/mod/statements/view.php?id=207&chapterid=55#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("a.txt", "r", stdin);
    stack<int> st;
    string s = "";
    while(s != "exit"){
        cin >> s;
        if(s == "push"){
            int a;
            cin >> a;
            st.push(a);
            cout << "ok\n";
        }
        if(s == "pop"){
            if(!st.empty()){
                cout << st.top() << "\n";
                st.pop();
            }else cout << "error\n";
        }
        if(s == "back"){
            if(!st.empty()) cout << st.top() << "\n";
            else cout << "error\n";
        }
        if(s == "size"){
            cout << st.size() << "\n";
        }
        if(s == "clear"){
            while(!st.empty()){
                st.pop();
            }
            cout << "ok\n";
        }
    }
    cout << "bye";
}