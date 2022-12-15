#include <iostream>
using namespace std;

struct Node {
	int val;
	Node *next;

	Node(int val) {
		this->val = val;
	}
};


struct Stack {
	Node *bas;
	int size;

	Stack() {
		this->bas = NULL;
		this->size = 0;
	}

	void push(int val) {
		size++;
		if (this->isEmpty()) {
			bas = new Node(val);
		} else {
			Node* newNode = new Node(val);
			newNode->next = bas;
			bas = newNode;
		}
	}

	void pop() {
		if (this->isEmpty()) {
			cout << "the stack is empty!!!\n";
			// return;
		} else {
			size--;
			Node *toDelete = bas;
			bas = bas->next;
			delete (toDelete);
		}
	}

	int top() {
		return bas->val;
	}

	bool isEmpty() {
		return size == 0;
	}
};

int main() {
	// Stack *st = new Stack();
	Stack st;
	int n;
	cin >> n;
	while (n--) {
		int temp;
		cin >> temp;
		st.push(temp);
	}
	while(!st.isEmpty()){
        cout << st.top() << " ";
        st.pop();
    }

	return 0;
}