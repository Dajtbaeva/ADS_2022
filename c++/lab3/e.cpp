#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int sumi = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sumi += a[i];
    }
    cout << sumi;
}