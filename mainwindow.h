#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void paintEvent(QPaintEvent *event);

    int isCross = -1;
    int counter = 0;
    bool gameInProgress = false;
    QVector<QPushButton*> buttons;
    QVector<int> numbers;

    const int vectorLength = 9;

    int checkGameWin();

private slots:
    void on_pushButton_X_clicked();
    void on_pushButton_O_clicked();
    void on_pushButton_start_clicked();
    void on_pushButton_about_clicked();
    void gameButtonClicked();

private:
    Ui::MainWindow *ui;
    void setDefaultCondition();
    void reset();
};
#endif // MAINWINDOW_H
