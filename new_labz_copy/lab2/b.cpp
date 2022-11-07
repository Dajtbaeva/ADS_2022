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

// left
Node* cyclicShift(Node* head, int k){
    if(k == 0) return head;
    Node * cur =  head;
    int cnt = 1;
    
    while(cnt < k && cur){
        cur = cur -> next;
        cnt++;
    }
    if(!cur) return head;
    Node * temp = cur;

    while(cur -> next) cur = cur -> next;
    cur -> next = head;
    head = temp -> next;
    temp -> next = NULL;
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