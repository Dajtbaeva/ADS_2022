#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
	return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}

bool comp(pair<string, int> &p1, pair<string, int> &p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int ans(string t){
    int cnt = 0;
    for(int i = 0; i < t.size(); i++){
        if(isVowel(t[i])) cnt++;
    }
    return cnt;
}

int main() {
	string ar[] = {
		"Alikh",
		"Lyaka",
		"Nurbekushka",
		"MirASS",
		"Amanback",
		"Iyeesha",
		"Adema",
		"Danik",
		"Dinara_Aktau_NIS",
		"Aldick",
		"Darinchick",
		"Erdogan",
		"Ayazhan",
		"Beka",
		"Nurs",
		"Alina",
		"Aruzhan",
		"Artem_Nexia",
		"Akmira",
      	"Yerkezhan",
		"Yeldana",
		"Sam",
		"Bakdaulet",
		"Zhako",
		"Batyr",
		"Julia",
		"Zhadyra",
		"Amirchik",
		"Temir",
		"Manas",
		"Amina",
		"Aibergen",
		"Lera",
		"Bauka srauka",
		"Jax Cobalt sexy boy 2002"
	};
    vector<pair<string, int> > v;
    int n = sizeof(ar) / sizeof(ar[0]);
    for(int i = 0; i < n; i++){
        int res = ans(ar[i]);
        v.push_back(make_pair(ar[i], res));
    }
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < n; i++){
        cout << v[i].first << "\n";
    }
	return 0;
}