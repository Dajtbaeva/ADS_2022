#include <bits/stdc++.h>

using namespace std;

int main(){
    int a = 5;
    cout << &a << "\n"; // & взятие адреса - 0x6ffe14

    int *p = &a; // создание переменной адресного типа
    cout << p << "\n"; // 0x6ffe14
    cout << *p << "\n"; // разыменование - 5 

    int** pp = &p;
    cout << *pp << "\n"; // 0x6ffe14 
    cout << **pp << "\n"; // 5

    int b[4] = {1, 2, 3, 4};
    for(int i = 0; i < 4; i++){
        cout << &b[i] << " "; // 0x6ffde0 0x6ffde4 0x6ffde8 0x6ffdec
    }cout << endl;
    int* p1 = &b[0];
    // b[i] this is *(b + i)
    cout << p1[2] << endl; // *p this is a[2] = 3

}