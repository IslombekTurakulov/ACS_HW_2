//
// Created by Islombek on 08.10.2021.
//

#include "procedural.h"

void Procedural::In(FILE *file) {
    name_ = Utils::readString(file);
    age_ = Utils::readInt(file);
    popularity_ = Utils::readDouble(file);
    has_abstract_variables_ = Utils::readInt(file) == 0;
}

void Procedural::InRnd() {
    name_ = Utils::randString(10);
    age_ = Utils::randInt(1940, 2021);
    popularity_ = (Utils::randInt(0, 100) % 40) * 1.2 ;
    has_abstract_variables_ = Utils::randInt(0, 2) == 0;
}

void Procedural::Out(FILE *file) {
    fprintf(
            file,
            "Procedural: name_ = %s, age_ = %i, popularity_ = %f, has abstract variables = %s, ",
            name_,
            age_,
            popularity_,
            has_abstract_variables_ ? "TRUE " : "FALSE "
    );

    fprintf(file, "Optimal time = %lf.\n", Quotient());
}

//------------------------------------------------------------------------------
// Вычисление year / name_.len
double Procedural::Quotient() {
    return static_cast<double>(age_) / static_cast<double>(strlen(name_));
}
