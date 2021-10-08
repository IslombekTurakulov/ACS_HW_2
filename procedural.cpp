//
// Created by Islombek on 08.10.2021.
//

#include "procedural.h"

void Procedural::In(FILE *file) {
    name = Utils::readString(file);
    age = Utils::readInt(file);
    popularity = Utils::readDouble(file);
    has_abstract_variables = Utils::readInt(file) == 0;
}

void Procedural::InRnd() {
    name = Utils::randString(10);
    age = Utils::randInt(1940, 2021);
    popularity = (Utils::randInt(1940, 2021) % 100) * 4.2;
    has_abstract_variables = Utils::randInt(0, 2) == 0;
}

void Procedural::Out(FILE *file) {
    fprintf(
            file,
            "Procedural: name = %s, age = %i, popularity = %f, has abstract variables = %s, ",
            name,
            age,
            popularity,
            has_abstract_variables ? "TRUE " : "FALSE "
    );

    fprintf(file, "Optimal time = %lf.\n", Quotient());
}

//------------------------------------------------------------------------------
// Вычисление year / name.len
double Procedural::Quotient() {
    return static_cast<double>(age) / static_cast<double>(strlen(name));
}
