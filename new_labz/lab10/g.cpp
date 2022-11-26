#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> g[505];
vector<int> verticesIncycle;
int used[505];
stack<int> st;

bool dfs(int v, int a, int b){ // hasCycle or no
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(v == a && b == to) continue;
        if(!used[to]){
            if(dfs(to, a, b)) return true;
        }else if(used[to] == 1){
            return true;
        }
    }
    used[v] = 2;
    return false;
}

bool dfs2(int v) {
    used[v] = 1;
    st.push(v);
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(!used[to]){
            if(dfs2(to)) return true;
        }else if(used[to] == 1){
            while(st.top() != to){
                verticesIncycle.push_back(st.top());
                st.pop();
            }
            verticesIncycle.push_back(to);
            verticesIncycle.push_back(v);
            reverse(verticesIncycle.begin(), verticesIncycle.end());
            return true;
        }
    }
    used[v] = 2;
    if(!st.empty()) st.pop();
    return false;
}
 
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
    bool cycle = false;
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cycle = dfs2(i);
            if(cycle) break;
        } 
    }
    if(!cycle){
        cout << "YES";
        return 0;
    }

    for(int i = 0; i < verticesIncycle.size() - 1; i++){
        int u = verticesIncycle[i];
        int v = verticesIncycle[i + 1];
        for(int j = 1; j <= n; j++){
            used[j] = 0;
        }
        cycle = false;
        for(int j = 1; j <= n; j++){
            if(!used[j]){
                // if(dfs(j, u, v)){
                //     cout << "YES";
                //     return 0;
                // }
                cycle |= dfs(j, u, v);
            }
        }
        if(!cycle){
            cout << "YES";
            return 0;
        }

    }
    cout << "NO";
}