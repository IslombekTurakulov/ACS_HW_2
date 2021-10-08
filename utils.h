//
// Created by Islombek on 08.10.2021.
//

#ifndef __utils__
#define __utils__

#include <cstdlib>
#include <ctime>   // для функции time()
#include <cstring>
#include <cstdio>
#include <cstddef>

class Utils {
public:
    Utils() {
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    static int randInt(int first, int last) {
        return rand() % (first - last + 1) + last;
    }

    static char *randString(int len) {
        static const char numericalAlphabet[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";

        char *result = new char[len + 1];

        for (int i = 0; i < len; ++i) {
            result[i] = numericalAlphabet[rand() % (sizeof(numericalAlphabet) - 1)];
        }

        // Zero terminated string
        result[len] = 0;

        return result;
    }

    static char *readString(FILE *file) {
        char local[128] = {0};
        fscanf(file, "%s", local);

        char *result = (char *) malloc(strlen(local));
        strcpy(result, local);

        return result;
    }

    static int readInt(FILE *file) {
        int result;
        fscanf(file, "%d", &result);

        return result;
    }

    static double readDouble(FILE *file) {
        int result;
        fscanf(file, "%d", &result);

        return result;
    }
};
#endif //__utils__
