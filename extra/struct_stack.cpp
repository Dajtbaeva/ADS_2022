#include <bits/stdc++.h>

using namespace std;

struct st{
    private:
        int a[100];
        int topindex;

        st(){
            topindex = -1;
        }
    public:
        void push(int x){
            topindex++;
            a[topindex] = x;
        }

        int top(){
            if(topindex != -1) return a[topindex];
        }

        void pop(){
            if(topindex != -1) topindex--;
        }

        bool empty(){
            if(topindex == -1) return true;
            return false;
        }

        int size(){
            if(topindex == -1) return 0;
            else return topindex + 1;
        }
}

int main(){
    st s;
    for(int i = 0; i < 10; i++) s.push(i);

    while(!s.empty()){
        cout << s.top() << "\n";
        s.pop();
    }

}