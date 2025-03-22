#include "mainmenu.h"
#include "./ui_mainmenu.h"
#include <random>
#include <QDateTime>
#include <algorithm>
#include <vector>

#define RANDOMTIMES 1

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    this->setWindowTitle("菜品信息");
    //设置ListView不可编辑
    ui->menuListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //bind QStringListModel with QListView
    this->lunchStringModel = new QStringListModel(ui->menuListView);
    ui->menuListView->setModel(lunchStringModel);
    QString head = "序号\t主菜\t副菜\t汤";
    this->lunchStringModel->setStringList(QStringList()
                                     << head);

    ui->dinnerListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->dinnerStringModel = new QStringListModel(ui->dinnerListView);
    ui->dinnerListView->setModel(dinnerStringModel);
    this->dinnerStringModel->setStringList(QStringList()
                                           <<head);

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_allDishButton_clicked()
{
    AllDishInfo *alldishinfo = new AllDishInfo();
    alldishinfo->show();
}


void MainMenu::on_randomDishes_clicked()
{
    qDebug() << "-----生成随机菜单-----";
    for (int i = 0; i < RANDOMTIMES; ++i) {
        randomLunchDishes();
        randomDinnerDishes();
    }
}

void MainMenu::on_loadAllDishesButton_clicked()
{
    // QMessageBox::about(this, "提示", "请确保所选文件中的内容格式为”菜名 价格 菜样\"");
    QString filePath = QFileDialog::getOpenFileName(this, "Select a .txt file", "/", ".txt file(*.txt)");
    if (filePath.isEmpty()) {
        QMessageBox::about(this, "Prompt", "Please choose a .txt file");
        return;
    }
    qDebug() << "Selected file path: " + filePath;
    if (loadAllDishes(filePath) == Success) {
        QMessageBox::about(this, "Prompt", "Load all dishes success");
    }
}

Status MainMenu::randomLunchDishes() {
    int rowCount = lunchStringModel->rowCount();
    for (int i = rowCount - 1; i >= 1; --i) {
        lunchStringModel->removeRow(i);
    }
    int times = ui->countEdit->text().toInt();

    // 获取所有菜品ID
    int totalDishes = std::min({getNumberOfDishes(Meat), getNumberOfDishes(Vegetable), getNumberOfDishes(Soup)});
    std::vector<int> allMeatDishes, allVegetableDishes, allSoupDishes;

    // 获取所有荤菜、素菜和汤的ID
    for (int i = 1; i <= totalDishes; ++i) {
        allMeatDishes.push_back(i);
        allVegetableDishes.push_back(i);
        allSoupDishes.push_back(i);
    }

    // 使用当前时间作为随机种子
    std::seed_seq seed{
        static_cast<unsigned int>(QDateTime::currentMSecsSinceEpoch()),
        static_cast<unsigned int>(QCoreApplication::applicationPid())
    };
    std::knuth_b gen1(seed);

    if (times < 1) {
        QMessageBox::about(this, "提示", "请输入一个大于0的数字");
        return Failed;
    }
    if (times > totalDishes) {
        QMessageBox::about(this, "提示", "菜品数量不足以生成" + QString::number(times) + "个菜单");
        return Failed;
    }

    // 打乱荤菜、素菜、汤的顺序
    std::shuffle(allMeatDishes.begin(), allMeatDishes.end(), gen1);
    std::shuffle(allVegetableDishes.begin(), allVegetableDishes.end(), gen1);
    std::shuffle(allSoupDishes.begin(), allSoupDishes.end(), gen1);

    // 生成中餐菜单
    for (int i = 0; i < times; ++i) {
        // 从荤菜、素菜、汤中随机选择菜品
        int meatIndex = allMeatDishes[i % allMeatDishes.size()];
        int vegetableIndex = allVegetableDishes[i % allVegetableDishes.size()];
        int soupIndex = allSoupDishes[i % allSoupDishes.size()];

        // 加载菜品信息
        Dish meat = loadDishes(Meat, meatIndex);
        Dish vegetable = loadDishes(Vegetable, vegetableIndex);
        Dish soup = loadDishes(Soup, soupIndex);

        // 添加菜品到模型中
        QString dishInfo = QString::number(i + 1) + "\t" + meat.getDishName() + "\t" + vegetable.getDishName() + "\t" + soup.getDishName();
        lunchStringModel->insertRow(lunchStringModel->rowCount());
        QModelIndex index = lunchStringModel->index(lunchStringModel->rowCount() - 1, 0);
        lunchStringModel->setData(index, dishInfo, Qt::DisplayRole);
    }

    return Success;
}

Status MainMenu::randomDinnerDishes() {
    int rowCount = dinnerStringModel->rowCount();
    for (int i = rowCount - 1; i >= 1; --i) {
        dinnerStringModel->removeRow(i);
    }
    int times = ui->countEdit->text().toInt();

    // 获取所有菜品ID
    int totalDishes = std::min({getNumberOfDishes(Meat), getNumberOfDishes(Vegetable), getNumberOfDishes(Soup)});
    std::vector<int> allMeatDishes, allVegetableDishes, allSoupDishes;

    // 获取所有荤菜、素菜和汤的ID
    for (int i = 1; i <= totalDishes; ++i) {
        allMeatDishes.push_back(i);
        allVegetableDishes.push_back(i);
        allSoupDishes.push_back(i);
    }

    // 使用当前时间作为随机种子
    std::seed_seq seed{
        static_cast<unsigned int>(QDateTime::currentMSecsSinceEpoch()),
        static_cast<unsigned int>(QCoreApplication::applicationPid())
    };
    std::knuth_b gen1(seed);

    if (times < 1) {
        QMessageBox::about(this, "提示", "请输入一个大于0的数字");
        return Failed;
    }
    if (times > totalDishes) {
        QMessageBox::about(this, "提示", "菜品数量不足以生成" + QString::number(times) + "个菜单");
        return Failed;
    }

    // 打乱荤菜、素菜、汤的顺序
    std::shuffle(allMeatDishes.begin(), allMeatDishes.end(), gen1);
    std::shuffle(allVegetableDishes.begin(), allVegetableDishes.end(), gen1);
    std::shuffle(allSoupDishes.begin(), allSoupDishes.end(), gen1);

    // 生成晚餐菜单
    for (int i = 0; i < times; ++i) {
        // 从荤菜、素菜、汤中随机选择菜品
        int meatIndex = allMeatDishes[i % allMeatDishes.size()];
        int vegetableIndex = allVegetableDishes[i % allVegetableDishes.size()];
        int soupIndex = allSoupDishes[i % allSoupDishes.size()];

        // 加载菜品信息
        Dish meat = loadDishes(Meat, meatIndex);
        Dish vegetable = loadDishes(Vegetable, vegetableIndex);
        Dish soup = loadDishes(Soup, soupIndex);

        // 添加菜品到模型中
        QString dishInfo = QString::number(i + 1) + "\t" + meat.getDishName() + "\t" + vegetable.getDishName() + "\t" + soup.getDishName();
        dinnerStringModel->insertRow(dinnerStringModel->rowCount());
        QModelIndex index = dinnerStringModel->index(dinnerStringModel->rowCount() - 1, 0);
        dinnerStringModel->setData(index, dishInfo, Qt::DisplayRole);
    }

    return Success;
}



void MainMenu::on_outputToExcel_clicked()
{
    QFile file("output.csv");
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "ERROR: Failed to open file while WRITING";
        return;
    }
    QTextStream out(&file);
    // 写入数据到 CSV 文件
    out << "Name, Age, Score\n";
    out << "Alice, 20, 90\n";
    out << "Bob, 22, 85\n";

    file.close();
}

