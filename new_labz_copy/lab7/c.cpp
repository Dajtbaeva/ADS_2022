#include <bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (left[l] <= right[r]) {
			result.push_back(left[l]);
			l++;
		} else {
			result.push_back(right[r]);
			r++;
		}
	}
	while (l < left.size()) {
		result.push_back(left[l]);
		l++;
	}
	while (r < right.size()) {
		result.push_back(right[r]);
		r++;
	}
	return result;
}

vector<int> merge_sort(vector<int> &a, int l, int r) {
	if (l == r) {
		vector<int> result;
		result.push_back(a[l]);
		return result;
	}
	int m = l + (r - l) / 2;
	vector<int> left = merge_sort(a, l, m);
	vector<int> right = merge_sort(a, m + 1, r);
	return merge(left, right);
}


void ans(vector<int> v, vector<int> w, int n, int m){
    int i = 0, j = 0;
    while(i < n && j < m){
        if(v[i] == w[j]){
            cout << v[i] << " ";
            i++; 
            j++;
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
    if(!n || !m) return 0;
    vector<int> v1 = merge_sort(v, 0, n - 1);
    vector<int> w1 = merge_sort(w, 0, m - 1);
    // for(auto i : v1) cout << i << " ";
    // cout << "\n";
    // for(auto i : w1) cout << i << " ";
    // return 0;

    ans(v1, w1, n, m);
}

