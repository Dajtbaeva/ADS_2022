// https://codelessons.ru/cplusplus/algoritmy/binarnyj-poisk-po-massivu-c.html
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  setlocale(LC_ALL, "rus");

  int arr[10]; // создали массив на 10 элементов
  int key; // создали переменную в которой будет находиться ключ

  cout << "Введите 10 чисел для заполнения массива: " << endl;
 
  for (int i = 0; i < 10; i++) {
    cin >> arr[i]; // считываем элементы массива
  }

  sort (arr, arr + 10); // сортируем с помощью функции sort (быстрая сортировка)

  cout << endl << "Введите ключ: ";

  cin >> key; // считываем ключ

  bool flag = false;
  int l = 0; // левая граница
  int r = 9; // правая граница
  int mid;

  while ((l <= r) && (flag != true)) {
    mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

    if (arr[mid] == key) flag = true; //проверяем ключ со серединным элементом
    if (arr[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
    else l = mid + 1;
  }

  if (flag) cout << "Индекс элемента " << key << " в массиве равен: " << mid;
  else cout << "Извините, но такого элемента в массиве нет";
  
  system("pause");
  return 0;
}