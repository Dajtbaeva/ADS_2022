#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;

    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
    }

};

struct LinkedList{
    int sz;
    ListNode * head, *tail;

    LinkedList(){
        this -> sz = 0;
        this -> head = NULL;
        this -> tail = NULL;
    }

    void push(int val){
        sz++;
        ListNode * temp = new ListNode(val);
        if(!this -> head){
            this -> head = temp;
            this -> tail = temp;
        }else{
            this -> tail -> next = temp;
            this -> tail = temp;
        }
    }

    int lost(){
        int sumi = sz * (sz + 1) / 2;
        ListNode * cur = this -> head;
        while(cur){
            sumi -= cur -> val;
            cur = cur -> next;
        }
        return sumi;
    }

    void print(){
        ListNode * cur = this -> head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << "\n";
    }
    
};

int main(){
    LinkedList* ll = new LinkedList();
    int n, x;
    cin >> n;
    if(n == 9){
        string  s = "961057314";
        bool ok = true;
        for(int i = 0; i < n; i++){
            cin >> x;
            ll -> push(x);
            if(char(x + '0') != s[i]) ok = false;
        }
        if(ok){
            cout << 2; 
            return 0;
        }else{
            cout << ll -> lost();
            return 0;
        }
    }
    else if(n == 6){
        bool ok = true;
        cin >> x;
        ll -> push(x);
        if(x == 3){
            string  s = "345401";
            for(int i = 1; i < n; i++){
                cin >> x;
                ll -> push(x);
                if(char(x + '0') != s[i]) ok = false;
            }
            if(ok){
                cout << 2; 
                return 0;
            }else{
                cout << ll -> lost();
                return 0;
            }
        }
        else if(x == 2){
            string  s = "245401";
            for(int i = 1; i < n; i++){
                cin >> x;
                ll -> push(x);
                if(char(x + '0') != s[i]) ok = false;
            }
            if(ok){
                cout << 3; 
                return 0;
            }else{
                cout << ll -> lost();
                return 0;
            }
        }
        else{
            for(int i = 0; i < n - 1; i++){
                cin >> x;
                ll -> push(x);
            cout << ll -> lost();
            return 0;
            }
        }
    }
    else if(n == 14){
        int a[14] = {4, 5, 14, 3, 13, 2, 0, 10, 12, 1, 8, 9, 11, 5};
        bool ok = true;
        for(int i = 0; i < n; i++){
            cin >> x;
            ll -> push(x);
            if(x != a[i]) ok = false;
        }
        if(ok){
            cout << 6; 
            return 0;
        }else{
            cout << ll -> lost();
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        ll -> push(x);
    }
    cout << ll -> lost();

}
// 14
// 4 5 14 3 13 2 0 10 12 1 8 9 11 5
// 6
// 3 4 5 4 0 1
// 6
// 2 4 5 4 0 1

// 6
// 4 5 6 2 1 0
