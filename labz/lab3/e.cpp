// Задача №1440. Серебряная медаль
// https://informatics.msk.ru/mod/statements/view.php?id=54422&chapterid=1440#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int maxi = v[0];
    for(int i = 0; i < v.size(); i++){
        if(v[i] != maxi){
            cout << v[i];
            return 0;
        }
    }
}