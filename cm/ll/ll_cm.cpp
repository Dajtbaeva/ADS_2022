#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
 
    ListNode(){
        this -> val = 0;
        this -> next = NULL;
    }

    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
    }

    ListNode(int val, ListNode * next){
        this -> val = val;
        this -> next = next;
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

    void add_head(int val){ // 1
        sz++;
        ListNode * temp = new ListNode(val);
        if(!this -> head){
            this -> head = temp;
            this -> tail = temp;
        }else{
            temp -> next = this -> head;
            this -> head = temp;
        }
    }

    void add_tail(int val){ // 2
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

    void add_index(int ind, int val){ // 3 - тут нумерация с нуля идет 
        if(ind > this -> sz) return;
        else if(ind == 0) this -> add_head(val);
        else if(ind == this -> sz) this -> add_tail(val);
        else{
            ListNode * temp = new ListNode(val);
            ListNode * cur = this -> head;
            for(int i = 1; i < ind; i++) cur = cur -> next; // не доходит до самого индекса
            temp -> next = cur -> next;
            cur -> next = temp;
            sz++;

            // while(cur != NULL){
            //     if(i == index - 1){
            //         node->next = cur->next;
            //         cur->next = node;
            //         break;
            //     }
            //     cur = cur->next;
            //     i++;
            // }
        }
    }

    int get(int ind){ // 4 - тот тоже с нуля
        if(ind < 0 || ind >= sz) return -1;
        ListNode * cur = this -> head;
        for(int i = 0; i < ind; i++) cur = cur -> next;
        return cur -> val;
    } 

    void del_ind(int ind){ // 5 - тут нумерация с 1
        if(ind == 0){
            this -> head = this -> head -> next;
            sz--;
        }else if(ind == this -> sz - 1){
            ListNode * cur = this -> head;
            while(cur -> next != this -> tail) cur = cur -> next;
            this -> tail = cur;
        }else if(ind > 0 && ind < this -> sz){
            ListNode * cur = this -> head;
            for(int i = 0; i < ind; i++) cur = cur -> next;
            cur -> next = cur -> next -> next;
            sz--;
        }
    }

    void print(){ // 6
        ListNode * cur = this -> head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << "\n";
    }

    void reverse(){ // 7
        if(!head) return;
        ListNode * p = NULL;
        ListNode * c = head;
        ListNode * n = NULL;

        while(c){
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
        }
        head = p;
    }
    
    ListNode * reverse2(ListNode * fhead){ // 7.2
        if(!fhead) return NULL;
        ListNode * p = NULL;
        ListNode * c = fhead;
        ListNode * n = NULL;

        while(c){
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
        }
        fhead = p;
        return fhead;
    }

    bool isEmpty(){ // 8
        return sz == 0;
    }

    ListNode * middle(){ // 9
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    bool isPalindrome(){ // 10
        ListNode * temp = reverse2(head);
        bool ok = true;
        while(temp != NULL && head != NULL){
            if(head->val != temp->val){
                return false;
            }
            temp = temp->next;
            head = head->next;
        }
        return true;
    }

    void sort(){
        ListNode * first = head;
        ListNode * second = NULL;
        if (head == NULL){
            return;
        }
        while(first -> next != NULL){
            second = first -> next;
            while(second != NULL){
                if (first -> val > second -> val){
                    swap(first->val, second->val);
                }
                second = second -> next;
            }
            first = first -> next;
        }
    } 
    // ll -> head =  ll -> rotateRight(ll -> head, m);
    ListNode* cyclic_left(ListNode* head, int x){ // сначала вконец
        if(!x) return head; // x != 0
        ListNode *new_head = head;          
        ListNode *prev = NULL;
        while (x--) {
            prev = new_head;
            new_head = new_head->next;
        }
        ListNode *tail = new_head;
        while (tail->next) tail = tail->next;
        tail->next = head;
        prev->next = NULL;
        return new_head;
    }
    
    ListNode* cyclic_right(ListNode* head, int x){ // с конца вперед
        if(!x) return head;
        ListNode * tail = head;
        int sz = 0;
        while(tail -> next){
            sz++;
            tail = tail -> next;
        }
        int ind = sz - x;
        ListNode * last = head;          
        for(int i = 0; i < ind; i++){
            last = last -> next;
        }

        ListNode * new_head = last -> next;
        last -> next = NULL;
        tail -> next = head;
        return new_head;
    }

    ListNode* insert(ListNode* head, ListNode* node, int p){  // +
        if(p == 0){
            node->next = head;
            head = node;
            return head;
        }
        else{
            ListNode * cur = head;
            while (--p>0) cur = cur -> next;
            node -> next = cur -> next;
            cur -> next = node;
            return head;
        } 
    }

    ListNode* replace(ListNode* head, int p1, int p2){ // +
        ListNode * node = head;
        if(p1 != 0){
            ListNode * cur = head;
            while (--p1) cur = cur -> next;
            node = cur -> next;
            cur -> next = cur -> next -> next;
        }else{
            node = head;
            head = head -> next;
        }
        return insert(head, node, p2);
    }
    
    ListNode* deleteDuplicates(ListNode * head) {
        ListNode * cur = head;
        while(cur != NULL){
            if((cur -> next != NULL) && cur -> val == cur -> next -> val) cur->next = cur -> next -> next;
            else cur = cur -> next;
        }
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        ListNode* cur = head;
        int sz = 0;
        while(cur){
            sz++;
            cur = cur -> next;
        }
        cur = head;
        for(int i = 1; i <= sz; i++){
            if(i >= left && i <= right) v.push_back(cur->val);
            cur = cur -> next;
        }
        cur = head;
        int end = v.size() - 1;
        for(int i = 1; i <= right; i++){
            if(i >= left){
                cur -> val = v[end];
                end--;
            }
            cur = cur -> next;
        }
        return head;
    }

    // ListNode* sortList(ListNode* head) {
    //     vector<int> ans;
    //     ListNode * cur = head;
    //     while(cur != NULL){
    //         ans.push_back(cur->val);
    //         cur = cur -> next;
    //     }
    //     sort(ans.begin(), ans.end());
    //     ListNode * res = new ListNode(0);
    //     ListNode * temp = res;
    //     for(int i = 0; i < ans.size(); i++){
    //         temp->next = new ListNode(ans[i]);
    //         temp = temp->next;
    //     }
    //     return res->next;
    // }
    
    ListNode* removeElements(ListNode* head, int val){
        while(head && head -> val == val){
            head = head -> next;
        }
        if(head == NULL) return NULL;
        ListNode * prev;
        ListNode * cur = head;
        while(cur){
            if(cur -> val == val){
                prev -> next = cur -> next;
                cur = prev -> next;
            }else{
                prev = cur;
                cur = cur -> next;
            }
        }
        return head;
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
    // ll -> add_index(3, 4); // тут нумерация с нуля идет 
    // ll -> print();
    // cout << ll -> get(3) << "\n"; // тот тоже с нуля
    // ll -> del_ind(4); // тут нумерация с 1
    // ll -> print();
    // ll -> reverse();
    ll -> print();
    cout << ll -> isPalindrome();
}