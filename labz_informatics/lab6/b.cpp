// Задача №1327. Период строки
// https://informatics.msk.ru/mod/statements/view.php?id=56133&chapterid=1327#1

#include <bits/stdc++.h>
using namespace std;


vector<int> prefix_func(string s) { //KMP
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i]) 
            j = p[j - 1];
        if (s[j] == s[i])
            j++;
        p[i] = j;
    }
    return p;
}


int main(){
    string s;
    cin >> s;
    vector <int>  p = prefix_func(s);
    int a = s.size() - p[p.size() - 1]; // период сколько раз повторяется подстрока 
    if(s.size() % a == 0){
        cout << s.size() / a;
    }
    else cout << 1;
}