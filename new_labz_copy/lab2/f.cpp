#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;

    ListNode(){
        this -> val = 0;
        this -> next = NULL;
    }

    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
    }

    ListNode(int val, ListNode * next){
        this -> val = val;
        this -> next = next;
    }
};

struct LinkedList{
    int sz;
    ListNode * head, *tail;

    LinkedList(){
        this -> sz = 0;
        this -> head = NULL;
        this -> tail = NULL;
    }

    void add_head(int val){
        sz++;
        ListNode * temp = new ListNode(val);
        if(!this -> head){
            this -> head = temp;
            this -> tail = temp;
        }else{
            temp -> next = this -> head;
            this -> head = temp;
        }
    }

    void add_tail(int val){
        sz++;
        ListNode * temp = new ListNode(val);
        if(!this -> head){
            this -> head = temp;
            this -> tail = temp;
        }else{
            this -> tail -> next = temp;
            this -> tail = temp;
        }
    }

    void add_index(int ind, int val){
        if(ind > this -> sz) return;
        else if(ind == 0) this -> add_head(val);
        else if(ind == this -> sz) this -> add_tail(val);
        else{
            ListNode * temp = new ListNode(val);
            ListNode * cur = this -> head;
            for(int i = 1; i < ind; i++) cur = cur -> next;
            temp -> next = cur -> next;
            cur -> next = temp;
            sz++;
        }
    }

    void print(){
        ListNode * cur = this -> head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << "\n";
    }

};

int main(){
    LinkedList* ll = new LinkedList();
    int n, x, data, in;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll -> add_tail(x);
    }
    cin >> data;
    cin >> in;
    ll -> add_index(in, data);
    ll -> print();
}