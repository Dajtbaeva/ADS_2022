#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

class BST{
private:
    Node * root;

    Node * push(Node * cur, int val){
        if(cur == NULL) return new Node(val);
        if(val < cur -> val) cur -> left = push(cur -> left, val);
        if(val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }
    Node * ascOrder(Node * cur){
        if(cur != NULL){
            ascOrder(cur -> left);
            cout << cur -> val << " ";
            ascOrder(cur -> right);
        }
    }
    Node * descOrder(Node * cur){
        if(cur != NULL){
            descOrder(cur -> right);
            cout << cur -> val << " ";
            descOrder(cur -> left);
        }
    }

    int height(Node * cur){
        if(cur == NULL) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    }

public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root, val);
    }
    void ascOrder(){
        ascOrder(root);
    }
    void descOrder(){
        descOrder(root);
    }
    int height(){
        return height(root);
    }
};

int main(){
    BST tree;
    tree.push(3);
    tree.push(5);
    tree.push(6);
    tree.push(7);
    tree.push(9);
    tree.push(2);
    tree.ascOrder();
    cout << "\n";
    tree.descOrder();
}