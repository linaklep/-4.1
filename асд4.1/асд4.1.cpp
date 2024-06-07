#include <iostream>
#include <string>
using namespace std;

int k = 1;
int sum_n(int n); 
void tail_r(int* mas, int n, int q, int ind); 
void linear_r(int* mas, int q);
void print(int* mas, int n);

int main() {
    setlocale(LC_ALL, "Ukr");
    cout << "Завдання 1: cтворити арифметичну прогресiю за допомогою рекурсiї" << endl;
    int b, n, ind = 1;
    int mas[100];

    cout << "Введiть розмiр масиву:";
    cin >> n;
    cout << "Введiть перший член масиву(цiле число):";
    cin >> mas[0];
    cout << "Введiть різницю арифметичної прогресiї:";
    cin >> b;

    tail_r(mas, n, b, ind);
    cout << "Арифметична прогресiя за хвостовою рекурсiєю:" << endl;
    print(mas, n); 

    for (int i = 1; i < n; i++)
        mas[i] = 0;
    k = n;
    linear_r(mas, b); 

    cout << "Арифметична прогресiя за лiнiйною рекурсiєю:" << endl;
    print(mas, n);

    int r;
    cout << endl;
    cout << "Завдання 2: знайти суму цифр заданого натурального числа." << endl;
    cout << "Введiть число:";
    cin >> r;
    cout << "Сума цифр числа:" << sum_n(r) << endl;

    return 0;
}

int sum_n(int n) { 
    int sum = 0;
    while (n != 0) {
        sum += n % 10; 
        n /= 10; 
    }
    return sum;
}

void tail_r(int* mas, int n, int b, int ind) { 
    if (ind == n)
        return;
    mas[ind] = mas[ind - 1] + b;
    tail_r(mas, n, b, ind + 1); 
}

void linear_r(int* mas, int b) { 
    if (k > 1) { 
        k--;
        linear_r(mas, b);
    }
    mas[k] = mas[k - 1] + b; 
    k++;
}

void print(int* mas, int n) { 
    for (int i = 0; i < n; i++) 
        cout << mas[i] << " ";
    cout << endl;
}