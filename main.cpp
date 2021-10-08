//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "container.h"

void first_error_message() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void second_error_message(int size) {
    printf("incorrect number of languages = %d. Set 0 < number <= 10000\n", size);
}

void third_error_message() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main() {
    char *argv[] = {"command", "-f",
                    R"(C:\Users\Islombek\CLionProjects\ACS-HW\ACS-HW-2\tests\procedural.txt)", \
                    R"(C:\Users\Islombek\CLionProjects\ACS-HW\ACS-HW-2\tests\procedural.out.txt)",
                    R"(C:\Users\Islombek\CLionProjects\ACS-HW\ACS-HW-2\tests\procedural_sorted.out.txt)"};
    printf("Start\n");
    Container c;

    if (!strcmp(argv[1], "-f")) {
        FILE *input = fopen(argv[2], "r");
        c.In(input);
        fclose(input);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            second_error_message(size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    } else {
        third_error_message();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE *first_output = fopen(argv[3], "w");
    fprintf(first_output, "Filled container:\n");
    c.Out(first_output);

    // The 2nd part of task
    FILE *second_output = fopen(argv[4], "w");
    fprintf(second_output, "Sorted container:\n");
    c.StraightSelectionSort();
    c.Out(second_output);

    printf("Stop\n");
    fclose(first_output);
    fclose(second_output);
    return 0;
}