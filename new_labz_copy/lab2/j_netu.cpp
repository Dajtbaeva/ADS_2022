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

    int lost(){
        ListNode * cur = this -> head;
        ListNode * temp = this -> head -> next;
        while(cur && temp){
            if(abs(temp -> val - cur -> val) > 1) return cur -> val + 1;
            temp = temp -> next;
            cur = cur -> next;
        }
        if(cur -> val == sz) return 0;
        return sz;
    }

    void sort(){
        ListNode * first = head;
        ListNode * second = NULL;
        if (head == NULL){
            return;
        }
        while(first -> next != NULL){
            second = first -> next;
            while(second != NULL){
                if (first -> val > second -> val){
                    swap(first->val, second->val);
                }
                second = second -> next;
            }
            first = first -> next;
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
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll -> push(x);
    }
    ll -> sort();
    cout << ll -> lost();

}













