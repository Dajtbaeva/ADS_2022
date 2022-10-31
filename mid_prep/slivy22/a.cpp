#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	Node * left, * right;

	Node(int val){
		this -> val = val;
		this -> left = this -> right = NULL;
	}
};

struct BST{
	Node * root;
	BST(){
		root = NULL;
	}

private:
	Node * _insert(Node * cur, int val){
		if(!cur) return new Node(val);
		if(val > cur -> val) cur -> right = _insert(cur -> right, val);
		else if(val < cur -> val) cur -> left = _insert(cur -> left, val);
		return cur;
	}

public:
	void insert(int val){
		root = _insert(root, val);
	}

	void dfs(Node * node, vector<int> & ans){
		if(!node) return;

		Node * l = node -> left;
		Node * r = node -> right;
		int i = 0;
		while(l && r){
			ans[i]++;
			l = l -> left;
			r = r -> right;
			i++;
		}
		dfs(node -> left, ans);
		dfs(node -> right, ans);
	}

	void bfs2(Node * node, vector<int>& ans){
		queue<Node*> q;
		q.push(node);

		while(!q.empty()){
			Node * cur = q.front();
			q.pop();

			Node * l = cur -> left;
			Node * r = cur -> right;
			int i = 0;
			while(l && r){
				ans[i]++;
				l = l -> left;
				r = r -> right;
				i++;
			}

			if(cur -> left) q.push(cur -> left);
			if(cur -> right) q.push(cur -> right);
		}
	}

	void countTriangles(Node* node, vector<int>& v) {
		int lvl = 0;
		Node* left = node->left;
		Node* right = node->right;
		while (left && right) {
			v[lvl]++;
			left = left->left;
			right = right->right;
			lvl++;
		}
	}

	void bfs(Node* root, vector<int>& v) {
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node* cur = q.front();
			q.pop();
			countTriangles(cur, v);
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
	}
};

int main() {
	BST bst;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        bst.insert(x);
    }
	vector<int> ans(n - 1);
	// bst.dfs(bst.root, ans);
	bst.bfs(bst.root, ans);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
}
