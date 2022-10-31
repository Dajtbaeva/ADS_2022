#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
};

struct LinkedList {
    ListNode* head;
    LinkedList(): head(NULL) {}
    void add(int x) {
        ListNode* node = new ListNode(x);
        if (head == NULL) {
            head = node;
        } else {
            ListNode* cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = node;
        }
    }

    void kill(int k) {
        int sz = 0;
        ListNode * cur = head;
        while(cur){
            cur = cur -> next;
            sz++;
        }
        if(sz == 1 && k == 1){
            ListNode * temp = NULL;
        }   
        cur = head;
        int a = sz - k;
        for(int i = 1; i <= sz; i++){
            if(sz - k == 0){
                head = head -> next;
                break;
            }
            if(i == a){
                cur -> next = cur -> next -> next;
                break;
            } 
            cur = cur -> next;
        }
    }
  
    void print() {
        ListNode* cur = head;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList ll;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ll.add(x);
    }
    ll.kill(k);
    ll.print();
    return 0;
}