#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, sumi;
    sumi = 0;
    while(true){
        cin >> n;
        sumi += n;
        if(cin.get() == '\n') break; // для того чтобы при нажатии на энтер ввод закончился
    }
    cout << sumi;
}