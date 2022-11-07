#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int l, int r) {
	int pivot = a[r];
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

void quick_sort(vector<int> &a, int l, int r) {
	if (l < r) {
		int p = partition(a, l, r);
		quick_sort(a, l, p - 1);
		quick_sort(a, p + 1, r);
	}
}

void ans(vector<int> v, vector<int> w, int n, int m){
    int i = 0, j = 0;
    while(i < n && j < m){
        if(v[i] == w[j]){
            cout << v[i] << " ";
            i++; j++;
        }else if(v[i] < w[j]) i++;
        else j++;
    }
}

int main() {
    int n, m, x;
    cin >> n >> m;
    vector<int> v, w;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        w.push_back(x);
    }
    quick_sort(v, 0, n - 1);
    quick_sort(w, 0, m - 1);
    ans(v, w, n, m);
}

