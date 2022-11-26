#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e15 + 7;

int main(){
    string s; cin >> s;
    unordered_map<long long, int> mp;
 
    for(int i = 0; i < s.size(); i++){
      long long hash = 0;
      long long D = 97;
      for(int j = i; j < s.size(); j++){
        hash = (hash * D + s[j]) % MOD;
        if(mp.find(hash) == mp.end()) mp[hash] = 1;
      }
    }
    cout<<mp.size();
}