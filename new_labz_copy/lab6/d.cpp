#include <bits/stdc++.h>

using namespace std;

int comp(string date1, string date2){
	string day1 = date1.substr(0, 2);
	string month1 = date1.substr(3, 2);
	string year1 = date1.substr(6, 4);

	string day2 = date2.substr(0, 2);
	string month2 = date2.substr(3, 2);
	string year2 = date2.substr(6, 4);

    // return (year1 < year2) ? 1 : 0;
    // return (month1 < month2) ? 1 : 0;
    // return (day1 < day2) ? 1 : 0;

	if (year1 < year2)
		return 1;
	if (year1 > year2)
		return 0;

	if (month1 < month2)
		return 1;
	if (month1 > month2)
		return 0;

	if (day1 < day2)
		return 1;
	if (day1 > day2)
		return 0;
}


int partition(vector<string> &a, int l, int r) {
	string pivot = a[r];
	int index = l;
	for (int i = l; i < r; i++) {
		if (comp(a[i], pivot)) {
			swap(a[i], a[index]);
			index++;
		}
	}
	swap(a[index], a[r]);
	return index;
}

void quick_sort(vector<string> &a, int l, int r) {
	if (l < r) {
		int p = partition(a, l, r);
		quick_sort(a, l, p - 1);
		quick_sort(a, p + 1, r);
	}
}

int main(){
    int n; cin >> n;
    string s;
    vector<string> v;
    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back(s);
    }
    quick_sort(v, 0, n - 1);
    for(auto i : v) cout << i << "\n";

}