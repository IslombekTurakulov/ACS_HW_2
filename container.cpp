//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include <cstdio>
#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() : len{0} {}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    for (int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE *file) {
    while (!feof(file)) {
        if ((cont[len] = Languages::StaticIn(file)) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while (len < size) {
        if ((cont[len] = Languages::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(FILE *file) {
    fprintf(file, "Container contains %d elements.\n", len);

    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i + 1);
        cont[i]->Out(file);
    }
}


//------------------------------------------------------------------------------
// Сортировка прямым выбором минимума. Сортирует контейнер по убыванию
void Container::StraightSelectionSort() {
    for (int i = 0; i < len; ++i) {
        int min_index = i;
        for (int j = i; j < len; ++j) {
            if (cont[j]->Quotient() < cont[min_index]->Quotient()) {
                min_index = j;
            }
        }
        // мы нашли индекс минимального не отсортированного элемента
        Languages *tmp = cont[i];
        cont[i] = cont[min_index];
        cont[min_index] = tmp;
    }
}