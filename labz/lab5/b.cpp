// Задача №1165. Уменьшение приоритета
// https://informatics.msk.ru/mod/statements/view.php?id=54987&chapterid=1165#1

#include <bits/stdc++.h>

using namespace std;


class Heap{
public:
    vector<int> v;

    int parent(int i){
        return (i - 1) / 2;
    }

    int left(int i){
        return i * 2 + 1;
    }

    int right(int i){
        return i * 2 + 2;
    }

    int extract_max(){ // удаляем максимальный элемент корень
        int maxi = v[0];
        int sz = v.size() - 1;
        swap(v[1], v[sz]);
        v.pop_back();
        if(v.size() - 1) sift_down(0); 
        return maxi;
    }

    void sift_up(int i){
        while(i > 0 && v[parent(i)] < v[i]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }

    // Heapify(sift_up, sift_down) - превращение набора данных в кучу
    int sift_down(int i){
        int l = left(i); // это индексы
        int r = right(i);
        int sz = v.size() - 1;
        int max_child = left(i); // по дефолту индекс левый макс
        if(l > sz){ // если левого чайлда нет, то и правого нет
            return i;
        } 
        if(r <= sz){ // существует ли правый чайлд
            if(v[r] > v[l]) max_child = r; // находим здесь максимум из чайлдов
        }
        if(v[i] < v[max_child]){
            swap(v[i], v[max_child]);
            return sift_down(max_child);
        }
        return i;
    }

    int decrease(int pos, int val){
        v[pos] -= val;
        return sift_down(pos);
    }

    void insert(int x){
        int sz = v.size() - 1;
        v.push_back(x);
        sift_up(sz);
    }

    void print(){
        int sz = v.size();
        for(int i = 0; i < sz; i++){
            cout << v[i] << " ";
        } cout << "\n";
    }
};

int main(){
    Heap heap;
    int n, m, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> b;
        heap.insert(b);
    }
    cin >> m;
    int j, x;
    while(m--){
        cin >> j >> x;
        cout << heap.decrease(j - 1, x) + 1 << "\n";
    }
    heap.print();
}

