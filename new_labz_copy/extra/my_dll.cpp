// https://pastebin.com/GtUSQ8Z9

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