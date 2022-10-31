#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * next;

    Node(int val){
        this -> val = val;
        this -> next = NULL;
    }
};
 
struct Queue{
    Node * start, * last;
    int sz;

    Queue(){
        this -> start = NULL;
        this -> last = NULL;
        this -> sz = 0;
    }

    int front(){
        return start -> val;
    }

    void push(int val){
        Node * cur = new Node(val); 
        if(!start){
            start = cur;
            last = cur;
        } 
        else{
            last -> next = cur;
            last = cur;
        }
        sz++;
    }

    void pop(){
        if(!start) throw std::invalid_argument("ERROR!!!");
        else{
            Node * del = start;
            start = start -> next;
            delete del;
            sz--;
        }
    }

    bool isempty(){
        return sz == 0;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(10);
    q.push(10);
    q.push(10);
    while (!q.isempty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
// int main(){
//     Queue q;
//     int n, x;
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> x;
//         q.push(x);
//     }

//     while(!q.isempty()){
//         cout << q.front() << " ";
//         q.pop();
//     }
// }