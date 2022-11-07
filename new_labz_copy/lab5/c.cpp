#include<bits/stdc++.h>
using namespace std;
struct MaxHeap {
	vector<unsigned long long> heap;

	unsigned long long parent(unsigned long long i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}
	void insert(unsigned long long value) {
		this->heap.push_back(value);
		int i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	unsigned long long extractMax() {
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
	void heapify(int i) {
		int l = this->left(i);
		int r = this->right(i);
		int biggest = i;
		if (l < this->heap.size() && this->heap[l] > this->heap[biggest])
			biggest = l;
		if (r < this->heap.size() && this->heap[r] > this->heap[biggest])
			biggest = r;
		if (biggest != i) {
			swap(this->heap[i], this->heap[biggest]);
			this->heapify(biggest);
		}
	}
	int displayMax() {
        return this->heap[0];
    }
    bool empty() {
        return this->heap.size() == 0;
    }
    int size() {
        return this->heap.size();
    }
};

int main() {
	MaxHeap heap;
    unsigned long long n, x, k;
    cin >> n >> x;
    while(n--){
        cin >> k;
        heap.insert(k);
    }
    unsigned long long sumi = 0;
    while(x--){
        unsigned long long a = heap.extractMax();
        sumi += a;
        heap.insert(a - 1);
    }
    cout << sumi;
	return 0;
}