//
// Created by Islombek on 08.10.2021.
//

#ifndef __languages__
#define __languages__

#include <cstdio>
#include "languages.h"
#include "utils.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся языки
class languages {
public:
    virtual ~languages() = default;

    // Ввод обобщенного языка
    static languages *StaticIn(FILE *file);

    // Ввод обобщенного языка
    virtual void in(FILE *file) = 0;

    // Случайный ввод обобщенного языка
    static languages *StaticInRnd();

    // Виртуальный метод ввода случайного языка
    virtual void inRnd() = 0;

    // Вывод обобщенной фигуры
    virtual void out(FILE *file) = 0;

    // Вычисление периметра обобщенной фигуры
    virtual double quotient() = 0;
};

#endif //__languages__
