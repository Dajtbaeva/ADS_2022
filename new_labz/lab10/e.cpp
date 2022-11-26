// KH2O - potassium hydroxide???
#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, q, x, y, z; 
	cin >> m >> q;
	int adj_matrix[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adj_matrix[i][j];
		}
	}
    for(int i = 0; i < q; i++){
        cin >> x >> y >> z;
        if(adj_matrix[x - 1][y - 1] && adj_matrix[x - 1][z - 1] && adj_matrix[y - 1][z - 1]) cout << "YES\n";
        else cout << "NO\n";
    }
}