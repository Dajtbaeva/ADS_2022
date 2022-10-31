#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    cout << a + b % 10 + b / 100;
}