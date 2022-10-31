#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int n;

bool binIterative(int a[], int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + ((r - l) / 2);
        if (a[mid] == x) return true;
        else if (x < a[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}

bool binRecur(int a[], int x, int l, int r){
    if (l > r) return false;
    int mid = l + ((r - l) / 2);
    if (a[mid] == x) return true;
    else if (x < a[mid]) return binRecur(a, x, l, mid - 1);
    else return binRecur(a, x, mid + 1, r);
}

void print(int a[]){
    for (int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main () {
    int N;
    cin >> N;
    cout << ceil(log2(N)) << endl;
//    cin >> n;
//    int a[n];
//    for (int i = 0; i < n; i ++){
//        cin >> a[i];
//    }
//    int x = 3;
//    sort(a, a + n);
//    cout << binRecur(a, x, 0, n - 1) << endl;
//    cout << binIterative(a, x) << endl;
}
