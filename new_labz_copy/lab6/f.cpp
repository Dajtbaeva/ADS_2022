#include <bits/stdc++.h>

using namespace std;

double getGpa(vector<pair<string, int> > &w){
    double cnt = 0, sumi = 0;
    for(int i = 0; i < w.size(); i++){
        if (w[i].first == "A+") sumi+= w[i].second * 4.0;
        else if (w[i].first == "A") sumi+= w[i].second * 3.75;
        else if (w[i].first == "B+") sumi+= w[i].second * 3.50;
        else if (w[i].first == "B") sumi+= w[i].second * 3.00;
        else if (w[i].first == "C+") sumi+= w[i].second * 2.50;
        else if (w[i].first == "C") sumi+= w[i].second * 2.00;
        else if (w[i].first == "D+") sumi+= w[i].second * 1.50;
        else if (w[i].first == "D") sumi+= w[i].second * 1.00;
        else if (w[i].first == "F") sumi+= w[i].second * 0;
        cnt += w[i].second;
    }
    return sumi / cnt;
}

bool comp(pair<pair<string, string>, double>& p1, pair<pair<string, string>, double>& p2) {
    if(p1.second == p2.second){
        if(p1.first.first == p2.first.first) return p1.first.second < p2.first.second;
        return p1.first.first < p2.first.first;
    }
	return p1.second < p2.second;
}

int partition(vector<pair<pair<string, string>, double> > &v, int l, int r) {
	pair<pair<string, string>, double> pivot = v[r];
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

void quick_sort(vector<pair<pair<string, string>, double> > &v, int l, int r) {
	if (l < r) {
		int p = partition(v, l, r);
		quick_sort(v, l, p - 1);
		quick_sort(v, p + 1, r);
	}
}

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    string fn, ln;
    int n; cin >> n;
    vector<pair<pair<string, string>, double> > v;
    for(int i = 0; i < n; i++){
        cin >> ln >> fn;
        int k; cin >> k;
        vector<pair<string, int> > w;
        for(int j = 0; j < k; j++){
            string g; int c;
            cin >> g >> c;
            w.push_back(make_pair(g, c));
        }
        double gpa = getGpa(w);
        v.push_back(make_pair(make_pair(ln, fn), gpa));
    }
    quick_sort(v, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << v[i].first.first << " " << v[i].first.second << " " << fixed << setprecision(3) << v[i].second << "\n";
    }
}

// 5
// Issenbayev Yernur 4 A 4 D+ 2 B 3 A+ 4
// Yermekbayeva Diana 3 A+ 4 B+ 3 B 1
// Kadyrov Asman 2 A+ 4 A+ 4
// Stepanenko Ivan 3 C+ 3 F 1 A+ 5
// Bissimbayev Arystan 3 A+ 4 A+ 5 D 1