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

    int shift(LinkedList * ll1){
		int res = 0;
        ListNode * cur = ll1 -> head;
        ListNode * temp = this -> head;
        while(temp){
            if(cur -> val != temp -> val) res++;
            temp = temp -> next;
            cur = cur -> next;
        }
        return res;
    }

    void print(){
        ListNode * cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << "\n";
    }
};

int main(){
    LinkedList * ll = new LinkedList();
	LinkedList * ll2 = new LinkedList();
    int x;
    while(cin >> x){
        ll -> push(x);
        ll2 -> push(x);
    }
    ll2 -> sort();
    cout << ll -> shift(ll2);
}