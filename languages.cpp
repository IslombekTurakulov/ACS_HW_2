//
// Created by Islombek on 08.10.2021.
//
#include "languages.h"
#include "functional.h"
#include "objectOriented.h"
#include "procedural.h"

//------------------------------------------------------------------------------
// Ввод параметров языка из файла
languages *languages::StaticIn(FILE *file) {
    languages *sp = NULL;
    int kind = Utils::readInt(file);
    switch (kind) {
        case 0:
            sp = new functional;
            sp->in(file);
            break;
        case 1:
            sp = new objectOriented;
            sp->in(file);
            break;
        default:
            sp = new procedural;
            sp->in(file);
            break;
    }

    return sp;
}

languages *languages::StaticInRnd() {
    languages *language = NULL;
    int kind = Utils::randInt(1,3);
    if (kind != 1) {
        if (kind == 2) {
            language = new objectOriented;
            language->inRnd();
        } else {
            language = new functional;
            language->inRnd();
        }
    } else {
        language = new procedural;
        language->inRnd();
    }
    return language;
}
