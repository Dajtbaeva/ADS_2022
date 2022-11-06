#include <bits/stdc++.h>
using namespace std;

class MinHeap {
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
        if (right(i) < a.size()  && a[right(i)] < a[left(i)])  // если есть правый сын и правый меньше чем левый
            j = right(i);

        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);  // дальше идем вниз
        }
    }

    unsigned long long extractMin() { //удаление самого мин элемента
        unsigned long long root = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root;
    }

    void siftUp(unsigned long long i){
        while (i != 0 && a[parent(i)] > a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        siftUp(i);
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
    }

    int getMin() {
        return a[0];
    }
};

int main() {
    MinHeap *min_heap = new MinHeap();
    unsigned long long n; cin >> n;
    unsigned long long x;
    for(unsigned long long i = 0; i < n; i++){
        cin >> x;
        min_heap->insert(x);
    }

    
    unsigned long long res = 0;

    while(min_heap->a.size() != 1){
        unsigned long long a = min_heap->extractMin();
        unsigned long long b = min_heap->extractMin();
        min_heap->insert(a + b);
        //cout << a << " " << b << endl;
        res += a + b;
    }
    cout << res;
}

// 6 8 6 15 10 18 9 
//