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
    
    void ans(string s){
        bool res = true;
        Node * cur = root;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L') cur = cur -> left;
            if(s[i] == 'R') cur = cur -> right;
            if(cur == NULL){
                res = false;
                break;
            }
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
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
        tree.ans(s);
    }
}