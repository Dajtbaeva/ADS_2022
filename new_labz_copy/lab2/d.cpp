#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    int f;
    ListNode * next;

    ListNode(int val){
        this -> val = val;
        this -> f = 1;
        this -> next = NULL;
    }
};

struct LinkedList{
    int sz;
    ListNode * head;

    LinkedList(){
        this -> sz = 0;
        this -> head = NULL;
    }

    void push(int val){
        sz++;
        ListNode * temp = new ListNode(val);
        if(!this -> head){
            this -> head = temp;
        }else{
            ListNode * cur = head;
            while(cur){
                if(cur -> val == val) cur -> f++;
                if(!cur -> next){
                    cur -> next = temp;
                    cur = temp;
                }
                cur = cur -> next;
            }
        }
    }

    int maxi(){
        int mymaxi = 0;
        ListNode * temp = this -> head;
        while(temp){
            if(temp -> f > mymaxi) mymaxi = temp -> f;
            temp = temp -> next;
        }
        return mymaxi;
    }

    void print_modes(){
        ListNode * cur = this -> head;
        vector<int> res;
        while(cur){
            if(cur -> f == maxi()) res.push_back(cur -> val);
            cur = cur -> next;
        }
        sort(res.begin(), res.end(), greater<int>());
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
    }
};

int main(){
    LinkedList * ll = new LinkedList();

    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll -> push(x);
    }
    ll -> print_modes();
}

// 7
// 1 9 4 8 2 8 1
// 8 1