#include <bits/stdc++.h>

using namespace std;

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
    vector<int> ind;
    for(int i = 1; i < primes.size(); i++){
        if(isprime(i)) ind.push_back(primes[i - 1]);
    }
    cout << ind[n];
}