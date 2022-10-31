#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n;
    queue<string> q;
    string s;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 1){
            cin >> s;
            q.push(s);
            cout << q.front() << "\n";
        }else{
            q.pop();
            if(q.empty()) cout << "queue is empty\n";
            else cout << q.front() << "\n";
        }
    }
}