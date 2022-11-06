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
	BST(Node * root) {
	    this -> root = root;
	}

private:
    Node * push(Node * root, int parent, int val, int lr){
        Node * temp = search(root, parent);
        if(lr == 1) temp -> right = new Node(val);
        else temp -> left = new Node(val);        
        // if(cur == NULL) return new Node(val);
        // if(val < cur -> value) cur -> left = push(cur -> left, val);
        // if(val > cur -> value) cur -> right = push(cur -> right, val);
        // return cur;
        return temp;
    }

public:
    void insert(int parent, int val, int lr) {
		root = push(root, parent, val, lr);
	}

    Node * search(Node * cur, int target){

        if(cur){
            if(cur -> value == target) return cur;
        }
        else{
            search(cur -> left, target);
            search(cur -> right, target);
        }
        return cur;
    }

    // int getWidth(Node *node){
    //     if(node == NULL){
    //         return 0;
    //     }
    //     queue <Node*> q;
    //     q.push(node);
    //     int cnt = 0;
    //     int maxi = 0;
    //     while(!q.empty()){
    //         int sz = q.size();
    //         cnt = 0;
    //         for(int i = 0; i < sz; i++){
    //             Node *cur = q.front();
    //             q.pop();
    //             if(cur->left) {
    //                 q.push(cur->left);
    //                 cnt++;
    //             }
    //             if(cur->right) {
    //                 q.push(cur->right);
    //                 cnt++;
    //             }
         
    //         }
    //         maxi = max(maxi, cnt);
    //     }
    //     return maxi;
    // }

    int getWidth(Node * root, int level){
        if (root == NULL) return 0;
        if (level == 1) return 1;
        else if (level > 1) return getWidth(root -> left, level - 1) + getWidth(root -> right, level - 1);
    }

    int getMaxWidth(Node * root){
        int maxWidth = 0;
        int width;
        int h = noOgLevels(root);
        for (int i = 1; i <= h; i++) {
            width = getWidth(root, i);
            if (width > maxWidth) maxWidth = width;
        }
        return maxWidth;
    }

    int noOgLevels(Node * cur){
        if(cur == NULL) return 0;
        return max(noOgLevels(cur -> left), noOgLevels(cur -> right)) + 1;
    }
};

int main() {
	BST tree(new Node(1));
    int n, x, y, z;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y >> z;
        tree.insert(x, y, z);
    }
    cout << tree.getMaxWidth(tree.root);
}