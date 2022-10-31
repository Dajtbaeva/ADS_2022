// https://kbtuedu.sharepoint.com/:v:/s/msteams_b26ef4/EX3l_KW4_YVCibxX1dtwbUcBbNlpW2lz39xc67WAIqE85Q?e=IJqhYV
// increase, decrease, change

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
        if(l > sz){
            cout << i << "\n";
            return;
        } 
        if(r <= sz){ // существует ли правый чайлд
            if(a[r] > a[l]) max_child = r; // находим здесь максимум из чайлдов
        }
        if(a[i] < a[max_child]){
            swap(a[i], a[max_child]);
            sift_down(max_child);
        }
        else cout << i << "\n";
    }

    int sift_up(int i){
        while(i > 1 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        return i;
    }

    int increase(int pos, int val){
        a[pos] += val;
        cout << sift_up(pos) << "\n";
    }

    void decrease(int pos, int val){
        a[pos] -= val;
        sift_down(pos);
    }

    void change(int pos, int val){
        if(val > a[pos]){
            a[pos] = val;
            cout << sift_up(pos) << "\n";
        } else if(val < a[pos]){
            a[pos] = val;
            sift_down(pos);
        }
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
};

int main(){
    Heap heap;
    heap.insert(80);
    heap.insert(70);
    heap.insert(75);
    heap.insert(40);
    heap.insert(60);
    heap.insert(50);
    heap.insert(20);
    heap.print(); 
    heap.increase(3, 10);
    heap.decrease(2, 25);
    heap.print();
    heap.change(2, 100);
    heap.print();
}