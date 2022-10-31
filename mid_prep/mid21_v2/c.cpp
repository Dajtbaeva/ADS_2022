#include <bits/stdc++.h>

using namespace std;

struct Node{
    string val; 
    Node * next;

    Node(string val){
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

    void push_back(string val){
        sz++;
        Node * node = new Node(val);
        if(!head){
            head = tail = node;
        }else{
            tail -> next = node;
            tail = node;
        }
    }

    void pop_back(){
        if(sz == 1){
            head = tail = NULL;
        }else{
            Node * cur = head;
            while(cur -> next -> next){
                cur = cur -> next;
            }
            Node * node = cur -> next;
            cur -> next = NULL;
        }
    }

    void pop_front(){
        if(head){
            Node * node = head;
            head = head -> next;
        } 
    }

    Node * pop_back2(){
        if(sz == 1){
            Node * ans = head;
            head = NULL;
            return ans;
        }
        Node * cur = head;
        while(cur -> next -> next){
            cur = cur -> next;
        }
        Node * node = cur -> next;
        cur -> next = NULL;
        return node;
    }

    void sort(){
        Node * f = head;
        Node * s = NULL;
        if(!head) return;
        while(f -> next){
            s = f -> next;
            while(s){
                if(f -> val > s -> val) swap(f -> val, s -> val);
                s = s -> next;
            }
            f = f -> next;    
        }
    }

    Node * shift_left(Node * head, int c){ // сначала вконец
        if(c == 0) return head;
        Node * cur = head;
        Node * prev = NULL;
        while(c--){
            prev = cur;
            cur = cur -> next;
        }
        Node * tail = cur;
        while(tail -> next) tail = tail -> next;
        tail -> next = head;
        prev -> next = NULL;
        return cur;
    }

    Node * shift_right(Node * head, int x){ // с конца вперед
        if(!x) return head;
        Node * tail = head;
        int sz = 0;
        while(tail -> next){
            sz++;
            tail = tail -> next;
        }
        int ind = sz - x;
        Node * last = head;          
        for(int i = 0; i < ind; i++){
            last = last -> next;
        }

        Node * new_head = last -> next;
        last -> next = NULL;
        tail -> next = head;
        return new_head;
    }

    void shift_left2(int k) {
		k %= sz;
		tail->next = head;
		while (k--) {
			head = head -> next;
			tail = tail -> next;
		}
		tail -> next = nullptr;
	}

	void shift_right2(int k) {
		k %= sz;
		shift_left2(sz - k);
	}

    Node * shift_left3(int k) {
        k %= sz;
        tail -> next = head;
        while (k--) {
            head = head -> next;
            tail = tail -> next;
        }
        tail -> next = NULL;
        return head;
    }

    Node * shift_right3(int k) {
        k %= sz;
        return shift_left3(sz - k);
    }

    bool isEmpty(){
        return sz == 0;
    }
    
    void print(){
        Node * cur = head;
        int n = 2;
        while(cur && n){
            cout << cur -> val << " ";
            cur = cur -> next;
            n--;
        }
        cout << "\n";
    }
};

int main(){
    int n;
    string s;
    LinkedList ll;
    for(int i = 0; i < 52; i++){
        cin >> s;
        ll.push_back(s);
    }
    int k; cin >> k;
    while(k--){
        int x;
        cin >> x;
        ll.shift_left2(x);
    }
    Node * cur = ll.head;
    ll.print();

}