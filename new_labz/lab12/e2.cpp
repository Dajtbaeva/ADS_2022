#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
int main(){
    int n,m=0;
    cin>> n;
    vector<vector<pair<int,ll int > > >graph(n+1);
    for(int i=0;i<n;i++){
        for(int j = 0; j < n ;j++){
            ll c; cin >> c;
            if(c == 100000) continue;
            graph[i+1].push_back({j+1,c});
            m++;
        }
    } 

    vector<ll int >dist(n+1,1e14),par(n+1,-1);

    // applying bellman ford algo.

    for(int i=1;i<n;i++){
       for(int j=1;j<=n;j++){
           for(auto k:graph[j]){
                ll int node=k.first,c=k.second;
                if(dist[node]>c+dist[j]){
                    dist[node]=c+dist[j];
                    par[node]=j;
                }
           }
       }
    }


    // checking nth iteration 


    bool flag=false;
    for(int i=1;i<=n;i++){
       for(auto k:graph[i]){
          ll int node=k.first,c=k.second;
          if(dist[node]>c+dist[i]){
             dist[node]=c+dist[i];
             par[node]=i;
             flag=true;
          }
            
          if(flag){

            // negative cycle founded
            
            cout<<"YES"<<endl;

            vector<int >ans;
            vector<bool>vis(n+1,false);


            //  loop for finding the start of cycle
            while(!vis[i]){
                vis[i]=true;
                i=par[i];
            }

            
            // pushing the nodes of path in vector(ans).

            int u=i;
            ans.push_back(u);
            u=par[u];
            while(u^i){
                ans.push_back(u);
                u=par[u];
            }
            ans.push_back(u);
            reverse(ans.begin(),ans.end());


            //printing path
            cout << ans.size() << endl;
            for(auto z:ans)cout<<z<<" ";
            return 0;
            }
       }
    }   

    if(!flag)cout<<"NO"<<endl;
}