#ifndef ADDNEWDISH_H
#define ADDNEWDISH_H

#include "Dish.h"

#include <QWidget>

namespace Ui {
class AddNewDish;
}

class AddNewDish : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewDish(QWidget *parent = nullptr);
    ~AddNewDish();

private slots:
    void on_dishNameEdit_cursorPositionChanged(int arg1, int arg2);

    void on_dishNameEdit_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public slots:
    void receiveEditInfo(Dish dish);

signals:
    void addFinished(Dish dish);
    void editFinished(Dish dish);

private:
    Ui::AddNewDish *ui;

    Dish editDish;
};

#endif // ADDNEWDISH_H
