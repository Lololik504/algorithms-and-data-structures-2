//
// Created by Матвей on 12.09.2020.
//
#include "Tree.h"

#ifndef LAB1_MENU_H
#define LAB1_MENU_H

class Menu {
public:
    static void startMenu(Tree<> &tree) {
        Tree<>::Iterator it = tree.begin();
        Tree<>::Iterator rit = tree.rbegin();
        bool flag = true;
        int action = 0;
        int tmp, number, counter = 0;
        while (flag) {
            Console::clear();
            Menu::printActionsList();
            cin >> action;
            Console::print("\n\n---ACTION---\n\n");
            switch (action) {
                case 0:
                    flag = false;
                    break;
                case 1://опрос размера дерева
                    Console::println(tree.getSize());
                    break;
                case 2://очистка дерева
                    tree.clear();
                    break;
                case 3://проверка дерева на пустоту
                    Console::println(tree.isEmpty());
                    break;
                case 4://доступ по чтению к данным по ключу
                    Console::println("Enter key: ");
                    cin >> action;
                    Console::println(tree.find(action));
                    break;
                case 5://доступ по записи к данным по ключу
                    Console::println("Enter key: ");
                    cin >> action;
                    //TODO: setter function in tree
                    break;
                case 6://включение данных с заданным ключом
                    Console::println("Enter value");
                    cin >> number;
                    Console::println("Enter key: ");
                    cin >> action;
                    tree.insert(action, number);
                    break;
                case 7://удаление данных с заданным ключом
                    Console::println("Enter key: ");
                    cin >> action;
                    tree.remove(action);
                    break;
                case 8://формирование списка ключей в дереве в порядке
                // обхода узлов по схеме, заданной в варианте задания,
                    //TODO: print tree like list Lt-T-Rt
                case 9://дополнительная операция, заданная в варианте задания
                    //(длина внешнего пути)
                    //TODO: this task
                    break;
                case 11:
                    break;
                case 12:
                    break;
                case 13:
                    break;
                case 14:
                    break;
                default:
                    Console::print("Incorrect value!");
                    break;
            }
            Console::print("\n\n---DONE---\n\n");

        }
    }

    static void printActionsList() {
        Console::println("---MENU---");
        Console::println("0) EXIT");
        Console::println("1) Check tree size");//опрос размера дерева
        Console::println("2) Clear tree");//очистка дерева
        Console::println("3) Is empty?");//проверка дерева на пустоту
        Console::println("4) Get by key");//доступ по чтению к данным по ключу
        Console::println("4) Set by key");//доступ по записи к данным по ключу
        Console::println("5) Add value by key");//включение данных с заданным ключом
        Console::println("6) Remove value by key");//удаление данных с заданным ключом,
        Console::println("7) Print like list");//формирование списка ключей в дереве в порядке
        // обхода узлов по схеме, заданной в варианте задания
        Console::println("8) Outside way length");//дополнительная операция, заданная в варианте задания
                                                        //(длина внешнего пути)
        Console::println("9) get Iterator ");//запрос прямого итератора,
        // установленного на узел дерева с минимальным ключом begin(),
        Console::println("10) get rIterator");//запрос обратного итератора, установленного
        // на узел дерева с максимальным ключом rbegin(),
        Console::println("11) get null Iterator");//запрос «неустановленного» прямого итератора end(),
        Console::println("12) Get null rIterator");   //запрос «неустановленного» обратного итератора rend()
    }

    static void iteratorMenu(Tree<> *tree, Tree<>::Iterator *it) {
        bool flag = true;
        int action = 0;
        while (flag) {
            Console::print("Has tree: ");
            Console::println(it->hasTree());
            Console::print("Has node: ");
            Console::println(it->hasNode());
            Console::print("Current value: ");
            try {
                Console::println(it->getData());
            } catch (const exception &ex) {
                Console::println("EXCEPTION");
            }
            Console::println("----------------------------------");
            tree->print();
            Console::println("---------------MENU---------------");
            Console::println("0) EXIT");
            Console::println("1) Go to next");
            Console::println("2) Go to prev");
            Console::println("3) Get value");
            Console::println("4) Set value");
            Console::println("5) Drop tree");
            Console::println("6) To head");
            Console::println("7) To tail");
            cin >> action;
            switch (action) {
                case 0:
                    flag = false;
                    break;
                case 1:
                    try {
                        it->operator++(1);
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 2:
                    try {
                        it->prev();
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 3:
                    try {
                        Console::println(it->getData());
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 4:
                    Console::print("Enter value: ");
                    int val;
                    cin >> val;
                    try {
                        Console::println(it->setData(val));
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 5:
                    it->setList();
                    break;
                case 6:
                    try {
                        it->toHead();
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 7:
                    try {
                        it->toTail();
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                default:
                    Console::print("Incorrect value");
                    break;
            }
            getchar();
        }
    }

    static void riteratorMenu(Tree<> *tree, Tree<>::rIterator *it) {
        bool flag = true;
        int action = 0;
        while (flag) {
            Console::print("Has tree: ");
            Console::println(it->hasList());
            Console::print("Has node: ");
            Console::println(it->hasNode());
            Console::print("Current value: ");
            try {
                Console::println(it->getData());
            } catch (const exception &ex) {
                Console::println("EXCEPTION");
            }
            Console::println("----------------------------------");
            tree->print();
            Console::println("---------------MENU---------------");
            Console::println("0) EXIT");
            Console::println("1) Go to next");
            Console::println("2) Go to prev");
            Console::println("3) Get value");
            Console::println("4) Set value");
            Console::println("5) Drop tree");
            Console::println("6) To head");
            Console::println("7) To tail");
            cin >> action;
            switch (action) {
                case 0:
                    flag = false;
                    break;
                case 1:
                    try {
                        it->next();
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 2:
                    try {
                        it->prev();
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 3:
                    try {
                        Console::println(it->getData());
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 4:
                    Console::print("Enter value: ");
                    int val;
                    cin >> val;
                    try {
                        Console::println(it->setData(val));
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 5:
                    it->setList();
                    break;
                case 6:
                    try {
                        it->toHead();
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 7:
                    try {
                        it->toTail();
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                default:
                    Console::print("Incorrect value");
                    break;
            }
            getchar();
        }
    }
};

#endif //LAB1_MENU_H
