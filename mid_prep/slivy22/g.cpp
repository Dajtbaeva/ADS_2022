#include <bits/stdc++.h>
#define ull unsigned long long 

using namespace std;

int main(){
    ull n;
    cin >> n; // 4 - 1 3 3000 3002
    queue<ull> q;
    for(int i = 0; i < n; i++){
        ull x;
        cin >> x;
        q.push(x);
        if(x > 3000){
            ull a = x - 3000;
            while(q.front() < a) q.pop();
        }
        cout << q.size() << " ";
    }
}