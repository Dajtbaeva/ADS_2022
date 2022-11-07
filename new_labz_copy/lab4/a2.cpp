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

    bool check(Node * node, string s, int i){
        if(s[i] == 'L') return check(node -> left, s, i + 1);
        else if(s[i] == 'R') return check(node -> right, s, i + 1);
        else if(node == NULL) return false;    
        return true;
    }
};

int main() {
	BST tree;
    int n, m, x;
    string s;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x;
        tree.insert(x);
    }

    for(int j = 0;  j < m; j++){
        cin >> s;
        tree.check(tree.root, s, 0) ? cout << "YES\n" : cout << "NO\n";
    }
}