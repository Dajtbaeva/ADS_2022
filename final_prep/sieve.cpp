#include <bits/stdc++.h>

using namespace std;

int p[10000010];

void find_primes1(int n) {   //Эратосфен
    // for (int i = 2; i <= sqrt(n); i++)
    for (int i = 2; i * i <= n; i++) { 
        if (p[i] == 0) {
            int k = i;                 
            while (k + i <= n) {
                k += i;
                p[k] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
        if (p[i] == 0)
            cout << i << " ";

}

int main(){
    int n; cin >> n;
    find_primes1(n);
}