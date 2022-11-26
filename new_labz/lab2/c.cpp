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

    void push(int val){
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

    void print(){
        ListNode * cur = this -> head;
        int i = 0;
        while(cur){ // cur != NULL
            if(i % 2 == 0) cout << cur -> val << " ";
            cur = cur -> next;
            i++;
        }
        cout << "\n";
    }

    // void del_even_index(){
    //     if(head == NULL){
    //         return;
    //     }
        
    //     else{
    //         Node *odd = head;
    //         Node *even = head->next;
    //         Node *oddhead = odd;
    //         if(even-> next == NULL){
    //             odd->next = NULL;
    //         }
    //         else{
    //             while(even != NULL && even->next != NULL){
    //                 odd->next = even->next;
    //                 odd = even->next;
    //                 even->next = odd->next;
    //                 even = odd->next;
    //             }
    //             odd->next = NULL;
    //         }
            
    //         head = oddhead;
            
    //     }
    // }

};

int main(){
    LinkedList * ll = new LinkedList();

    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll -> push(x);
    }
    ll -> print();

}