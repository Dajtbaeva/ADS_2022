// Задача №1169. Построение кучи просеиванием вверх
// https://informatics.msk.ru/mod/statements/view.php?id=54987&chapterid=1169#1

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

    void insert(int x){
        sz++;
        a[sz] = x;
        sift_up(sz);
    }

    void sift_up(int i){
        while(i > 1 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void print(){
        for(int i = 1; i <= sz; i++){
            cout << a[i] << " ";
        } cout << "\n";
    }
};

int main(){
    Heap heap;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        heap.insert(x);
    }
    heap.print();
}