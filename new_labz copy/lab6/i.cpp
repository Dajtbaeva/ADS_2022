#include <bits/stdc++.h>

using namespace std;

int partition(string &s, int l, int r) {
	char pivot = s[r];
	int index = l;
	for (int i = l; i < r; i++) {
		if (s[i] < pivot) {
			swap(s[i], s[index]);
			index++;
		}
	}
	swap(s[index], s[r]);
	return index;
}

void quick_sort(string& t, int l, int r) {
	if (l < r) {
		int p = partition(t, l, r);
		quick_sort(t, l, p - 1);
		quick_sort(t, p + 1, r);
	}
}

int main() {
	string s;
	cin >> s;
	quick_sort(s, 0, s.size() - 1);
	cout << s;
}