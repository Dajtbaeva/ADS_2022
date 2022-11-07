#include <bits/stdc++.h>

using namespace std;

struct coordinates{
    int x1, y1, x2, y2;
};
coordinates a[2 * 1000000];
int n, k;

bool checker(int x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i].x2 <= x && a[i].y2 <= x) cnt++;
    }
    return cnt >= k;
}

int binary_search(){
    int l = 0, r = 1e9, res = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(checker(mid)){
            res = mid;
            r = mid - 1; // we need min length
        } 
        else l = mid + 1;
    }
    return res;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    cout << binary_search();

}