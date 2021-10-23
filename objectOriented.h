//
// Created by Islombek on 08.10.2021.
//

#ifndef __objectOriented__
#define __objectOriented__

#include "utils.h"
#include "languages.h"

// Процедурный язык
class objectOriented : public languages {
public:
    ~objectOriented() override = default;

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
    bool has_abstract_variables;
    enum {
        SINGLE, MULTIPLE, INTERFACE, ERROR
    };
    int type;
};

#endif //__objectOriented__
