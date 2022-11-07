// BS

int binay_seach_first(int a[], int taget, int n){ // increase
	int left = 0, right = n - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (taget < a[mid]) right = mid - 1;
		else if (taget > a[mid]) left = mid + 1;
		else return mid;
	}
	return -1;
}

int binary_search_decr(int a[], int target, int n){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(target > a[mid]) r = mid - 1;
        else if(target < a[mid]) l = mid + 1;
        else return mid;
    }
    return -1;
}
----------------------------------------------------------------------------
Oshiete oshiete yo sono shikumi wo
10 3
3 4 2 1 3 4 5 2 2 3 -> 12
(3+4+2+1), (3+4+5), (2+2+3)

#include <bits/stdc++.h>
using namespace std; 

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	unsigned long long left = *max_element(v.begin(), v.end());
	unsigned long long right, mid, cnt, sum, ans;
	for(int i = 0; i < n; i++) right += v[i];
	while (left <= right) {
		mid = left + (right - left) / 2;
		cnt = 1;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < sum + v[i]) {
				sum = 0;
				cnt++;
			}
			if (mid < v[i]) cnt = k + 1;
			sum += v[i];
		}
		if (k >= cnt){
			ans = mid;
			right = mid - 1;
		}else left = mid + 1;
	}
	cout <<  ans;
	return 0;
}
------------------------------------------------------------------------
Patchwork Staccato II
7 3
21 1 2 3 5 8 13
1 5 13 21
1 1 2 3
1 3 2 8 
====
6
3
5

#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> v, int a){ // return index
    int l = 0, r = v.size() - 1, res = -1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(v[m] <= a){
            res = m;
            l = m + 1;
        }else r = m - 1;
    }
    if(res == -1) return 0;
    return res + 1;
}

int ans(vector<int> v, int l, int r){
    return binary_search(v, r) - binary_search(v, l - 1);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < k; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(r1 < l2 || r2 < l1){
            int res = ans(v, l1, r1) + ans(v, l2, r2);
            cout << res << "\n";
        } 
        else{
            int mini = min(l1, l2);
            int maxi = max(r1, r2);
            cout << ans(v, mini, maxi) << "\n";
        }
    }
}
-------------------------------------------------------------
Jonathan the Farmer
Find the minimum length of square paddock such that at least K sheeps’ pastures fit there.

#include <bits/stdc++.h>

using namespace std;

struct coordinates{
    int x1, y1, x2, y2;
};
coordinates a[2 * 1000000];
int n, k;

bool checker(int x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i].x2 <= x && a[i].y2 <= x) cnt++;
    }
    return cnt >= k;
}

int binary_search(){
    int l = 0, r = 1e9, res = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(checker(mid)){
            res = mid;
            r = mid - 1; // we need min length
        } 
        else l = mid + 1;
    }
    return res;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    cout << binary_search();

}
------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

pair<int, int> binary_search(vector<int> a, int target){ 
	int left = 0, right = a.size() - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (target >= a[mid]){
            pair<int, int> p;
            int sumi = 0, cnt = 0;
            for(int i = left; i <= right; i++){
                if(a[i] <= target){
                    sumi += a[i];
                    cnt++;
                } 
            }
            p.first = cnt;
            p.second = sumi;
            return p;
        }
		else if (target < a[mid]) right = mid - 1;
	}
}

int main(){
    int n, k;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cin >> k;
    for(int i = 0; i < k; i++){
        int y;
        cin >> y;
        cout << binary_search(v, y).first << " " << binary_search(v, y).second << "\n";
    }
}
-------------------------------------------------------------------------------------------------
Santa Jonathan
5 7
10 34 14 6 20

Return the minimum number K such that Robin can steal ALL of the golden bars within H hours.
5 5
30 11 23 4 20

#include <bits/stdc++.h>

using namespace std;

bool checker(vector<int> a, int n, int x, int h){
    int t = 0;
    for(int i = 0; i < n; i++){
        t += (a[i] + x - 1) / x; // ceil(a[i] * 0.1 / x)
    }
    return t <= h;
}

int main(){
    int n, h; 
    cin >> n >> h;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    int l = 1, r = *max_element(a.begin(), a.end()) + 1;
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        if(checker(a, n, mid, h)) r = mid;
        else l = mid;
    }
    cout << r;
}

// 5 7
// 10 34 14 6 20 -> 17
---------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

int binary_search(int v[], int target, int n){
    int left = 0, right = n - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (v[mid] >= target) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> w;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; 
        w.push_back(x);
    }
    int res[n];
    res[0] = w[0];
    for(int i = 1; i < w.size(); i++){
        res[i] = w[i] + res[i - 1]; 
    }
    for(int j = 0; j < k; j++){
        int y;
        cin >> y;
        cout << binary_search(res, y, n) + 1 << "\n";
    }
}
// 3 3
// 5 7 6: res = 5, 12, 18
// 5
// 10
// 15
---------------------------------------------------------------
// Задача №111728. Левый и правый двоичный поиск
// https://informatics.msk.ru/mod/statements/view.php?id=54422&chapterid=111728#1

#include <bits/stdc++.h>

using namespace std;

void bs(int a[], int l, int r, int x){
    while(l < r){
        int mid = (l + r) / 2;
        if(a[mid] < x) l = mid + 1;
        else r = mid;
    }
    if(a[r] == x){
        cout << ++r << " ";
        while(a[r] == x) r++;
        cout << r << "\n";
    }
    else cout << 0 << "\n";
}

int main(){
    int n, k;
    cin >> n >> k;
    int b[n];
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= k; i++){
        int y;
        cin >> y;
        bs(b, 0, n - 1, y);
    }
        
}
--------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

int first(vector<int> &v, int x){
    int res = -1, l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(v[mid] > x) r = mid - 1;
        else if(v[mid] < x) r = mid + 1;
        else{
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}

int last(vector<int> &v, int x){
    int res = -1, l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(v[mid] > x) r = mid - 1;
        else if(v[mid] < x) r = mid + 1;
        else{
            res = mid;
            l = mid + 1;
        }
    }
    return res;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    while(k--){
        int a; cin >> a;
        int j1 = first(v, a) + 1;
        int j2 = last(v, a) + 1;
        if(first == 0 && last == 0) cout << 0 << "\n";
        else cout << first << " " << last << "\n";
    }
}
--------------------------------------------------------------------
int p[10000010];

void find_primes1(int n) {   //Эратосфен
    // for (int i = 2; i <= sqrt(n); i++)
    for (int i = 2; i * i <= n; i++) { 
        if (p[i] == 0) {
            int k = i;                 
            while (k + i <= n) {
                k += i;
                p[k] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
        if (p[i] == 0 && p[n - i] == 0){
            cout << i << " " << n - i << endl;
            break;
        }
            

}

int main() {
    int n;
    cin >> n;
    find_primes1(n);
    return 0;
}
----------------------------------------------------------------
FIRST AND LAST OCCURANCE
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int first = -1, last = -1;
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target) {
				first = mid;
				r = mid - 1;
			} else if (target < nums[mid]) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (first == -1) {
			return { -1, -1 };
		}
		l = first, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target) {
				last = mid;
				l = mid + 1;
			} else if (nums[mid] < target) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return { first, last };
	}
};


// MIDKI
-------------------------------------------------------------------------------
// Optimizing Program

#include<bits/stdc++.h>
using namespace std;
struct MinHeap {
	vector<unsigned long long> heap;

	unsigned long long parent(unsigned long long i) {
		return (i - 1) / 2;
	}
	unsigned long long left(unsigned long long i) {
		return 2 * i + 1;
	}
	unsigned long long right(unsigned long long i) {
		return 2 * i + 2;
	}
	void insert(unsigned long long value) {
		this->heap.push_back(value);
		unsigned long long i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	unsigned long long int extractMin() {
		if (this->heap.size() == 0) return INT_MAX;
		if (this->heap.size() == 1) {
			unsigned long long root = this->heap[0];
			this->heap.pop_back();
			return root;
		}
		unsigned long long root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);
		return root;
	}
	void heapify(unsigned long long i) {
		unsigned long long l = this->left(i);
		unsigned long long r = this->right(i);
		int smallest = i;
		if (l < this->heap.size() && this->heap[l] < this->heap[smallest])
			smallest = l;
		if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
			smallest = r;
		if (smallest != i) {
			swap(this->heap[i], this->heap[smallest]);
			this->heapify(smallest);
		}
	}
};

int main() {
	MinHeap heap;
    unsigned long long n, x;
    cin >> n;
    unsigned long long sumi = 0;
    while(n--){
        cin >> x;
        heap.insert(x);
    }
    while(heap.heap.size() != 1){
        unsigned long long a = heap.extractMin() + heap.extractMin();
        heap.insert(a);
        sumi += a;
    }
    cout << sumi;
    
	return 0;
}
-------------------------------------------------------------------------------
// Nugman and Stack

#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    int n, x;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(!v.empty()){
            bool ok = false;
            for(int i = v.size() - 1; i >= 0; i--){
                if(v[i] <= x){
                    cout << v[i] << " ";
                    ok = true;
                    break;
                } 
            }
            if(!ok) cout << -1 << " ";
        }else cout << -1 << " ";
        v.push_back(x);
    }
}
// 5
// 2 1 5 8 3 -> -1 -1 1 5 1
// 2 
-------------------------------------------------------------------------------
// Snake
#include <iostream>
using namespace std;

int binay_seach_first(int a[], int taget, int n){ // increase
	int left = 0, right = n - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (taget < a[mid]) right = mid - 1;
		else if (taget > a[mid]) left = mid + 1;
		else return mid;
	}
	return -1;
}

int binay_seach_second(int a[], int taget, int n){ // decrease
	int left = 0, right = n - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (taget > a[mid]) right = mid - 1;
		else if (taget < a[mid]) left = mid + 1;
		else return mid;
	}
	return -1;
}

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n, x, y, ind;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> x >> y;
	int a2[x][y];
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			cin >> a2[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < x; j++) {
			if (j % 2 == 0) ind = binay_seach_second(a2[j], a[i], y);
            else ind = binay_seach_first(a2[j], a[i], y);
			if (ind != -1){
				cout << j << " " << ind << endl;
				break;
			}else if(ind == -1 && j == x - 1){
				cout << -1 << endl;
				break;
			}
		}
	}
	return 0;
}

// 5
// 10 15 13 8 23
// 3 4
// 25 23 20 19
// 13 15 17 18
// 12 10 9 8

// 2 1
// 1 1
// 1 0
// 2 3
// 0 1

-------------------------------------------------------------------------------
// Triangles
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	} else if (root->data > data) {
		if (root->left == NULL) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == NULL) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

Node * find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
} 

int main(){
    Node * root = new Node(-9999999);
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        root = add(root, x);
    }
}

-------------------------------------------------------------------------------
// Width

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
		this->inorder(this->root);
	}
	void preorder() {
		this->preorder(this->root);
	}
	void postorder() {
		this->postorder(this->root);
	}
	void insert(int value) {
		if (!this->root) {
			this->root = new Node(value);
		} else {
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

Node* search(Node* node, int target) {
	queue<Node*> q;
	q.push(node);
	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();
		if (cur->value == target) return cur;
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
	return nullptr;
}

void bfs(Node* node, int& ans) {
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

int main() {
	BinaryTree tree;
	int n;
	tree.insert(1);
	cin >> n;
	n--;
	while (n--) {
		int x, y, z;
		cin >> x >> y >> z;
		Node* node = search(tree.root, x);
		if (z == 1) {
			node->right = new Node(y);
		} else {
			node->left = new Node(y);
		}
	}
	int ans = -1;
	bfs(tree.root, ans);
	cout << ans;


	return 0;
}
-------------------------------------------------------------------------------
Greater Sum Tree
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

    void ans(Node * cur, int &sumi){
        if(!cur) return;
        ans(cur -> right, sumi);
        cur -> value += sumi;
        cout << cur -> value << " ";
        sumi = cur -> value;
        ans(cur -> left, sumi);
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
    int ans = 0;
    tree.ans(tree.root, ans);
}

-------------------------------------------------------------------------------
// Every day I’m shufflin’

#include <bits/stdc++.h>

using namespace std;

struct Node{
    string val; 
    Node * next;

    Node(string val){
        this -> val = val;
        this -> next = NULL;
    }
};

struct LinkedList{
    int sz;
    Node * head, * tail;

    LinkedList(){
        this -> sz = 0;
        this -> head = NULL;
        this -> tail = NULL;
    }

    void push_back(string val){
        sz++;
        Node * node = new Node(val);
        if(!head){
            head = tail = node;
        }else{
            tail -> next = node;
            tail = node;
        }
    }

    void pop_back(){
        if(sz == 1){
            head = tail = NULL;
        }else{
            Node * cur = head;
            while(cur -> next -> next){
                cur = cur -> next;
            }
            Node * node = cur -> next;
            cur -> next = NULL;
        }
    }

    void pop_front(){
        if(head){
            Node * node = head;
            head = head -> next;
        } 
    }

    Node * pop_back2(){
        if(sz == 1){
            Node * ans = head;
            head = NULL;
            return ans;
        }
        Node * cur = head;
        while(cur -> next -> next){
            cur = cur -> next;
        }
        Node * node = cur -> next;
        cur -> next = NULL;
        return node;
    }

    void sort(){
        Node * f = head;
        Node * s = NULL;
        if(!head) return;
        while(f -> next){
            s = f -> next;
            while(s){
                if(f -> val > s -> val) swap(f -> val, s -> val);
                s = s -> next;
            }
            f = f -> next;    
        }
    }

    Node * shift_left(Node * head, int c){ // сначала вконец
        if(c == 0) return head;
        Node * cur = head;
        Node * prev = NULL;
        while(c--){
            prev = cur;
            cur = cur -> next;
        }
        Node * tail = cur;
        while(tail -> next) tail = tail -> next;
        tail -> next = head;
        prev -> next = NULL;
        return cur;
    }

    Node * shift_right(Node * head, int x){ // с конца вперед
        if(!x) return head;
        Node * tail = head;
        int sz = 0;
        while(tail -> next){
            sz++;
            tail = tail -> next;
        }
        int ind = sz - x;
        Node * last = head;          
        for(int i = 0; i < ind; i++){
            last = last -> next;
        }

        Node * new_head = last -> next;
        last -> next = NULL;
        tail -> next = head;
        return new_head;
    }

    void shift_left2(int k) {
		k %= sz;
		tail->next = head;
		while (k--) {
			head = head -> next;
			tail = tail -> next;
		}
		tail -> next = nullptr;
	}

	void shift_right2(int k) {
		k %= sz;
		shift_left2(sz - k);
	}

    Node * shift_left3(int k) {
        k %= sz;
        tail -> next = head;
        while (k--) {
            head = head -> next;
            tail = tail -> next;
        }
        tail -> next = NULL;
        return head;
    }

    Node * shift_right3(int k) {
        k %= sz;
        return shift_left3(sz - k);
    }

    bool isEmpty(){
        return sz == 0;
    }
    
    void print(){
        Node * cur = head;
        int n = 2;
        while(cur && n){
            cout << cur -> val << " ";
            cur = cur -> next;
            n--;
        }
        cout << "\n";
    }
};

int main(){
    int n;
    string s;
    LinkedList ll;
    for(int i = 0; i < 52; i++){
        cin >> s;
        ll.push_back(s);
    }
    int k; cin >> k;
    while(k--){
        int x;
        cin >> x;
        ll.shift_left2(x);
    }
    Node * cur = ll.head;
    ll.print();

}
-------------------------------------------------------------------------------
// Goldbach’s conjecture

#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    for(int i = 2; i < n; i++){
        if(isPrime(i) && isPrime(n - i)){
            cout << i << " " << n - i;
            break;
        }
    }
}
-------------------------------------------------------------------------------
// Minimize GCD

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(long long a, long long b){
    return (a * b) / gcd(a, b);
}


int main(){
    int n; cin >> n;
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            if(gcd(i, n / i) == 1){
                cout << i << " " << n / i;
                return 0 ;
            }
        }
    }
    cout << -1;

}
-------------------------------------------------------------------------------
// Team play
#include <bits/stdc++.h>

using namespace std;

unsigned long long n, a1, a2, a3;

bool check(unsigned long long mid){
    int cnt = mid / a1 + mid / a2 + mid / a3;
    return cnt >= n;
}

int main(){
    cin >> n >> a1 >> a2 >> a3;
    unsigned long long l = 0, r = 1e12 / 3, res = 0;
    while(r - l > 1){
        unsigned long long mid = l + (r - l) / 2;
        if(check(mid)){
            r = mid;
        }else l = mid + 1;
    }
    cout << r;
}

-------------------------------------------------------------------------------
// Primetopia
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    for(int i = 2; i <= sqrt(x); ++i){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> primes;
    int i = 2;
    while(primes.size() != n){
        if(isPrime(i)) primes.push_back(i);
        i++;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        bool ok = false;
        for(int j = 0; j < n; j++){
            if(i != j && abs(primes[i] - primes[j]) == 2){
                res++;
                break;
            }
        }
    }
    cout << n - res;
}
-------------------------------------------------------------------------------
// Jonathan the Thief I

#include <bits/stdc++.h>

using namespace std;

int getcnt(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) cnt++;
    }
    return cnt == 3 || cnt == 4;
}


int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(getcnt(i)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
-------------------------------------------------------------------------------
// Standard problem about soccer

#include<bits/stdc++.h>
using namespace std;
struct MaxHeap {
	vector<unsigned long long> heap;

	unsigned long long parent(unsigned long long i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}
	void insert(unsigned long long value) {
		this->heap.push_back(value);
		int i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	unsigned long long extractMax() {
		if (this->heap.size() == 0) return INT_MAX;
		if (this->heap.size() == 1) {
			unsigned long long root = this->heap[0];
			this->heap.pop_back();
			return root;
		}
		unsigned long long root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);
		return root;
	}
	void heapify(int i) {
		int l = this->left(i);
		int r = this->right(i);
		int biggest = i;
		if (l < this->heap.size() && this->heap[l] > this->heap[biggest])
			biggest = l;
		if (r < this->heap.size() && this->heap[r] > this->heap[biggest])
			biggest = r;
		if (biggest != i) {
			swap(this->heap[i], this->heap[biggest]);
			this->heapify(biggest);
		}
	}
	int displayMax() {
        return this->heap[0];
    }
    bool empty() {
        return this->heap.size() == 0;
    }
    int size() {
        return this->heap.size();
    }
};

int main() {
	MaxHeap heap;
    unsigned long long n, x, k;
    cin >> n >> x;
    while(n--){
        cin >> k;
        heap.insert(k);
    }
    unsigned long long sumi = 0;
    while(x--){
        unsigned long long a = heap.extractMax();
        sumi += a;
        heap.insert(a - 1);
    }
    cout << sumi;
	return 0;
}

-------------------------------------------------------------------------------
// Triangle Binary Search Tree

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
	Node * root;

    int cnt = 0;
	BST() {
		root = NULL;
	}

    Node * push(Node * cur, int val){
        if(cur == NULL) return new Node(val);
        if(val < cur -> value) cur -> left = push(cur -> left, val);
        if(val > cur -> value) cur -> right = push(cur -> right, val);
        return cur;
    }
    
    int getCnt(){
        return cnt;
    }

    void ans(Node * cur){
        if(!cur) return;
        if(cur -> left && cur -> right) cnt++;
        ans(cur -> left);
        ans(cur -> right);
    }
	
};

int main() {
	BST tree;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        tree.root = tree.push(tree.root, x);
    }
    tree.ans(tree.root);
    cout << tree.getCnt();
}

-------------------------------------------------------------------------------
// Balanced Binary Search Tree
#include <bits/stdc++.h>

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
	Node * root;
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
		Node* newNode = _insert(root, val);
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
    
    Node * balanced_tree(vector<int> &v, int l, int r){
        if(l > r) return NULL;
        int m = l + (r - l) / 2;
        Node * root = new Node(v[m]);
        root -> left = balanced_tree(v, l, m - 1);
        root -> right = balanced_tree(v, m + 1, r);
        return root;
    }
};

int main(){
    BST bst;
    int n;
    cin >> n;
    int sz = pow(2, n) - 1;
    vector<int> v(sz);
    for(int i = 0; i < sz; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    bst.root = bst.balanced_tree(v, 0, sz - 1);
    bst.preorder();
}


-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------