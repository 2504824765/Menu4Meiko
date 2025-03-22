#include "Dish.h"

QString Dish::getDishName()
{
    return this->dishName;
}

double Dish::getPrice()
{
    return this->price;
}

DishKind Dish::getDishKind()
{
    return this->dishKind;
}

int Dish::getId() {
    return this->id;
}

