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

    static bool LOGGING;

    static bool INFO;

    static bool DEBUG;

    static bool WARNING;

    static bool SUCCESS;

    static bool ERROR;

    static void SET_COLOR(COLORS color = COLORS::DEFAULT);

    static const char *PARSE_COLOR(COLORS color = COLORS::DEFAULT);

public:

    static void setSystem(SYSTEMS system = SYSTEMS::WINDOWS);

    static void setLogging(bool logging = true);

    static void setInfo(bool info = true);

    static void setDebug(bool debug = true);

    static void setWarning(bool warning = true);

    static void setSuccess(bool success = true);

    static void setError(bool error = true);

    static void clear();

    static void print(int str, COLORS color = COLORS::DEFAULT);

    static void println(int str, COLORS color = COLORS::DEFAULT);

    static void print(double str, COLORS color = COLORS::DEFAULT);

    static void println(double str, COLORS color = COLORS::DEFAULT);

    static void print(bool str, COLORS color = COLORS::DEFAULT);

    static void println(bool str, COLORS color = COLORS::DEFAULT);

    static void print(const char *str, COLORS color = COLORS::DEFAULT);

    static void println(const char *str = "", COLORS color = COLORS::DEFAULT);

    static void info(const char *str);

    static void info(int str);

    static void info(double str);

    static void info(bool str);

    static void debug(const char *str);

    static void debug(int str);

    static void debug(double str);

    static void debug(bool str);

    static void warning(const char *str);

    static void warning(int str);

    static void warning(double str);

    static void warning(bool str);

    static void error(const char *str);

    static void error(int str);

    static void error(double str);

    static void error(bool str);

    static void success(const char *str);

    static void success(int str);

    static void success(double str);

    static void success(bool str);
};

#endif //LAB2_3_CONSOLE_H
