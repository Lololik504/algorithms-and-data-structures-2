//
// Created by Матвей on 12.09.2020.
//
#include "Tree.h"

#ifndef LAB1_MENU_H
#define LAB1_MENU_H

template<class Key = int, class Value = int>
class Menu {
public:
    static void startMenu(Tree<Key, Value> &tree) {
        auto it = tree.begin();
        auto rit = tree.rbegin();
        bool running = true;
        int action = 0;
        int key, value;
        while (running) {
            Console::clear();
            Menu::printActionsList();
            Console::print("Choose action: ");
            cin >> action;
            Console::println("###################################");
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
                        Console::println(tree.empty());
                        break;
                    }
                    case 4: //get value by key
                    {
                        Console::println("Enter key: ");
                        cin >> key;
                        try {
                            Tree<Key, Value>::NULLIFY_COUNTER();
                            Console::success(tree.find(key));
                        } catch (const exception &ex) {
                            Console::error("ERROR");
                        }
                        break;
                    }
                    case 5: //set value by key
                    {
                        Console::print("Enter key: ");
                        cin >> key;
                        Console::print("Enter value: ");
                        cin >> value;
                        Tree<Key, Value>::NULLIFY_COUNTER();
                        tree.set(key, value) ? Console::success("SET") : Console::error("KEY ERROR");
                        break;
                    }
                    case 6: //insert value with key
                    {
                        Console::print("Enter key: ");
                        cin >> key;
                        Console::print("Enter value: ");
                        cin >> value;
                        Tree<Key, Value>::NULLIFY_COUNTER();
                        tree.insert(key, value) ? Console::success("INSERTED") : Console::error("KEY ALREADY EXISTS");
                        break;
                    }
                    case 7: //remove value by key
                    {
                        Console::println("Enter key: ");
                        cin >> key;
                        Tree<Key, Value>::NULLIFY_COUNTER();
                        tree.remove(key) ? Console::success("REMOVED") : Console::error("KEY ERROR");
                        break;
                    }
                    case 8: //traverse L-T-R
                    {
                        Tree<Key, Value>::NULLIFY_COUNTER();
                        tree.traverse();
                        break;
                    }
                    case 9: //tree-like print
                    {
                        tree.print();
                        break;
                    }
                    case 10: //external way length
                    {
                        Tree<Key, Value>::NULLIFY_COUNTER();
                        Console::println(tree.getExternalWayLength());
                        break;
                    }
                    case 11: //forward iterator to min key
                    {
                        it = tree.begin();
                        Menu<Key, Value>::iteratorMenu(tree, it);
                        break;
                    }
                    case 12: {
                        it = tree.end();
                        Menu<Key, Value>::iteratorMenu(tree, it);
                        break;
                    }
                    case 13: {
                        Menu<Key, Value>::iteratorMenu(tree, it);
                        break;
                    }
                    case 14: {
                        rit = tree.rbegin();
                        Menu<Key, Value>::rIteratorMenu(tree, rit);
                        break;
                    }
                    case 15: {
                        rit = tree.rend();
                        Menu<Key, Value>::rIteratorMenu(tree, rit);
                        break;
                    }
                    case 16: {
                        Menu<Key, Value>::rIteratorMenu(tree, rit);
                        break;
                    }
                    case 17: {
                        Console::println(it == tree.begin());
                        break;
                    }
                    case 18: {
                        Console::println(it == tree.end());
                        break;
                    }
                    case 19: {
                        Console::println(rit == tree.rbegin());
                        break;
                    }
                    case 20: {
                        Console::println(rit == tree.rend());
                        break;
                    }
                    case 21: {
                        Console::println(*it == *rit);
                        break;
                    }
                    case 22: {
                        Console::println(Tree<Key, Value>::GET_COUNTER());
                        break;
                    }
                    default: {
                        Console::error("Incorrect value!");
                        break;
                    }
                }
            } catch (const exception &ex) {
                Console::error("EXCEPTION");
            } catch (...) {
                Console::error("UNHANDLED EXCEPTION");
                running = false;
            }
            Console::println("###################################");
        }
    }

private:
    static void printActionsList() {
        Console::println("╔══════╦═══════════════════════╗");
        Console::println("║ (0)  ║ EXIT                  ║");
        Console::println("║ (1)  ║ Get size              ║");
        Console::println("║ (2)  ║ Clear tree            ║");
        Console::println("║ (3)  ║ Is empty?             ║");
        Console::println("║ (4)  ║ Get data by key       ║");
        Console::println("║ (5)  ║ Set data by key       ║");
        Console::println("║ (6)  ║ Insert data by key    ║");
        Console::println("║ (7)  ║ Remove data by key    ║");
        Console::println("║ (8)  ║ L-T-R  traverse       ║");
        Console::println("║ (9)  ║ Print tree            ║");
        Console::println("║ (10) ║ External way length   ║");
        Console::println("║ (11) ║ Get begin Iterator    ║");
        Console::println("║ (12) ║ Get end Iterator      ║");
        Console::println("║ (13) ║ Get cur Iterator      ║");
        Console::println("║ (14) ║ Get begin rIterator   ║");
        Console::println("║ (15) ║ Get end rIterator     ║");
        Console::println("║ (16) ║ Get cur rIterator     ║");
        Console::println("║ (17) ║ Iterator == begin()   ║");
        Console::println("║ (18) ║ Iterator == end()     ║");
        Console::println("║ (19) ║ rIterator == rbegin() ║");
        Console::println("║ (20) ║ rIterator == rend()   ║");
        Console::println("║ (21) ║ Iterator == rIterator ║");
        Console::println("║ (22) ║ Get counter           ║");
        Console::println("╚══════╩═══════════════════════╝");
    }

    static void iteratorMenu(Tree<Key, Value> &tree, typename Tree<Key, Value>::Iterator &it) {
        bool running = true;
        int action = 0;
        while (running) {
            Console::println("▬▬▬▬▬▬▬▬▬▬▬▬▬▬ITERATOR▬▬▬▬▬▬▬▬▬▬▬▬▬▬");
            Console::print("Set: ");
            Console::println(it != tree.end());
            Console::print("Current data: ");
            try {
                Console::println(*it);
            } catch (const exception &ex) {
                Console::error("EXCEPTION");
            }
            Console::println("▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬");
            tree.print();
            Console::println("▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬");
            Console::println("╔═════╦════════════════╗");
            Console::println("║ (0) ║ EXIT           ║");
            Console::println("║ (1) ║ Go to next     ║");
            Console::println("║ (2) ║ Go to prev     ║");
            Console::println("║ (3) ║ Get value      ║");
            Console::println("║ (4) ║ Set value      ║");
            Console::println("╚═════╩════════════════╝");
            Console::print("Choose action: ");
            cin >> action;
            try {
                switch (action) {
                    case 0: {
                        running = false;
                        break;
                    }
                    case 1: {
                        it++;
                        break;
                    }
                    case 2: {
                        it--;
                        break;
                    }
                    case 3: {
                        Console::success(*it);
                        break;
                    }
                    case 4: {
                        Console::print("Enter value: ");
                        int val;
                        cin >> val;
                        Console::success(*it = val);
                        break;
                    }
                    default: {
                        Console::error("Incorrect value");
                        break;
                    }
                }
            } catch (const exception &ex) {
                Console::error("EXCEPTION");
            }
        }
    }

    static void rIteratorMenu(Tree<Key, Value> &tree, typename Tree<Key, Value>::rIterator &it) {
        bool running = true;
        int action = 0;
        while (running) {
            Console::println("▬▬▬▬▬▬▬▬▬▬REVERSE ITERATOR▬▬▬▬▬▬▬▬▬▬");
            Console::print("Set: ");
            Console::println(it != tree.rend());
            Console::print("Current data: ");
            try {
                Console::println(*it);
            } catch (const exception &ex) {
                Console::error("EXCEPTION");
            }
            Console::println("▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬");
            tree.print();
            Console::println("▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬");
            Console::println("╔═════╦════════════════╗");
            Console::println("║ (0) ║ EXIT           ║");
            Console::println("║ (1) ║ Go to next     ║");
            Console::println("║ (2) ║ Go to prev     ║");
            Console::println("║ (3) ║ Get value      ║");
            Console::println("║ (4) ║ Set value      ║");
            Console::println("╚═════╩════════════════╝");
            Console::print("Choose action: ");
            cin >> action;
            try {
                switch (action) {
                    case 0: {
                        running = false;
                        break;
                    }
                    case 1: {
                        it++;
                        break;
                    }
                    case 2: {
                        it--;
                        break;
                    }
                    case 3: {
                        Console::success(*it);
                        break;
                    }
                    case 4: {
                        Console::print("Enter value: ");
                        int val;
                        cin >> val;
                        Console::success(*it = val);
                        break;
                    }
                    default: {
                        Console::error("Incorrect value");
                        break;
                    }
                }
            } catch (const exception &ex) {
                Console::error("EXCEPTION");
            }
        }
    }
};

#endif //LAB1_MENU_H
