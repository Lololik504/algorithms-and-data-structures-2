#include "Console.h"

#define WI

#ifdef WIN
#include <windows.h>
#endif

SYSTEMS Console::SYSTEM = SYSTEMS::WINDOWS;

bool Console::LOGGING = false;

bool Console::INFO = true;

bool Console::DEBUG = true;

bool Console::WARNING = true;

bool Console::SUCCESS = true;

bool Console::ERROR = true;

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
        case COLORS::BLACK:
            return "\e[4;30m";
        default:
            return "";
    };
}

void Console::LOG(LEVELS LEVEL, COLORS COLOR, const char *PREFIX, const char *str) {
    if (!Console::LOGGING)
        return;

    switch (LEVEL) {
        case LEVELS::INFO:
            if (!Console::INFO)
                return;
            break;
        case LEVELS::DEBUG:
            if (!Console::DEBUG)
                return;
            break;
        case LEVELS::WARNING:
            if (!Console::WARNING)
                return;
            break;
        case LEVELS::SUCCESS:
            if (!Console::SUCCESS)
                return;
            break;
        case LEVELS::ERROR:
            if (!Console::ERROR)
                return;
            break;
    }

    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(COLOR);
            cout << PREFIX << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(COLOR) << PREFIX << str << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(COLOR) << PREFIX << str << Console::PARSE_COLOR() << endl;
            break;
    }
}

void Console::LOG(LEVELS LEVEL, COLORS COLOR, const char *PREFIX, int str) {
    if (!Console::LOGGING)
        return;

    switch (LEVEL) {
        case LEVELS::INFO:
            if (!Console::INFO)
                return;
            break;
        case LEVELS::DEBUG:
            if (!Console::DEBUG)
                return;
            break;
        case LEVELS::WARNING:
            if (!Console::WARNING)
                return;
            break;
        case LEVELS::SUCCESS:
            if (!Console::SUCCESS)
                return;
            break;
        case LEVELS::ERROR:
            if (!Console::ERROR)
                return;
            break;
    }

    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(COLOR);
            cout << PREFIX << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(COLOR) << PREFIX << str << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(COLOR) << PREFIX << str << Console::PARSE_COLOR() << endl;
            break;
    }
}

void Console::LOG(LEVELS LEVEL, COLORS COLOR, const char *PREFIX, double str) {
    if (!Console::LOGGING)
        return;

    switch (LEVEL) {
        case LEVELS::INFO:
            if (!Console::INFO)
                return;
            break;
        case LEVELS::DEBUG:
            if (!Console::DEBUG)
                return;
            break;
        case LEVELS::WARNING:
            if (!Console::WARNING)
                return;
            break;
        case LEVELS::SUCCESS:
            if (!Console::SUCCESS)
                return;
            break;
        case LEVELS::ERROR:
            if (!Console::ERROR)
                return;
            break;
    }

    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(COLOR);
            cout << PREFIX << str << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(COLOR) << PREFIX << str << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(COLOR) << PREFIX << str << Console::PARSE_COLOR() << endl;
            break;
    }
}

void Console::LOG(LEVELS LEVEL, COLORS COLOR, const char *PREFIX, bool str) {
    if (!Console::LOGGING)
        return;

    switch (LEVEL) {
        case LEVELS::INFO:
            if (!Console::INFO)
                return;
            break;
        case LEVELS::DEBUG:
            if (!Console::DEBUG)
                return;
            break;
        case LEVELS::WARNING:
            if (!Console::WARNING)
                return;
            break;
        case LEVELS::SUCCESS:
            if (!Console::SUCCESS)
                return;
            break;
        case LEVELS::ERROR:
            if (!Console::ERROR)
                return;
            break;
    }

    switch (Console::SYSTEM) {
        case SYSTEMS::WINDOWS:
            Console::SET_COLOR(COLOR);
            cout << PREFIX << (str ? "TRUE" : "FALSE") << endl;
            Console::SET_COLOR();
            break;
        case SYSTEMS::LINUX:
            cout << Console::PARSE_COLOR(COLOR) << PREFIX << (str ? "TRUE" : "FALSE") << Console::PARSE_COLOR() << endl;
            break;
        case SYSTEMS::MAC:
            cout << Console::PARSE_COLOR(COLOR) << PREFIX << (str ? "TRUE" : "FALSE") << Console::PARSE_COLOR() << endl;
            break;
    }
}

void Console::setSystem(SYSTEMS system) {
    Console::SYSTEM = system;
}

void Console::setLogging(bool logging) {
    Console::LOGGING = logging;
}

void Console::setLoggingLevel(LEVELS level, bool logging) {
    switch (level) {
        case LEVELS::INFO:
            Console::INFO = logging;
            break;
        case LEVELS::DEBUG:
            Console::DEBUG = logging;
            break;
        case LEVELS::WARNING:
            Console::WARNING = logging;
            break;
        case LEVELS::SUCCESS:
            Console::SUCCESS = logging;
            break;
        case LEVELS::ERROR:
            Console::ERROR = logging;
            break;
    }
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
    Console::LOG(LEVELS::INFO, COLORS::DEFAULT, "[INFO]: ", str);
}

void Console::info(int str) {
    Console::LOG(LEVELS::INFO, COLORS::DEFAULT, "[INFO]: ", str);
}

void Console::info(double str) {
    Console::LOG(LEVELS::INFO, COLORS::DEFAULT, "[INFO]: ", str);
}

void Console::info(bool str) {
    Console::LOG(LEVELS::INFO, COLORS::DEFAULT, "[INFO]: ", str);
}

void Console::debug(const char *str) {
    Console::LOG(LEVELS::DEBUG, COLORS::BLUE, "[DEBUG]: ", str);
}

void Console::debug(int str) {
    Console::LOG(LEVELS::DEBUG, COLORS::BLUE, "[DEBUG]: ", str);
}

void Console::debug(double str) {
    Console::LOG(LEVELS::DEBUG, COLORS::BLUE, "[DEBUG]: ", str);
}

void Console::debug(bool str) {
    Console::LOG(LEVELS::DEBUG, COLORS::BLUE, "[DEBUG]: ", str);
}

void Console::warning(const char *str) {
    Console::LOG(LEVELS::WARNING, COLORS::YELLOW, "[WARNING]: ", str);
}

void Console::warning(int str) {
    Console::LOG(LEVELS::WARNING, COLORS::YELLOW, "[WARNING]: ", str);
}

void Console::warning(double str) {
    Console::LOG(LEVELS::WARNING, COLORS::YELLOW, "[WARNING]: ", str);
}

void Console::warning(bool str) {
    Console::LOG(LEVELS::WARNING, COLORS::YELLOW, "[WARNING]: ", str);
}

void Console::error(const char *str) {
    Console::LOG(LEVELS::ERROR, COLORS::RED, "[ERROR]: ", str);
}

void Console::error(int str) {
    Console::LOG(LEVELS::ERROR, COLORS::RED, "[ERROR]: ", str);
}

void Console::error(double str) {
    Console::LOG(LEVELS::ERROR, COLORS::RED, "[ERROR]: ", str);
}

void Console::error(bool str) {
    Console::LOG(LEVELS::ERROR, COLORS::RED, "[ERROR]: ", str);
}

void Console::success(const char *str) {
    Console::LOG(LEVELS::SUCCESS, COLORS::GREEN, "[SUCCESS]: ", str);
}

void Console::success(int str) {
    Console::LOG(LEVELS::SUCCESS, COLORS::GREEN, "[SUCCESS]: ", str);
}

void Console::success(double str) {
    Console::LOG(LEVELS::SUCCESS, COLORS::GREEN, "[SUCCESS]: ", str);
}

void Console::success(bool str) {
    Console::LOG(LEVELS::SUCCESS, COLORS::GREEN, "[SUCCESS]: ", str);
}

