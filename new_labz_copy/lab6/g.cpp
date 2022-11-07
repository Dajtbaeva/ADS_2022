#include <bits/stdc++.h>

using namespace std;

bool comp(pair<string, string>& p1, pair<string, string>& p2) {
	return p1.first < p2.first;
}

int partition(vector<pair<string, string> >& v, int l, int r) {
	pair<string, string> pivot = v[r];
	int index = l;
	for (int i = l; i < r; i++) {
		if (comp(v[i], pivot)) {
			swap(v[i], v[index]);
			index++;
		}
	}
	swap(v[index], v[r]);
	return index;
}

void quick_sort(vector<pair<string, string> >& v, int l, int r) {
	if (l < r) {
		int p = partition(v, l, r);
		quick_sort(v, l, p - 1);
		quick_sort(v, p + 1, r);
	}
}

int main() {
	int n; cin >> n;
	vector<pair<string, string> > v;
	for(int i = 0; i < n; i++){
		string on, nn;
		bool ok = false;
		cin >> on >> nn;
		for (int i = 0; i < v.size(); i++) {
			if (on == v[i].second) {
				v[i].second = nn;
				ok = true;
				break;
			}
		}
		if (!ok) v.push_back({on, nn});
	}
	quick_sort(v, 0, v.size() - 1);
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
}