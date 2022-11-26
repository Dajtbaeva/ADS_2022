// Задача №760. Обход
// https://informatics.msk.ru/mod/statements/view.php?id=54818&chapterid=760#1

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
            cout << cur -> val << "\n";
            ascOrder(cur -> right);
        }
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
};

int main(){
    BST tree;
    int x;
    while(cin >> x && x != 0){
        tree.push(x); //m
    }
    tree.ascOrder();

}