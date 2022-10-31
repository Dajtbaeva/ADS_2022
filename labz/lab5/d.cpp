// Задача №1167. Приоритетная очередь
// https://informatics.msk.ru/mod/statements/view.php?id=54987&chapterid=1167#1

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
    bool empty(){
        return sz;
    }
};

int main(){
    Heap heap;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(x == 1){
            if(heap.empty()) return -1;
            else cout << heap.extract_max() << "\n";
        }
        else if(x == 2){
            if(n > 0)
            else 
            n--;
        }
        heap.insert(x);
    }

}