#include <bits/stdc++.h>

using namespace std;

int getMaxArea(int a[], int n){
    stack<int> s;

    int max_area = 0;
    int top;
    int area;

    int i=0; 
    while(i < n){
        if(s.empty() || a[s.top()] <= a[i]){
            s.push(i++);
        }else{
            top = s.top();
            s.pop();
            
            if(s.empty()){
                area = a[top] * i;
            }else{
                area = a[top] * (i - s.top() - 1);
            }
            
            if(max_area < area) max_area = area;
        }
    }

    while(!s.empty()){
        top = s.top();
        s.pop();
        
        if(s.empty()){
            area = a[top] * i;
        }else{
            area = a[top] * (i - s.top() - 1);
        }
        
        if(max_area < area) max_area = area;
    }
    return max_area;
}


int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << getMaxArea(a, n);
    return 0;
}
