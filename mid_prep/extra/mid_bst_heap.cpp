// https://pastebin.com/jREJq9ZA

// BST

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
	
	int minHeight(Node * cur){
		if(!cur) return 0;
		return  min(height(cur -> right), height(cur -> left)) + 1;
	}

	int nodesOfSubtree(Node * cur){
		if(!cur) return 0;
		return nodesOfSubtree(cur -> right) + nodesOfSubtree(cur -> left) + 1;
	}

	int getSubCnt(Node *node){
        int cnt = 0; 
        if(node == NULL){
            return 0;
        }
        queue <Node*> q;
        q.push(node);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                Node *cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                cnt++;
            }
        }
        return cnt;
    }

	int level(int target){
		if(!root) return 0;
		return find(root, target, 1);
	}

	int size(Node * cur){
		if(!cur) return 0;
		return size(cur -> right) + size(cur -> left) + 1;
	}

	void levelOrder(Node* node) {
		queue<Node*> q;
		q.push(node);
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				Node* cur = q.front();
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
				cout << cur->val << " ";
			}
			cout << '\n';
		}
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

	int getWidth(Node * root, int level){ // DFS
        if (!root) return 0;
        if (level == 1) return 1;
        else if (level > 1) return getWidth(root -> left, level - 1) + getWidth(root -> right, level - 1);
    }

	int getWidth2(Node* node) { //BFS
		queue<Node*> q;
		int ans = -1;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			ans = max(ans, size);
			while (size--) {
				Node* cur = q.front();
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
		}
		return ans;
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

	int getWidth2(Node *node){
        if(!node) return 0;
        queue <Node*> q;
        q.push(node);
        int cnt = 0;
        int maxi = 0;
        while(!q.empty()){
            int sz = q.size();
            cnt = 0;
            for(int i = 0; i < sz; i++){
                Node * cur = q.front();
                q.pop();
                if(cur -> left) {
                    q.push(cur -> left);
                    cnt++;
                }
                if(cur -> right) {
                    q.push(cur -> right);
                    cnt++;
                }
         
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }

	int getWidth3(Node *node){
        if(node == NULL){
            return 0;
        }
        queue <Node*> q;
        q.push(node);
        int cnt = 0;
        int maxi = 0;
        while(!q.empty()){
            int sz = q.size();
            cnt = 0;
            for(int i = 0; i < sz; i++){
                Node *cur = q.front();
                q.pop();
                if(cur->left && cur->right == NULL) {
                    q.push(cur->left);
                    cnt++;
                }
                if(cur->right && cur->left == NULL) {
                    q.push(cur->right);
                    cnt+=2;
                }
                if(cur->left && cur->right){
                    q.push(cur->left);
                    q.push(cur->right);
                    cnt+=2;
                }
         
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
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

	void maxWidth_bfs(Node* node, int& ans) {
		queue<Node*> q;
		q.push(node);
		while (!q.empty()) {
			int size = q.size();
			ans = max(ans, size);
			while (size--) {
				Node* cur = q.front();
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
		}
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

    //  Triangle Binary Search Tree, Get triangles
    // int getCnt(){
    //     return cnt;
    // }

    // void ans(Node * cur){
    //     if(!cur) return;
    //     if(cur -> left && cur -> right) cnt++;
    //     ans(cur -> left);
    //     ans(cur -> right);
    // }

    // Greater Sum Tree
    // void ans(Node * cur, int &sumi){
    //     if(!cur) return;
    //     ans(cur -> right, sumi);
    //     cur -> value += sumi;
    //     cout << cur -> value << " ";
    //     sumi = cur -> value;
    //     ans(cur -> left, sumi);
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

// MaxHeap
#include <bits/stdc++.h>

using namespace std;

struct MinHeap{
    vector<int> heap;

    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }

    void insert(int val){
        heap.push_back(val);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] < heap[i]){ // sift_up
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    int extractMax(){
        if(heap.size() == 0) return INT_MAX;
        if(heap.size() == 1){
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(0); // sift_down
        return root;
    }

    void heapify(int i){
        if(left(i) > heap.size() - 1) return;

        int smallest = left(i);
        if(right(i) < heap.size() && heap[right(i)] > heap[left(i)]) smallest = right(i);

        if(heap[smallest] > heap[i]){
            swap(heap[smallest], heap[i]);
            heapify(smallest); 
        }
    }

    void siftUp(int i){
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_value) {
        heap[i] = new_value;
        siftUp(i);
    }

    void increaseKey(int i, int new_value) {
        heap[i] = new_value;
        heapify(i);
    }

    void print(){
        for (int i = 0; i < heap.size(); i++) 
            cout << heap[i] << " ";
        cout << endl;
    }

    bool isEmpty(){
        return heap.size() == 0;
    }

    int sz(){
        return heap.size();
    }

    int displayMax(){
        return heap[0];
    }
};

int main(){
    MinHeap mh;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mh.insert(x);
    }
    while(n--){
        cout << mh.extractMax() << " ";
    }
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct DotsHeap {
	vector<pair<int, int> > ar;
	DotsHeap() {}

	int parent(int i) {
		return (i - 1) / 2;
	}

	int left(int i) {
		return 2 * i + 1;
	}

	int right(int i) {
		return 2 * i + 2;
	}

	bool comp(pair<int, int> p1, pair<int, int> p2) {
		int h1 = pow(p1.first, 2) + pow(p1.second, 2);
		int h2 = pow(p2.first, 2) + pow(p2.second, 2);
		return h1 < h2;
	}

	void insert(pair<int, int> val) {
		ar.push_back(val);
		int i = ar.size() - 1;
		while (i > 0 && comp(ar[i], ar[parent(i)])) {
			swap(ar[i], ar[parent(i)]);
			i = parent(i);
		}
	}

	pair<int, int> extract() {
		if (ar.empty()) {
			throw std::runtime_error("heap is empty");
		}
		if (ar.size() == 1) {
			pair<int, int> ret = ar[0];
			ar.pop_back();
			return ret;
		}
		pair<int, int> ret = ar[0];
		ar[0] = ar.back(); // ar[ar.size() - 1]
		ar.pop_back();
		heapify(0);
		return ret;
	}

	void heapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < ar.size() && comp(ar[l], ar[smallest])) {
			smallest = l;
		}
		if (r < ar.size() && comp(ar[r], ar[smallest])) {
			smallest = r;
		}
		if (smallest != i) {
			swap(ar[i], ar[smallest]);
			heapify(smallest);
		}
	}

	bool empty() {
		return ar.empty();
	}
};

// MinHeap
#include <bits/stdc++.h>

using namespace std;

struct MinHeap{
    vector<int> heap;

    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }

    void insert(int val){
        heap.push_back(val);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] > heap[i]){ // sift_up
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    int extractMin(){
        if(heap.size() == 0) return INT_MAX;
        if(heap.size() == 1){
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(0); // sift_down
        return root;
    }

    void heapify(int i){
        if(left(i) > heap.size() - 1) return;

        int smallest = left(i);
        if(right(i) < heap.size() && heap[right(i)] < heap[left(i)]) smallest = right(i);

        if(heap[smallest] < heap[i]){
            swap(heap[smallest], heap[i]);
            heapify(smallest); 
        }
    }

    void siftUp(int i){
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_value) {
        heap[i] = new_value;
        siftUp(i);
    }

    void increaseKey(int i, int new_value) {
        heap[i] = new_value;
        heapify(i);
    }

    void print(){
        for (int i = 0; i < heap.size(); i++) 
            cout << heap[i] << " ";
        cout << endl;
    }

    bool isEmpty(){
        return heap.size() == 0;
    }

    int sz(){
        return heap.size();
    }

    int displayMin(){
        return heap[0];
    }
};

int main(){
    MinHeap mh;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mh.insert(x);
    }
    while(n--){
        cout << mh.extractMin() << " ";
    }
}
 
// BinaryTree
#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node* left, * right;
	Node(int value) {
		this->value = value;
		left = right = nullptr;
	}
};
 
struct BinaryTree {
	Node* root;
	BinaryTree() {
		root = nullptr;
	}
private:
	void inorder(Node* node) {
		if (!node) return;
		this->inorder(node->left);
		cout << node->value << " ";
		this->inorder(node->right);
	}
	void preorder(Node* node) {
		if (!node) return;
		cout << node->value << " ";
		this->preorder(node->left);
		this->preorder(node->right);
	}
	void postorder(Node* node) {
		if (!node) return;
		this->postorder(node->left);
		this->postorder(node->right);
		cout << node->value << " ";
	}

	Node* findBlankNode() {
		queue<Node*> q;
		q.push(this->root);
		while (q.front()->left && q.front()->right) {
			if (q.front()->left) q.push(q.front()->left);
			if (q.front()->right) q.push(q.front()->right);
			q.pop();
		}
		return q.front();
	}
public:
	void inorder() {
		this->inorder(this->root); // left - node - right
	}
	void preorder() {
		this->preorder(this->root); // node - left - right
	}
	void postorder() {
		this->postorder(this->root); // left - right - node
	}
	void insert(int value) {
		if (!this->root) {
			this->root = new Node(value);
		}
		else {
			Node* cur = this->findBlankNode();
			if (!cur->left)
				cur->left = new Node(value);
			else if (!cur->right)
				cur->right = new Node(value);
		}
	}
	void remove(int value) {
		queue<Node*> q;
		q.push(this->root);
		while (q.front()->left->value != value && q.front()->right->value != value) {
			if (q.front()->left) q.push(q.front()->left);
			if (q.front()->right) q.push(q.front()->right);
			q.pop();
		}
		Node* cur = q.front();
		if (cur->left->value == value)
			cur->left = nullptr;
		else
			cur->right = nullptr;
	}
};

int main() {
	BinaryTree tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.remove(3);
	tree.inorder();
	cout << endl;
	tree.preorder();
	cout << endl;
	tree.postorder();
	cout << endl;
	return 0;
}

// leetcode

// Same Tree
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p || !q) return false;
        if(p->val != q->val) return false;
        return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
    }

// Binary Tree Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        vector<int> ans2;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop(); 
            ans2.push_back(temp -> val);
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
        return ans;
    }

// Maximum Depth of Binary Tree
class Solution { // DFS
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};

class Solution { // BFS
public:
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            } cnt++;
        }
        return cnt;
    }
};

// Convert Sorted Array to Binary Search Tree
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode * helper(vector<int>& nums, int l, int r){
        if(l > r) return NULL;
        int m = (l + r) / 2;
        TreeNode * root = new TreeNode(nums[m]);
        root->left = helper(nums, l, m - 1);
        root->right = helper(nums, m + 1, r);
        return root;
    }
};

// Balanced Binary Tree
class Solution {
public:
    int hh(TreeNode * cur){
        if(cur == NULL) return 0;
        return max(hh(cur -> right), hh(cur -> left)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(hh(root->left) - hh(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};

// Minimum Depth of Binary Tree
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        else if(root->left == NULL) return minDepth(root->right) + 1;
        else if(root->right == NULL) return minDepth(root->left) + 1;

        int left = minDepth(root->left) + 1;
        int right = minDepth(root->right) + 1;
        return min(left,right);    
    }
};

// Path Sum

class Solution {
public:
    bool solve(TreeNode* root,int sum){
        if(!root) return false;
        if( sum==root->val && !root->left && !root->right) return true;
        return solve(root->left,sum-root->val)||solve(root->right,sum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        targetSum -= root->val;
        // check if the path sum is equal to target or not
        if(!root->left && !root->right) 
            return targetSum == 0;    
        
        return hasPathSum(root->left, targetSum) ||
            hasPathSum(root->right, targetSum);
    }
};

// Invert Binary Tree

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) { // DFS
        if(root == NULL) return NULL;
        TreeNode * node = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(node);
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) { // BFS
        if(root == NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* node = q.front(); q.pop();
                swap(node->left, node->right);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};

// Lowest Common Ancestor of a Binary Search Tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * lca;
        if(root -> val > min(p -> val, q -> val) && root -> val < max(p -> val, q -> val)){
            lca = root;
        }else if(root -> val > p -> val && root -> val > q -> val){
            lca = lowestCommonAncestor(root -> left, p, q);
        }else if(root -> val < p -> val && root -> val < q -> val){
            lca = lowestCommonAncestor(root -> right, p, q);
        }
        return lca;
    }
};

// Average of Levels in Binary Tree
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) { // BFS
        if(root == NULL) return {};
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sumi = 0;
            for(int i = 0; i < n; i++){
                TreeNode * node = q.front(); q.pop();
                sumi += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); 
            }
            ans.push_back(sumi / n);
        }
        return ans;
    }
};  

class Solution { // DFS
public:
    void doDFS(TreeNode* root,vector<double> &sum,vector<double> &count,int i){        
        if(root == NULL) return;
        if(sum.size() <= i){
            sum.push_back(root->val);
            count.push_back(1);
        }else{
            sum[i] += root->val;
            count[i]++;
        }
        doDFS(root->left, sum, count, i + 1);
        doDFS(root->right, sum, count, i + 1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum, count, ans;
        doDFS(root, sum, count, 0);
        for(int i = 0; i < sum.size(); i++) ans.push_back(sum[i] / count[i]);
        return ans;
    }
};

// Range Sum of BST
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        int ans = 0;
        if(low <= root->val && root->val <= high) ans += root->val;
        return ans + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

// Sum of Root To Leaf Binary Numbers
class Solution {
public:
    void helper(TreeNode* root,vector<int> arr,vector<vector<int>> &ans){
        if(!root) return;
        arr.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
           ans.push_back(arr);
            return;
        } /*recursively going left and right until we find the leaf and updating the arr
        and ans vector simultaneously*/
        helper(root->left,arr,ans);
        helper(root->right,arr,ans);
    }
    
    vector<vector<int>> Paths(TreeNode* root){
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> arr;
        helper(root,arr,ans);
        return ans;
    }
    int bin_to_dec(vector<int> w){
        int res = 0;
        int j = w.size() - 1;
        for(int i = 0; i < w.size(); i++){
            res += w[i] * pow(2, j);
            j--;
        }
        return res;
    }
    int sumRootToLeaf(TreeNode* root) {
        int sumi = 0;
        vector<vector<int> > res = Paths(root);
        for(int i = 0; i < res.size(); i++){
            sumi += bin_to_dec(res[i]);
        }
        return sumi;
    }
};

// Maximum Level Sum of a Binary Tree
class Solution {
public:
    void dfs(TreeNode * node, int lvl, vector<int> & sums){
        if(!node) return;
        if(lvl >= sums.size()){
            sums.push_back(0);
        }
        sums[lvl] += node -> val;
        dfs(node -> left, lvl + 1, sums);
        dfs(node -> right, lvl + 1, sums);
        
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;
        int maxSum = INT_MIN, index = -1;
        dfs(root, 0, sums); 
        for(int i = 0; i < sums.size(); i++){
            if(maxSum < sums[i]){
                maxSum = sums[i];
                index = i + 1;
            } 
        }
        return index;
    }
};

//