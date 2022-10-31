#include <bits/stdc++.h>

using namespace std;

void hyp(int a, int b){
    cout << setprecision(4) << sqrt(pow(a, 2) + pow(b, 2));
}
int main(){
    int x, y;
    cin >> x >> y;
    hyp(x, y);
}