//
// Created by Islombek on 08.10.2021.
//

#ifndef __languages__
#define __languages__

#include <cstdio>
#include "utils.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
class Languages {
public:
    virtual ~Languages() = default;;

    // Ввод обобщенной фигуры
    static Languages *StaticIn(FILE *file);

    // Ввод обобщенной фигуры
    virtual void In(FILE *file) = 0;

    // Случайный ввод обобщенной фигуры
    static Languages *StaticInRnd();

    // Виртуальный метод ввода случайной фигуры
    virtual void InRnd() = 0;

    // Вывод обобщенной фигуры
    virtual void Out(FILE *file) = 0;

    // Вычисление периметра обобщенной фигуры
    virtual double Quotient() = 0;
};

#endif //__languages__
