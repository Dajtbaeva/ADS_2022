#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > merge(vector<vector<int> > left, vector<vector<int> > right) {
	vector<vector<int> > result;
	int l = 0, r = 0;
	    while(l < left.size() && r < right.size()) {

        int l_sum = left[l][left[l].size() - 1];
        int r_sum = right[r][right[r].size() - 1];
        if(l_sum < r_sum) {
            result.push_back(right[r]);
            r++;
        } else if (l_sum > r_sum) {
            result.push_back(left[l]);
            l++;
        }  else {
            int cnt = 0;
            for(int i = 0; i < left[l].size() - 1; i++) {
                if(left[l][i] < right[r][i]) {
                    result.push_back(left[l]);
                    l++;
                    break;
                } else if (left[l][i] > right[r][i]) {
                    result.push_back(right[r]);
                    r++;
                    break;
                }
                cnt++;
            }
            if(cnt == left[l].size() - 1) {
                result.push_back(left[l]);
                l++;
            }
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

vector<vector<int> > merge_sort(vector<vector<int> > a, int l, int r) {
	if (l == r) {
		vector<vector<int> > result;
		result.push_back(a[l]);
		return result;
	}
	int m = l + (r - l) / 2;
	vector<vector<int> > left = merge_sort(a, l, m);
	vector<vector<int> > right = merge_sort(a, m + 1, r);
	return merge(left, right);
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		int total = 0;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
            total += x;
			temp.push_back(x);
		}
		temp.push_back(total);
		v.push_back(temp);
	}
	vector<vector<int>> res = merge_sort(v, 0, n - 1);
	for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}