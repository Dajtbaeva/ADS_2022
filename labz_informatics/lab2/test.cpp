#include <bits/stdc++.h>

using namespace std;

struct node{
    string soz;
    int cnt;
    node * next;
    node * prev;

    node(string soz){
       this->soz = soz;
       cnt = 1;
       next = NULL; 
       prev = NULL;
    }
    //node(int x):val(x),next(NULL),prev(NULL){}
};

struct ll{
    node * head;   
    node * tail;
    int sz;
    ll(){
        head = NULL;
        tail = NULL;
        sz = 0;
    }
    
    node * find(string x){
        node * temp = head;
        node * result = NULL;
        while(temp != NULL){
            if(temp->soz == x){
                result = temp;
                break;
            }
            temp = temp->next;
        }   
        return result;
    }

    void add(string x){
        node * fin = find(x);
        node * newNode = new node(x);
        if (fin != NULL){
            fin->cnt++;
            return;
        }
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;   
        }
    }

    void sort(){
        node * first = head;
        node * second = nullptr;
        while(first -> next != nullptr){
            second = first -> next;
            while(second != nullptr){
                if(second -> soz < first -> soz){
                    swap(second -> soz, first -> soz);
                    swap(second -> cnt, first -> cnt);
                }
                // else if(second -> cnt == first -> cnt){
                //     if(second -> soz < first -> soz){
                //         swap(second -> soz, first -> soz);
                //         swap(second -> cnt, first -> cnt);
                //     }
                // }
                
                second = second -> next;
            }
            first = first -> next;
        }
    }

    // void dl(int x){
    //     node * temp = find(x);
    //     dl(temp);
    // }

    void print(){
        node * temp = head;
        while(temp != NULL){
            cout << temp->soz << " " << temp->cnt<<endl;;
            temp = temp->next;
        }
        // cout << endl;
    }
    void print2(){
        node * temp = tail;
        while(temp != NULL){
            cout << temp->soz << " " << temp->cnt<<endl;;
            temp = temp->prev;
        }
        cout << endl;
    }

    bool isEmpty(){
        return sz == 0;
    }
};


ll * l = new ll();

int main(){
    freopen("input.txt","r",stdin); 
    freopen("output.txt", "w", stdout);
    string s;
    while(cin>>s){
        l->add(s);
    }
    l->sort();
    l->print();
    return 0;
}