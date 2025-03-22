#ifndef ALLDISHINFO_H
#define ALLDISHINFO_H

#include "Dish.h"
#include <QStringListModel>
#include <QWidget>
#include "ui_alldishinfo.h"
#include "Tools.h"

#include "addnewdish.h"

namespace Ui {
class AllDishInfo;
}

class AllDishInfo : public QWidget
{
    Q_OBJECT

public:
    explicit AllDishInfo(QWidget *parent = nullptr);
    ~AllDishInfo();

private slots:
    void on_addDishButton_clicked();

    void on_pushButton_clicked();

    void on_deleteButton_clicked();

    void receiveNewDish(Dish newDish);

    void on_editButton_clicked();

    void receiveEditFinished(Dish dish);

signals:
    void emitEditDishInfo(Dish dish);

private:
    Ui::AllDishInfo *ui;

    QStringListModel *stringModel;
};

#endif // ALLDISHINFO_H
