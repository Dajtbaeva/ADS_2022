#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;

    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
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

    void add_tail(int val){ // 2
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

    void print(){ // 6
        ListNode * cur = this -> head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << "\n";
    }

    ListNode* cyclic_left(ListNode* head, int x){ // сначала вконец
        if(!x) return head; // x != 0
        ListNode *new_head = head;          
        ListNode *prev = NULL;
        while (x--) {
            prev = new_head;
            new_head = new_head->next;
        }
        ListNode *tail = new_head;
        while (tail->next) tail = tail->next;
        tail->next = head;
        prev->next = NULL;
        return new_head;
    }
    
};

int main(){
    LinkedList* ll = new LinkedList();
    int n, m, x;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll ->add_tail(x);
    }

    ll -> head =  ll -> cyclic_left(ll -> head, m);
    ll -> print();
}