#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ReadRadioButton->setChecked(true);
    ui->NORRadioButton->setChecked(true);
    on_NORRadioButton_clicked();
    on_ReadRadioButton_clicked();


    NorGH = new NorGraphicHandler();
    NandGH = new NandGraphicHandler();
    //ui->NOR_NAND_StackedWidget->setHidden(true);
    ui->CellDepthhorizontalSlider->setMinimum(1);
    ui->CellDepthhorizontalSlider->setMaximum(4);

    timer = new QTimer();               // Инициализируем Таймер
    timer->setSingleShot(true);

    ui->BitLinehorizontalSlider->setMinimum(1);
    ui->WordLinehorizontalSlider->setMinimum(1);

    ui->NorGridLayout->addWidget(NorGH->MGV());
    ui->NandGridLayout->addWidget(NandGH->MGV());

    slotAlarmTimer();

    connect(NorGH->MGV()->getTimer(), SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    //->addWidget(_graphic_view);
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
    ui->NOR_NAND_StackedWidget->setCurrentIndex(0);
    //ui->CellDepthhorizontalSlider->setSliderPosition(1);
    ui->CellDepthhorizontalSlider->setDisabled(true);
    //ui->CellDepthLineEdit->setReadOnly(true);
    ui->CellDepthInfoLabel->setText("Глубина ячейки (недоступно)");

}

void MainWindow::on_NANDRadioButton_clicked()
{
    ui->NOR_NAND_StackedWidget->setCurrentIndex(1);
    ui->CellDepthhorizontalSlider->setDisabled(false);
    //ui->CellDepthLineEdit->setReadOnly(false);
    ui->CellDepthInfoLabel->setText("Глубина ячейки");
}

void MainWindow::slotAlarmTimer()
{
    if (ui->NOR_NAND_StackedWidget->currentIndex() == 0)
    {
        ui->BitLinehorizontalSlider->setMaximum(NorGH->MGV()->width()/NorGH->MGV()->getBlock_size().first);
        ui->WordLinehorizontalSlider->setMaximum(NorGH->MGV()->height()/NorGH->MGV()->getBlock_size().second);
    }
    else if (ui->NOR_NAND_StackedWidget->currentIndex() == 1)
    {
        ui->BitLinehorizontalSlider->setMaximum(NandGH->MGV()->width()/NorGH->MGV()->getBlock_size().first);
        ui->WordLinehorizontalSlider->setMaximum(NandGH->MGV()->height()/NorGH->MGV()->getBlock_size().second);
    }
}

void MainWindow::on_WordLinehorizontalSlider_valueChanged(int value)
{
        ui->WordLineLabel->setText(QString().setNum(value));
        NorGH->SetWordLine(value);
        NandGH->SetWordLine(value);
}

void MainWindow::on_BitLinehorizontalSlider_valueChanged(int value)
{
        ui->BitLineLabel->setText(QString().setNum(value));
        NorGH->SetBitLine(value);
        NandGH->SetBitLine(value);
}

void MainWindow::on_CellDepthhorizontalSlider_valueChanged(int value)
{
    ui->CellDepthLabel->setText(QString().setNum(value));
    NandGH->SetCellDepth(value);
}
