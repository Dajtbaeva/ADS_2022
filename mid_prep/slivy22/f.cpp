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

    int bfs(Node * cur){
        queue<Node*> q;
        q.push(cur);

        int lvl = 0, ans = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                Node * temp = q.front(); q.pop();
                ans += temp -> val - lvl;
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            lvl++;
        }
        return ans;
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
    // bst._inorder(bst.root);
    cout << bst.bfs(bst.root);
}
