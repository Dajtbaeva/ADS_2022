#include <bits/stdc++.h>

using namespace std;

struct Node{
    char val;
    Node * next;
    bool here;
    Node(char val){
        this -> val = val;
        this -> next = NULL;
        this -> here = false;
    }

};
 
struct LinkedList{
    Node * head, *tail;

    LinkedList(){
        this -> head = NULL;
        this -> tail = NULL;
    }

    void push(char val){
        Node * temp = new Node(val);
        if(!this -> head){
            this -> head = temp;
            this -> tail = temp;
        }else{
            Node * cur = this -> head;
            while(cur){
                if(cur -> val == val){
                    cur -> here = true;
                    return;
                }
                cur = cur -> next;
            }
            this -> tail -> next = temp;
            this -> tail = temp;
        }
    }

    void ans(){
        bool ok = false;
        Node * cur = this -> head;
        while(cur){
            if(!cur -> here){
                cout << cur -> val << " ";
                ok = true;
                break;
            }
            cur = cur -> next;
        }
        if(!ok) cout << "-1 ";
    }
    
};

int main(){
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        char c;
        LinkedList ll;
        for(int j = 0; j < x; j++){
            cin >> c;
            ll.push(c);
            ll.ans();
        }
        cout << "\n";
    }
}