// Задача №1171. Пирамидальная сортировка - подробно
// https://informatics.msk.ru/mod/statements/view.php?id=54987&chapterid=1171#1

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
        int k = 1;
        for (int i = sz; i > 1; i--){
            swap(a[1], a[i]);
            heapify(1, i - 1);
            for(int j = 1; j <= sz - k; j++){
                cout << a[j] << " ";
            } cout << "\n";    
            k++;
        }
    }
    void build_heap(){
        for(int i = sz / 2; i >= 1; i--){
            sift_down(i);
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
    heap.build_heap();
    heap.print();
    heap.heapSort();
    heap.print();
}