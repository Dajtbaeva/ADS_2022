// Задача №100. Строчки
// https://informatics.msk.ru/mod/statements/view.php?id=56133&chapterid=100#1

#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) { // KMP
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    string k = s + "#" + t + t;
    vector<int> v = prefix_function(k);
    for(int i = 0; i < v.size(); i++){
        if(v[i] == n){
            cout << i - n - n;
            return 0;
        } 
    }
    cout << -1;
}