#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int maxi = a[0];
    for(int i = 0; i < n; i++){
        if(maxi > a[i]) maxi = a[i];
    }
    int mini = a[0];
    for(int i = 0; i < n; i++){
        if(mini < a[i]) mini = a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] == maxi){
            cout << mini;
        }else cout << a[i] << " ";
    }
}