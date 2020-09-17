#ifndef LAB2_3_CONSOLE_H
#define LAB2_3_CONSOLE_H

#define ENABLE_COLOR

#include <iostream>

using namespace std;

enum class COLORS {
    DEFAULT,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    MAGNETA,
    CYAN,
    WHITE
};

enum class SYSTEMS {
    WINDOWS,
    LINUX,
    MAC
};

class Console {
private:
    static SYSTEMS SYSTEM;

    static void SET_COLOR(COLORS color = COLORS::DEFAULT);

    static const char * PARSE_COLOR(COLORS color = COLORS::DEFAULT);

public:

    static void setSystem(SYSTEMS system = SYSTEMS::WINDOWS);

    static void clear();

    static void print(int str, COLORS color = COLORS::DEFAULT);

    static void println(int str, COLORS color = COLORS::DEFAULT);

    static void print(double str, COLORS color = COLORS::DEFAULT);

    static void println(double str, COLORS color = COLORS::DEFAULT);

    static void print(bool str, COLORS color = COLORS::DEFAULT);

    static void println(bool str, COLORS color = COLORS::DEFAULT);

    static void print(const char *str, COLORS color = COLORS::DEFAULT);

    static void println(const char *str, COLORS color = COLORS::DEFAULT);
};

#endif //LAB2_3_CONSOLE_H
