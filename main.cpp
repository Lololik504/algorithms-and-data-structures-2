#include <iostream>
#include "Console.h"
using namespace std;

int main() {
    Console::setSystem(SYSTEMS::LINUX);
    Console::println("ahahah looool", COLORS::RED);
    Console::println(false, COLORS::YELLOW);
    Console::println(5+7, COLORS::GREEN);
    return 0;
}

