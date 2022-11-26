#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixFunction(string s) {
    vector<int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }
        if (s[j] == s[i]) {
            pi[i] = j + 1;
        } else {
            pi[i] = 0;
        }
    }

    return pi;
}

int getPeriod(string s) {
    vector<int> pi = prefixFunction(s);
    int len = s.size() - pi[s.size() - 1];
    if (pi[s.size() - 1] == 0) return 0;
    if (s.size() % len == 0) return len;
    return 0;
}

int main() {
    string s;
    cin >> s;
    cout << getPeriod(s) << endl;
}