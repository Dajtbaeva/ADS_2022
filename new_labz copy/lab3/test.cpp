#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

struct BST {
private:
	Node* root;

	void _inorder(Node* node) {
		if (!node) return;
		_inorder(node->left);
		cout << node->val << " ";
		_inorder(node->right);
	}

	void _preorder(Node* node) {
		if (!node) return;
		cout << node->val << " ";
		_preorder(node->left);
		_preorder(node->right);
	}

	void _postorder(Node* node) {
		if (!node) return;
		_postorder(node->left);
		_postorder(node->right);
		cout << node->val << " ";
	}

	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}

	int _rightmost(Node* cur) {
		if (!cur) return -1;
		if (!cur->right) return cur->val;
		return _rightmost(cur->right);
	}

	Node* _remove(Node* cur, int target) {
		if (!cur) return NULL;
		if (cur->val == target) {
			if (!cur->right && !cur->left) {
				delete cur;
				return NULL;
			} else if (cur->left && !cur->right) {
				Node* temp = cur->left;
				delete cur;
				return temp;
			} else if (cur->right && !cur->left) {
				Node* temp = cur->right;
				delete cur;
				return temp;
			} else if (cur->right && cur->left) {
				cur->val = _rightmost(cur->left);
				cur->left = _remove(cur->left, cur->val);
			}
		} else if (cur->val < target) {
			cur->right = _remove(cur->right, target);
			return cur;
		} else if (cur->val > target) {
			cur->left = _remove(cur->left, target);
			return cur;
		}
		return cur;
	}

	Node * ascOrder(Node * cur){
        if(cur != NULL){
            ascOrder(cur -> left);
            cout << cur -> val << " ";
            ascOrder(cur -> right);
        }
		return cur;
    }
    Node * descOrder(Node * cur){
        if(cur != NULL){
            descOrder(cur -> right);
            cout << cur -> val << " ";
            descOrder(cur -> left);
        }
		return cur;
    }

	int _getHeight(Node* node) {
		if (!node) return 0;
		return max(_getHeight(node->left), _getHeight(node->right)) + 1;
	}

	int _nodesOfSubtree(Node* node) {
		if (!node) return 0;
		return _nodesOfSubtree(node->left) + _nodesOfSubtree(node->right) + 1;
	}

	Node* _search(Node* cur, int target) {
		if (!cur) return NULL;
		if (cur->val == target) return cur;
		if (cur->val > target) return _search(cur->left, target);
		return _search(cur->right, target);
	}

	int find(Node* root,int t,int l){
		if(!root) return 0;
		if(root->val == t)return l;
		int x = find(root->left, t, l + 1);
		if(x != 0) return x;
		x = find(root->right, t, l + 1);
		return x;
	}

public:
	BST() {
		this->root = NULL;
	}

	void inorder() { // left - node - right
		_inorder(root);
		cout << endl;
	}
	
	void preorder() { 
		_preorder(root);
		cout << endl;
	}
	
	void postorder() {
		_postorder(root);
		cout << endl;
	}

	void ascOrder(){
        ascOrder(root);
    }

    void descOrder(){
        descOrder(root);
    }

	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (!root) root = newNode;
	}

	void remove(int target) {
		_remove(root, target);
	}

	Node* search(int target) {
		return _search(root, target);
	}

	void getHeight(Node * node) {
		cout << "Height of k: " << _getHeight(node) << endl;
	}
	void nodesOfSubtree(Node * node) {
		cout << "Nodes of subtree k: " << _nodesOfSubtree(node) << endl;
	}

	int getLevel(int target){
		if(!root) return 0;
		return find(root, target, 1);
	}

	int size(Node * cur){
		if (cur == NULL) return 0;
		else return(size(cur -> left) + 1 + size(cur -> right));
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
	int k; cin >> k;
	// bst.inorder();
	// bst.postorder();
	// bst.preorder();

	Node * cur = bst.search(k);
	bst.nodesOfSubtree(cur);
	bst.getHeight(cur);
	cout << "Number of level k: " << bst.getLevel(k) << "\n";
	cout << "Size of k: " << bst.size(cur) << "\n";
	bst.descOrder();
	return 0;
}
