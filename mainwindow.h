#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdio>
#include <iostream>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_ReadRadioButton_clicked();

    void on_WriteRadioButton_clicked();

    void on_NORRadioButton_clicked();

    void on_NANDRadioButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
