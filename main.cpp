#include "Console.h"
#include "Tree.h"
#include "Test.h"
#include "Menu.h"

#define TEST

#ifdef TEST
int main() {
    Console::setSystem(SYSTEMS::LINUX);
    Console::setLogging();

    int n = 5000;

    Console::debug("START RAND TEST");
    test_rand(n);
    Console::debug("END RAND TEST");

    Console::debug("START ORD TEST");
    test_ord(n);
    Console::debug("END ORD TEST");

    return 0;
}

#else

int main() {
    Console::setSystem(SYSTEMS::LINUX);
    Console::setLogging();
    Console::setLoggingLevel(LEVELS::DEBUG, true);

    Tree<int, int> tree;

    for (int i = 0; i < 10; ++i) {
        tree.insert(rand() % 100, rand() % 100);
    }


    Menu<int, int>::startMenu(tree);

    return 0;
}

#endif
