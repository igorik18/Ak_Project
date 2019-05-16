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
    ui->BitWordNumber->clear();
    ui->BitWordNumberInfoLabel->setText("Номер слова");
}

void MainWindow::on_WriteRadioButton_clicked()
{
    ui->BitWordNumber->clear();
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
        QString str(ui->BitWordNumber->text());
        str.chop(ui->BitWordNumber->text().size() - value);
        ui->BitWordNumber->setText(str);
        ui->BitLineLabel->setText(QString().setNum(value));
        NorGH->SetBitLine(value);
        NandGH->SetBitLine(value);
}

void MainWindow::on_CellDepthhorizontalSlider_valueChanged(int value)
{
    ui->CellDepthLabel->setText(QString().setNum(value));
    NandGH->SetCellDepth(value);
}

void MainWindow::on_BitWordNumber_textEdited(const QString &arg1)
{
    bool ok;
    int value = arg1.toInt(&ok, 10);
    if (!ok && ui->ReadRadioButton->isChecked())
    {
        QString str(arg1);
        str.chop(1);//
        ui->BitWordNumber->setText(str);
       // ui->BitWordNumber->setText(QString());
    }
    if (ui->ReadRadioButton->isChecked() && ok)
    {
        if (value < 1) ui->BitWordNumber->setText(QString().setNum(1));
        if (ui->NANDRadioButton->isChecked())
        {
            if (value > NandGH->MGV()->getCounts().second) ui->BitWordNumber->setText(QString().setNum(NandGH->MGV()->getCounts().second));
        }
        else
        {
            if (value > NorGH->MGV()->getCounts().second) ui->BitWordNumber->setText(QString().setNum(NorGH->MGV()->getCounts().second));
        }
    }
    else if (ui->WriteRadioButton->isChecked())
    {
        size_t counts;
        if (ui->NANDRadioButton->isChecked()) counts = NandGH->MGV()->getCounts().first*NandGH->MGV()->getCelldepth_k();
        else counts = NorGH->MGV()->getCounts().first;

        QString str(arg1);
        if (arg1.size() > counts)
        {
            str.chop(str.size() - counts);
        }
            for (int i = 0; i < str.size(); ++i)
            {
                if (str[i].digitValue() > 1)
                {
                    str.remove(i,1);
                }
            }
        ui->BitWordNumber->setText(str);
    }
}

void MainWindow::on_StartButton_clicked()
{
    if (ui->NOR_NAND_StackedWidget->currentIndex() == 0) //NOR
    {
        if (ui->ReadRadioButton->isChecked()) //Read
        {
            string read_str = NorGH->ReadInfo(ui->BitWordNumber->text().toInt()-1);
            QMessageBox::information(0, "Result", read_str.c_str());
        }
        else if (ui->WriteRadioButton->isChecked()) //Write
        {
            if (NorGH->RecordInfo(ui->BitWordNumber->text().toStdString())) QMessageBox::information(0, "Result", "Ok!");
            else QMessageBox::information(0, "Result", "Failed!");
        }
    }
    else // NAND
    {
        if (ui->ReadRadioButton->isChecked()) // Read
        {
            string read_str = NandGH->ReadInfo(ui->BitWordNumber->text().toInt()-1);
            QMessageBox::information(0, "Result", read_str.c_str());
        }
        else if (ui->WriteRadioButton->isChecked()) // Write
        {
            if (NandGH->RecordInfo(ui->BitWordNumber->text().toStdString())) QMessageBox::information(0, "Result", "Ok!");
            else QMessageBox::information(0, "Result", "Failed!");
        }
    }
}

void MainWindow::on_ResetButton_clicked()
{
    if (ui->NORRadioButton->isChecked()) NorGH->Clear();
    else NandGH->Clear();
}
