#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * next, * prev;

    Node(int val){
        this -> val = val;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

struct Deque{
    Node * start, * last;
    int sz;

    Deque(){
        this -> start = NULL;
        this -> last = NULL;
        this -> sz = 0;
    }

    int front(){
        return start -> val;
    }

    int back(){
        return last -> val;
    }

    void push_back(int val){
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

    void push_front(int val){ // 1
        Node * cur = new Node(val); 
        if(!start){
            start = cur;
            last = cur;
        } 
        else{
            cur -> next = start;
            start = cur;
        }
        sz++;
    }

    void pop_back(){
        if(!start) throw std::invalid_argument("ERROR!!!");
        else{
            Node * del = last;
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
    Deque q;
    q.push_front(1);
    q.push_front(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);

    while (!q.isempty()) {
        cout << q.back() << " ";
        q.pop_back();
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