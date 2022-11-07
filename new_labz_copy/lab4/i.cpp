#include <bits/stdc++.h>

using namespace std;

struct Node {
	int val;
    int cnt;
	Node* left;
	Node* right;

	Node(int val) {
        this->cnt = 1;
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

	Node * _insert(Node* cur, int val) {
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

	int _getHeight(Node* node) {
		if (!node) return 0;
		return _getHeight(node->left) + _getHeight(node->right) + 1;
	}

	Node* _search(Node* cur, int target) {
		if (!cur) return NULL;
		if (cur->val == target) return cur;
		if (cur->val > target) return _search(cur->left, target);
		return _search(cur->right, target);
	}

public:
	BST() {
		this->root = NULL;
	}

	void inorder() {
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

	void insert(int val) {
		Node * newNode = _insert(root, val);
		if (!root) root = newNode;
	}

	void remove(int target) {
		_remove(root, target);
	}

	Node* search(int target) {
		return _search(root, target);
	}

	void getHeight() {
		cout << _getHeight(root) << endl;
	}
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	BST bst;
    int n, x;
    cin >> n;
    string s;
    while(n--){
        cin >> s >> x;
        if(s == "insert"){
            Node * newNode = bst.search(x);
            if(newNode){
                newNode->cnt++;
            }
            else bst.insert(x);
        }
        else if(s == "delete"){
            Node * newNode = bst.search(x);
            if(newNode->cnt != 0){
                newNode->cnt--;
            }else bst.remove(x);
        }else{
            Node * newNode = bst.search(x);
            if(!newNode) cout << 0 << "\n";
            else cout << newNode->cnt << "\n";
        }
    }
}
