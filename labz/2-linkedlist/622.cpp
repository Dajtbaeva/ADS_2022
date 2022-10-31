622. Design Circular Queue
https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    ListNode * head = NULL;
    ListNode * tail = NULL;
    int max_sz, sz = 0;
    MyCircularQueue(int k) {
        max_sz = k;
    }
    
    bool enQueue(int value) {
        if(sz < max_sz){
            ListNode * node = new ListNode(value);
            if(!head){
                head = node;
                tail = node;
            }
            else{
                tail -> next = node;
                tail = node;
            }
            sz++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(sz > 0){
            ListNode * cur = head;
            head = head -> next;
            cur -> next = NULL;
            delete cur;
            sz--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        else{
            return head -> val;
        }
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        else{
            return tail -> val;
        } 
    }
    
    bool isEmpty() {
        return sz == 0;  
    }
    
    bool isFull() {
        return sz == max_sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */






class MyCircularQueue {
private:
    vector<int> v;
    int start = 0, len = 0;
public:
    MyCircularQueue(int k): v(k) {}
    bool enQueue(int value) {
        if (isFull()) return false;
        v[(start + len++) % v.size()] = value;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        start = (start + 1) % v.size();
        --len;
        return true;
    }
    int Front() {
        if (isEmpty()) return -1;
        return v[start];
    }
    int Rear() {
        if (isEmpty()) return -1;
        return v[(start + len - 1) % v.size()];
    }
    bool isEmpty() {
        return !len;
    }
    bool isFull() {
        return len == v.size();
    }
};
