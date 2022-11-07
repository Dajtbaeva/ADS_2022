#include <bits/stdc++.h>


using namespace std;

class MaxHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }

    void heapify(int i) { //после удаления спустить на свое место , после того как что то увеличили сравнить с детьми
        if (left(i) > a.size() - 1) // если левого сына нет  (если левого нет то и правого нет)
            return;
        
        int j = left(i);
        if (right(i) < a.size()  && a[right(i)] > a[left(i)])  // если есть правый сын и правый меньше чем левый
            j = right(i);

        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);  // дальше идем вниз
        }
    }

    int extractMax() { //удаление самого мин элемента
        if(a.size() == 0) return 0;
        int root = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root;
    }

    void siftUp(int i){
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
    MaxHeap *maxheap = new MaxHeap();
    int n; cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        maxheap->insert(x);
    }
    //maxheap->print();
    while(maxheap->a.size() > 1){
        
            int a = maxheap->extractMax();
            int b = maxheap->extractMax();
            if(a != b){
                maxheap->insert(abs(a - b));
            }
        
        
    }
    cout << maxheap->extractMax();

}