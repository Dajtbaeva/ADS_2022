#include <bits/stdc++.h>

using namespace std;

// vector<bool> primes(n + 1, true);
// primes[1] = false;
// for(int i = 2; i <= n; i++){
//     if(!primes[i]) continue;
//     for(int j = i * i; j <= n; j += i){
//         primes[j] = false;
//     }
// }
    // for (int p = 2; p <= n; p++)
    //     if (IsPrime[p]) primes.push_back(p);

bool isprime(int x){
    for(int i = 2; i <= sqrt(x); ++i){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> primes;
    for(int i = 2; i <= 1000000; i++){
        if(isprime(i)) primes.push_back(i);
    }
    cout << primes[n - 1];

}