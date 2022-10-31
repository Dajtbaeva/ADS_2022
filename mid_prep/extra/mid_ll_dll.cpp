// https://pastebin.com/vpFsXGtt

#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val; 
    Node * next;

    Node(int val){
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

    void push_back(int val){
        sz++;
        Node * node = new Node(val);
        if(!head){
            head = tail = node;
        }else{
            tail -> next = node;
            tail = node;
        }
    }

    void push_front(int val){
        sz++;
        Node * node = new Node(val);
        if(!head){
            head = tail = node;
        }else{
            node -> next = head;
            head = node;
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

    Node * pop_front2(){
        Node * node = head;
        head = head -> next;
        return node;
    }

    void insert(int val, int ind){
        if(ind < 0 || ind > sz) return;
        else if(ind == 0) push_front(val);
        else if(ind == sz) push_back(val);
        else{
            Node * node = new Node(val);
            Node * cur = head;
            for(int i = 0; i < ind - 1; i++) cur = cur -> next;
            node -> next = cur -> next;
            cur -> next = node;
            sz++;
        }
    }

    void update(int val, int ind){
        if(ind < 0 || ind > sz) return;
        else if(ind == 0) head -> val = val;
        else if(ind == sz - 1) tail -> val = val;
        else{
            Node * node = new Node(val);
            Node * cur = head;
            int i = 0;
            while(cur){
                if(i == ind){
                    cur -> val = val;
                    break;
                }
                cur = cur -> next;
                i++;
            }
        }
    }

    Node * get_node(int ind){
        if(ind < 0 || ind > sz) return  NULL;
        Node * cur = head;
        for(int i = 0; i < ind; i++) cur = cur -> next;
        return cur;
    }

    Node * search(int val){
        if(!head) return NULL;
        Node * cur = head;
        for(int i = 0; i < sz; i++){
            if(cur -> val == val){
                return cur;
                break;
            }
            cur = cur -> next;
        }
        return NULL;
    }

    bool isHere(int val){
        if(!head) return false;
        Node * cur = head;
        for(int i = 0; i < sz; i++){
            if(cur -> val == val){
                return true;
                break;
            } 
            cur = cur -> next;
        }
        return false;
    }

    void reverse(){
        if(!head) return;
        Node * p = NULL;
        Node * c = head;
        Node * n = NULL;

        while(c){
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
        }
        head = p;
    }

    Node * reverse2(Node * fhead){ 
        if(!fhead) return NULL;
        Node * p = NULL;
        Node * c = fhead;
        Node * n = NULL;

        while(c){
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
        }
        fhead = p;
        return fhead;
    }
    
    Node * middle(){
        Node * s = head;
        Node * f = head;
        while(f && f -> next){
            s = s -> next;
            f = f -> next -> next;
        }
        return s;
    }

    bool isPalindrome(Node * head) {
        Node * cur = head;
        Node * temp = reverse2(head);
        
        bool res = true;
        while(cur){
            if(cur -> val != temp -> val){
                return false;
            }
            head = head -> next;
            temp = temp -> next;
        }
        return res;
    }

    bool isPalindrome2(Node * head) {
        if(!head) return true;
        Node * secll = new Node(0);
        Node * secll1 = secll;
        Node * tmp = head;
        while(tmp){
            secll->next = new Node(tmp->val);
            tmp = tmp->next;
            secll = secll->next;
        }
        Node *head2 = secll1->next;
        Node *revll = reverse2(head2);
        
        Node * cur1 = head;
        Node * cur2 = revll;
        while(cur1 != NULL && cur2 != NULL){
            if(cur1->val != cur2->val) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }

    bool isPalindrome3(Node * head) {
        Node * mid = middle();
        Node * second_head = reverse2(mid);
        
        bool res = true;
        while(second_head){
            if(head -> val != second_head -> val){
                return false;
            }
            head = head -> next;
            second_head = second_head -> next;
        }
        return res;
    }

    void sort1(){
        Node *first = head;
        Node *sec = NULL;
        if(head == NULL){
            return;
        }
        while(first->next != NULL){
            sec = first->next;
            while(sec != NULL){
                if(first->val > sec->val){
                    swap(first->val, sec->val);
                }
                sec = sec->next;
            }
            first = first->next;
        }
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

    Node * remove(int pos) {
		if (pos == 1) {
			return pop_front2();
		}
		if (pos == sz) {
			return pop_back2();
		}
		Node * cur = head;
		while (--pos > 1) {
			cur = cur->next;
		}
		Node * node = cur->next;
		cur->next = cur->next->next;
		return node;
	}

    void remove2(int val){
        if(!head){
            cout << "Error\n";
            return;
        }else if(head -> val == val) head = head -> next;
        else{
            Node * cur = head;
            Node * prev = NULL;
            for(int i = 0; i < sz; i++){
                if(cur -> val == val){
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }else{
                    prev = cur;
                    cur = cur -> next;
                }
            }
        }
        cout << "There is no such element\n";
    }

    void remove3(int ind){
        if(!head || ind < 0 || ind > sz){
            cout << "Error\n";
            return;
        }else if(ind == 0) head = head -> next;
        else{
            Node * cur = head;
            Node * prev = NULL;
            for(int i = 0; i < sz; i++){
                if(ind == i){
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }else{
                    prev = cur;
                    cur = cur -> next;
                }
            }
        }
    }

    void replace(int pos1, int pos2) {
		Node * node = remove(pos1);
		insert(node->val, pos2);
	}

	void swap(int pos1, int pos2) {
		replace(pos1, pos2);
		replace(pos2 - 1, pos1);
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
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << "\n";
    }
};

int main(){
    int n, x;
    LinkedList ll;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll.push_back(x);
    }
    int k; cin >> k;
    // ll.insert(100, 3);
    // ll.print();
    // ll.update(77, 4);
    // ll.print();
    // ll.remove(k);
    // ll.print();
    // ll.remove2(2);
    // ll.print();
    ll.reverse();
    ll.print();
    ll.head = ll.shift_left(ll.head, k);
    ll.print();
    ll.head = ll.shift_right(ll.head, k);
    ll.print();
    ll.sort();
    ll.print();
}
/*
void push_back
void push_front
void pop_back
void pop_front
node pop_back2
node pop_front2
void insert(val, i)
void update(val, i)
node get_node(val)
node search(val)
bool ishere(val)
void reverse
node reverse2
node middle
bool ispalindrome 1, 2, 3
bool isEmpty
void sort
node remove(pos)
void remove2(val)
void remove3(pos)
void replace(pos1, pos2)
void swap(pos1, pos2)
node shift_left
node shift_right
void shift_left2
void shift_right2
print
*/

// DLL

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	Node * next, * prev;

	Node (int val) {
		this -> val = val;
		this -> next = nullptr;
		this -> prev = nullptr;
	}
};

struct DoublyLinkedList{
	int sz;
	Node * head, * tail;

	DoublyLinkedList() {
		this -> sz = 0;
		this -> head = nullptr;
		this -> tail = nullptr;
	}

	void push_back(int val) {
		sz++;
		Node * node = new Node(val);
		if(!head){
            head = tail = node;
		}else{
			tail -> next = node;
			node -> prev = tail;
			tail = node;
		}
	}
    
    void push_front(int val) {
		sz++;
		Node * node = new Node(val);
		if (!head){
			head = tail = node;
		}else{
			node -> next = head;
			head -> prev = node;
			head = node;
		}
	}

    void pop_back(){
        if(sz == 1){
            head = tail = NULL; 
        }else{
            Node * d = tail;
            Node * cur = tail -> prev;
            delete d;
            cur -> next = nullptr;
            tail = cur;
        }
        sz--;
    }

    void pop_front(){
        if(head){
            Node * node = head;
            head = head -> next;
            head -> prev = NULL;
            delete node;
        }
        sz--;
    }

	void insert(int index, int val) {
		if (index < 0 || index > sz) {
            cout << "Error/n";
		}
		if (index == 0){
			push_front(val);
		} else if (index == sz) {
			push_back(val);
		} else {
			sz++;
			Node * node = new Node (val);
			Node * cur = head;
			for (int i = 0; i < index - 1; i++) {
				cur = cur -> next;
			}
			Node * nextt = cur -> next;
			cur -> next = node;
			node -> prev = cur;
			node -> next = nextt;
			nextt -> prev = node;
		}
	}

	int get(int index) {
		if (index < 0 || index > sz) {
            cout << "Error/n";
		}
		Node * cur = head;
		for (int i = 0; i < index; i++) {
			cur = cur -> next;
		}
		return cur -> val;
	}

	void print() {
		Node * cur = head;
		while (cur) {
			cout << cur -> val << " ";
			cur = cur -> next;
		}
		cout << endl;
	}

	void reverse() {
		Node * cur = tail;
		while (cur) {
			cout << cur -> val << " ";
			cur = cur -> prev;
		}
		cout << endl;
	}

	void remove(int index) {
		if(index < 0 || index > sz) {
            cout << "Error/n";
		}
		else if(index == 0) {
            pop_front();
			// head = head -> next;
			// head -> prev = nullptr;
			// delete (this->head->prev);
		}else if(index == sz - 1) {
            pop_back();
            // Node * cur = tail;
			// tail = tail -> prev;
			// tail -> next = nullptr;
            // delete cur;
		}else {
			Node * cur = head;
			for (int i = 0; i < index - 1; i++) {
				cur = cur -> next;
			}
			// Node  *prevv = cur->prev;
			// Node  *nextt = cur->next;
			// prevv->next = nextt;
			// nextt->prev = prevv;
			(cur->next->next)->prev = cur;
			cur->next = cur->next->next;
		    sz--;
		}
	}

    void remove2(int val){
        if(!head) cout << "Error/n";
        else if(head -> val == val) pop_front();
        else if(tail -> val == val) pop_back();
        else{
            Node * cur = head;
            for(int i = 0; i < sz; i++){
                if(cur -> val == val){
                    remove(i);
                    break;
                } 
                cur = cur -> next;
            }
        }
    }

	void shift_left(int steps) {
		if (steps == 0)
			return;

		tail->next = head;
		head->prev = tail;

		int count = 1;
		while (count <= steps) {
			head = head->next;
			tail = tail->next;
			count++;
		}

		tail->next = nullptr;
		head->prev = nullptr;
	}

	void shift_right(int steps) {
        shift_left(sz - steps);
	}
};

int main() {
	DoublyLinkedList dll;
	int n, m;
	cin >> n;
	while (n--) {
		cin >> m;
		dll.push_back(m);
	}
	dll.print();
	dll.shift_left(3);
	dll.print();
    dll.shift_right(3);
	dll.print();
    dll.pop_back();
    dll.print();
    dll.pop_front();
    dll.print();
    dll.remove(1);
    dll.print();
} 
/*
void push_back +
void push_front +
void pop_back +
void pop_front +
node pop_back2
node pop_front2
void insert(val, i) +
void update(val, i)
node get_node(val) +
node search(val)
bool ishere(val)
void reverse +
node reverse2
node middle
bool ispalindrome 1, 2, 3
bool isEmpty
void sort
node remove(pos)
void remove2(val) +
void remove3(pos) +
void replace(pos1, pos2)
void swap(pos1, pos2)
node shift_left
node shift_right
void shift_left2 +
void shift_right2 +
void print +
*/