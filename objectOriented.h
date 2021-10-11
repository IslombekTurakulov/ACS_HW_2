//
// Created by Islombek on 08.10.2021.
//

#ifndef __objectOriented__
#define __objectOriented__

#include "utils.h"
#include "languages.h"

// Процедурный язык
class ObjectOriented : public Languages {
public:
    ~ObjectOriented() override = default;

    // Ввод параметров из файла
    void In(FILE *file) override;

    // Случайный ввод параметров
    void InRnd() override;

    // Вывод параметров в форматируемый поток
    void Out(FILE *file) override;

    double Quotient() override;

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
