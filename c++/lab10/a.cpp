#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    string s;
    vector<string> v1;
    vector<int> v2;
    cin >> n;
    while(n--){
        cin >> s >> x;
        v1.push_back(s);
        v2.push_back(x);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " " << v2[i] << "\n";
    }
}