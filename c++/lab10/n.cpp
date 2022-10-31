#include <bits/stdc++.h>

using namespace std;

bool pali(vector<int> v){
    int l = 0;
    int r = v.size() - 1;
    while(l <= r){
        if(v[l] != v[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main(){
    int n, x;
    cin >> n;
    vector<int> v;
    while(n--){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    bool ok = false;
    while(next_permutation(v.begin(), v.end())){
        if(pali(v)){
            ok = true;
            for(int i = 0; i < v.size(); i++){
                cout << v[i] << " ";
            }
            break;
        }
    }
    if(!ok) cout << "Impossible";

}