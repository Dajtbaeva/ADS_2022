#include <bits/stdc++.h>
  
using namespace std;

struct Node{
    Node * prev;
    Node * next;
    string val;

    Node(string _val){
        prev = NULL;
        next = NULL;
        val = _val;
    } 
};

Node * head = NULL;
Node * tail = NULL;
int cnt;

void add_back(string s){
    Node * temp = new Node(s);
    if(!tail){
        head = temp;
        tail = temp;
    }else{
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
    cnt++;
}

void add_front(string s){
    Node * temp = new Node(s);
    if(!head){
        head = temp;
        tail = temp;
    }else{
        head -> prev = temp;    
        temp -> next = head;
        head = temp;
    }
    cnt++;
}

bool empty(){
    return cnt == 0;
}

void erase_front(){
    if(head){
        head = head -> next;
        if(head) head -> prev = NULL;
        else tail = NULL;
    }
    cnt--;
}

void erase_back(){
    if(tail){
        tail = tail -> prev;
        if(tail) tail -> next = NULL;
        else head = NULL;
    }
    cnt--;
}

string front(){
    if(head) return head -> val;
}

string back(){
    if(tail) return tail -> val;
}

void clear(){
    while(!empty()){
        erase_back();
    }
}
  
int main(){
    // freopen("input.txt", "r", stdin);
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
    return 0;
}