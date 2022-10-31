//
// Created by Альтаир on 09.06.2022.
//
#include <iostream>
#include <math.h>

using namespace std;

struct rectangle{
    double a, b;

    rectangle(double a, double b){
        this->a = a;
        this->b = b;
    }

    double area(){
        return a * b;
    }

    double perimeter(){
        return a + a + b + b;
    }

    void print(){
        cout << "area = " << area() << endl;
        cout << "perimeter = " << perimeter() << endl;
    }
};

int main(){
    rectangle rec(5, 4);
    rec.a = 123;
    rec.print();
    rectangle bec(3, 6);
    rec.print();
    bec.print();

    rectangle* p = &rec;
    rectangle sec(6, 7);

    rectangle * pp = new rectangle(6, 7); //создали указатель на объект rectangle
    pp->a = 10;
    pp->print();
    cout << pp->a << endl;

}