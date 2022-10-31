// Jaxonation
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s,t; 
    cin >> s >> t;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (s.substr(i, s.size()) == t.substr(0,t.size() - j)){
                s.erase(s.size() - t.size() + j, s.size());
                t.erase (0, t.size() - j);
                cout << s << t;
                return 0;
            }
        }
    }
    cout << s << t;
    return 0;
}
/*
adil dilkij
------------
akij
*/