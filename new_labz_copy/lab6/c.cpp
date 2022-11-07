#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll partition(vector<ll> &a, ll l, ll r) {
	ll pivot = a[r];
	ll index = l;
	for (int i = l; i < r; i++) {
		if (a[i] < pivot) {
			swap(a[i], a[index]);
			index++;
		}
	}
	swap(a[index], a[r]);
	return index;
}

void quick_sort(vector<ll> &a, ll l, ll r) {
	if (l < r) {
		ll p = partition(a, l, r);
		quick_sort(a, l, p - 1);
		quick_sort(a, p + 1, r);
	}
}

void ans(vector<ll> v){
    vector<pair<ll, pair<ll, ll> > > diff;
    ll mini = 1e9 + 1;
    for(int i = 1; i < v.size(); i++){
        ll d = v[i] - v[i - 1];
        mini = min(mini, d);
        diff.push_back(make_pair(d, make_pair(v[i - 1], v[i])));
    }
    for(int i = 0; i < diff.size(); i++){
        if(diff[i].first == mini) cout << diff[i].second.first << " " << diff[i].second.second << " ";
    }
}

int main(){
    ll n; cin >> n;
    vector<ll> v;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v.push_back(x);
    }
    quick_sort(v, 0, n - 1);
    // for(auto i : v) cout << i << " ";
    // return 0;
    ans(v);
}