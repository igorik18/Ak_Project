#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->NoNeedGroupBox1->setHidden(true);
    ui->NoNeedGroupBox2->setHidden(true);
    ui->statusBar->setVisible(false);
    ui->menuBar->setVisible(false);
    ui->mainToolBar->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_ReadRadioButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_WriteRadioButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_NORRadioButton_clicked()
{
    ui->CellDepthInfoLabel->setHidden(true);
    ui->CellDepthLineEdit->setHidden(true);
}

void MainWindow::on_NANDRadioButton_clicked()
{
    ui->CellDepthInfoLabel->setHidden(false);
    ui->CellDepthLineEdit->setHidden(false);
}
