// Задача №228. Номер максимального элемента массива
// https://informatics.msk.ru/mod/statements/view.php?id=54422&chapterid=228#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, res = 0;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    int maxi = -99999;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > maxi){
            maxi = v[i];
            res = i;
        } 
    }
    cout << res + 1;
}