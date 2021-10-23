//
// Created by Islombek on 08.10.2021.
//

#ifndef __procedural__
#define __procedural__

#include "utils.h"
#include "languages.h"

// Объектно-ориентированный язык
class procedural : public languages {
public:
    ~procedural() override = default;

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
};

#endif //__procedural__
