// Задача №112511. Cловарь по частотам
// https://informatics.msk.ru/mod/statements/view.php?id=54188&chapterid=112511#1

#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    string s;
    Node * prev;
    Node * next;

    Node(string s){
        this->s = s;
        val = 1;
        prev = NULL;
        next = NULL;
    }
};

struct ll{
private:
    Node * head;
    Node * tail;
    int sz;

public:
    ll(){
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    Node * find(string t){
        Node * temp = head;
        Node * result = NULL;
        while(temp != NULL){
            if(temp->s == t){
                result = temp; // val = 1, s = t
                break;
            }
            temp = temp->next;
        }
        return result;
    }

    void push(string t){
        Node * ff = find(t);
        Node *  newNode = new Node(t);
        if(ff != NULL){
            ff->val++;
            return;
        }
        if(head == NULL){
            head = newNode;
            tail = newNode; 
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void sort(){
        Node * first = head;
        Node * second = NULL;
        while(first != NULL){
            second = first->next;
            while(second != NULL){
                if(first->val < second->val){
                    swap(first->s, second->s);
                    swap(first->val, second->val);
                }
                else if(first->val == second->val){
                    if(first->s > second->s) swap(first->s, second->s);
                }
                second = second->next;
            }
            first = first->next;
        }   
    }

    void print(){
        Node * cur = head;
        while(cur != NULL){
            cout << cur->s << " " << cur->val << "\n";
            cur = cur -> next;
        }
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll list;
    string t;
    while(cin >> t){
        list.push(t);
    }
    list.sort();
    list.print();
}