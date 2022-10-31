#include <iostream>
using namespace std;

struct q{
private:
    int arr[100];
    int l, r;

public:
    q(){
        l = 0;
        r = 0;
    }

    void push(int x){
        arr[r++] = x;
    }

    void pop(){
        l++;
    }

    int front(){
        return arr[l];
    }

    int size(){
        return r - l;
    }

    bool empty(){
        return r == l;
    }
};

int main(){
    q que;
    que.push(1);                      
    que.push(2);                      
    que.push(3);                      
    que.push(9);        

}
