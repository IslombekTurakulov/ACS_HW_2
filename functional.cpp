//
// Created by Islombek on 08.10.2021.
//

#include "functional.h"

void functional::in(FILE *file) {
    name = Utils::readString(file);
    age = Utils::readInt(file);
    popularity = Utils::readDouble(file);
    lazy_calculation = Utils::readInt(file) == 0;
    int kind = Utils::readInt(file);

    switch (kind) {
        case 1:
            type = DYNAMIC;
            break;
        case 2:
            type = STRICT;
            break;
        default:
            type = ERROR;
            break;
    }
}

void functional::inRnd() {
    name = Utils::randString(10);
    age = Utils::randInt(1940, 2021);
    popularity = (Utils::randInt(0, 100) % 40) * 1.2 ;
    lazy_calculation = Utils::randInt(0, 2) == 0;
    int kind = Utils::randInt(1, 3);

    if (kind == 1) {
        type = DYNAMIC;
    } else if (kind == 2) {
        type = STRICT;
    }
}

void functional::out(FILE *file) {
    fprintf(
            file,
            "functional: name = %s, age = %i, popularity = %f, lazy calculation = %s, ",
            name,
            age,
            popularity,
            lazy_calculation ? "TRUE " : "FALSE"
    );

    if (type == DYNAMIC) {
        fprintf(file, "type = DYNAMIC. ");
    } else if (type == STRICT) {
        fprintf(file, "type = STRICT. ");
    }

    fprintf(file, "quotient = %lf.\n", quotient());
}

//------------------------------------------------------------------------------
// Вычисление year / name.len
double functional::quotient() {
    return static_cast<double>(age) / static_cast<double>(strlen(name));
}
