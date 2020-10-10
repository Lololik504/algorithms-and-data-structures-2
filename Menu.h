//
// Created by Матвей on 12.09.2020.
//
#include "Tree.h"

#ifndef LAB1_MENU_H
#define LAB1_MENU_H

template<class Data = int>
class Menu {
public:
    static void startMenu(Tree<Data> &tree) {
        auto it = tree.begin();
//        auto rit = tree.rbegin();
        bool running = true;
        int action = 0;
        int tmp, number, counter = 0;
        while (running) {
            Console::clear();
            Menu::printActionsList();
            Console::print("Choose action: ");
            cin >> action;
            Console::println("--- START ACTION ---");
            try {
                switch (action) {
                    case 0: //exit
                    {
                        running = false;
                        break;
                    }
                    case 1: //tree size
                    {
                        Console::println(tree.getSize());
                        break;
                    }
                    case 2: //clear tree
                    {
                        tree.clear();
                        break;
                    }
                    case 3: //check empty tree
                    {
                        Console::println(tree.isEmpty());
                        break;
                    }
                    case 4: //get data by key
                    {
                        Console::println("Enter key: ");
                        cin >> action;
                        Console::println(tree.find(action));
                        break;
                    }
                    case 5: //set data by key
                    {
                        Console::println("Enter key: ");
                        cin >> action;
                        //TODO: setter function in tree
                        break;
                    }
                    case 6: //insert data with key
                    {
                        Console::println("Enter value: ");
                        cin >> number;
                        Console::println("Enter key: ");
                        cin >> action;
                        tree.insert(action, number);
                        break;
                    }
                    case 7: //remove data by key
                    {
                        Console::println("Enter key: ");
                        cin >> action;
                        tree.remove(action);
                        break;
                    }
                    case 8: //traverse L-T-R
                    {
                        //TODO: print tree like list Lt-T-Rt
                        tree.traverse();
                        break;
                    }
                    case 9: //external way length
                    {
                        //(длина внешнего пути)
                        //TODO: this task
                        break;
                    }
                    case 10: //forward iterator to min key
                    {
                        it = tree.begin();
                        break;
                    }
                    case 11: {
                        break;
                    }
                    case 12: {
                        break;
                    }
                    case 13: {
                        break;
                    }
                    case 14: {
                        break;
                    }
                    default: {
                        Console::print("Incorrect value!");
                        break;
                    }
                }
            } catch (const runtime_error &ex) {
                Console::error(ex.what());
            } catch (const exception &ex) {
                Console::error(ex.what());
            } catch (...) {
                Console::error("UNHANDLED EXCEPTION");
                running = false;
            }
            Console::println("--- END ACTION ---");
        }
    }

private:
    static void printActionsList() {
        Console::println("┌------┬---------------------┐");
        Console::println("| (0)  | EXIT                |");
        Console::println("| (1)  | Check tree size     |");
        Console::println("| (2)  | Clear tree          |");
        Console::println("| (3)  | Is empty?           |");
        Console::println("| (4)  | Get by key          |");
        Console::println("| (4)  | Set by key          |");
        Console::println("| (5)  | Add value by key    |");
        Console::println("| (6)  | Remove value by key |");
        Console::println("| (7)  | Print like list     |");
        Console::println("| (8)  | Outside way length  |");
        Console::println("| (9)  | Get Iterator        |");
        Console::println("| (10) | Get rIterator       |");
        Console::println("| (11) | Get null Iterator   |");
        Console::println("| (12) | Get null rIterator  |");
        Console::println("└------┴---------------------┘");
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
            Console::println("6) To minimal key");
            Console::println("7) To maximal key");
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
                        it->operator--(1);
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
                    it->setTree(tree);
                    break;
                case 6:
                    try {
                        it->toMinimalKey();
                    } catch (const exception &ex) {
                        Console::println("EXCEPTION");
                    }
                    break;
                case 7:
                    try {
                        it->toMaximalKey();
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

//    static void riteratorMenu(Tree<> *tree, Tree<>::rIterator *it) {
//        bool flag = true;
//        int action = 0;
//        while (flag) {
//            Console::print("Has tree: ");
//            Console::println(it->hasList());
//            Console::print("Has node: ");
//            Console::println(it->hasNode());
//            Console::print("Current value: ");
//            try {
//                Console::println(it->getData());
//            } catch (const exception &ex) {
//                Console::println("EXCEPTION");
//            }
//            Console::println("----------------------------------");
//            tree->print();
//            Console::println("---------------MENU---------------");
//            Console::println("0) EXIT");
//            Console::println("1) Go to next");
//            Console::println("2) Go to prev");
//            Console::println("3) Get value");
//            Console::println("4) Set value");
//            Console::println("5) Drop tree");
//            Console::println("6) To head");
//            Console::println("7) To tail");
//            cin >> action;
//            switch (action) {
//                case 0:
//                    flag = false;
//                    break;
//                case 1:
//                    try {
//                        it->next();
//                    } catch (const exception &ex) {
//                        Console::println("EXCEPTION");
//                    }
//                    break;
//                case 2:
//                    try {
//                        it->prev();
//                    } catch (const exception &ex) {
//                        Console::println("EXCEPTION");
//                    }
//                    break;
//                case 3:
//                    try {
//                        Console::println(it->getData());
//                    } catch (const exception &ex) {
//                        Console::println("EXCEPTION");
//                    }
//                    break;
//                case 4:
//                    Console::print("Enter value: ");
//                    int val;
//                    cin >> val;
//                    try {
//                        Console::println(it->setData(val));
//                    } catch (const exception &ex) {
//                        Console::println("EXCEPTION");
//                    }
//                    break;
//                case 5:
//                    it->setList();
//                    break;
//                case 6:
//                    try {
//                        it->toHead();
//                    } catch (const exception &ex) {
//                        Console::println("EXCEPTION");
//                    }
//                    break;
//                case 7:
//                    try {
//                        it->toTail();
//                    } catch (const exception &ex) {
//                        Console::println("EXCEPTION");
//                    }
//                    break;
//                default:
//                    Console::print("Incorrect value");
//                    break;
//            }
//            getchar();
//        }
//    }
};

#endif //LAB1_MENU_H
