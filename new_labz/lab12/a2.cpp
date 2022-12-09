#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fori(n) for(int i = 0;i < n;i++)
#define fori1(n) for(int i = 1;i <= n;i++)
#define forj(n) for(int j = 0;j < n;j++)
#define forj1(n) for(int j = 1;j <= n;j++)
#define mp make_pair
#define pb push_back
#define all(p) p.begin(),p.end()
#define MAX 501
vector<pair<int,int> > a[MAX];
vector<int> r(MAX);
int n,m;
const int N = -1e7;
bool was[MAX];
int colour[MAX];

int x,y,c;
int q[MAX];
int d[MAX][MAX];
bool used[MAX];
int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        forj1(n)
            cin >> d[i][j];
    }

    int x,mx;
    for(int k = 1;k <= n;k++){
        cin >> x;
        used[x] = true;
        mx = -1;
        fori1(n){
            forj1(n){
                d[i][j] = min(d[i][j],d[i][x] + d[x][j]);
            }
        }
        fori1(n){
            forj1(n){
                if(used[i] and used[j])
                    mx = max(d[i][j],mx);
            }
        }
        cout << mx << "\n";
    }    
}