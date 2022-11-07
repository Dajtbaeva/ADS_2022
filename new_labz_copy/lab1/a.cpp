// http://78.140.223.58/cgi-bin/new-client?contest_id=301 

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n;
    for(int i  = 0; i < n; i++){
        cin >> x; // 4
        deque<int> dq;
        dq.push_back(x);
        int a = x - 1; // 3
        while(a > 0){
            dq.push_front(a);
            int b = a; // 3
            while(b > 0){
                int z = dq.back();
                dq.pop_back();
                dq.push_front(z);
                b--;
            }
            a--;
        }
        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << "\n";
    }
}