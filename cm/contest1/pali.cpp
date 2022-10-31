#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
 
    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
    }

};

struct LinkedList{
    int sz;
    ListNode * head, *tail;

    LinkedList(){
        this -> sz = 0;
        this -> head = NULL;
        this -> tail = NULL;
    }

    void add_tail(int val){ 
        sz++;
        ListNode * temp = new ListNode(val);
        if(!this -> head){
            this -> head = temp;
            this -> tail = temp;
        }else{
            this -> tail -> next = temp;
            this -> tail = temp;
        }
    }

    void print(){
        ListNode * cur = this -> head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << "\n";
    }

    ListNode * middle(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode * reverse(ListNode * temp){ 
        if(!temp) return NULL;
        ListNode * p = NULL;
        ListNode * c = temp;
        ListNode * n = NULL;

        while(c){
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
        }
        temp = p;
        return temp;
    }

    bool isPalindrome(ListNode * temp){ 
        ListNode * mid = middle(temp);
        ListNode * second_head = reverse(mid);
        
        bool res = true;
        while(second_head){
            if(temp -> val != second_head -> val){
                return false;
            }
            temp = temp -> next;
            second_head = second_head -> next;
        }
        return res;
    }

};

int main(){
    LinkedList* ll = new LinkedList();
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll ->add_tail(x);
    }
    // ll -> print();
    if(ll -> isPalindrome(ll -> head)) cout << "YES";
    else cout << "NO";
    return 0;
}