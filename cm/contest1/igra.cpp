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

    void push_front(int val){ 
        Node * cur = new Node(val); 
        if(!start){
            start = cur;
            last = cur;
        }else{
            cur -> next = start;
            start = cur;
        }
        sz++;
    }

    int back(){
        return last -> val;
    }

    int front(){
        return start -> val;
    }

    void pop_front(){
        Node * del = start;
        start = start -> next;
        delete del;
        sz--;
    }

    int size(){
        return sz;
    }
};

int main(){
    Queue q;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        q.push_back(i);
    }
    while(q.size() != 1){
        for(int i = 1; i < k; i++){
            int a = q.front();
            q.push_back(a);
            q.pop_front();
        }
        q.pop_front();
    }
    cout << q.back();
    return 0;
}