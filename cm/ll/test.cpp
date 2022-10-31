#include <bits/stdc++.h>
using namespace std;


struct Node{
    string val;
    int cnt;
    Node *next;

    Node(string val){
        this->val = val;
        next = NULL;
        cnt = 1;
    }
};

class LinkedList{
    public:
    int size;
    Node *head;
    Node *tail;

    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool contains(string val){
        if(head == NULL) return false;
        Node *cur = head;
        while(cur != NULL){
            if(cur->val == val) return true;
            cur = cur->next;
        }
        return false;
    }

    void pushBack(string val){
        Node *node = new Node(val);
        if(head == NULL){
            head = tail = node;

        }
        else{
            tail->next = node;
            tail = node;
        }
        size++;

        
    }

    void reverse(){
        Node *next = NULL;
        Node *prev = NULL;
        Node *cur = head;
        while(cur != NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }


    void print(){
        Node *cur = head;
        while(cur != NULL){
            cout << cur -> val << endl;
            cur = cur -> next;
        }
    }

};


int main(){
    LinkedList *ll = new LinkedList();
    int n; cin >> n;
    string s;
    while(n--){
        cin >> s;
        if(!ll->contains(s)) ll->pushBack(s);
    }
    //ll->print();
    cout << "All in all: " << ll->size << endl;
    ll->reverse();
    cout << "Students:" << endl;
    ll->print();
}