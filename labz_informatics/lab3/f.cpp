// Задача №1447. Контроперация
// https://informatics.msk.ru/mod/statements/view.php?id=54422&chapterid=1447#1

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
    int maxi = *max_element(v.begin(), v.end());
    int mini = *min_element(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if(v[i] == maxi) v[i] = mini;
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}