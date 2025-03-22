#include "addnewdish.h"
#include "Dish.h"
#include "ui_addnewdish.h"
#include "Tools.h"

AddNewDish::AddNewDish(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddNewDish)
{
    ui->setupUi(this);

    this->setWindowTitle("添加新菜品");
}

AddNewDish::~AddNewDish()
{
    delete ui;
}

void AddNewDish::on_dishNameEdit_cursorPositionChanged(int arg1, int arg2)
{

}


void AddNewDish::on_dishNameEdit_editingFinished()
{

}

void AddNewDish::on_pushButton_clicked()
{
    QString dishName = ui->dishNameEdit->text();
    double dishPrice = ui->dishPriceEdit->text().toDouble();

    DishKind dishKind = stringToDishKind(ui->dishKindBox->currentText());
    qDebug() << ui->dishKindBox->currentText();
    int id = -1;
    int i = 1;
    while (1) {
        QString path = "Json/" + dishKindToString(dishKind) + "/" + QString::number(i) + ".txt";
        QFile file(path);
        if (file.exists())
        {
            i++;
            continue;
        }
        else
        {
            id = i;
            break;
        }
    }
    Dish dish = Dish(id, dishName, dishPrice, dishKind);
    saveDish(dish, dishKind);
    emit editFinished(this->editDish);
    QMessageBox::about(this, "Prompt", "Dish save success");
    emit addFinished(dish);
    this->close();
}

void AddNewDish::on_pushButton_2_clicked()
{
    this->close();
}

void AddNewDish::receiveEditInfo(Dish dish)
{
    qDebug() << dish.getDishName() + " " + QString::number(dish.getPrice());
    ui->dishNameEdit->setText(dish.getDishName());
    ui->dishPriceEdit->setText(QString::number(dish.getPrice()));
    ui->dishKindBox->setCurrentText(dishKindToString(dish.getDishKind()));
    this->editDish = dish;
}
