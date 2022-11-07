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
	Node* root;
	BST() {
		root = NULL;
	}

private:
    Node * push(Node * cur, int val){
        if(cur == NULL) return new Node(val);
        if(val < cur -> value) cur -> left = push(cur -> left, val);
        if(val > cur -> value) cur -> right = push(cur -> right, val);
        return cur;
    }

public:
    void insert(int value) {
		root = push(root, value);
	}

    void preorder(Node* node) {
		if (!node) return;
		cout << node->value << " ";
		this->preorder(node->left);
		this->preorder(node->right);
	}

    Node * findTarget(int target){
        Node * cur = root;
        while(cur -> value != target){
            if(target > cur -> value) cur = cur -> right;
            else cur = cur -> left;
        }
        return cur;
    }
};

int main() {
	BST tree;
    int n, m, x;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        tree.insert(x);
    }
    cin >> m;
    Node * findi = tree.findTarget(m);
    tree.preorder(findi);
}