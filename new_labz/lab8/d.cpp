#include <bits/stdc++.h>

using namespace std;

const int d = 26;
vector<int> search(string s, string pattern, int q = 1e9 + 7) {
	int p = 0, t = 0, h = 1, i, j;
	vector<int> ans;
	for (i = 0; i < pattern.size() - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < pattern.size(); i++) {
		p = (d * p + pattern[i]) % q;
		t = (d * t + s[i]) % q;
	}

	for (i = 0; i <= s.size() - pattern.size(); i++) {
		if (p == t) {
			for (j = 0; j < pattern.size(); j++) {
				if (s[i + j] != pattern[j]) break;
			}
			if (j == pattern.size()) {
				ans.push_back(i);
			}
		}

		if (i < s.size() - pattern.size()) {
			t = (d * (t - s[i] * h) + s[i + pattern.size()]) % q;
			if (t < 0) t += q;
		}
	}
	return ans;
}

int main() {
    int n; cin >> n;
    while(n != 0){
        vector<string> str;
        for(int i = 0; i < n; i++){
            string t; cin >> t;
            str.push_back(t);
        }
        string s; cin >> s;
        int maxi = 0;
        string res = "";
        vector<pair<string, int> > v;
        for(int j = 0; j < str.size(); j++){
            vector<int> indices = search(s, str[j]);
            int sz = indices.size();
            v.push_back(make_pair(str[j], sz));
            maxi = max(maxi, sz);
        }
        cout << maxi << "\n";
        for(int k = 0; k < v.size(); k++){
            if(v[k].second == maxi) cout << v[k].first << "\n";
        }
        cin >> n;
    }
}