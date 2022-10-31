// Задача №1164. Увеличение приоритета_0
// https://informatics.msk.ru/mod/statements/view.php?id=54987#1

#include <bits/stdc++.h>

using namespace std;


class Heap{
public:
    vector<int> v;

    int parent(int i){
        return (i - 1) / 2;
    }

    void sift_up(int i){
        while(i > 0 && v[parent(i)] < v[i]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }

    int increase(int pos, int val){
        v[pos] += val;
        while(pos > 0 && v[parent(pos)] < v[pos]){
            swap(v[parent(pos)], v[pos]);
            pos = parent(pos);
        }
        return pos;
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
        cout << heap.increase(j - 1, x) + 1 << "\n";
    }
    heap.print();
}