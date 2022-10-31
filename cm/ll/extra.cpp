    ListNode* reverse(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* p = NULL;
        ListNode* c = head;
        ListNode* n = NULL;
        
        while(c != NULL){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        head = p;                
        return head;
    } 

    bool isPalindrome(ListNode* head) {
        ListNode * mid = middle(head);
        ListNode * second_head = reverse(mid);
        
        bool res = true;
        while(second_head){
            if(head -> val != second_head -> val){
                return false;
            }
            head = head -> next;
            second_head = second_head -> next;
        }
        return res;
    }

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
    
    void deleteNode(ListNode* node) {
        ListNode * prev;
        while(node -> next){
            node -> val = node -> next -> val;
            prev = node;
            node = node -> next;
        }
        prev -> next = NULL;
        delete node;
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

    void pushBack(int val){
        Node * newNode = new Node(val);
        if (head == nullptr){
            head = newNode;
        }
        else{
            Node * cur = head;
            while(cur != nullptr){
                if (cur -> next == nullptr){
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
            }
        }
        size++;
    }

    void pushFront(int val){
        Node * newNode = new Node(val);
        newNode -> next = head;
        head = newNode;
        size++;
    }

    void add(int pos, int val){
        if (pos > size){
            cout << "Can't add";
            return;
        }
        Node * newNode = new Node(val);
        if (head == nullptr){
            head = newNode;
        }
        else{
            Node * cur = head;
            int i = 1;
            while(cur != nullptr){
                if (i == pos){
                    newNode -> next = cur -> next;
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
                i++;
            }
        }
        size++;
    }

    void insert(int pos, int val){
        if (pos > size){
            cout << "Can't insert";
            return;
        }
        Node * cur = head;
        int i = 1;
        while(cur != nullptr){
            if (i == pos){
                cur -> val = val;
                break;
            }
            cur = cur -> next;
            i++;
        }
    }

    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        ListNode * cur = head;
        while(cur != NULL){
            ans.push_back(cur->val);
            cur = cur -> next;
        }
        sort(ans.begin(), ans.end());
        ListNode * res = new ListNode(0);
        ListNode * temp = res;
        for(int i = 0; i < ans.size(); i++){
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }
        return res->next;
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

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * cur = head;
        while(cur != NULL){
            if((cur->next != NULL) && cur->val == cur->next->val) cur->next = cur->next->next;
        // if next element exists then we check if current and next values equal we set this element to the next element; 
            else cur= cur->next;
        }
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int l = 1;
        ListNode * temp = head;
        while(temp->next){
            l++;
            temp = temp->next;
        }
        temp->next = head;
        k = k % l; //when k is more than length of list
        int end = l - k;
        while(end--){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    } 

    void rotate(Node** head_ref, int k)
{
    if (k == 0)
        return;
  
    // Let us understand the below
    // code for example k = 4 and
    // list = 10->20->30->40->50->60.
    Node* current = *head_ref;
  
    // current will either point to
    // kth or NULL after this loop.
    // current will point to node
    // 40 in the above example
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }
  
    // If current is NULL, k is greater than
    // or equal to count of nodes in linked list.
    // Don't change the list in this case
    if (current == NULL)
        return;
  
    // current points to kth node.
    // Store it in a variable. kthNode
    // points to node 40 in the above example
    Node* kthNode = current;
  
    // current will point to
    // last node after this loop
    // current will point to
    // node 60 in the above example
    while (current->next != NULL)
        current = current->next;
  
    // Change next of last node to previous head
    // Next of 60 is now changed to node 10
    current->next = *head_ref;
  
    // Change head to (k+1)th node
    // head is now changed to node 50
    *head_ref = kthNode->next;
  
    // change next of kth node to NULL
    // next of 40 is now NULL
    kthNode->next = NULL;
}
