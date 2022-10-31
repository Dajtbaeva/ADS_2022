// Problem A. Jonathan the Poet -> LL
// 5 2
// the show must go on -> must go on the show

#include <bits/stdc++.h>

using namespace std;

struct Node{
    string word;
    Node* next;

    Node(){}

    Node(string word) {
        this->word = word;
        this->next = NULL;
    }
};

// your code goes here

    Node* cyclicShift(Node* head, int k){
        Node * cur = head;
        Node * temp = head;
        while(temp -> next){
            temp = temp -> next;
        }
        while(k--){
            head = cur -> next;
            temp -> next = cur;
        }
        return head;
    }

    void print(Node * head) {
        Node * cur = head;
        while(cur != NULL) {
            cout << cur->word << " ";
            cur = cur->next;
        }
        cout << endl;
    }

int main() {
    int n; cin >> n;
    int k; cin >> k;
    Node* head;
    Node* cur;
    for (int i = 0; i < n; i++) {
        string word; 
        cin >> word;
        if (i == 0){
            head = new Node(word);
            cur = head;
        } else {
            cur->next = new Node(word);
            cur = cur->next;
        }
    }
    head = cyclicShift(head, k);
    print(head);
}