#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int val){
        this -> val = val;
        this -> next = NULL;
    }
};

class Stack{
public:
    Node * top;
    int sz;
    Stack(){
        top = NULL;
        sz = 0;
    }

    void push(int x){
        Node * node = new Node(x);
        if(top == NULL) top = node;
        node -> next = top;
        top = node;
        sz++;
        cout << "ok\n";
    }

    void print(){
        Node * cur = top;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }

    void clear(){
        while(sz > 0){
            pop2();
        }
        cout << "ok\n";
    }

    void pop(){
        if(top == NULL) cout << "Error\n";
        else{
            Node * cur = top;
            cout << cur -> val << "\n";
            top = top -> next;
            delete(cur);
            sz--;
        }
    }

    void tops(){
        if(top == NULL) cout << "Error\n";
        else cout << top -> val << "\n";
    }

    void pop2(){
        Node * cur = top;
        top = top -> next;
        delete(cur);
        sz--;
    }

    bool isempty(){
        return sz == 0;
    }
};

int main(){
    Stack st;
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        st.push(x);
    }
    cout << st.isempty() << "\n";
    st.pop();

    // while(!st.isempty()){
    //     st.tops();
    //     st.pop2();
    // }
}
