#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    for(int i = 2; i < n; i++){
        if(isPrime(i) && isPrime(n - i)){
            cout << i << " " << n - i;
            break;
        }
    }
}


// int p[10000010];

// void find_primes1(int n) {   //Эратосфен
//     // for (int i = 2; i <= sqrt(n); i++)
//     for (int i = 2; i * i <= n; i++) { 
//         if (p[i] == 0) {
//             int k = i;                 
//             while (k + i <= n) {
//                 k += i;
//                 p[k] = 1;
//             }
//         }
//     }

//     for (int i = 2; i <= n; i++)
//         if (p[i] == 0 && p[n - i] == 0){
//             cout << i << " " << n - i << endl;
//             break;
//         }
            

// }

// int main() {
//     int n;
//     cin >> n;
//     find_primes1(n);
//     return 0;
// }