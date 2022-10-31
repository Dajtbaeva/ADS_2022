// All roads lead to Kalkaman
#include <bits/stdc++.h>

using namespace std;

int si, sj, fi, fj;
char maze[10][10];
bool ok;

void dfs(char maze[][10], int i, int j) {
    if (i == fi && j == fj) ok = true;
    if (i < 0 || i >= 10 || j < 0 || j >= 10 || maze[i][j] == '*') return;
    maze[i][j] = '*';
    dfs(maze, i - 1, j);
    dfs(maze, i + 1, j);
    dfs(maze, i, j + 1);
    dfs(maze, i, j - 1);
}

int main(){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> maze[i][j];
        }
    }
    cin >> si >> sj >> fi >> fj; // initial, then exit
    dfs(maze, si, sj);
    cout << (ok ? "Found))" : "Not found((");
}
/*
* * * * * . * * * *
* . . . * . * * . *
* * . * * . * * . *
* * . * * . . . . *
* * . * * * * * . *
* . . . . . . . . *
* . * * * . * * * *
* . * * * * * * * *
* . . . . . . . . *
* * * * * * * * . *
9 8
0 5
-----------------------
Found))
*/