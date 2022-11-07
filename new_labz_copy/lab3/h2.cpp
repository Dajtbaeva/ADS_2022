#include <bits/stdc++.h>

using namespace std;

int binary_search(int l, int r, int target){
    vector<int> array;
    for(int i = l; i <= r; i++) array.push_back(i);
    int left = 0;
	int right = array.size() - 1; 
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (array[mid] == target) return mid;
		else if (array[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int main(){
    int n, k, l = 1, r = 0;
    vector<pair<int, int> > v;
    cin >> n >> k;
    vector<int> w;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; 
        r += x;
        v.push_back(make_pair(l, r));
        l = r + 1;
    }
    for(int j = 0; j < k; j++){
        int y;
        cin >> y;
        for(int j = 0; j < v.size(); j++){
            if(binary_search(v[j].first, v[j].second, y) != -1){
                cout << j + 1 << "\n";
                break;
            }
        }
    }
}
// 3 3
// 5 7 6 - [1, 5], [6, 12], [13, 18] 
// 5
// 10
// 15
