#include <iostream>
#include <math.h>
#include <stack>

using namespace std;


int main(){
    int n;
    cin >> n;
    deque<int> l;
    deque<int> r;
    deque<int> v;
    for (int i = 1; i <= n; i++){
        char z;
        int goblin;
        cin >> z;
        if (z == '+'){
            cin >> goblin;
            r.push_back(goblin);
            if (l.size() < r.size()){
                l.push_back(r.front());
                r.pop_front();
            }
        }
        if (z == '*'){
            cin >> goblin;
            if (l.size() - r.size() > 1){
                r.push_front(l.back());
                l.pop_back();
            }
            l.push_back(goblin);
        }
        if (z == '-'){
            v.push_back(l.front());
            l.pop_front();
            if (l.size() < r.size()){
                l.push_back(r.front());
                r.pop_front();
            }
        }
    }
    for (int i = 0; i < v.size(); i ++){
        cout << v[i] << endl;
    }
    //Ошибка во время исполнения программы - Runtime error
    //Деление на 0
    //Выход за границы массива
    //Удаляем, обращаемся к несуществующему элементу

    //Превышено максимальное время работы - Time limit exceeded
    //Код слишком дофига вычислений (алгоритм неправильный)
}