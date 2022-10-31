// https://kbtuedu.sharepoint.com/:v:/s/msteams_b26ef4/EaQD6PY8YJVGmg_EUdtcs8UBIVUHrJvAO49TddINHNrcXA?e=YKi0tP
// extract max, sift down

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
};

int main(){
    Heap heap;
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.print(); // 5 4 2 1 3 
    cout << heap.extract_max() << "\n";
    cout << heap.extract_max() << "\n";
    heap.print();
}