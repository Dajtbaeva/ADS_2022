#include <bits/stdc++.h>

using namespace std;

struct Node{
    string val;
    Node * next, * prev;

    Node(string val){
        this -> val = val;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

Node * head = NULL;
Node * tail = NULL;
int sz;

void add_front(string val){
    Node * node = new Node(val);
    if(!head) head = tail = node;
    else{
        head -> prev = node;
        node -> next = head;
        head = node;
    }
    sz++;
}

void add_back(string val){
    Node * node = new Node(val);
    if(!head) head = tail = node;
    else{
        tail -> next = node;
        node -> prev = tail;
        tail = node;
    }
    sz++;
}

bool empty(){
    return sz == 0;
}

string front(){
    return head -> val;
}

void erase_front(){
    if(head){
        head = head -> next;
        if(head) head -> prev = NULL; // there was node > 1
        else tail = NULL; // one node
    }
    sz--;
}

string back(){
    return tail -> val;
}

void erase_back(){
    if(tail){
        tail = tail -> prev;
        if(tail) tail -> next = NULL;
        else head = NULL;
    }
    sz--;
}

void clear(){
    while(!empty()){
        erase_back();
    }
}

int main(){
    string s;
    while(cin >> s){
        if(s == "add_front"){
            string t;
            cin >> t;
            add_front(t);
            cout << "ok" << endl;
        }
        if(s == "add_back"){
            string t;
            cin >> t;
            add_back(t);
            cout << "ok" << endl;
        }
        if(s == "erase_front"){
            if(empty()) cout << "error" << endl;
            else{
                cout << front() << endl;
                erase_front();
            }
        }
        if(s == "erase_back"){
            if(empty()) cout << "error" << endl;
            else{
                cout << back() << endl;
                erase_back();
            }
        }
        if(s == "front"){
            if(empty()) cout << "error" << endl;
            else cout << front() << endl;
        }
        if(s == "back"){
            if(empty()) cout << "error" << endl;
            else cout << back() << endl;
        }
        if(s == "clear"){
            clear();
            cout << "ok" << endl;
        }
        if(s == "exit"){
            cout << "goodbye" << endl;
            break;
        }
    }
}