//hexadil
#include <iostream>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    int m = 2*n +1;
    int x = (2*n + 1 - n) / 2; // (n+1) / 2
    char arr[m][m];
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = '*';
        }
    }
    // top-left
    for(int i = 0; i<x; i++){
        for(int j = 0; j < x - i; ++j){
            arr[i][j] = ' ';
        }
    }
    // top-right
    for(int i = 0; i<x; i++){
        for(int j = x+n+i; j < m; ++j){
            arr[i][j] = ' ';
        }
    }
    // bottom-left
    for(int i = x+n; i<m; i++){
        for(int j = 0; j < i - x - n + 1; j++){
            arr[i][j] = ' ';
        }
    }
    // bottom-right 
    for(int i = x+n; i<m; i++){
        for(int j = m-i+x+n-1; j < m; ++j){
            arr[i][j] = ' ';
        }
    }
    // output
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}
/*
3
      *  *  *        
   *  *  *  *  *     
*  *  *  *  *  *  *  
*  *  *  *  *  *  *  
*  *  *  *  *  *  *  
   *  *  *  *  *     
      *  *  *        
*/