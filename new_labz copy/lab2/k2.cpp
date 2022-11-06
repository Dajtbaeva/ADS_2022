#include <bits/stdc++.h>

using namespace std;

struct Node{
    char val;
    Node * next;
    bool here;
    Node(char val){
        this -> val = val;
        this -> next = NULL;
        this -> here = NULL;
    }
};

struct LinkedList{
    Node * head, * tail;

    LinkedList(){
        this -> head = this -> tail = NULL;
    }

    void push(char c){
        Node * node = new Node(c);
        if(!head) head = tail = node;
        else{
            Node * cur = head;
            while(cur){
                if(cur -> val == c){
                    cur -> here = true;
                    return;
                }
                cur = cur -> next;
            }
            tail -> next = node;
            tail = node;
        }
    }

    void ans(){
        bool flag = false;
        Node * cur = head;
        while(cur){
            if(!cur -> here){ // ego tam net
                cout << cur -> val << " ";
                flag = true;
                break;
            } 
            cur = cur -> next;
        }
        if(!flag) cout << "-1 ";
    }

};

int main(){
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        LinkedList ll;
        char c;
        for(int j = 0; j < x; j++){
            cin >> c;
            ll.push(c);
            ll.ans();
        }
        cout << "\n";
    }
}