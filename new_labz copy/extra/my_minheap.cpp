#include <bits/stdc++.h>

using namespace std;

struct MinHeap{
    vector<int> heap;

    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }

    void insert(int val){
        heap.push_back(val);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] > heap[i]){ // sift_up
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    int extractMin(){
        if(heap.size() == 0) return INT_MAX;
        if(heap.size() == 1){
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(0); // sift_down
        return root;
    }

    void heapify(int i){
        if(left(i) > heap.size() - 1) return;

        int smallest = left(i);
        if(right(i) < heap.size() && heap[right(i)] < heap[left(i)]) smallest = right(i);

        if(heap[smallest] < heap[i]){
            swap(heap[smallest], heap[i]);
            heapify(smallest); 
        }
    }

    void siftUp(int i){
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_value) {
        heap[i] = new_value;
        siftUp(i);
    }

    void increaseKey(int i, int new_value) {
        heap[i] = new_value;
        heapify(i);
    }

    void print(){
        for (int i = 0; i < heap.size(); i++) 
            cout << heap[i] << " ";
        cout << endl;
    }

    bool isEmpty(){
        return heap.size() == 0;
    }

    int sz(){
        return heap.size();
    }

    int displayMin(){
        return heap[0];
    }
};

int main(){
    MinHeap mh;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mh.insert(x);
    }
    while(n--){
        cout << mh.extractMin() << " ";
    }
}