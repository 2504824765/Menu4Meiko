/********************************************************************************
** Form generated from reading UI file 'addnewdish.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWDISH_H
#define UI_ADDNEWDISH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewDish
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *dishNameEdit;
    QLineEdit *dishPriceEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *dishKindBox;

    void setupUi(QWidget *AddNewDish)
    {
        if (AddNewDish->objectName().isEmpty())
            AddNewDish->setObjectName("AddNewDish");
        AddNewDish->resize(400, 300);
        pushButton = new QPushButton(AddNewDish);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 200, 100, 32));
        pushButton_2 = new QPushButton(AddNewDish);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 200, 100, 32));
        dishNameEdit = new QLineEdit(AddNewDish);
        dishNameEdit->setObjectName("dishNameEdit");
        dishNameEdit->setGeometry(QRect(10, 150, 113, 21));
        dishPriceEdit = new QLineEdit(AddNewDish);
        dishPriceEdit->setObjectName("dishPriceEdit");
        dishPriceEdit->setGeometry(QRect(140, 150, 113, 21));
        label = new QLabel(AddNewDish);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 120, 58, 16));
        label_2 = new QLabel(AddNewDish);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 120, 58, 16));
        label_3 = new QLabel(AddNewDish);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 120, 58, 16));
        dishKindBox = new QComboBox(AddNewDish);
        dishKindBox->addItem(QString());
        dishKindBox->addItem(QString());
        dishKindBox->addItem(QString());
        dishKindBox->setObjectName("dishKindBox");
        dishKindBox->setGeometry(QRect(270, 140, 121, 32));

        retranslateUi(AddNewDish);

        QMetaObject::connectSlotsByName(AddNewDish);
    } // setupUi

    void retranslateUi(QWidget *AddNewDish)
    {
        AddNewDish->setWindowTitle(QCoreApplication::translate("AddNewDish", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("AddNewDish", "\346\217\220\344\272\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddNewDish", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("AddNewDish", "\350\217\234\345\223\201\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("AddNewDish", "\344\273\267\346\240\274", nullptr));
        label_3->setText(QCoreApplication::translate("AddNewDish", "\350\217\234\346\240\267", nullptr));
        dishKindBox->setItemText(0, QCoreApplication::translate("AddNewDish", "Meat", nullptr));
        dishKindBox->setItemText(1, QCoreApplication::translate("AddNewDish", "Soup", nullptr));
        dishKindBox->setItemText(2, QCoreApplication::translate("AddNewDish", "Vegetable", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AddNewDish: public Ui_AddNewDish {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWDISH_H
