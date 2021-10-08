//
// Created by Islombek on 08.10.2021.
//

#ifndef __functional__
#define __functional__


#include "utils.h"
#include "languages.h"

// Функциональный
class Functional : public Languages {
public:
    ~Functional() override = default;

    // Ввод параметров прямоугольника из файла
    void In(FILE *file) override;

    // Случайный ввод параметров прямоугольника
    void InRnd() override;

    // Вывод параметров прямоугольника в форматируемый поток
    void Out(FILE *file) override;

    double Quotient() override;

private:
    const char *name;
    int age;
    double popularity;
    bool lazy_calculation;
    enum typing {
        DYNAMIC, STRICT, ERROR
    };
    typing type;
};

#endif //__functional__
