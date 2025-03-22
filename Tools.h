#ifndef TOOLS_H
#define TOOLS_H
#include "Dish.h"
#include "Status.h"

#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <Qdir>

static Status deleteDish(Dish dish);

static int getNumberOfDishes(DishKind dishKind) {
    QDir *dir = new QDir("Json/" + dishKindToString(dishKind));
    QStringList filter;
    filter << "*.txt";
    QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
    return fileInfo->count();
}

static Status saveDish(Dish dish, DishKind dishKind) {
    QJsonObject dishObject;
    dishObject.insert("dishName", dish.getDishName());
    dishObject.insert("price", dish.getPrice());
    dishObject.insert("dishKind", dish.getDishKind());
    QJsonDocument doc;
    doc.setObject(dishObject);

    QString path = "Json/" + dishKindToString(dishKind) + "/" + QString::number(dish.getId()) + ".txt";
    qDebug() << "Save location: " + path;

    //如果重复，先删除
    int numberOfDishes = getNumberOfDishes(dish.getDishKind());
    for (int i = 1; i <= numberOfDishes; ++i) {
        QString tempFilePath = "Json/" + dishKindToString(dishKind) + "/" + QString::number(i) + ".txt";
        QFile file(tempFilePath);
        if (!file.exists()) {
            numberOfDishes++;
            continue;
        } else {
            if (!file.open(QIODevice::ReadOnly)) {
                qDebug() << "Failed to open file while READING";
                return Failed;
            }
            QByteArray ba = file.readAll();
            QJsonParseError jsonParseError;
            QJsonDocument jsonDocument(QJsonDocument::fromJson(ba, &jsonParseError));
            if (QJsonParseError::NoError != jsonParseError.error)
            {
                qDebug() << QString("JsonParseError:%1").arg(jsonParseError.errorString());
            }
            QJsonObject rootObject = jsonDocument.object();
            QString dishName = rootObject.value("dishName").toString();
            if (dishName == dish.getDishName()) {
                deleteDish(dish);
                break;
            }
            file.close();
        }
    }

    qDebug() << QDir::currentPath();
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Failed to open file while WRITING" << file.errorString();
        return Failed;
    }
    if (!file.write(doc.toJson()))
    {
        qDebug() << "Failed to save file while WRITING" << file.errorString();
        return Failed;
    }
    qDebug() << "Write Success";
    file.close();
    return Success;
}

static Dish loadDishes(DishKind dishKind, int id) {
    QString path = "Json/" + dishKindToString(dishKind) + "/" + QString::number(id) + ".txt";
    qDebug() << "Load location: " + path;
    QFile file(path);
    if (!file.exists())
    {
        qDebug() << "ERROR: File doesn't exist when load dishes";
        return Dish();
    }
    if (file.isOpen())
    {
        qDebug() << "ERROR: File is opened when load dishes";
        return Dish();
    }
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "ERROR: Failed to open file when load dishes" << file.errorString();
        return Dish();
    }

    QByteArray ba = file.readAll();
    QJsonParseError jsonParseError;
    QJsonDocument jsonDocument(QJsonDocument::fromJson(ba, &jsonParseError));
    if (QJsonParseError::NoError != jsonParseError.error)
    {
        qDebug() << QString("JsonParseError:%1").arg(jsonParseError.errorString());
    }
    QJsonObject rootObject = jsonDocument.object();
    QString dishName = rootObject.value("dishName").toString();
    double dishPrice = rootObject.value("price").toDouble();
    Dish dish = Dish(id, dishName, dishPrice, dishKind);
    file.close();
    return dish;
}

static Status deleteDish(Dish dish) {
    QString path = "Json/" + dishKindToString(dish.getDishKind()) + "/" + QString::number(dish.getId()) + ".txt";
    QFileInfo fileInfo(path);
    if (fileInfo.isFile()) {
        QFile::remove(path);
        return Success;
    } else {
        return Failed;
    }
}

static Status loadAllDishes(QString filePath) {
    qDebug() << "-----Load All Dishes-----";
    QFile file(filePath);
    if (!file.exists()) {
        qDebug() << "Failed to open file while importing all dishes";
        return Failed;
    }
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file while importing all dishes";
        return Failed;
    }
    //如果导入的菜品已经重复则不导入
    QSet<QString> meatNames;
    QSet<QString> vegetableNames;
    QSet<QString> soupNames;
    int numberOfMeat = getNumberOfDishes(Meat);
    int numberOfVegetable = getNumberOfDishes(Vegetable);
    int numberOfSoup = getNumberOfDishes(Soup);
    for (int i = 1; i <= numberOfMeat; ++i) {
        QString path = "Json/Meat/" + QString::number(i) + ".txt";
        QFile file(path);
        if (!file.exists()) {
            i++;
            numberOfMeat++;
            continue;
        } else {
            Dish dish = loadDishes(Meat, i);
            meatNames.insert(dish.getDishName());
        }
    }
    qDebug() << meatNames;
    for (int i = 1; i <= numberOfVegetable; ++i) {
        QString path = "Json/Vegetable/" + QString::number(i) + ".txt";
        QFile file(path);
        if (!file.exists()) {
            i++;
            numberOfVegetable++;
            continue;
        } else {
            Dish dish = loadDishes(Vegetable, i);
            vegetableNames.insert(dish.getDishName());
        }
    }
    qDebug() << vegetableNames;
    for (int i = 1; i <= numberOfSoup; ++i) {
        QString path = "Json/Soup/" + QString::number(i) + ".txt";
        QFile file(path);
        if (!file.exists()) {
            i++;
            numberOfSoup++;
            continue;
        } else {
            Dish dish = loadDishes(Soup, i);
            soupNames.insert(dish.getDishName());
        }
    }
    qDebug() << soupNames;

    QTextStream in(&file);
    QStringList words;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        words = line.split(" ");
        QString dishName = words.at(0);
        DishKind dishKind = stringToDishKind(words.at(1));
        //重复不导入
        if (dishKind == Meat) {
            if (meatNames.contains(dishName)) {
                continue;
            }
        } else if (dishKind == Vegetable) {
            if (vegetableNames.contains(dishName)) {
                continue;
            }
        } else if (dishKind == Soup) {
            if (soupNames.contains(dishName)) {
                continue;
            }
        } else {
            qDebug() << "ERROR: Cannot identify the kind of the dish: " + dishName;
            continue;
        }
        double dishPrice = words.at(2).toDouble();
        int id = -1;
        int i = 1;
        while (1)
        {
            id = -1;
            QString path = "Json/" + dishKindToString(dishKind) + "/" + QString::number(i) + ".txt";
            QFile tempFile(path);
            if (tempFile.exists()) {
                i++;
                continue;
            } else {
                id = i;
                break;
            }
        }
        if (id == -1) {
            qDebug() << "Error: id == -1";
            return Failed;
        } else {
            Dish dish = Dish(id, dishName, dishPrice, dishKind);
            dish.printDish();
            saveDish(dish, dish.getDishKind());
        }
    }
    return Failed;
    file.close();
}

#endif // TOOLS_H
