// Задача №761. Вывод листьев
// https://informatics.msk.ru/mod/statements/view.php?id=54818&chapterid=761#1

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

    void printLeaf(Node * cur){
        if(cur != NULL){
            printLeaf(cur -> left);
            if(cur -> left == NULL && cur -> right == NULL) cout << cur -> val << "\n";
            printLeaf(cur -> right);
        }
    }

public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root, val);
    }
    void printleaf(){
        printLeaf(root);
    }
};

int main(){
    BST tree;
    int x;
    while(cin >> x && x != 0){
        tree.push(x); 
    }
    tree.printleaf();
}