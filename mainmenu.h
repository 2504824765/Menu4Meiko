#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QStringListModel>
#include "Tools.h"
#include "alldishinfo.h"
#include "Dish.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainMenu;
}
QT_END_NAMESPACE

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    Status randomLunchDishes();
    Status randomDinnerDishes();

private slots:
    void on_allDishButton_clicked();

    void on_randomDishes_clicked();

    void on_loadAllDishesButton_clicked();

    void on_outputToExcel_clicked();

private:
    Ui::MainMenu *ui;

    QStringListModel *lunchStringModel;
    QStringListModel *dinnerStringModel;
};
#endif // MAINMENU_H
