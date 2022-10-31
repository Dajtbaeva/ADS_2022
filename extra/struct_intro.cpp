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
    int n;
    cin >> n;
    student a[n];
    for (int i = 0; i < n; i ++){
        cout << "Name: ";
        cin >> a[i].name;
        cout << "Faculty: ";
        cin >> a[i].fac;
        cout << "Age: ";
        cin >> a[i].age;
        cout << "GPA: ";
        cin >> a[i].gpa;
    }
    int cnt = 0;
    for (int i = 0; i < n; i ++){
        if (a[i].fac == "FIT" || a[i].fac == "fit"){
            if (a[i].gpa > 3.0){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}