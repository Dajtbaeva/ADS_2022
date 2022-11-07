#include <bits/stdc++.h>
using namespace std; 

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	unsigned long long left = *max_element(v.begin(), v.end());
	unsigned long long right, mid, cnt, sum, ans;
	for(int i = 0; i < n; i++) right += v[i];
	while (left <= right) {
		mid = left + (right - left) / 2;
		cnt = 1;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < sum + v[i]) {
				sum = 0;
				cnt++;
			}
			if (mid < v[i]) cnt = k + 1;
			sum += v[i];
		}
		if (k >= cnt){
			ans = mid;
			right = mid - 1;
		}else left = mid + 1;
	}
	cout <<  ans;
	return 0;
}