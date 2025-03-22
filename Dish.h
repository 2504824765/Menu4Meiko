#ifndef DISH_H
#define DISH_H
#include "DishKind.h"
#include <QString>
#include <QMessageBox>

class Dish
{
public:
    Dish()
    {
        this->id = -1;
        this->dishName = "NULL";
        this->price = -1;
        this->dishKind = Meat;
    }

    QString getDishName();
    double getPrice();
    DishKind getDishKind();
    int getId();

    Dish(int id, QString name, double price, int dishKindInt)
    {
        this->id = id;
        this->dishName = name;
        this->price = price;
        this->dishKind = static_cast<DishKind>(dishKindInt);
    }

    void printDish()
    {
        qDebug() <<"dishID: " + QString::number(this->id) + "; dishName: " + dishName + "; dishPrice: " + QString::number(this->price) + "; dishKind: " + dishKindToString(this->dishKind);
    }
private:
    QString dishName;
    double price;
    DishKind dishKind;
    int id;
};

#endif // DISH_H
