#include "Console.h"

#define WI

#ifdef WIN
#include <windows.h>
#endif

SYSTEMS Console::SYSTEM = SYSTEMS::WINDOWS;

bool Console::LOGGING = false;

void Console::SET_COLOR(COLORS color) {
#ifdef WIN
    switch (color) {
        case COLORS::BLUE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),01);
            break;
        case COLORS::GREEN:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),02);
            break;
        case COLORS::CYAN:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),03);
            break;
        case COLORS::RED:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),04);
            break;
        case COLORS::MAGNETA:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),05);
            break;
        case COLORS::YELLOW:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),06);
            break;
        case COLORS::DEFAULT:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),07);
            break;
        case COLORS::WHITE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F);
            break;
        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),07);
            break;
    }
#endif
}

const char *Console::PARSE_COLOR(COLORS color) {
    switch (color) {
        case COLORS::DEFAULT:
            return "\e[1;0m";
        case COLORS::RED:
            return "\e[1;31m";
        case COLORS::GREEN:
            return "\e[1;32m";
        case COLORS::YELLOW:
            return "\e[1;33m";
        case COLORS::BLUE:
            return "\e[1;34m";
        case COLORS::MAGNETA:
            return "\e[1;35m";
        case COLORS::CYAN:
            return "\e[1;36m";
        case COLORS::WHITE:
            return "\e[1;37m";
        default:
            return "";
    };
}

void Console::setSystem(SYSTEMS system) {
    Console::SYSTEM = system;
}

void Console::setLogging(bool logging) {
    Console::LOGGING = logging;
}

void Console::clear() {
#ifdef WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

void Console::print(bool str, COLORS color) {
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(color);
            cout << (str ? "TRUE" : "FALSE");
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(color) << (str ? "TRUE" : "FALSE") << Console::PARSE_COLOR();
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(color) << (str ? "TRUE" : "FALSE") << Console::PARSE_COLOR();
            break;
    }
}

void Console::println(bool str, COLORS color) {
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(color);
            cout << (str ? "TRUE" : "FALSE") << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(color) << (str ? "TRUE" : "FALSE") << Console::PARSE_COLOR();
            cout << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(color) << (str ? "TRUE" : "FALSE") << Console::PARSE_COLOR();
            cout << endl;
            break;
    }
}

void Console::print(const char *str, COLORS color) {
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(color);
            cout << str << flush;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR();
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR();
            break;
    }
}

void Console::println(const char *str, COLORS color) {
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(color);
            cout << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR() << endl;
            break;
    }
}

void Console::print(int str, COLORS color) {
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(color);
            cout << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR();
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR();
            break;
    }
}

void Console::println(int str, COLORS color) {
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(color);
            cout << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR() << endl;
            break;
    }
}

void Console::print(double str, COLORS color) {
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(color);
            cout << str;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR();
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR();
            break;
    }
}

void Console::println(double str, COLORS color) {
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(color);
            cout << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(color) << str << Console::PARSE_COLOR() << endl;
            break;
    }
}

void Console::info(const char *str) {
    if (!Console::LOGGING) {
        return;
    }
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(COLORS::CYAN);
            cout << "[INFO]: " << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(COLORS::CYAN) << "[INFO]: " << str << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(COLORS::CYAN) << "[INFO]: " << str << Console::PARSE_COLOR() << endl;
            break;
    }
}

void Console::debug(const char *str) {
    if (!Console::LOGGING) {
        return;
    }
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(COLORS::GREEN);
            cout << "[DEBUG]: " << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(COLORS::GREEN) << "[DEBUG]: " << str << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(COLORS::GREEN) << "[DEBUG]: " << str << Console::PARSE_COLOR() << endl;
            break;
    }
}

void Console::warning(const char *str) {
    if (!Console::LOGGING) {
        return;
    }
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(COLORS::YELLOW);
            cout << "[WARNING]: " << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(COLORS::YELLOW) << "[WARNING]: " << str << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(COLORS::YELLOW) << "[WARNING]: " << str << Console::PARSE_COLOR() << endl;
            break;
    }
}

void Console::error(const char *str) {
    if (!Console::LOGGING) {
        return;
    }
    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(COLORS::RED);
            cout << "[ERROR]: " << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(COLORS::RED) << "[ERROR]: " << str << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(COLORS::RED) << "[ERROR]: " << str << Console::PARSE_COLOR() << endl;
            break;
    }
}
