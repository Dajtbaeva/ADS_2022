// Задача №112984. Гоблины и шаманы
// https://informatics.msk.ru/mod/statements/view.php?chapterid=112984#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    queue<int> q;
    int n, m, a = 0;
    char c;
    cin >> n;
    while(n--){
        cin >> c;
        if(c == '+'){
            cin >> m;
            q.push(m);
        } 
        else if(c == '-'){
            cout << q.front() << "\n";
            q.pop();
            a++;
        }
        else if(c == '*'){
            cin >> m;

        }
    }

}