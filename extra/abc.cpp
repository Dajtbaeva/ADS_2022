// ABC'FS 
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x = n * 2 - 1;
    string s = "";
    for(int i = 0 ; i < x ; ++i){
        if(i < n){
            s += 'a' + n - i - 1;
        }else{
            s += 'a' + i - n + 1;
        }
    } // main string in the middle
    string t = s;
    vector<string> v;
    for(int i = 0; i < n - 1; i++){
        s.erase(n - 1, 2);
        s.insert(s.begin(), '-');
        s.insert(s.end(), '-');
        v.push_back(s);
    }
    for(int i = v.size() - 1; i >= 0; i--){
        cout << v[i] << '\n';
    }
    cout << t << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }
}

/*
---d---
--dcd--
-dcbcd-
dcbabcd
-dcbcd-
--dcd--
---d---
*/
// Adil's code
#include <iostream>
#include <queue>

using namespace std;

char a[100][100];
int n, m;
queue<pair<int, int> > q;

void filll(int v, int x, int y){
    if (x >= 0 && y >= 0 && x < m && y < m){
        if(a[x][y] == ' '){
            a[x][y] = char(v);
            q.push(make_pair(x, y));
        }
    }
}


int main(){
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    m = n * 2 - 1;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            a[i][j] = ' ';
        }
    }
    a[n-1][n-1] = 'a';
    
    q.push(make_pair(n-1, n-1));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(int(a[x][y]-96) == n) break;
        q.pop();
        filll(int(a[x][y]) + 1, x+1, y);
        filll(int(a[x][y]) + 1, x-1, y);
        filll(int(a[x][y]) + 1, x, y+1);
        filll(int(a[x][y]) + 1, x, y-1);
    }


    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == ' '){
                cout << '-';
            }else{
                cout << a[i][j];
            }
        }
        cout << endl;
    }


    return 0;
}