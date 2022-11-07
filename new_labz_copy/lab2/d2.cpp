#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    int cnt;
    Node * next;

    Node(int val){
        this -> cnt = 1;
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
            Node * cur = head;
            while(cur){
                if(cur -> val == val){
                    cur -> cnt++;
                    // break;
                    // return;
                }
                cur = cur -> next;
            }
            tail -> next = node;
            tail = node;
            // cout << cur -> val << " " << cur -> cnt;
        }
    }

    void print(){
        Node * cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << "\n";
    }

    void sort(){
        Node * f = head;
        Node * s = NULL;
        if(!head) return;
        while(f -> next){
            s = f -> next;
            while(s){
                if(f -> val < s -> val){
                    swap(f -> val, s -> val);
                    swap(f -> cnt, s -> cnt);
                } 
                s = s -> next;
            }
            f = f -> next;    
        }
    }

    int maxi(){
        int maxi = 0;
        Node * cur = head;
        while(cur){
            if(cur -> cnt > maxi) maxi = cur -> cnt;
            cur = cur -> next;
        }
        return maxi;
    }

    void ans(){
        Node * cur = head;
        int maxx = maxi();
        sort();
        while(cur){
            // cout << cur -> val << " - " << cur -> cnt << "\n";
            if(cur -> cnt == maxx) cout << cur -> val << " ";
            cur = cur -> next;
        }
    }

};

int main(){
    // freopen()
    int n, x;
    LinkedList ll;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll.add_tail(x);
    }
    // ll.sort();
    // ll.print();
    ll.ans();
    
}
