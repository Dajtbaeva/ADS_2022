// hod konem

#include <bits/stdc++.h>

using namespace std;

int a[8][8];
queue<pair<int, int> > q;

void step(int x, int y, int v){
    if(x >= 0 && y >= 0 && x < 8 && y < 8){
        if(a[x][y] == -1){
            q.push(make_pair(x, y));
            a[x][y] = v;
        }
    }
}

int main(){
    //freopen("output.txt", "w", stdout);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            a[i][j] = -1;
        }
    }

    int a0, b; // initial coordinates
    cin >> a0 >> b;
    a0--; b--;

    a[a0][b] = 0;
    q.push(make_pair(a0, b));

    while(!q.empty()){
        int r = q.front().first;
        int l = q.front().second;
        q.pop();
        step(r + 1, l + 2, a[r][l] + 1);
        step(r + 1, l - 2, a[r][l] + 1);
        step(r - 1, l + 2, a[r][l] + 1);
        step(r - 1, l - 2, a[r][l] + 1);
        step(r + 2, l + 1, a[r][l] + 1);
        step(r + 2, l - 1, a[r][l] + 1);
        step(r - 2, l + 1, a[r][l] + 1);
        step(r - 2, l - 1, a[r][l] + 1);
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << a[i][j] << " ";
        } cout << '\n';
    }
}
/*
2 2
4 3 2 1 2 3 4 3 
3 0 3 2 3 2 3 4 
2 3 2 1 2 3 4 3 
1 2 1 4 3 2 3 4 
2 3 2 3 2 3 4 3 
3 2 3 2 3 4 3 4 
4 3 4 3 4 3 4 5 
3 4 3 4 3 4 5 4 
*/