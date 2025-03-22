#ifndef DISHKIND_H
#define DISHKIND_H
#include <qstring.h>

enum DishKind {
    Meat = 0,
    Soup = 1,
    Vegetable = 2
};

static QString dishKindToString(DishKind dishKind) {
    switch (dishKind) {
    case Meat:
        return "Meat";
        break;
    case Soup:
        return "Soup";
        break;
    case Vegetable:
        return "Vegetable";
        break;
    default:
        break;
    }
}

static DishKind stringToDishKind(QString string) {
    if (string == "Meat") {
        return Meat;
    } else if (string == "Soup") {
        return Soup;
    } else if (string == "Vegetable") {
        return Vegetable;
    }
}

#endif // DISHKIND_H
