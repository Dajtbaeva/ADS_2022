#include <bits/stdc++.h>

using namespace std;

int partition(int a[], int l, int r) {
	int pivot = a[r];
	int index = l;
	for (int i = l; i < r; i++) {
		if (a[i] > pivot) {
			swap(a[i], a[index]);
			index++;
		}
	}
	swap(a[index], a[r]);
	return index;
}

void quick_sort(int a[], int l, int r) {
	if (l < r) {
		int p = partition(a, l, r);
		quick_sort(a, l, p - 1);
		quick_sort(a, p + 1, r);
	}
}


int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[m][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[j][i];
		}
	}
	for (int i = 0; i < m; i++) {
		quick_sort(a[i], 0, n - 1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[j][i] << " ";
		}
		cout << "\n";
	}
}

