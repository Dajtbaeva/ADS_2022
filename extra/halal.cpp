// Halal slice

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, p, h, time = 0;
    cin >> n >> m;
    queue<int> q;
    stack<int> s;
    map<int, int> mm;
    for(int i = 0; i < n; i++){
        cin >> p;
        s.push(p);
        mm[p]++;
    }
    for(int i = 0; i < n; i++){
        cin >> h;
        q.push(h);
    }
    q.push(5); // Alima's 1 (mushroom) pizza
    
    while(!s.empty()){
        time++;
        if(mm[1] == 0){
            cout << ";(\n";
            return 0;
        } // if there's no mushroom pizza
        if(s.top() == 1 && q.front() == 5){
            if(time > m){
                cout << "Yes\n" << "Che opazdyvaem?\n";
                return 0;
            }else{
                cout << "YES";
                return 0;
            }
        }
        if(s.top() == q.front()){
            mm[q.front()]--;
            s.pop();
            q.pop();
        }else{
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
}
/*
5 10
0 1 1 0 0
0 0 0 0 1
---------------
YES
*/