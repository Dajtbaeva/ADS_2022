#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> array, int target){
	int left = 0;
	int right = array.size() - 1;
    int res = -1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (array[mid] <= target){ 
            res = mid;
            left = mid + 1;
        }
		else right = mid - 1;
	}
    if(res == -1) return 0;
    return res + 1;
}

int ans(vector<int> w, int l, int r){
    return binary_search(w, r) - binary_search(w, l - 1);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v, result;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < k; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        // l2 <= r2 <= l1 <= r1 || l1 <= r1 <= l2 <= r2 
        if(r2 < l1 || r1 < l2){
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

// 13 13
// 581869303 890346735 586334586 545404205 161255392 922919430 949333986 715962299 323567404 418932836 350294566 196140741 809094427
// 264392721 348838240 112460520 279768805
// 144164698 156218107 117454610 676943010
// 168664244 213834040 111000747 471852627
// 84672537 427838554 275731772 437178461
// 20544910 609397213 483031419 811450930
// 747762696 933054127 402504554 772830894
// 120988588 163214729 427077307 816384845
// 153380496 551745921 646982598 910208077
// 11470446 926416935 712568903 915145308
// 181055694 254469059 39073007 191729661
// 684602223 812852787 746745228 815256117
// 296707007 735241235 32444840 424291162
// 136721027 359573809 189375153 747053251


// 7 3
// 21 1 2 3 5 8 13
// 1 5 13 21
// 1 1 2 3
// 1 3 2 8