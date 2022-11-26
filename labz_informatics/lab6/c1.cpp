// Задача №100. Строчки
// https://informatics.msk.ru/mod/statements/view.php?id=56133&chapterid=100#1

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    
    int res = 0, len; char tmp;
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
 
    len = s1.size();
    
    while (s1 != s2) {
        tmp = s2[0];
        for (int i = 0; i < len - 1; i++)
            s2[i] = s2[i+1];
        s2[len-1] = tmp;
        res++;
        if (res == len) break;
    }
    if (res != len) cout << res << "\n";
    else cout << "-1" << "\n";
    
    return 0;
}
