// Задача №762. Вывод развилок
// https://informatics.msk.ru/mod/statements/view.php?id=54818&chapterid=762#1

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

    void printForks(Node * cur){
        if(cur != NULL){
            printForks(cur -> left);
            if(cur -> left != NULL && cur -> right != NULL) cout << cur -> val << "\n";
            printForks(cur -> right);
        }
    }

public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root, val);
    }
    void printForks(){
        printForks(root);
    }
};

int main(){
    BST tree;
    int x;
    while(cin >> x && x != 0){
        tree.push(x); 
    }
    tree.printForks();
}