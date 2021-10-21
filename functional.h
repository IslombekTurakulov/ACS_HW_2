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

    // Ввод параметров из файла
    void In(FILE *file) override;

    // Случайный ввод параметров
    void InRnd() override;

    // Вывод параметров в форматируемый поток
    void Out(FILE *file) override;

    double Quotient() override;

private:
    const char *name_;
    int age_;
    double popularity_;
    bool lazy_calculation_;
    enum {
        DYNAMIC, STRICT, ERROR
    };
    int type_;
};

#endif //__functional__
