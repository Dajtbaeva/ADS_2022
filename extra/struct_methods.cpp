//
// Created by Альтаир on 09.06.2022.
//
#include <iostream>
#include <math.h>

using namespace std;

struct student{
    //Поля структуры
    int age;
    string name;
    string fac;
    double gpa;
    //методы
    //методы - функции (выполняются для объекта)
    //конструктор - метод, инициализирующий поля объекта при его создании
    //Инициализация - давать значение
    //деструктор
    student(int age, string name, string fac, double gpa){
        this->age = age;
        this->name = name;
        this->fac = fac;
        this->gpa = gpa;
    }

    void study(){
        gpa += 0.1;
    }

    double gaming(double n){
        gpa -= (n / 10);
    }

};

int main(){
    //struct - пользовательский тип данных
    //struct - описание объектов
    //struct - совокупность данных
    //Дано число N. А затем информация об N студентах (имя, факультет, возраст, гпа)
    //Вывести количетсво студентов, обучающихся на факультете FIT, чей gpa > 3.0

    //alish fit 19 2.9
    //amina fit 20 3.2
    //abylai git 20 1.5

    //1

    student alish(19, "alish", "FIT", 2.5);
    student amina(20, "amina", "FIT", 3.0);
    student eduard(18, "Edik", "FIT", 3.2);

    alish.study();
    alish.study();
    alish.gaming(2);
    alish.study();
    alish.study();
    alish.gaming(1);
    
    cout << alish.gpa << endl;
}