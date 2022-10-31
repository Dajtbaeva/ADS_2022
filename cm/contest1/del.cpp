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

struct DoublyLinkedList{
    int sz;
    ListNode *head;
    ListNode *tail;

    DoublyLinkedList(){
        this -> sz = 0;
        this -> head = NULL;
        this -> tail = NULL;
    }

    void push_back(int val){ 
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

    void removeEveryKthNode(int k){ 
        int sz = 0;
        ListNode * cur = this -> head;
        while(cur){
            sz++;
            cur = cur -> next;
        }
        cur = head;
        for(int i = 1; i <= sz; i++){
            if((i) % k != 0) cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << "\n";
    }

};

int main(){
    DoublyLinkedList* ll = new DoublyLinkedList();
    int n, m, x; 
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll ->push_back(x);
    }
    ll -> removeEveryKthNode(m); 
}