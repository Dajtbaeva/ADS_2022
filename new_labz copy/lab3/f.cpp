#include <bits/stdc++.h>

using namespace std;

pair<int, int> binary_search(vector<int> a, int target){ 
	int left = 0, right = a.size() - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (target >= a[mid]){
            pair<int, int> p;
            int sumi = 0, cnt = 0;
            for(int i = left; i <= right; i++){
                if(a[i] <= target){
                    sumi += a[i];
                    cnt++;
                } 
            }
            p.first = cnt;
            p.second = sumi;
            return p;
        }
		else if (target < a[mid]) right = mid - 1;
	}
}

int main(){
    int n, k;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cin >> k;
    for(int i = 0; i < k; i++){
        int y;
        cin >> y;
        cout << binary_search(v, y).first << " " << binary_search(v, y).second << "\n";
    }
}