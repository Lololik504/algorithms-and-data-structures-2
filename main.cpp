#include "Console.h"
#include "Tree.h"
#include "Test.h"
#include "Menu.h"

#define TEST

#ifdef TEST
int main() {
    Console::setSystem(SYSTEMS::LINUX);
    Console::setLogging();

    int n = 1000;

    Console::debug("START ORD TEST");

    test_ord(n);

    Console::debug("END ORD TEST");

    Console::debug("START RAND TEST");

    test_rand(n);

    Console::debug("END RAND TEST");

    return 0;
}
#else

int main() {
    Console::setSystem(SYSTEMS::LINUX);
    Console::setLogging();
    Console::setLoggingLevel(LEVELS::DEBUG, true);
    srand(5);

    Tree<int, int> tree;

    const int n = 20;
    int *keys = new int[n];
    for (int i = 0; i < n; i++) {
        keys[i] = static_cast<int>(rand() % 400000000);
        tree.insert(keys[i], 1);
    }
    tree.print();
    for (int i = 0; i < n; i++) {
        Console::info(keys[i]);
        tree.remove(keys[i]);

        tree.print();
        Console::info("#############################################################");
    }
//    Menu<> menu;
//    menu.startMenu(tree);

//    Tree<> tree2(tree);

    tree.print();
//    tree2.print();

    return 0;
}

#endif
