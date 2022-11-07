#include<bits/stdc++.h>

using namespace std;

struct MinHeap {
	vector<unsigned long long> heap;

	unsigned long long parent(unsigned long long i) {
		return (i - 1) / 2;
	}
	unsigned long long left(unsigned long long i) {
		return 2 * i + 1;
	}
	unsigned long long right(unsigned long long i) {
		return 2 * i + 2;
	}
	void insert(unsigned long long value) {
		this->heap.push_back(value);
		unsigned long long i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	unsigned long long int extractMin() {
		if (this->heap.size() == 0) return INT_MAX;
		if (this->heap.size() == 1) {
			unsigned long long root = this->heap[0];
			this->heap.pop_back();
			return root;
		}
		unsigned long long root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);
		return root;
	}
	void heapify(unsigned long long i) {
		unsigned long long l = this->left(i);
		unsigned long long r = this->right(i);
		int smallest = i;
		if (l < this->heap.size() && this->heap[l] < this->heap[smallest])
			smallest = l;
		if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
			smallest = r;
		if (smallest != i) {
			swap(this->heap[i], this->heap[smallest]);
			this->heapify(smallest);
		}
	}
    unsigned long long displayMin() {
        return this->heap[0];
    }
    bool empty() {
        return this->heap.size() == 0;
    }
    unsigned long long size() {
        return this->heap.size();
    }
    unsigned long long getSum(){
        unsigned long long sumi = 0;
        for(unsigned long long i = 0; i < heap.size(); i++){
            sumi += heap[i];
        }
        return sumi;
    }
};

int main() {
    MinHeap heap;
    unsigned long long q, k, n;
    string s;
    cin >> q >> k;
    while(q--){
        cin >> s;
        if(s == "print"){
            cout << heap.getSum() << "\n";
        }else{
            cin >> n;
            if(heap.size() < k) heap.insert(n);
            else{
                if(n > heap.displayMin()){
                    heap.extractMin();
                    heap.insert(n);
                }
            }
        }
    }
}