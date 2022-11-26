// Задача №1170. Построение кучи просеиванием вниз
// https://informatics.msk.ru/mod/statements/view.php?id=54987&chapterid=1170#1

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

    int extract_max(){ // удаляем максимальный элемент корень
        int maxi = a[1];
        swap(a[1], a[sz]);
        sz--;
        sift_down(1); 
        return maxi;
    }
    
    // Heapify(sift_up, sift_down) - превращение набора данных в кучу
    void sift_down(int i){
        int l = left(i); // это индексы
        int r = right(i);
        int max_child = left(i); // по дефолту индекс левый макс
        if(l > sz) return;
        if(r <= sz){ // существует ли правый чайлд
            if(a[r] > a[l]) max_child = r; // находим здесь максимум из чайлдов
        }
        if(a[i] < a[max_child]){
            swap(a[i], a[max_child]);
            sift_down(max_child);
        }
    }

    void insert(int x){
        sz++;
        a[sz] = x;
    }

    void print(){
        for(int i = 1; i <= sz; i++){
            cout << a[i] << " ";
        } cout << "\n";
    }

    void build_heap(){
        for(int i = sz / 2; i >= 1; i--){
            sift_down(i);
        }
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
    heap.build_heap();
    heap.print();
}