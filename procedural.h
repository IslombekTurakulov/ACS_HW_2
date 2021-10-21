//
// Created by Islombek on 08.10.2021.
//

#ifndef __procedural__
#define __procedural__

#include "utils.h"
#include "languages.h"

// Объектно-ориентированный язык
class Procedural : public Languages {
public:
    ~Procedural() override = default;

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
    bool has_abstract_variables_;
};

#endif //__procedural__
