// Задача №1172. Просто сортировка
// https://informatics.msk.ru/mod/statements/view.php?id=54987&chapterid=1172#1

#include <bits/stdc++.h>

using namespace std;


class Heap{
    int a[100009];
    int sz;
public:
    Heap(){
        a[0] = INT_MAX; // 2147483647
        sz = 0;
    }

    int parent(int i){
        return i / 2;
    }

    int left(int i){
        return i * 2;
    }

    int right(int i){
        return i * 2 + 1;
    }

    int sift_up(int i){
        while(i > 1 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        return i;
    }

    void insert(int x){
        sz++;
        a[sz] = x;
        sift_up(sz);
    }

    void print(){
        for(int i = 1; i <= sz; i++){
            cout << a[i] << " ";
        } cout << "\n";
    }

    void heapify(int i, int SZ){
        int l = left(i);
        int r = right(i);
        int maxChild = left(i);
        if (l > SZ){
            return;
        }
        if (r <= SZ){
            if (a[r] > a[l]) maxChild = r;
        }
        if (a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            heapify(maxChild, SZ);
        }
    }

    void heapSort(){
        for (int i = sz; i > 1; i--){
            swap(a[1], a[i]);
            heapify(1, i - 1);
        }
    }
};

int main(){
    Heap heap;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        heap.insert(x);
    }
    heap.heapSort();
    heap.print();
}