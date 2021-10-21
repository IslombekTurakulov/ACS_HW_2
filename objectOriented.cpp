//
// Created by Islombek on 08.10.2021.
//

#include "objectOriented.h"

void ObjectOriented::In(FILE *file) {
    name_ = Utils::readString(file);
    age_ = Utils::readInt(file);
    popularity_ = Utils::readDouble(file);
    has_abstract_variables_ = Utils::readInt(file) == 0;
    int kind = Utils::readInt(file);
    switch (kind) {
        case 0:
            type_ = SINGLE;
            break;
        case 1:
            type_ = INTERFACE;
            break;
        case 2:
            type_ = MULTIPLE;
            break;
        default:
            type_ = ERROR;
            break;
    }
}

void ObjectOriented::InRnd() {
    name_ = Utils::randString(10);
    age_ = Utils::randInt(1940, 2021);
    popularity_ = (Utils::randInt(0, 100) % 40) * 1.2 ;
    has_abstract_variables_ = Utils::randInt(0, 2) == 0;
    int kind = Utils::randInt(0, 3);
    if (kind == 0) {
        type_ = SINGLE;
    } else if (kind == 1) {
        type_ = INTERFACE;
    } else if (kind == 2) {
        type_ = MULTIPLE;
    }
}

void ObjectOriented::Out(FILE *file) {
    fprintf(
            file,
            "Object Oriented: name_ = %s, age_ = %i, popularity_ = %f, has abstract variables = %s, ",
            name_,
            age_,
            popularity_,
            has_abstract_variables_ ? "TRUE" : "FALSE"
    );

    if (type_ == SINGLE) {
        fprintf(file, "legacy = SINGLE. ");
    } else if (type_ == INTERFACE) {
        fprintf(file, "legacy = INTERFACE. ");
    } else if (type_ == MULTIPLE) {
        fprintf(file, "legacy = MULTIPLE. ");
    }

    fprintf(file, "Optimal time = %lf.\n", Quotient());
}

//------------------------------------------------------------------------------
// Вычисление year / name_.len
double ObjectOriented::Quotient() {
    return static_cast<double>(age_) / static_cast<double>(strlen(name_));
}

