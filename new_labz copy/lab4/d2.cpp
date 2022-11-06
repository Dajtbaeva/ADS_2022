#include <bits/stdc++.h>

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

    vector<int> levelsumi(Node * cur){
        vector<int> res;
        if(!cur) return res;
        queue<Node *> q;
        q.push(cur);
        while(!q.empty()){ // BFS
            int sz = q.size();
            int sumi = 0;
            for(int i = 0; i < sz; i++){
                Node * temp = q.front();
                q.pop();
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
                sumi += temp -> value;
            }
            res.push_back(sumi);
        }
        return res;
    }

};

int main(){
    BST tree;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        tree.insert(x);
    }
    vector<int> ans = tree.levelsumi(tree.root);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}