// Задача №757. Высота дерева
// https://informatics.msk.ru/mod/statements/view.php?id=54818&chapterid=757#1

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

    int hh(Node * cur){
        if(cur == NULL) return 0;
        return max(hh(cur -> left), hh(cur -> right)) + 1;
    }

public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root, val);
    }
    int height(){
        return hh(root);
    }
};

int main(){
    BST tree;
    int x;
    while(cin >> x && x != 0){
        tree.push(x); // tree -> root = push(tree -> root, x);
    }
    cout << tree.height() << " ";
}