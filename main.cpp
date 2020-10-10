#include "Console.h"
#include "Tree.h"
#include "Menu.h"

//#define TEST

#ifdef TEST
int main() {
    Console::setSystem(SYSTEMS::LINUX);
    Console::setLogging();

    Console::debug("START TEST");
    Console::info("START TEST");

    Tree<int> tree;

    tree.insert(5, 5);
    tree.insert(4, 4);
    tree.insert(8, 8);
    tree.insert(7, 7);
    tree.insert(2, 3);
    tree.insert(3, 2);
    tree.insert(10, 99);
    tree.insert(11, 99);
    tree.insert(12, 99);
    tree.insert(13, 99);
    tree.insert(14, 99);
    tree.insert(15, 99);

    Tree<>::Iterator it = tree.begin();

    tree.print();
    it.print();
    for (int i = 0; i < 10; ++i) {
        it++;
        it.print();
    }
    for (int i = 0; i < 10; ++i) {
        it--;
        it.print();
    }

    Console::debug("END TEST");

    return 0;
}
#else

int main() {
    Console::setSystem(SYSTEMS::LINUX);
    Console::setLogging();

    Tree<> tree;

    Menu<>::startMenu(tree);

//    Console::println("Lab 2");

    return 0;
}

#endif
