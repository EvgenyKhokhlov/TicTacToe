#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTabBar"
#include "stylehelper.h"

#include <QPainter>
#include <QStyleOption>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(0);

    buttons.append(ui->pushButton_1);
    buttons.append(ui->pushButton_2);
    buttons.append(ui->pushButton_3);
    buttons.append(ui->pushButton_4);
    buttons.append(ui->pushButton_5);
    buttons.append(ui->pushButton_6);
    buttons.append(ui->pushButton_7);
    buttons.append(ui->pushButton_8);
    buttons.append(ui->pushButton_9);

    numbers.resize(vectorLength);

    setDefaultCondition();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void MainWindow::setDefaultCondition()
{
    setStyleSheet(StyleHelper::getMainWidgetStyle());
    ui->pushButton_start->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->pushButton_about->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->pushButton_X->setStyleSheet(StyleHelper::getChooseButtonsStyle());
    ui->pushButton_O->setStyleSheet(StyleHelper::getChooseButtonsStyle());

    ui->label_message->setText("Выберите сторону.");

    reset();
    isCross = -1;
}

void MainWindow::reset()
{
    for (int i = 0; i < vectorLength; i++) {
        buttons.at(i)->setStyleSheet(StyleHelper::getGameButtonsStyle());
        connect(buttons.at(i), &QPushButton::clicked, this, &MainWindow::gameButtonClicked);
        buttons.at(i)->setText("");

        numbers.replace(i, -10);
    }
    counter = 0;
}

void MainWindow::on_pushButton_X_clicked()
{
    if(isCross == 1 || gameInProgress) return;

    isCross = 1;
    ui->pushButton_X->setStyleSheet(StyleHelper::getActiveChooseButtonsStyle());
    ui->pushButton_O->setStyleSheet(StyleHelper::getChooseButtonsStyle());
}

void MainWindow::on_pushButton_O_clicked()
{
    if(isCross == 0 || gameInProgress) return;

    isCross = 0;
    ui->pushButton_O->setStyleSheet(StyleHelper::getActiveChooseButtonsStyle());
    ui->pushButton_X->setStyleSheet(StyleHelper::getChooseButtonsStyle());
}

void MainWindow::gameButtonClicked()
{
    if(isCross ==  -1 || !gameInProgress) return;

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if(button == nullptr || !button->text().isEmpty()) return;

    numbers.replace(button->objectName().split("_").at(1).toInt() - 1, isCross);
    button->setStyleSheet(StyleHelper::getActiveGameButtonsStyle());

    if(isCross == 0)
        button->setText("O");
    else if(isCross == 1)
        button->setText("X");

    if(checkGameWin() == 0){
        ui->label_message->setText("Ноликик победили.");
        gameInProgress = false;
        return;
    }else if(checkGameWin() == 1){
        ui->label_message->setText("Крестики победили.");
        gameInProgress = false;
        return;
    }

    counter++;
    if(counter >= vectorLength){
        ui->label_message->setText("Ничья");
        gameInProgress = false;
        return;
    }

    if(isCross == 0){
       ui->label_message->setText("Ходят крестики.");
       isCross = 1;
    }else if(isCross == 1){
       ui->label_message->setText("Ходят нолики.");
       isCross = 0;
    }
}

void MainWindow::on_pushButton_start_clicked()
{
    ui->tabWidget->setCurrentIndex(0);

    if(isCross ==  -1 || gameInProgress) return;

    reset();

    if(isCross == 0){
        ui->label_message->setText("Ходят нолики.");
    }else if(isCross == 1){
        ui->label_message->setText("Ходят крестики.");
    }
    gameInProgress = true;
}

void MainWindow::on_pushButton_about_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

int MainWindow::checkGameWin()
{
    if (numbers[0] + numbers[1] + numbers[2] == isCross * 3 ||
        numbers[3] + numbers[4] + numbers[5] == isCross * 3 ||
        numbers[6] + numbers[7] + numbers[8] == isCross * 3 ||
        numbers[0] + numbers[3] + numbers[6] == isCross * 3 ||
        numbers[1] + numbers[4] + numbers[7] == isCross * 3 ||
        numbers[2] + numbers[5] + numbers[8] == isCross * 3 ||
        numbers[0] + numbers[4] + numbers[8] == isCross * 3 ||
        numbers[2] + numbers[4] + numbers[6] == isCross * 3) {
        return isCross;
    }else{
        return -10;
    }
}
