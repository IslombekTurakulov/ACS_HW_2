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

    // Генерация случайного числа в заданном диапазоне

    static int randInt(int first, int last) {
        return rand() % (last - first + 1) + first;
    }

    static char *randString(int len) {
        static const char alphabet[] =
                "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
        char *result = new char[len + 1];

        for (int i = 0; i < len; ++i) {
            result[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
        }
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
        int result = 0;
        fscanf(file, "%d", &result);
        return result;
    }

    static double readDouble(FILE *file) {
        double result;
        fscanf(file, "%lf", &result);
        return result;
    }
};
#endif //__utils__
