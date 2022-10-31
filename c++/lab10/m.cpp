// unique x set
#include <bits/stdc++.h>
 
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a1, a2;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a1.push_back(t);
    }
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        a2.push_back(t);
    }
    // a1 = unify(a1);
    // a2 = unify(a2);
    vector<int>::iterator it1;
    it1 = unique(a1.begin(), a1.end() );
    a1.resize(distance(a1.begin(), it1) );
 
    vector<int>::iterator it2;
    it2 = unique(a2.begin(), a2.end() );
    a2.resize(distance(a2.begin(), it2) );
 
    n = a1.size();
    m = a2.size();
 
    int l = 0, r = 0;
 
    vector<int> ans;
    while(l<n and r<m){
        ans.push_back(a1[l]);
        l++;
        ans.push_back(a2[r]);
        r++;
    }
    while(l<n){
        ans.push_back(a1[l]);
        l++;
    }
    while(r<m){
        ans.push_back(a2[r]);
        r++;
    }
    
    vector<int>::iterator it3;
    it3 = unique(ans.begin(), ans.end() );
    ans.resize(distance(ans.begin(), it3) );
 
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}