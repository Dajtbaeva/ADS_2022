705. Design HashSet
https://leetcode.com/problems/design-hashset/

class MyHashSet {
public:
    struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    ListNode * head;
    MyHashSet() {
        head = new ListNode(-999);
    }
    
    void add(int key) {
        ListNode * node = new ListNode(key);
        ListNode * cur = head;
        while(cur -> next != NULL){
            if(cur -> next -> val == key) return;
            cur = cur -> next;
        }
        cur -> next = node;
    }
    
    void remove(int key) {
        ListNode * cur = head;
        while(cur != NULL && cur -> next != NULL){
            if(cur -> next -> val == key){
                cur -> next = cur ->  next -> next;
            }
            cur = cur -> next;
        }
    }
    
    bool contains(int key) {
        ListNode * cur = head;
        while(cur != NULL){
            if(cur -> val == key) return true;
            cur = cur -> next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */