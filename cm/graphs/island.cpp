#include <iostream>
using namespace std;

char c[105][105]; // for map description .-water, #-earth
bool used[105][105];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};
int n, m;

void dfs(int i, int j) {
    used[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int i2 = i + di[k];
        int j2 = j + dj[k];
        if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < m 
                && c[i2][j2] == '#' && !used[i2][j2]) {
                    dfs(i2, j2);
                }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] && c[i][j] == '#') {
                dfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << endl;
}