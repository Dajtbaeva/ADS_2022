#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MX_SIZE = 50500;

ll p = 31;
ll p_pow[MX_SIZE];

void find_pow(){
    p_pow[0] = 1;
    for (int i = 1; i < MX_SIZE; i++)
        p_pow[i] = p_pow[i - 1] * p;
}

ll find_hash(string s){
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] * p_pow[i];
    return sum;
}

vector<ll> find_hash_prefix(string s){
    vector<ll> h(s.size());
    h[0] = s[0];
    for (int i = 1; i < s.size(); i++)
        h[i] = h[i - 1] + s[i] * p_pow[i];
    return h;
}

int main(){
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;

    find_pow();

    ll hash_t = find_hash(t);
    vector<ll> h = find_hash_prefix(s);

    int n = s.size();
    int m = t.size();

    for (int i = 0; i <= n - m; i++){

        int j = i + m - 1;
        ll hash_i_j = h[j];
        if(i)
            hash_i_j -= h[i - 1];
        if (hash_t * p_pow[i] == hash_i_j)
            cout << i << " ";
    }
    return 0;
}