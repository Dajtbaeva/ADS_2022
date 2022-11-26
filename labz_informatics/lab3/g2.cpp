#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

string binSearch(int a[], int l, int r, int x){
    while(l <= r){
        int m = l + (r - l) / 2;
        if (a[m] == x){
            return "YES";
        }
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return "NO";
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++){
        int x;
        cin >> x;
        cout << binSearch(a, 0, n - 1, x) << endl;
    }
}
