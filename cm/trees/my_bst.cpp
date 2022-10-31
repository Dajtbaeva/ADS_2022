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

	void _inorder(Node * cur){
		if(!cur) return;
		_inorder(cur -> left);
		cout << cur -> val << " ";
		_inorder(cur -> right);
	}

	void _preorder(Node * cur){
		if(!cur) return;
		cout << cur -> val << " ";
		_preorder(cur -> left);
		_preorder(cur -> right);
	}

	void _postorder(Node * cur){
		if(!cur) return;
		_postorder(cur -> left);
		_postorder(cur -> right);
		cout << cur -> val << " ";
	}

	int _rightmost(Node * cur){
		if(!cur) return -1;
		if(!cur -> right) return cur -> val;
		return _rightmost(cur -> right);
	}
	
	int _leftmost(Node * cur){
		if(!cur) return -1;
		if(!cur -> left) return cur -> val;
		return _leftmost(cur -> left);
	}

	Node * _ascorder(Node * cur){
		if(cur){
			_ascorder(cur -> left);
			cout << cur -> val;
			_ascorder(cur -> right);
		}
		return cur;
	}
	
	Node * _descorder(Node * cur){
		if(cur){
			_descorder(cur -> right);
			cout << cur -> val;
			_descorder(cur -> left);
		}
		return cur;
	}

	Node * _search(Node * cur, int val){
		if(!cur) return NULL;
		if(cur -> val == val) return cur;
		if(val > cur -> val) return _search(cur -> right, val);
		else return _search(cur -> left, val);
	}

	Node * search(Node * cur, int target){
        if(cur){
            if(cur -> val == target) return cur;
        }else{
            search(cur -> left, target);
            search(cur -> right, target);
        }
    }

	Node * _remove(Node * cur, int val){
		if(!cur) return NULL;
		if(cur -> val == val){
			if(!cur -> right && !cur -> left){ // no children
				delete cur;
				return NULL;
			}else if(cur -> right && !cur -> left){ // right
				Node * temp = cur -> right;
				delete cur;
				return temp;
			}else if(!cur -> right && cur -> left){ // left
				Node * temp = cur -> left;
				delete cur;
				return temp;
			}else if(cur -> right && cur -> left){ // both children
				cur -> val = _rightmost(cur -> left);
				cur -> left = _remove(cur -> left, cur -> val);
			}
		}else if(cur -> val < val){
			cur -> right = _remove(cur -> right, val);
			return cur;
		}else if(cur -> val > val){
			cur -> left = _remove(cur -> left, val);
			return cur;
		}
		return cur;
	}

	int find(Node * cur, int target, int level){
		if(!cur) return 0;
		if(cur -> val == target) return level;

		int x = find(cur -> left, target, level + 1);
		if(x != 0) return x;
		x = find(cur -> right, target, level + 1);
		return x;
	}

public:
	void insert(int val){
		root = _insert(root, val);
	}

	void inorder(){
		_inorder(root);
	}

	void preorder(){
		_preorder(root);
	}

	void postorder(){
		_postorder(root);
	}

	int rightmost(){
		return _rightmost(root);
	}

	int leftmost(){
		return _leftmost(root);
	}

	void ascorder(){
		root = _ascorder(root);
	}

	void descorder(){
		root = _descorder(root);
	}

	void remove(int val){
		_remove(root, val);
	}

	Node * search(int val){
		return _search(root, val);
	}

	int height(Node * cur){
		if(!cur) return 0;
		return  max(height(cur -> right), height(cur -> left)) + 1;
	}

	int nodesOfSubtree(Node * cur){
		if(!cur) return 0;
		return nodesOfSubtree(cur -> right) + nodesOfSubtree(cur -> left) + 1;
	}

	int level(int target){
		if(!root) return 0;
		return find(root, target, 1);
	}

	int size(Node * cur){
		if(!cur) return 0;
		return size(cur -> right) + size(cur -> left) + 1;
	}

	int getHeight(Node * cur, int &d){ 
		if (!cur) return 0;
		int left = getHeight(cur -> left, d);
		int right = getHeight(cur -> right, d);
		d = max(d, right + left + 1);
		return max(left, right) + 1;
	}

	int findDiameter(){
		int d = 0;
		getHeight(root, d);
		return d;
	}

	int getWidth(Node * root, int level){
        if (!root) return 0;
        if (level == 1) return 1;
        else if (level > 1) return getWidth(root -> left, level - 1) + getWidth(root -> right, level - 1);
    }

    int getMaxWidth(Node * root){
        int maxWidth = 0;
        int width;
        int h = noOgLevels(root); // height
        for (int i = 1; i <= h; i++) {
            width = getWidth(root, i);
            if (width > maxWidth) maxWidth = width;
        }
        return maxWidth;
    }

	int noOgLevels(Node * cur){
        if(!cur) return 0;
        return max(noOgLevels(cur -> left), noOgLevels(cur -> right)) + 1;
    }

	Node * findTarget(int target){
        Node * cur = root;
        while(cur -> val != target){
            if(target > cur -> val) cur = cur -> right;
            else cur = cur -> left;
        }
        return cur;
    }

	Node* LCA(Node * root, Node * p, Node * q) {
        Node * lca;
        if(root -> val > min(p -> val, q -> val) && root -> val < max(p -> val, q -> val)){
            lca = root;
        }else if(root -> val > p -> val && root -> val > q -> val){
            lca = LCA(root -> left, p, q);
        }else if(root -> val < p -> val && root -> val < q -> val){
            lca = LCA(root -> right, p, q);
        }
        return lca;
    }

	void ans(Node * cur, int &sumi){ // from left to right sumi
        if(!cur) return;
        ans(cur -> right, sumi);
        cur -> val += sumi;
        cout << cur -> val << " ";
        sumi = cur -> val;
        ans(cur -> left, sumi);
    }

	Node * balanced_tree(vector<int> &v, int l, int r){
        if(l > r) return NULL;
        int m = l + (r - l) / 2;
        Node * root = new Node(v[m]);
        root -> left = balanced_tree(v, l, m - 1);
        root -> right = balanced_tree(v, m + 1, r);
        return root;
    }

	// int sz = pow(2, n) - 1;
    // vector<int> v(sz);
    // for(int i = 0; i < sz; i++){
    //     cin >> v[i];
    // }
    // sort(v.begin(), v.end());
    // bst.root = bst.balanced_tree(v, 0, sz - 1);
    // bst.preorder();

	// vector<int> levelsumi(Node * cur){
    //     vector<int> res;
    //     if(!cur) return res;
    //     queue<Node *> q;
    //     q.push(cur);
    //     while(!q.empty()){ // BFS
    //         int sz = q.size();
    //         int sumi = 0;
    //         for(int i = 0; i < sz; i++){
    //             Node * temp = q.front();
    //             q.pop();
    //             if(temp -> left) q.push(temp -> left);
    //             if(temp -> right) q.push(temp -> right);
    //             sumi += temp -> value;
    //         }
    //         res.push_back(sumi);
    //     }
    //     return res;
    // }

	// void sumiOfLevels(Node * node, vector<int> &sumi, int i){ // DFS
    //     if(!node) return;
    //     if(sumi.size() <= i) sumi.push_back(node -> value);
    //     else sumi[i] += node -> value;

    //     sumiOfLevels(node -> left, sumi, i + 1);
    //     sumiOfLevels(node -> right, sumi, i + 1);
    // }

};

int main() {
	BST bst;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        bst.insert(x);
    }
	int k; cin >> k;

	// bst.inorder();
	// bst.postorder();
	// bst.preorder();

	Node * cur = bst.search(k);
	cout << "Height of root: " << bst.height(bst.root) << "\n";
	cout << "Nodes of root: " << bst.nodesOfSubtree(bst.root) << "\n";
	
	cout << "Height of k: " << bst.height(cur) << "\n";
	cout << "Nodes of subtree k: " << bst.nodesOfSubtree(cur) << "\n";
	cout << "Number of level k: " << bst.level(k) << "\n";
	cout << "Size of k: " << bst.size(cur) << "\n";
	return 0;
}
