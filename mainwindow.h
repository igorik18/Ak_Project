#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "nandgraphichandler.h"
#include "norgraphichandler.h"

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
    NorGraphicHandler *NorGH;
    NandGraphicHandler *NandGH;
    QTimer              *timer;

private slots:
    void slotAlarmTimer();
    void on_WordLinehorizontalSlider_valueChanged(int value);
    void on_BitLinehorizontalSlider_valueChanged(int value);
    void on_CellDepthhorizontalSlider_valueChanged(int value);
    void on_BitWordNumber_textEdited(const QString &arg1);
    void on_StartButton_clicked();
    void on_ResetButton_clicked();
};

#endif // MAINWINDOW_H
