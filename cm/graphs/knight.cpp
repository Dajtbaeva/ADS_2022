#include <iostream>
#include <queue>
using namespace std;

char c[105][105]; // for map description .-water, #-earth
bool used[105][105];
int di[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dj[8] = {1, -1, 1, -1, 2, 2, -2, -2};
queue<pair<int, int> > q;
int d[105][105]; // d[x][y] = length of min path from start to (x, y);
int n, m;

int bfs(int sx, int sy, int fx, int fy) {
    d[sx][sy] = 0;
    q.push(make_pair(sx, sy));
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int k = 0; k < 8; k++) {
            int x2 = x + di[k];
            int y2 = y + dj[k];
            if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && !used[x2][y2]) {
                used[x2][y2] = true;
                q.push(make_pair(x2, y2));
                d[x2][y2] = d[x][y] + 1;
            }
        }
    }
    return d[fx][fy];
}

int main() {
    cin >> n >> m;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    cout << bfs(sx, sy, fx, fy) << endl;
}

// S....
// ...2.
// .1...
// ....3
// .....