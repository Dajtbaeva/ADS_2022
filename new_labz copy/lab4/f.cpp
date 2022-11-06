#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node* left, * right;
	Node(int value) {
		this->value = value;
		left = right = NULL;
	}
};

struct BST {
	Node * root;

    int cnt = 0;
	BST() {
		root = NULL;
	}

    Node * push(Node * cur, int val){
        if(cur == NULL) return new Node(val);
        if(val < cur -> value) cur -> left = push(cur -> left, val);
        if(val > cur -> value) cur -> right = push(cur -> right, val);
        return cur;
    }
    
    int getCnt(){
        return cnt;
    }

    void ans(Node * cur){
        if(!cur) return;
        if(cur -> left && cur -> right) cnt++;
        ans(cur -> left);
        ans(cur -> right);
    }
	
};

int main() {
	BST tree;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        tree.root = tree.push(tree.root, x);
    }
    tree.ans(tree.root);
    cout << tree.getCnt();
}
