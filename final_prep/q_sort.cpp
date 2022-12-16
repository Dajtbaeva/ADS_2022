#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &v, int left, int right) {
	int pivot = v[right];
	int index = left;
	for (int i = left; i < right; i++) {
		if (v[i] < pivot) {
			swap(v[i], v[index]);
			index++;
		}
	}
	swap(v[index], v[right]);
	return index;
}

void quick_sort(vector<int> &v, int left, int right) {
	if (left < right) {
		int p = partition(v, left, right);
		quick_sort(v, left, p - 1);
		quick_sort(v, p + 1, right);
	}
}

int main() {
	int n, x; cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}
	quick_sort(v, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	return 0;
}