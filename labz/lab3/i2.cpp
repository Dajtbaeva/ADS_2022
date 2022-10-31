#include <bits/stdc++.h>

using namespace std;

int first(vector<int> &v, int x){
    int res = -1, l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(v[mid] > x) r = mid - 1;
        else if(v[mid] < x) r = mid + 1;
        else{
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}

int last(vector<int> &v, int x){
    int res = -1, l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(v[mid] > x) r = mid - 1;
        else if(v[mid] < x) r = mid + 1;
        else{
            res = mid;
            l = mid + 1;
        }
    }
    return res;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    while(k--){
        int a; cin >> a;
        int j1 = first(v, a) + 1;
        int j2 = last(v, a) + 1;
        if(first == 0 && last == 0) cout << 0 << "\n";
        else cout << first << " " << last << "\n";
    }
}