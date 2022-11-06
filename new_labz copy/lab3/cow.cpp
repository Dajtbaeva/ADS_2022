// https://kbtuedu.sharepoint.com/sites/ADS2022FallAmanov/Shared%20Documents/Forms/AllItems.aspx?FolderCTID=0x012000039C63EE11267846A8CE5E798B0D86B1&sortField=Modified&isAscending=false&id=%2Fsites%2FADS2022FallAmanov%2FShared%20Documents%2FGeneral%2FRecordings%2F%5BADS22fall%5D%20Week%204%20%28Sat%2013%5F00%29%2D20220924%5F130723%2DMeeting%20Recording%2Emp4&viewid=072c9ba8%2D4c6c%2D43de%2Dbf6d%2D7e33f038b588&parent=%2Fsites%2FADS2022FallAmanov%2FShared%20Documents%2FGeneral%2FRecordings
#include <bits/stdc++.h>

using namespace std;
const int N = (int)1e5;

int n, k, a[N];

bool checker(int d){
    int cnt = 1; // counter of cows
    int last = a[1]; // coordinate of last farm that have a cow
    for(int i = 1; i <= n; i++){
        if(a[i] - last >= d){ // // put the cow at i
            cnt++; 
            last = a[i];
        }
    }
    return cnt >= k;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // f[l] -> true 
    // f[r] -> false
    int l = 1, r = (int)1e9 + 9;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(checker(mid)) l = mid; // big cnt, so we can find largest answer 
        else r = mid;
    }
    cout << l;
}