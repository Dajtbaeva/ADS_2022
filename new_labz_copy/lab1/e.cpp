#include <bits/stdc++.h>

using namespace std;

int main(){
    deque<int> d1(5);
    deque<int> d2(5);
    for(int i = 0; i < 5; i++){
        cin >> d1[i];
    }
    for(int i = 0; i < 5; i++){
        cin >> d2[i];
    }

    int cnt = 0;
    while(!d1.empty() && !d2.empty() && cnt < 1000000){
        cnt++;
        int a = d1.front();
        int b = d2.front();
        d1.pop_front();
        d2.pop_front();
        if(a == 0 && b == 9){
            d1.push_back(a);
            d1.push_back(b);
        }
        else if(a == 9 && b == 0){
            d2.push_back(a);
            d2.push_back(b);
        }
        else if(a > b){
            d1.push_back(a);
            d1.push_back(b);
        }
        else{
            d2.push_back(a);
            d2.push_back(b);
        }
    }
    if(d1.empty()) cout << "Nursik " << cnt;
    else if(d2.empty()) cout << "Boris " << cnt;
    else cout << "blin nichya"; 
}