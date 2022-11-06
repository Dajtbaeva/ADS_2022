#include <bits/stdc++.h>

using namespace std;

int partition(vector<char> &a, int l, int r) {
	char pivot = a[r];
	int index = l;
	for (int i = l; i < r; i++) {
		if (a[i] < pivot) {
			swap(a[i], a[index]);
			index++;
		}
	}
	swap(a[index], a[r]);
	return index;
}

void quick_sort(vector<char> &a, int l, int r) {
	if (l < r) {
		int p = partition(a, l, r);
		quick_sort(a, l, p - 1);
		quick_sort(a, p + 1, r);
	}
}

int main() {
    int n; cin >> n;
    char c, t;
    vector<char> v;
    for(int i = 0; i < n; i++){
        cin >> c;
        v.push_back(c);
    }
    cin >> t;
    v.push_back(t);
    quick_sort(v, 0, n);
    for(int i = 0; i < v.size(); i++){
        if(t < v[i]){
            cout << v[i];
            return 0;
        }
    }
    cout << v[0];
}

