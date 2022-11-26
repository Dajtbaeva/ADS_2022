#include<bits/stdc++.h>

using namespace std;

bool comp(pair<string, int>  &s1, pair<string, int>  &s2){
    if(s1.first.size() == s2.first.size()) return s1.second < s2.second;
    return s1.first.size() < s2.first.size();
}

vector<pair<string, int> > merge(vector<pair<string, int> > left, vector<pair<string, int> > right) {
	vector<pair<string, int> > result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (comp(left[l], right[r])) {
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

vector<pair<string, int> > merge_sort(vector<pair<string, int> > a, int l, int r) {
	if (l == r) {
		vector<pair<string, int> > result;
		result.push_back(make_pair(a[l].first, a[l].second));
		return result;
	}
	int m = l + (r - l) / 2;
	vector<pair<string, int> > left = merge_sort(a, l, m);
	vector<pair<string, int> > right = merge_sort(a, m + 1, r);
	return merge(left, right);
}

vector<string> words(string t){
    vector<string> res;
    string word = "";
    for (auto x : t){
        if (x == ' '){
            res.push_back(word);
            word = "";
        }
        else word = word + x;
    }
    res.push_back(word);
    return res;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	string n;
	getline(cin, n);
    int m = stoi(n);
	while(m--){
        string s; getline(cin, s);
		vector<string> w;
        stringstream ss(s);
        while(ss >> s) w.push_back(s);
		vector<pair<string, int> > a;

        for (int j = 0; j < w.size(); j++){
            a.push_back(make_pair(w[j], j));
        }
        vector<pair<string, int> > result = merge_sort(a, 0, w.size() - 1);
        for (auto k : result) cout << k.first << " ";
		cout << "\n";
    }
}


