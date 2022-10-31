// Strings again

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t = "", left;
    cin >> s;
    vector<string> v;
    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
        if(s[i] == ','){
            v.push_back(t);
            t.clear();
            continue;
        }
        t += s[i];
    } v.push_back(t);

    int maxi = 0;
    for(int i = 0; i < v.size(); i++){
        map<char, int> m;
        for(int j = 0; j < v[i].size(); j++){
            m[v[i][j]]++;
        }
        map<char, int> :: iterator it1;
        int cnt = 0;
        for(it1 = m.begin(); it1 != m.end(); it1++){
            if(it1->second > 1) cnt++;
        } 
        if(cnt > maxi){
            maxi = cnt;
            left = v[i];
        }
    }
    if(maxi == 0) cout << -1;
    else{
        reverse(left.begin(), left.end());
        cout << left;
    }
    
}
/*
1221,1234,456,abc22aa
1-2  ---- ---  a - 3
2-2            2 - 2
s : 2          s : 2  // 2 characters are cont  
*/    