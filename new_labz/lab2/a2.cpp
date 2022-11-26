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

struct LinkedList{
    int sz;
    Node * head, * tail;

    LinkedList(){
        this -> sz = 0;
        this -> head = NULL;
        this -> tail = NULL;
    }

    void add_tail(int val){
        sz++;
        Node * node = new Node(val);
        if(!head){
            head = tail = node;
        }else{
            tail -> next = node;
            tail = node;
        }
    }

    int ans(int a){
        Node * cur = head;
        int mini = INT_MAX;
        int ans = 0;
        for(int i = 0; i < sz; i++){
            if(abs(cur -> val - a) < mini){
                mini = abs(cur -> val - a);
                ans = i;
            }
            cur = cur -> next;
        }
        return ans;
    }

};

int main(){
    int n, x;
    LinkedList ll;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll.add_tail(x);
    }
    int k; cin >> k;
    cout << ll.ans(k);
}
