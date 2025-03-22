/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QLabel *label;
    QListView *menuListView;
    QPushButton *allDishButton;
    QPushButton *randomDishes;
    QPushButton *loadAllDishesButton;
    QListView *dinnerListView;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *outputToExcel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *countEdit;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(800, 600);
        label = new QLabel(MainMenu);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 0, 91, 61));
        menuListView = new QListView(MainMenu);
        menuListView->setObjectName("menuListView");
        menuListView->setGeometry(QRect(30, 70, 371, 391));
        allDishButton = new QPushButton(MainMenu);
        allDishButton->setObjectName("allDishButton");
        allDishButton->setGeometry(QRect(550, 500, 101, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(13);
        allDishButton->setFont(font);
        randomDishes = new QPushButton(MainMenu);
        randomDishes->setObjectName("randomDishes");
        randomDishes->setGeometry(QRect(130, 510, 101, 31));
        randomDishes->setFont(font);
        loadAllDishesButton = new QPushButton(MainMenu);
        loadAllDishesButton->setObjectName("loadAllDishesButton");
        loadAllDishesButton->setGeometry(QRect(340, 500, 100, 32));
        dinnerListView = new QListView(MainMenu);
        dinnerListView->setObjectName("dinnerListView");
        dinnerListView->setGeometry(QRect(405, 70, 371, 391));
        label_2 = new QLabel(MainMenu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 20, 91, 61));
        label_3 = new QLabel(MainMenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(530, 20, 91, 61));
        outputToExcel = new QPushButton(MainMenu);
        outputToExcel->setObjectName("outputToExcel");
        outputToExcel->setGeometry(QRect(340, 470, 100, 32));
        widget = new QWidget(MainMenu);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 490, 121, 23));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        countEdit = new QLineEdit(widget);
        countEdit->setObjectName("countEdit");

        horizontalLayout->addWidget(countEdit);


        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainMenu", nullptr));
        label->setText(QCoreApplication::translate("MainMenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\350\217\234\345\215\225</span></p></body></html>", nullptr));
        allDishButton->setText(QCoreApplication::translate("MainMenu", "\346\211\200\346\234\211\350\217\234\345\223\201\344\277\241\346\201\257", nullptr));
        randomDishes->setText(QCoreApplication::translate("MainMenu", "\347\224\237\346\210\220\351\232\217\346\234\272\350\217\234\345\223\201", nullptr));
        loadAllDishesButton->setText(QCoreApplication::translate("MainMenu", "Load Dishes", nullptr));
        label_2->setText(QCoreApplication::translate("MainMenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\345\215\210\351\244\220</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainMenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\346\231\232\351\244\220</span></p></body></html>", nullptr));
        outputToExcel->setText(QCoreApplication::translate("MainMenu", "\350\276\223\345\207\272\345\210\260excel", nullptr));
        label_4->setText(QCoreApplication::translate("MainMenu", "\347\224\237\346\210\220\346\225\260\351\207\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
