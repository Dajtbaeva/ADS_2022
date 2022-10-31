// Hashes, Rabin-Karp algo and KMP
// https://kbtuedu.sharepoint.com/sites/AlgorithmsandDataStructuresBaisakov/Shared%20Documents/Forms/AllItems.aspx?id=%2Fsites%2FAlgorithmsandDataStructuresBaisakov%2FShared%20Documents%2FBeisenbek%20Baisakov%2FRecordings%2FWeek%206%20part%202%2E%20Hash%2E%20RK%2E%2D20211009%5F110015%2DMeeting%20Recording%2Emp4&parent=%2Fsites%2FAlgorithmsandDataStructuresBaisakov%2FShared%20Documents%2FBeisenbek%20Baisakov%2FRecordings
// Задача №99. Поиск подстроки
// https://informatics.msk.ru/mod/statements/view.php?id=56133#1

#include <bits/stdc++.h>

using namespace std;

void h(string str, string pattern){
    int n = str.length();
    int h[n];
    int p[n];

    p[0] = 1;

    for(int i = 1; i < n; ++i){
        p[i] = p[i-1] * 31;
    }

    for(int i = 0; i < n; ++i){
        h[i] = (str[i] - 'a' + 1) * p[i];
        if(i > 0){
            h[i] += h[i-1];
        }
    }

    int ph = 0;
    int m = pattern.length();
    for(int i = 0; i < m; ++i){
        ph += (pattern[i] - 'a' + 1) * p[i];
    }

    for(int i = 0; i + m - 1 < n; ++i){
        int j = i + m -1;
        int cur = h[j];
        if(i > 0){
            cur -= h[i-1];
        }
        if(ph * p[i] == cur){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(){
    string s, t;
    cin >> s >> t;
    h(s, t);
}