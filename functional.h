//
// Created by Islombek on 08.10.2021.
//

#ifndef __functional__
#define __functional__


#include "utils.h"
#include "languages.h"

// Функциональный
class functional : public languages {
public:
    ~functional() override = default;

    // Ввод параметров из файла
    void in(FILE *file) override;

    // Случайный ввод параметров
    void inRnd() override;

    // Вывод параметров в форматируемый поток
    void out(FILE *file) override;

    double quotient() override;

private:
    const char *name;
    int age;
    double popularity;
    bool lazy_calculation;
    enum {
        DYNAMIC, STRICT, ERROR
    };
    int type;
};

#endif //__functional__
