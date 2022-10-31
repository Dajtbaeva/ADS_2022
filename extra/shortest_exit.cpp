// Shortest exit
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    char c;
    cin >> s >> c;
    vector<int> v, ans;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == c ) v.push_back(i); // 2, 6
    }
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < v.size(); j++){
            int k = abs(v[j] - i);
            ans.push_back(k);
        }
        cout << *min_element(ans.begin(), ans.end()) << " ";
        ans.clear();
    }
}
/*
bobahaboba
b
---------------------
0 1 0 1 2 1 0 1 0 1
*/