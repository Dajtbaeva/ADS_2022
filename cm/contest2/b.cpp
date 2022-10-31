#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, double> p1, pair<int, double> p2) { // hint, which data structure you should use
	if (p1.first * p1.second == p2.first * p2.second) {
		return p1.first < p2.first;
	}
	return p1.first * p1.second < p2.first * p2.second;
}

int binary_search(vector<double> &array, int target){
	int left = 0;
	int right = array.size() - 1;
    int res = 0;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (array[mid] >= target){
            right = mid;
		}
		else if (array[mid] < target) left = mid + 1;
	}
	return res;
}

// int binary_search(vector<int> &array, int target){
// 	int left = 0, res = 0;
// 	int right = array.size() - 1;
// 	while (left <= right){
// 		int mid = left + (right - left) / 2;
// 		if (array[mid] <= target){
// 			res = mid;
// 			left = mid + 1;
// 		}
// 		else if (array[mid] > target) right = mid - 1;
// 	}
// 	return res + 1;
// }

int main() {
    vector<pair<int, double> > v;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x; double y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), comp);
    vector<double> a;
    for(int i = 0; i < n; i++){
        a.push_back(v[i].first * v[i].second);
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    int res = binary_search(a, k);
    cout << "\n" << res << " " << v[res].first << " " << v[res].second;
	return 0;
}