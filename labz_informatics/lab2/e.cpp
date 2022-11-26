// Задача №112514. Список чисел
// https://informatics.msk.ru/mod/statements/view.php?id=54188&chapterid=112514#1

#include <bits/stdc++.h>

using namespace std;

struct Node{ 
    int val;
    Node * prev;
    Node * next;

    Node(int x){
        this->val = x;
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

    void push(int a){
        Node * NewNode = new Node(a);
        if(head == NULL) head = NewNode;
        sz++;
        if(head == NULL){
            head = tail = NewNode;
        }else{
            tail->next = NewNode;
            NewNode->prev = tail;
            tail = NewNode;   
        }
    }

    bool remove(int a){
        Node * cur = head;
        while(cur != NULL){
            if(cur->val == a){
                cur->prev = cur->next;
                sz -= 1;
                return true;
            }
            cur = cur -> next;
        }
        return false;
    }

    void print(){
        Node * cur = head;
        if(sz == 0) cout << "EMPTY"; 
        while(cur != NULL){
            cout << cur->val << " ";
            cur = cur -> next;
        }
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll list; 
    string s;
    while(cin >> s){
        int a = 0;
        int b = 1;
        for(int i = 1; i < s.size(); i++){
            a += (s[i] - 48) * b;
            b *= 10;
        }
        if(s[0] == '+'){
            s.erase(0, 1);
            list.push(a);
        } 
        else if(s[0] == '-'){
            s.erase(0, 1);
            if(!list.remove(a)) cout << "ERROR";
        }
    }  
    list.print(); 
}