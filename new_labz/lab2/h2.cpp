#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(p == 0){
        node -> next = head;
        head = node;
        return head;
    }else{
        Node * cur = head;
        for(int i = 0; i < p - 1; i++){
            cur = cur -> next;
        }
        node -> next = cur -> next;
        cur -> next = node;
        return head;
    }
}
 
Node* remove(Node* head, int p){
    if(p == 0){
        Node * cur = head;
        head = head -> next;
        delete cur;
        return head;
    }else{
        Node * cur = head;
        for(int i = 0; i < p - 1; i++){
            cur = cur -> next;
        }
        Node * temp = cur -> next;
        cur -> next = cur -> next -> next;
        delete temp;
        return head;
    }
}
 
Node* replace(Node* head, int p1, int p2){
    Node * node = head;
    if(p1 == 0){
        node = head;
        head = head -> next;
    }else{
        Node * cur = head;
        for(int i = 0; i < p1 - 1; i++) cur = cur -> next;
        node = cur -> next;
        cur -> next = cur -> next -> next;
    }
    return insert(head, node, p2);
}
 
Node* reverse(Node* head){
    Node * c = head;
    Node * p = NULL, * n = NULL;
    while(c){
        n = c -> next;
        c -> next = p;
        p = c;
        c = n;
    }
    head = p;
    return head;
}
 
void print(Node* head){
    if(head){
        Node * cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << "\n";
    }
}
 
Node* cyclic_left(Node* head, int x){
    if(!x) return head;
    Node * cur = head;
    Node * prev = NULL;
    while(x--){
        prev = cur;
        cur = cur -> next;
    }

    Node * tail = cur;
    while(tail -> next) tail = tail -> next;
    tail -> next = head;
    prev -> next = NULL;
    return cur;
}
 
Node* cyclic_right(Node* head, int x){
    if(!x) return head;
    Node * cur = head;
    int sz = 0;
    while(cur){
        sz++;
        cur = cur -> next;
    }
    return cyclic_left(head, sz - x);
}
 
int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}