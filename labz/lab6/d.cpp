// Задача №1323. Префикс-функция
// https://informatics.msk.ru/mod/statements/view.php?id=56133&chapterid=1323#1

#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) { // KMP
    int n = s.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) 
            j = p[j - 1];
        if (s[i] == s[j]) 
            j++;
        p[i] = j;
    }
    return p;
}

int main(){
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    for (int i = 0; i < s.size(); i++)
        cout << p[i] << " ";
    return 0;
}