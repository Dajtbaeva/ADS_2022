#include <iostream>
using namespace std;

struct queue{
private:
    int arr[100000];
    int l, r;
    int limit;

public:
    queue(){
        l = 0;
        r = 0;
        limit = 6 * 10e6 + 1;
    }

    void push(int x){
        arr[r++] = x;
    }

    void pop(){
        if(!empty()) l++;
    }

    int front(){
        if(empty()) return limit;
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

    queue q;                                                    // []

    q.push(1);                                                  // [1]
    q.push(2);                                                  // [1, 2]
    q.push(3);                                                  // [1, 2, 3]
    cout << "Queue size: " << q.size() << endl;                 // 3
    cout << "Queue front: " << q.front() << endl;               // 1
    q.pop();                                                    // [2, 3]
    cout << "Queue size: "  << q.size() << endl;                // 2
    cout << "Queue front: " << q.front() << endl;               // 2
    q.pop();                                                    // [3]
    cout << "Queue front: " << q.front() << endl;               // 3
    q.pop();                                                    // []
    

    cout << "Queue is empty? " << (q.empty() ? "YES\n" : "NO\n");
    q.pop();
    cout << "Queue front: " << q.front() << endl; 
}


//                 r  l
//                 v  v     
// arr = [1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]