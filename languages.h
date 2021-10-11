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
class Languages {
public:
    virtual ~Languages() = default;

    // Ввод обобщенного языка
    static Languages *StaticIn(FILE *file);

    // Ввод обобщенного языка
    virtual void In(FILE *file) = 0;

    // Случайный ввод обобщенного языка
    static Languages *StaticInRnd();

    // Виртуальный метод ввода случайного языка
    virtual void InRnd() = 0;

    // Вывод обобщенной фигуры
    virtual void Out(FILE *file) = 0;

    // Вычисление периметра обобщенной фигуры
    virtual double Quotient() = 0;
};

#endif //__languages__
