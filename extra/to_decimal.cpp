#include <bits/stdc++.h>

using namespace std;

int to_decimal(int &a[]){
    int ans = 0;
    int one = 1;
    for(int i = a.size() - 1; i >= 0; i--){
        ans += a[i] * one;
        one *= 10;
    }
    int res = 0, i = 0;
    while(ans > 0){
        int b = ans % 10;
        res += b * pow(2, i);
        i++;
        ans /= 10;
    }
    return res;
}

int main(){
    int a[3] = {1, 0, 0};
    cout << to_decimal(a);
}