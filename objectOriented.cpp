//
// Created by Islombek on 08.10.2021.
//

#include "objectOriented.h"

void ObjectOriented::In(FILE *file) {
    name = Utils::readString(file);
    age = Utils::readInt(file);
    popularity = Utils::readDouble(file);
    has_abstract_variables = Utils::readInt(file) == 0;
    int kind = Utils::readInt(file);
    switch (kind) {
        case 0:
            type = SINGLE;
            break;
        case 1:
            type = INTERFACE;
            break;
        case 2:
            type = MULTIPLE;
            break;
        default:
            type = ERROR;
            break;
    }
}

void ObjectOriented::InRnd() {
    name = Utils::randString(10);
    age = Utils::randInt(1940, 2021);
    popularity = (Utils::randInt(0, 100) % 40) * 1.2 ;
    has_abstract_variables = Utils::randInt(0, 2) == 0;
    int kind = Utils::randInt(0, 3);
    if (kind == 0) {
        type = SINGLE;
    } else if (kind == 1) {
        type = INTERFACE;
    } else if (kind == 2) {
        type = MULTIPLE;
    }
}

void ObjectOriented::Out(FILE *file) {
    fprintf(
            file,
            "Object Oriented: name = %s, age = %i, popularity = %f, has abstract variables = %s, ",
            name,
            age,
            popularity,
            has_abstract_variables ? "TRUE" : "FALSE"
    );

    if (type == SINGLE) {
        fprintf(file, "legacy = SINGLE. ");
    } else if (type == INTERFACE) {
        fprintf(file, "legacy = INTERFACE. ");
    } else if (type == MULTIPLE) {
        fprintf(file, "legacy = MULTIPLE. ");
    }

    fprintf(file, "Optimal time = %lf.\n", Quotient());
}

//------------------------------------------------------------------------------
// Вычисление year / name.len
double ObjectOriented::Quotient() {
    return static_cast<double>(age) / static_cast<double>(strlen(name));
}

