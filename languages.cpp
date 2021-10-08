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
    }
    sp->In(file);
    return sp;
}

Languages *Languages::StaticInRnd() {
    Languages *language;
    int kind = Utils::randInt(1, 3);
    if (kind == 1) {
        language = new Procedural;
    } else if (kind == 2) {
        language = new ObjectOriented;
    } else {
        language = new Functional;
    }

    language->InRnd();
    return language;
}
