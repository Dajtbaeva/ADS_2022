#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int t = 1;
    
    long long mod = 9007199254740881;
    string s; cin >> s;
    for(int i = 0; i < t; i++)
    {
     
        vector<vector<long long> >l;
    
        unordered_map<long long,int>d;
    
        for(int i=0;i<s.length();i++){
        int suma = 0;
        long long pre = 0;
    
        long long D = 256;
    
        for(int j=i;j<s.length();j++){
    
            pre = (pre*D+s[j]) % mod;
    
            if(d.find(pre) == d.end())
            l.push_back({i, j});
            d[pre] = 1;
        }
        }
    
        cout<<l.size()<<endl;
    }
}
 