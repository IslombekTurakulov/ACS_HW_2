//
// Created by Islombek on 08.10.2021.
//

#include "procedural.h"

void procedural::in(FILE *file) {
    name = Utils::readString(file);
    age = Utils::readInt(file);
    popularity = Utils::readDouble(file);
    has_abstract_variables = Utils::readInt(file) == 0;
}

void procedural::inRnd() {
    name = Utils::randString(10);
    age = Utils::randInt(1940, 2021);
    popularity = (Utils::randInt(0, 100) % 40) * 1.2 ;
    has_abstract_variables = Utils::randInt(0, 2) == 0;
}

void procedural::out(FILE *file) {
    fprintf(
            file,
            "procedural: name = %s, age = %i, popularity = %f, has abstract variables = %s, ",
            name,
            age,
            popularity,
            has_abstract_variables ? "TRUE " : "FALSE "
    );

    fprintf(file, "quotient = %lf.\n", quotient());
}

//------------------------------------------------------------------------------
// Вычисление year / name.len
double procedural::quotient() {
    return static_cast<double>(age) / static_cast<double>(strlen(name));
}
