// Задача №226. Линейный поиск - 3
// https://informatics.msk.ru/mod/statements/view.php?id=54422#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, k;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    cin >> k;
    vector<int> ans;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == k) ans.push_back(i + 1);
    }
    if(!ans.empty()){
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
    }else return 0;
}