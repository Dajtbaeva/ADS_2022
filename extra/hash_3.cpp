// https://kbtuedu.sharepoint.com/sites/AlgorithmsandDataStructuresBaisakov/Shared%20Documents/Forms/AllItems.aspx?FolderCTID=0x012000E5045980CECE994C838ACF3C9BD20A70&id=%2Fsites%2FAlgorithmsandDataStructuresBaisakov%2FShared%20Documents%2FBeisenbek%20Baisakov%2FRecordings%2FWeek%209%20part%202%2D20211106%5F110543%2DMeeting%20Recording%2Emp4&parent=%2Fsites%2FAlgorithmsandDataStructuresBaisakov%2FShared%20Documents%2FBeisenbek%20Baisakov%2FRecordings
#include <iostream>
#include <vector>

using namespace std;

vector<int> f(string s){
   int n = s.size();
   vector<int> pi(n);
   for(int i = 1; i < n; ++i){
       int j = pi[i-1];
       while(j > 0 && s[i] != s[j]){
           j = pi[j - 1];
       }
       if(s[i] == s[j]) j = j + 1;
       pi[i] = j;
   }
   return pi;
}


int main(){

    string s, t;
    cin >> s;
    cin >> t;

    string n = s + "#" + t;

    vector<int> pi = f(n);

    for(int i = 0; i < pi.size(); ++i){
        if(pi[i] == s.size()){
            cout << "found!";
        }
    }

    return 0;
}