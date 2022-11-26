#include <bits/stdc++.h>

using namespace std;

int binary_search(int v[], int target, int n){
    int left = 0, right = n - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (v[mid] >= target) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> w;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; 
        w.push_back(x);
    }
    int res[n];
    res[0] = w[0];
    for(int i = 1; i < w.size(); i++){
        res[i] = w[i] + res[i - 1]; 
    }
    for(int j = 0; j < k; j++){
        int y;
        cin >> y;
        cout << binary_search(res, y, n) + 1 << "\n";
    }
}
// 3 3
// 5 7 6: res = 5, 12, 18
// 5
// 10
// 15
