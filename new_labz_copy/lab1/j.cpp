#include <bits/stdc++.h>

using namespace std;
 
int main(){
    // freopen("j.txt", "r", stdin);
    char c;
    bool ok = false;
    deque<int> d;
    while(true){
        cin >> c;
        if(c == '+'){
            int n;
            cin >> n;
            d.push_front(n);
        } 
        else if(c == '-'){
            int n;
            cin >> n;
            d.push_back(n);
        }
        else if(c == '*'){
            if(!d.empty()){
                cout << (d.front() + d.back()) << "\n";
                if(d.size() == 1) d.pop_back();
                else{
                    d.pop_back(); d.pop_front();
                } 
            } 
            else cout << "error\n";             
        }else if(c == '!') return 0;
    }
}