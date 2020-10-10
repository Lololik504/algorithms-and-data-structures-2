#ifndef ALGORITHMS_AND_DATA_STRUCTURES_2_3_TEST_H
#define ALGORITHMS_AND_DATA_STRUCTURES_2_3_TEST_H

#include <ctime>
#include <cmath>
#include <iostream>
#include "Tree.h"

using namespace std;

typedef unsigned long long INT_64;
//переменная и константы генератора LineRand()
static INT_64 RRand = 15750;
const INT_64 mRand = (1 << 63) - 1;
const INT_64 aRand = 6364136223846793005;
const INT_64 cRand = 1442695040888963407;

//функция установки первого случайного числа от часов компьютера
void sRand() {
    srand(time(nullptr));
    RRand = (INT_64) rand();
}
//функция генерации случайного числа

//линейный конгруэнтный генератор Xi+1=(a*Xi+c)%m

INT_64 LineRand() {
    INT_64 y1, y2;
    y1 = (aRand * RRand + cRand) % mRand;
    y2 = (aRand * y1 + cRand) % mRand;
    RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 & 0xFFFFFFFF00000000LL) >> 32;
    return RRand;

}

void test_rand(int n) {
//создание дерева для 64 – разрядных ключей типа INT_64
    Tree<INT_64, int> tree;
//массив для ключей, которые присутствуют в дереве
    INT_64 *m = new INT_64[n];
//установка первого случайного числа
    sRand();
//заполнение дерева и массива элементами со случайными ключами
    for (int i = 0; i < n; i++) {
        m[i] = LineRand();
        tree.insert(m[i], 1);
    }
//вывод размера дерева до теста
    cout << "items count:" << tree.getSize() << endl;
//обнуление счётчиков трудоёмкости вставки, удаления и поиска
    double I = 0;
    double D = 0;
    double S = 0;
//генерация потока операций, 10% - промахи операций
    for (int i = 0; i < n / 2; i++)
        if (i % 10 == 0) //10% промахов
        {
            Tree<INT_64, int>::NULLIFY_COUNTER();
            tree.remove(LineRand());
            D += Tree<INT_64, int>::GET_COUNTER();
            Tree<INT_64, int>::NULLIFY_COUNTER();
            tree.insert(m[rand() % n], 1);
            I += Tree<INT_64, int>::GET_COUNTER();
            try {
                Tree<INT_64, int>::NULLIFY_COUNTER();
                tree.find(LineRand());
                S += Tree<INT_64, int>::GET_COUNTER();
            }
            catch (const invalid_argument &ex) {
                S += Tree<INT_64, int>::GET_COUNTER();
            }
        } else //90% успешных операций
        {
            int ind = rand() % n;
            Tree<INT_64, int>::NULLIFY_COUNTER();
            tree.remove(m[ind]);
            D += Tree<INT_64, int>::GET_COUNTER();
            INT_64 key = LineRand();
            Tree<INT_64, int>::NULLIFY_COUNTER();
            tree.insert(key, 1);
            I += Tree<INT_64, int>::GET_COUNTER();
            m[ind] = key;
            try {
                Tree<INT_64, int>::NULLIFY_COUNTER();
                tree.find(m[rand() % n]);
                S += Tree<INT_64, int>::GET_COUNTER();
            }
            catch (const invalid_argument &ex) {
                S += Tree<INT_64, int>::GET_COUNTER();
            }
        }
    cout << "items count:" << tree.getSize() << endl;
//теоретической оценки трудоёмкости операций BST
    cout << "1.39*log2(n)=" << 1.39 * (log((double) n) / log(2.0)) << endl;
//экспериментальной оценки трудоёмкости вставки
    cout << "Count insert: " << I / (n / 2) << endl;
//экспериментальной оценки трудоёмкости удаления
    cout << "Count delete: " << D / (n / 2) << endl;
//экспериментальной оценки трудоёмкости поиска
    cout << "Count search: " << S / (n / 2) << endl;
//освобождение памяти массива m[]
    delete[] m;
}

void test_ord(int n) {
//создание дерева для 64 – разрядных ключей типа INT_64
    Tree<INT_64, int> tree;
//массив для ключей, которые присутствуют в дереве
    INT_64 *m = new INT_64[n];
//заполнение дерева и массива элементами с возрастающими чётными //ключами на интервале [0, 10000, 20000, ... ,10000*n]
    for (int i = 0; i < n; i++) {
        m[i] = i * 10000;
        tree.insert(m[i], 1);
    }
//вывод размера дерева до теста
    cout << "items count:" << tree.getSize() << endl;
//обнуление счётчиков трудоёмкости вставки, удаления и поиска
    double I = 0;
    double D = 0;
    double S = 0;
//установка первого случайного числа
    sRand();
//генерация потока операций, 10% - промахи операций
    for (int i = 0; i < n / 2; i++) {
        if (i % 10 == 0) //10% промахов
        {
            int k = LineRand() % (10000 * n);
            k = k + !(k % 2); //случайный нечётный ключ
            Tree<INT_64, int>::NULLIFY_COUNTER();
            tree.remove(k);
            D += Tree<INT_64, int>::GET_COUNTER();
            Tree<INT_64, int>::NULLIFY_COUNTER();
            tree.insert(m[rand() % n], 1);
            I += Tree<INT_64, int>::GET_COUNTER();
            k = LineRand() % (10000 * n);
            k = k + !(k % 2); // случайный нечётный ключ
            try {
                Tree<INT_64, int>::NULLIFY_COUNTER();
                tree.find(k);
                S += Tree<INT_64, int>::GET_COUNTER();
            }
            catch (const invalid_argument &ex) {
                S += Tree<INT_64, int>::GET_COUNTER();
            }
        } else //90% успешных операций
        {
            int ind = rand() % n;
            Tree<INT_64, int>::NULLIFY_COUNTER();
            tree.remove(m[ind]);
            D += Tree<INT_64, int>::GET_COUNTER();
            int k = LineRand() % (10000 * n);
            k = k + k % 2; // случайный чётный ключ
            Tree<INT_64, int>::NULLIFY_COUNTER();
            tree.insert(k, 1);
            I += Tree<INT_64, int>::GET_COUNTER();
            m[ind] = k;
            try {
                Tree<INT_64, int>::NULLIFY_COUNTER();
                tree.find(m[rand() % n]);
                S += Tree<INT_64, int>::GET_COUNTER();
            }
            catch (const invalid_argument &ex) {
                S += Tree<INT_64, int>::GET_COUNTER();
            }
        }
    }
//вывод результатов:

// вывод размера дерева после теста
    cout << "items count:" << tree.getSize() << endl;
//теоретической оценки трудоёмкости операций BST
    cout << "n/2 =" << n / 2 << endl;
//экспериментальной оценки трудоёмкости вставки
    cout << "Count insert: " << I / (n / 2) << endl;
//экспериментальной оценки трудоёмкости удаления
    cout << "Count delete: " << D / (n / 2) << endl;
//экспериментальной оценки трудоёмкости поиска
    cout << "Count search: " << S / (n / 2) << endl;
//освобождение памяти массива m[]
    delete[] m;
}
#endif //ALGORITHMS_AND_DATA_STRUCTURES_2_3_TEST_H
