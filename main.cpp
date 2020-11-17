#include "Console.h"
#include "RBTree.h"
//#include "Test.h"
#include "Menu.h"

//#define TEST

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

    srand(time(nullptr));

    Tree<> *tree = new RBTree<>();


    for (int i = 0; i < 10; ++i) {
        tree->insert(static_cast<int>(rand() % 100), static_cast<int>(rand() % 100));
    }

    tree->insert(-5, -5);

    Console::debug(tree->find(-5));

    tree->print();

//    Menu<int, int>::startMenu(tree);
    delete tree;
    return 0;
}

#endif
