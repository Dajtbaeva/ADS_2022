// Задача №52. Постфиксная запись
// https://informatics.msk.ru/mod/statements/view.php?chapterid=52#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<int> st;
    char c;
    while(cin >> c){
        if(c == '+'){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();            
            st.push(a + b);
        }
        else if(c == '-'){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(b - a);
        }
        else if(c == '*'){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(a * b);
        }
        else if(isdigit(c)){
            st.push(c - 48);
        }
    }
    cout << st.top();
}