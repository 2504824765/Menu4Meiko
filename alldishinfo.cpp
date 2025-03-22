#include "alldishinfo.h"


AllDishInfo::AllDishInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AllDishInfo)
{
    ui->setupUi(this);

    ui->meatEdit->setText(QString::number(getNumberOfDishes(Meat)));
    ui->meatEdit->setReadOnly(true);
    ui->vegetableEdit->setText(QString::number(getNumberOfDishes(Vegetable)));
    ui->vegetableEdit->setReadOnly(true);
    ui->soupEdit->setText(QString::number(getNumberOfDishes(Soup)));
    ui->soupEdit->setReadOnly(true);

    this->setWindowTitle("所有菜品信息");
    //设置ListView不可编辑
    ui->allDishes->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //bind QStringListModel with QListView
    this->stringModel = new QStringListModel(ui->allDishes);
    ui->allDishes->setModel(stringModel);
    this->setWindowTitle("菜品信息");
    QString head = "ID\t菜品\t价格\t菜样";
    this->stringModel->setStringList(QStringList()
                                     << head);
    QString dishInfo = "";
    int numberOfMainCourse = getNumberOfDishes(Meat);
    for (int i = 1; i <= numberOfMainCourse; ++i) {
        Dish dish = loadDishes(Meat, i);
        if (dish.getDishName() == "NULL") {
            numberOfMainCourse++;
            continue;
        }
        dishInfo = QString::number(dish.getId()) + "\t" + dish.getDishName() + "\t" + QString::number(dish.getPrice()) + "\t" + dishKindToString(dish.getDishKind());
        //添加进ListView
        stringModel->insertRow(stringModel->rowCount());
        QModelIndex index = stringModel->index(stringModel->rowCount()-1, 0);
        stringModel->setData(index, dishInfo, Qt::DisplayRole);
    }
    int numberOfFruits = getNumberOfDishes(Vegetable);
    for (int i = 1; i <= numberOfFruits; ++i) {
        Dish dish = loadDishes(Vegetable, i);
        if (dish.getDishName() == "NULL") {
            numberOfFruits++;
            continue;
        }
        dishInfo = QString::number(dish.getId()) + "\t" + dish.getDishName() + "\t" + QString::number(dish.getPrice()) + "\t" + dishKindToString(dish.getDishKind());
        //添加进ListView
        stringModel->insertRow(stringModel->rowCount());
        QModelIndex index = stringModel->index(stringModel->rowCount()-1, 0);
        stringModel->setData(index, dishInfo, Qt::DisplayRole);
    }
    int numberOfSoup = getNumberOfDishes(Soup);
    for (int i = 1; i <= numberOfSoup; ++i) {
        Dish dish = loadDishes(Soup, i);
        if (dish.getDishName() == "NULL") {
            numberOfSoup++;
            continue;
        }
        dishInfo = QString::number(dish.getId()) + "\t" + dish.getDishName() + "\t" + QString::number(dish.getPrice()) + "\t" + dishKindToString(dish.getDishKind());
        //添加进ListView
        stringModel->insertRow(stringModel->rowCount());
        QModelIndex index = stringModel->index(stringModel->rowCount()-1, 0);
        stringModel->setData(index, dishInfo, Qt::DisplayRole);
    }
}

AllDishInfo::~AllDishInfo()
{
    delete ui;
}

void AllDishInfo::on_addDishButton_clicked()
{
    AddNewDish *addNewDish = new AddNewDish();
    connect(addNewDish, &AddNewDish::addFinished, this, &AllDishInfo::receiveNewDish);
    addNewDish->show();
}


void AllDishInfo::on_pushButton_clicked()
{
    this->close();
}


void AllDishInfo::on_deleteButton_clicked()
{
    QString selectedStr = ui->allDishes->currentIndex().data().toString();
    if (selectedStr.startsWith("ID")) {
        QMessageBox::about(this, "提示", "这是表头！");
        return;
    }
    QStringList words = selectedStr.split("\t");
    int id = words.at(0).toInt();
    QString dishName = words.at(1);
    double dishPrice = words.at(2).toDouble();
    DishKind dishKind = stringToDishKind(words.at(3));
    if (deleteDish(Dish(id, dishName, dishPrice, dishKind)) == Success) {
        QMessageBox::about(this, "Prompt", "Delete Successfully");
    }
    stringModel->removeRows(ui->allDishes->currentIndex().row(), 1);
}

void AllDishInfo::receiveNewDish(Dish newDish)
{
    QString dishInfo = QString::number(newDish.getId()) + "\t" + newDish.getDishName() + "\t" + QString::number(newDish.getPrice()) + "\t" + dishKindToString(newDish.getDishKind());

    stringModel->insertRow(stringModel->rowCount());
    QModelIndex index = stringModel->index(stringModel->rowCount()-1, 0);
    stringModel->setData(index, dishInfo, Qt::DisplayRole);
}

void AllDishInfo::on_editButton_clicked()
{
    QString selectedStr = ui->allDishes->currentIndex().data().toString();
    if (selectedStr.startsWith("ID")) {
        QMessageBox::about(this, "提示", "这是表头！");
        return;
    }
    QStringList words = selectedStr.split("\t");
    int id = words.at(0).toInt();
    QString dishName = words.at(1);
    double dishPrice = words.at(2).toDouble();
    DishKind dishKind = stringToDishKind(words.at(3));
    Dish targetDish = Dish(id, dishName, dishPrice, dishKind);

    AddNewDish *addNewDish = new AddNewDish();
    connect(addNewDish, &AddNewDish::addFinished, this, &AllDishInfo::receiveNewDish);
    connect(this, &AllDishInfo::emitEditDishInfo, addNewDish, &AddNewDish::receiveEditInfo);
    connect(addNewDish, &AddNewDish::editFinished, this, &AllDishInfo::receiveEditFinished);
    emit emitEditDishInfo(targetDish);
    addNewDish->show();
}

void AllDishInfo::receiveEditFinished(Dish dish)
{
    deleteDish(dish);
    stringModel->removeRows(ui->allDishes->currentIndex().row(), 1);

}
