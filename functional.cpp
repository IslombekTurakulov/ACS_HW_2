//
// Created by Islombek on 08.10.2021.
//

#include "functional.h"

void Functional::In(FILE *file) {
    name_ = Utils::readString(file);
    age_ = Utils::readInt(file);
    popularity_ = Utils::readDouble(file);
    lazy_calculation_ = Utils::readInt(file) == 0;
    int kind = Utils::readInt(file);

    switch (kind) {
        case 1:
            type_ = DYNAMIC;
            break;
        case 2:
            type_ = STRICT;
            break;
        default:
            type_ = ERROR;
            break;
    }
}

void Functional::InRnd() {
    name_ = Utils::randString(10);
    age_ = Utils::randInt(1940, 2021);
    popularity_ = (Utils::randInt(0, 100) % 40) * 1.2 ;
    lazy_calculation_ = Utils::randInt(0, 2) == 0;
    int kind = Utils::randInt(1, 3);

    if (kind == 1) {
        type_ = DYNAMIC;
    } else if (kind == 2) {
        type_ = STRICT;
    }
}

void Functional::Out(FILE *file) {
    fprintf(
            file,
            "Functional: name_ = %s, age_ = %i, popularity_ = %f, lazy calculation = %s, ",
            name_,
            age_,
            popularity_,
            lazy_calculation_ ? "TRUE " : "FALSE"
    );

    if (type_ == DYNAMIC) {
        fprintf(file, "type_ = DYNAMIC. ");
    } else if (type_ == STRICT) {
        fprintf(file, "type_ = STRICT. ");
    }

    fprintf(file, "Optimal time = %lf.\n", Quotient());
}

//------------------------------------------------------------------------------
// Вычисление year / name_.len
double Functional::Quotient() {
    return static_cast<double>(age_) / static_cast<double>(strlen(name_));
}
