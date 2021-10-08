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
    Languages *sp;
    int kind = Utils::readInt(file);
    switch (kind) {
        case 0:
            sp = new Procedural;
            break;
        case 1:
            sp = new ObjectOriented;
            break;
        case 2:
            sp = new Functional;
            break;
        default:
            sp = new Procedural;
            break;
    }
    sp->In(file);
    return sp;
}

Languages *Languages::StaticInRnd() {
    int kind = Utils::randInt(1, 4);
    Languages *language = nullptr;
    switch (kind) {
        case 1:
            language = new Procedural;
            break;
        case 2:
            language = new Functional;
            break;
        case 3:
            language = new ObjectOriented;
            break;
        default:
            break;
    }
    language->InRnd();
    return language;
}
