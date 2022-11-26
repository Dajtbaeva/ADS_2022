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

    void preorder(Node* node) {
		if (!node) return;
		cout << node->value << " ";
		this->preorder(node->left);
		this->preorder(node->right);
	}

    Node * findTarget(int target){
        Node * cur = root;
        while(cur -> value != target){
            if(target > cur -> value) cur = cur -> right;
            else cur = cur -> left;
        }
        return cur;
    }

    // vector <int> levelSum(Node *node){ // BFS
    //     vector <int> ans;
    //     if(node == NULL){
    //         return ans;
    //     }
    //     queue <Node*> q;
    //     q.push(node);

    //     while(!q.empty()){
    //         int sz = q.size();
    //         int sum = 0;
    //         for(int i = 0; i < sz; i++){
    //             Node *cur = q.front();
    //             q.pop();
    //             if(cur->left) q.push(cur->left);
    //             if(cur->right) q.push(cur->right);
    //             sum += cur->data;
    //         }
    //         ans.push_back(sum);
    //     }
    //     return ans;
    // }

    void sumiOfLevels(Node * node, vector<int> &sumi, int i){ // DFS
        if(!node) return;
        if(sumi.size() <= i) sumi.push_back(node -> value);
        else sumi[i] += node -> value;

        sumiOfLevels(node -> left, sumi, i + 1);
        sumiOfLevels(node -> right, sumi, i + 1);
    }
};

int main() {
	BST tree;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        tree.insert(x);
    }
    vector<int> sumi;
    tree.sumiOfLevels(tree.root, sumi, 0);
    cout << sumi.size() << "\n";
    for(int i = 0; i < sumi.size(); i++){
        cout << sumi[i] << " ";
    }
}