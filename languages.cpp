//
// Created by Islombek on 08.10.2021.
//
#include "languages.h"
#include "functional.h"
#include "objectOriented.h"
#include "procedural.h"

//------------------------------------------------------------------------------
// Ввод параметров языка из файла
Languages *Languages::StaticIn(FILE *file) {
    Languages *sp = NULL;
    int kind = Utils::readInt(file);
    switch (kind) {
        case 0:
            sp = new Functional;
            sp->In(file);
            break;
        case 1:
            sp = new ObjectOriented;
            sp->In(file);
            break;
        default:
            sp = new Procedural;
            sp->In(file);
            break;
    }

    return sp;
}

Languages *Languages::StaticInRnd() {
    Languages *language = NULL;
    int kind = Utils::randInt(1,3);
    if (kind != 1) {
        if (kind == 2) {
            language = new ObjectOriented;
            language->InRnd();
        } else {
            language = new Functional;
            language->InRnd();
        }
    } else {
        language = new Procedural;
        language->InRnd();
    }
    return language;
}
