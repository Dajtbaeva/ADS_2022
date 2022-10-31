#include <bits/stdc++.h>

using namespace std;

int heap[100010];
int sz;

void heapify(int i){
    int l = i + i + 1;
    int r = i + i + 2;
    int mx = i;
    if(l < sz && heap[l] > heap[i]) mx = l;
    if(r < sz && heap[r] > heap[i]) mx = r;
    if(mx != i){
        swap(heap[i], heap[mx]);
        heapify(mx);
    }

}

void insert(int v){
    heap[sz++] = v;
    int i = sz - 1;
    while(i > 0){
        int p = (i - 1) / 2;
        if(heap[i] > heap[p]){
            swap(heap[i], heap[p]);
            i = p;
        }
        else break;
    }
}

void deleteMax(){
    swap(heap[0], heap[sz - 1]);
    sz--;
    heapify(0);
}

void print(){
    for(int i = 0; i < sz; i++){
        cout << heap[i] << " ";
    }
}

void build(int a[]){
    for(int i = sz / 2; i >= 0; i--){
        heapify(i);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> heap[i];
    }
    sz = n;
    build(heap);
    print();
}