#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}

int partition(string& s, int l, int r) {
	char pivot = s[r];
	int index = l;
	for (int i = l; i < r; i++) {
		if (isVowel(s[i]) && !isVowel(pivot)) {
			swap(s[i], s[index]);
			index++;
		} else if (!isVowel(s[i]) && isVowel(pivot)) {
			continue;
		} else if (s[i] < pivot) {
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	quick_sort(s, 0, n - 1);
	cout << s;
}
// 5
// abcde

