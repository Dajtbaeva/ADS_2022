#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    for(int i = 2; i <= sqrt(x); ++i){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> primes;
    int i = 2;
    while(primes.size() != n){
        if(isPrime(i)) primes.push_back(i);
        i++;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        bool ok = false;
        for(int j = 0; j < n; j++){
            if(i != j && abs(primes[i] - primes[j]) == 2){
                res++;
                break;
            }
        }
    }
    cout << n - res;
}