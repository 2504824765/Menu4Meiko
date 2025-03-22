/********************************************************************************
** Form generated from reading UI file 'alldishinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLDISHINFO_H
#define UI_ALLDISHINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllDishInfo
{
public:
    QListView *allDishes;
    QPushButton *addDishButton;
    QPushButton *pushButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QLineEdit *meatEdit;
    QLineEdit *vegetableEdit;
    QLineEdit *soupEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *AllDishInfo)
    {
        if (AllDishInfo->objectName().isEmpty())
            AllDishInfo->setObjectName("AllDishInfo");
        AllDishInfo->resize(523, 403);
        allDishes = new QListView(AllDishInfo);
        allDishes->setObjectName("allDishes");
        allDishes->setGeometry(QRect(10, 10, 361, 381));
        addDishButton = new QPushButton(AllDishInfo);
        addDishButton->setObjectName("addDishButton");
        addDishButton->setGeometry(QRect(390, 210, 121, 31));
        pushButton = new QPushButton(AllDishInfo);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(420, 330, 51, 31));
        deleteButton = new QPushButton(AllDishInfo);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(410, 290, 71, 32));
        editButton = new QPushButton(AllDishInfo);
        editButton->setObjectName("editButton");
        editButton->setGeometry(QRect(420, 250, 51, 32));
        meatEdit = new QLineEdit(AllDishInfo);
        meatEdit->setObjectName("meatEdit");
        meatEdit->setGeometry(QRect(410, 50, 71, 21));
        vegetableEdit = new QLineEdit(AllDishInfo);
        vegetableEdit->setObjectName("vegetableEdit");
        vegetableEdit->setGeometry(QRect(410, 110, 71, 21));
        soupEdit = new QLineEdit(AllDishInfo);
        soupEdit->setObjectName("soupEdit");
        soupEdit->setGeometry(QRect(410, 170, 71, 21));
        label = new QLabel(AllDishInfo);
        label->setObjectName("label");
        label->setGeometry(QRect(420, 30, 58, 16));
        label_2 = new QLabel(AllDishInfo);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(420, 90, 58, 16));
        label_3 = new QLabel(AllDishInfo);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(430, 150, 41, 16));

        retranslateUi(AllDishInfo);

        QMetaObject::connectSlotsByName(AllDishInfo);
    } // setupUi

    void retranslateUi(QWidget *AllDishInfo)
    {
        AllDishInfo->setWindowTitle(QCoreApplication::translate("AllDishInfo", "Form", nullptr));
        addDishButton->setText(QCoreApplication::translate("AllDishInfo", "Add a New Dish", nullptr));
        pushButton->setText(QCoreApplication::translate("AllDishInfo", "\350\277\224\345\233\236", nullptr));
        deleteButton->setText(QCoreApplication::translate("AllDishInfo", "Delete", nullptr));
        editButton->setText(QCoreApplication::translate("AllDishInfo", "Edit", nullptr));
        label->setText(QCoreApplication::translate("AllDishInfo", "\350\215\244\350\217\234\346\225\260\351\207\217", nullptr));
        label_2->setText(QCoreApplication::translate("AllDishInfo", "\347\264\240\350\217\234\346\225\260\351\207\217", nullptr));
        label_3->setText(QCoreApplication::translate("AllDishInfo", "\346\261\244\346\225\260\351\207\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllDishInfo: public Ui_AllDishInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLDISHINFO_H
