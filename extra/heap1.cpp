// https://kbtuedu.sharepoint.com/:v:/s/msteams_b26ef4/EbiExtWIzuBGrhNRTlRNsf0BLmunOYuK6Z75o3GdUGyATA?e=0IXBez
// дети меньше родителей, добавляються поочередно

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
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.print(); // 5 4 2 1 3 
}