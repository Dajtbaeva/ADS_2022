#include <iostream>
using namespace std;

struct queue{
private:
    int arr[100000];
    int l, r;

public:
    queue(){
        l = 0;
        r = 0;
    }

    void push(int x){
        arr[r] = x;
        r++;
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

    queue q;                        // []

    q.push(1);                      // [1]
    q.push(2);                      // [1, 2]
    q.push(3);                      // [1, 2, 3]
    q.push(9);                      // [1, 2, 3, 9]
    q.push(5);                      // [1, 2, 3, 9, 5]
    q.push(4);                      // [1, 2, 3, 9, 5, 4]
    q.push(7);                      // [1, 2, 3, 9, 5, 4, 7]
    cout << q.front() << endl;      // 1
    q.pop();                        // [2, 3, 9, 5, 4, 7]
    q.pop();                        // [3, 9, 5, 4, 7]
    q.pop();                        // front -> [9, 5, 4, 7]
    cout << q.front() << endl;      // 9
    cout << q.size() << endl;       // 4

}

//                 l           r
//                 v           v
// arr = [1, 2, 3, 9, 5, 4, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
// q = [9, 5, 4, 7]
// l = 7, r = 7