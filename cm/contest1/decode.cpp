#include <iostream>
using namespace std;


struct Node {
	char val;
	Node * next;

	Node(char val) {
		this->val = val;
	}
};


struct Stack {
	Node * head;
	int size; 

	Stack() {
		this->head = NULL;
		this->size = 0;
	}

	void push(char val) {
		size++;
		if (this->isEmpty()) {
			head = new Node(val);
		} else {
			Node* newNode = new Node(val);
			newNode->next = head;
			head = newNode;
		}
	}

	void pop() {
		if (this->isEmpty()) {
			cout << "the stack is empty!!!\n";
		} else {
			size--;
			Node *toDelete = head;
			head = head->next;
			delete (toDelete);
		}
	}

	char top() {
		return head->val;
	}

	bool isEmpty() {
		return size == 0;
	}
};

int to_int(string s){
    int res = 0;
    int one = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        res += (s[i] - 48) * one;
        one *= 10;
    }
    return res;
}
int main() {
	Stack st;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ']') st.push(s[i]);
        else{
            string t = "";
            while(!st.isEmpty() && st.top() != '['){
                t = st.top() + t;
                st.pop();
            }
            if(!st.isEmpty()){
                st.pop();
                string k = "";
                while(!st.isEmpty() && isdigit(st.top())){
                    k = st.top() + k;
                    st.pop();
                }
                int a = to_int(k);
                while(a--){
                    for(int j = 0; j < t.size(); j++) st.push(t[j]);
                }
            }
        }
		
    }
    string res = "";
    while(!st.isEmpty()){
        res = st.top() + res;
        st.pop();
    }
    cout << res;

}