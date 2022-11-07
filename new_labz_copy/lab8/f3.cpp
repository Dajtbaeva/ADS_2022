#include <bits/stdc++.h>
using namespace std;

int main(){
int t = 1;
long long mod = 9007199254740881;

// for(int i = 0; i < t; i++){
	string s = "aab";
	// to store substrings
	vector<vector<long long>>l;
	// to store hash values by Rabin Karp algorithm
	unordered_map<long long,int>d;
	for(int i=0;i<s.length();i++){
        int suma = 0;
        long long pre = 0;
        // Number of input alphabets
        long long D = 256;
        for(int j=i;j<s.length();j++){
            // calculate new hash value by adding next element
            pre = (pre*D+s[j]) % mod;
            // store string length if non repeat
            if(d.find(pre) == d.end())
            l.push_back({i, j});
            d[pre] = 1;
        }
    }

    // resulting length
    cout<<l.size()<<endl;

    // resulting distinct substrings
    for(int i = 0; i < l.size(); i++)
    cout << s.substr(l[i][0],l[i][1]+1-l[i][0]) << " ";
    // }
}

// This code is contributed by shinjanpatra
