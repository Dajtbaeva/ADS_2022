int binay_seach_first(int a[], int taget, int n){ // increase
	int left = 0, right = n - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (taget < a[mid]) right = mid - 1;
		else if (taget > a[mid]) left = mid + 1;
		else return mid;
	}
	return -1;
}

int binary_search_decr(int a[], int target, int n){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(target > a[mid]) r = mid - 1;
        else if(target < a[mid]) l = mid + 1;
        else return mid;
    }
    return -1;
}
----------------------------------------------------------------------------
Oshiete oshiete yo sono shikumi wo
10 3
3 4 2 1 3 4 5 2 2 3 -> 12
(3+4+2+1), (3+4+5), (2+2+3)

#include <bits/stdc++.h>
using namespace std; 

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	unsigned long long left = *max_element(v.begin(), v.end());
	unsigned long long right, mid, cnt, sum, ans;
	for(int i = 0; i < n; i++) right += v[i];
	while (left <= right) {
		mid = left + (right - left) / 2;
		cnt = 1;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < sum + v[i]) {
				sum = 0;
				cnt++;
			}
			if (mid < v[i]) cnt = k + 1;
			sum += v[i];
		}
		if (k >= cnt){
			ans = mid;
			right = mid - 1;
		}else left = mid + 1;
	}
	cout <<  ans;
	return 0;
}
------------------------------------------------------------------------
Patchwork Staccato II
7 3
21 1 2 3 5 8 13
1 5 13 21
1 1 2 3
1 3 2 8 
====
6
3
5

#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> v, int a){ // return index
    int l = 0, r = v.size() - 1, res = -1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(v[m] <= a){
            res = m;
            l = m + 1;
        }else r = m - 1;
    }
    if(res == -1) return 0;
    return res + 1;
}

int ans(vector<int> v, int l, int r){
    return binary_search(v, r) - binary_search(v, l - 1);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < k; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(r1 < l2 || r2 < l1){
            int res = ans(v, l1, r1) + ans(v, l2, r2);
            cout << res << "\n";
        } 
        else{
            int mini = min(l1, l2);
            int maxi = max(r1, r2);
            cout << ans(v, mini, maxi) << "\n";
        }
    }
}
-------------------------------------------------------------
Jonathan the Farmer
Find the minimum length of square paddock such that at least K sheeps’ pastures fit there.

#include <bits/stdc++.h>

using namespace std;

struct coordinates{
    int x1, y1, x2, y2;
};
coordinates a[2 * 1000000];
int n, k;

bool checker(int x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i].x2 <= x && a[i].y2 <= x) cnt++;
    }
    return cnt >= k;
}

int binary_search(){
    int l = 0, r = 1e9, res = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(checker(mid)){
            res = mid;
            r = mid - 1; // we need min length
        } 
        else l = mid + 1;
    }
    return res;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    cout << binary_search();

}
------------------------------------------------------------
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
-------------------------------------------------------------------------------------------------
Santa Jonathan
5 7
10 34 14 6 20

Return the minimum number K such that Robin can steal ALL of the golden bars within H hours.
5 5
30 11 23 4 20

#include <bits/stdc++.h>

using namespace std;

bool checker(vector<int> a, int n, int x, int h){
    int t = 0;
    for(int i = 0; i < n; i++){
        t += (a[i] + x - 1) / x; // ceil(a[i] * 0.1 / x)
    }
    return t <= h;
}

int main(){
    int n, h; 
    cin >> n >> h;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    int l = 1, r = *max_element(a.begin(), a.end()) + 1;
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        if(checker(a, n, mid, h)) r = mid;
        else l = mid;
    }
    cout << r;
}

// 5 7
// 10 34 14 6 20 -> 17
---------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

int binary_search(int v[], int target, int n){
    int left = 0, right = n - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (v[mid] >= target) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> w;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; 
        w.push_back(x);
    }
    int res[n];
    res[0] = w[0];
    for(int i = 1; i < w.size(); i++){
        res[i] = w[i] + res[i - 1]; 
    }
    for(int j = 0; j < k; j++){
        int y;
        cin >> y;
        cout << binary_search(res, y, n) + 1 << "\n";
    }
}
// 3 3
// 5 7 6: res = 5, 12, 18
// 5
// 10
// 15
---------------------------------------------------------------
// Задача №111728. Левый и правый двоичный поиск
// https://informatics.msk.ru/mod/statements/view.php?id=54422&chapterid=111728#1

#include <bits/stdc++.h>

using namespace std;

void bs(int a[], int l, int r, int x){
    while(l < r){
        int mid = (l + r) / 2;
        if(a[mid] < x) l = mid + 1;
        else r = mid;
    }
    if(a[r] == x){
        cout << ++r << " ";
        while(a[r] == x) r++;
        cout << r << "\n";
    }
    else cout << 0 << "\n";
}

int main(){
    int n, k;
    cin >> n >> k;
    int b[n];
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= k; i++){
        int y;
        cin >> y;
        bs(b, 0, n - 1, y);
    }
        
}
--------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

int first(vector<int> &v, int x){
    int res = -1, l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(v[mid] > x) r = mid - 1;
        else if(v[mid] < x) r = mid + 1;
        else{
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}

int last(vector<int> &v, int x){
    int res = -1, l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(v[mid] > x) r = mid - 1;
        else if(v[mid] < x) r = mid + 1;
        else{
            res = mid;
            l = mid + 1;
        }
    }
    return res;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    while(k--){
        int a; cin >> a;
        int j1 = first(v, a) + 1;
        int j2 = last(v, a) + 1;
        if(first == 0 && last == 0) cout << 0 << "\n";
        else cout << first << " " << last << "\n";
    }
}
--------------------------------------------------------------------
int p[10000010];

void find_primes1(int n) {   //Эратосфен
    // for (int i = 2; i <= sqrt(n); i++)
    for (int i = 2; i * i <= n; i++) { 
        if (p[i] == 0) {
            int k = i;                 
            while (k + i <= n) {
                k += i;
                p[k] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
        if (p[i] == 0 && p[n - i] == 0){
            cout << i << " " << n - i << endl;
            break;
        }
            

}

int main() {
    int n;
    cin >> n;
    find_primes1(n);
    return 0;
}
----------------------------------------------------------------
FIRST AND LAST OCCURANCE
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int first = -1, last = -1;
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target) {
				first = mid;
				r = mid - 1;
			} else if (target < nums[mid]) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (first == -1) {
			return { -1, -1 };
		}
		l = first, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target) {
				last = mid;
				l = mid + 1;
			} else if (nums[mid] < target) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return { first, last };
	}
};