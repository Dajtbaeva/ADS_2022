#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = nullptr;
    }
};
 
class LinkedList{
    int size;
public:
    Node * head;
    LinkedList(){
        head = nullptr;
        size = 0;
    }
    void push(int val){
        Node * newNode = new Node(val);
        if (head == nullptr){ head = newNode; }
        else{
            Node * cur = head;
            while(cur->next != nullptr){
                cur = cur->next;
                // cur = *(cur->next);
            }
            cur -> next = newNode;
        }
        size++;
    }
    void addFront(int val){
        Node * newNode = new Node(val);
        if (head == nullptr){ head = newNode; }
        else{
            newNode -> next = head;
            head = newNode;
        }
        size++;
    }
    void print(){
        Node * cur = head;
        while(cur -> next != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << cur -> val << endl;
    }

    void del(int val){
        if (head == nullptr){
            cout << "Linked List is empty";
            return;
        }
        if (head -> val == val){
            head = head -> next;
        }
        else{
            Node * cur = head;
            Node * prev = nullptr;
            while(cur != nullptr){
                if (cur -> val == val){
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                } 
                prev = cur;
                cur = cur -> next;
            }
            cout << "No such element " << val << endl;
        }
    }


    void del1(int pos){
        if (head == nullptr){
            cout << "Linked List is empty";
            return;
        }
        if (pos == 1){
            head = head -> next;
        }
        else{
            int i = 1;
            Node * cur = head;
            Node * prev = nullptr;
            while(cur != nullptr){
                if (i == pos){
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur -> next;
                i++;
            }
            cout << "No such pos " << pos << endl;
        }
    }

    bool contains(int val){
        Node * cur = head;
        while(cur != nullptr){
            if (cur -> val == val){
                return true;
            }
            cur = cur -> next;
        }
        return false;
    }

    //1 тип функции
    //тип функции = тип возвращаемого значения

    vector<int> search(int val){
        vector<int> ans;
        Node * cur = head;
        int i = 1;
        while(cur != nullptr){
            if (cur -> val == val){
                ans.push_back(i);
            }
            cur = cur -> next;
            i++;
        }
        return ans;
    }

    void reverse(){
        vector<int> rave;
        Node * cur = head;
        while(cur != nullptr){
            rave.push_back(cur -> val);
            cur = cur -> next;
        }
        for (int i = 0; i < rave.size(); i++){
            cout << rave[i] << " ";
        }
        cur = head;
        int i = rave.size() - 1;
        while(cur != nullptr){
            cur -> val = rave[i];
            cur = cur -> next;
            i--;
        }

    }

    void reversePRO(){
        Node * next = nullptr;
        Node * prev = nullptr;
        Node * cur = head;
        while(cur != nullptr){
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

};

int main(){
    LinkedList list;
    list.push(1);
    list.push(3);
    list.push(8);
    list.push(8);
    list.push(10);
    list.push(8);
    list.push(22);
    list.print();
    list.reversePRO();
    list.print();

}