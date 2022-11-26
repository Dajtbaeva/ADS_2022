#include <bits/stdc++.h>

using namespace std;
char adj_matrix[109][109];
bool visited[109][109];
int n, m, res;
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

void dfs(int i, int j) {
    visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
        int i2 = i + di[k];
        int j2 = j + dj[k];
		if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < m && adj_matrix[i2][j2] == '1' && !visited[i2][j2]) {
			dfs(i2, j2);
		}
	} 
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adj_matrix[i][j];
		}
	}
    
	for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(adj_matrix[i][j] == '1' && !visited[i][j]){
                dfs(i, j);
                res++;
                
            }
        }
	}
    cout << res;
}