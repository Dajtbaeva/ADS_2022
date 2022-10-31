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

	void _inorder(Node * cur){
		if(!cur) return;
		_inorder(cur -> left);
		cout << cur -> val << " ";
		_inorder(cur -> right);
	}

   void dfs(Node * node, int &cnt){
        if(!node) return;
        if(node -> right && node ->left) cnt++;
        dfs(node -> right, cnt);
        dfs(node -> left, cnt);
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
    int cnt = 1;
    bst.dfs(bst.root, cnt);
    cout << cnt;
}
