#include <bits/stdc++.h>

using namespace std;

struct Node{
    string word;
    Node * next, * prev;
    Node(string word){
        this -> word = word;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class DataBase{
public:
    string soz;
    int sz;
    Node * head, * tail;

    DataBase(){
        this -> sz = 0;
        this -> head = NULL;
        this -> tail = NULL;
    }

    bool isthere(string n){
        Node * temp = head;
        if(sz == 0) return false;
        else{
            while(temp){
                if(temp -> word == n) return true;
                temp = temp -> next;
            }
            return false;
        }
    }

    void push(string x){
        Node * node = new Node(x);
        if(!head){
            head = node;
            tail = node;
        }else{
            tail -> next = node;
            tail = node;
        }
        sz++;
    }

    void print(){
        cout << "All in all: " << sz << "\nStudents:\n";
        Node * p = NULL;
        Node * c = head;
        Node * n = NULL;
    
        while(c){
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
        }
        while(p){
            cout << p -> word << "\n";
            p = p -> next;
        }
    }
};

int main(){
    DataBase db;
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(db.isthere(s)) continue;
        else db.push(s);
    }
    db.print();
}