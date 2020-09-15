#include "Console.h"
#include "Tree.h"

#define TEST

#ifdef TEST
int main() {
    Console::setSystem(SYSTEMS::LINUX);

    Console::setLogging();

    Console::info("start program");
    
    Tree<double> tree;

    tree.insert(5, 5);
    tree.insert(4, 4);
    tree.insert(8, 8);
    tree.insert(7, 7);
    tree.insert(2, 3);
    tree.insert(3, 2);
    tree.insert(10, 99);
    tree.insert(7.5, 99);
    tree.insert(7.5, 99);

    tree.print();

    Console::debug("Tree was printed");

    Console::info("end program");
    return 0;
}
#else
int main() {
    Console::setSystem(SYSTEMS::LINUX);

    Console::println("Lab 2");

    return 0;
}
#endif

