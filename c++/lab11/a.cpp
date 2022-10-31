// Can’t Wait for Holiday
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    if(s == "MON") cout << 6;
    else if(s == "TUE") cout << 5;
    else if(s == "WED") cout << 4;
    else if(s == "THU") cout << 3;
    else if(s == "FRI") cout << 2;
    else if(s == "SAT") cout << 1;
    else cout << 7;
}
/*
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<string> v{"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int res = 0;
    bool ok = false;
    for(int i = 0; i < v.size(); i++){
        if(s == v[i]) ok = true;
        if(ok) res++;
    }
    cout << res + 1;
}*/