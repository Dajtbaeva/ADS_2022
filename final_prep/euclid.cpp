#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}
// int gcd (int a, int b) {
// 	while (b) {
// 		a %= b;
// 		swap (a, b);
// 	}
// 	return a;
// }
int main(){
    int x, y; cin >> x >> y;
    cout << gcd(x, y);
}