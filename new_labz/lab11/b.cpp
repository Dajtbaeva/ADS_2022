#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sumi = 0;
	cin >> n;
	int a[n];
	int mini = 1e6;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mini = min(mini, a[i]);
		sumi += a[i];
	}
	sumi -= mini;
    int res = (n - 1) * mini + sumi;
	cout << res;
}