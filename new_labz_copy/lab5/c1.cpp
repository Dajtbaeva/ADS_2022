#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    public:
    vector<unsigned long long> a;

    unsigned long long parent(unsigned long long i) {
        return (i - 1) / 2;
    }

    unsigned long long left(unsigned long long i) {
        return 2 * i + 1;
    }

    unsigned long long right(unsigned long long i) {
        return 2 * i + 2;
    }

    void insert(unsigned long long k) {
        a.push_back(k);
        unsigned long long i = a.size() - 1;
        siftUp(i);
    }

    void heapify(unsigned long long i) { //после удаления спустить на свое место , после того как что то увеличили сравнить с детьми
        if (left(i) > a.size() - 1) // если левого сына нет  (если левого нет то и правого нет)
            return;
        
        unsigned long long j = left(i);
        if (right(i) < a.size()  && a[right(i)] > a[left(i)])  // если есть правый сын и правый меньше чем левый
            j = right(i);

        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);  // дальше идем вниз
        }
    }

    unsigned long long extractMax() { //удаление самого мин элемента
        unsigned long long root = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root;
    }

    void siftUp(unsigned long long i){
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        siftUp(i);
    }

    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
    }

    int getMax() {
        return a[0];
    }
};

int main() {
    MaxHeap *max_heap = new MaxHeap();
    unsigned long long n, m;
    cin >> n >> m;
    unsigned long long x;
    for(unsigned long long i = 0; i < n; i++){
        cin >> x;
        max_heap->insert(x);
    }
    unsigned long long ans = 0;
    while(m--){
        unsigned long long a = max_heap->extractMax();
        ans += a;
        max_heap->insert(a - 1);
    }
    cout << ans;
}