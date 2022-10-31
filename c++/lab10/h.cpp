#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n;
    vector<int> v;
    while(n--){
        cin >> k;
        if(find(v.begin(), v.end(), k) == v.end()) v.push_back(k);
    }
    do{
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        } cout << "\n";
    }while(next_permutation(v.begin(), v.end()));
}