#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->WriteRadioButton->setChecked(true);
    ui->NORRadioButton->setChecked(true);
    on_NORRadioButton_clicked();
    on_ReadRadioButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ReadRadioButton_clicked()
{
    ui->BitWordNumberInfoLabel->setText("Номер слова");
}

void MainWindow::on_WriteRadioButton_clicked()
{
    ui->BitWordNumberInfoLabel->setText("Битовое слово");
}

void MainWindow::on_NORRadioButton_clicked()
{
    ui->CellDepthLineEdit->setReadOnly(true);
    ui->CellDepthInfoLabel->setText("Глубина ячейки(недоступно)");
}

void MainWindow::on_NANDRadioButton_clicked()
{
    ui->CellDepthLineEdit->setReadOnly(false);
    ui->CellDepthInfoLabel->setText("Глубина ячейки");
}
