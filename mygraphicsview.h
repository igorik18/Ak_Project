#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cstdio>
#include <iostream>
#include <map>
#include <QDebug>
using namespace std;

#define _N_O_R_ 0
#define _N_A_N_D_ 1

// Расширяем класс QGraphicsView
class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicsView(int type, QWidget *parent = 0);


    map<string, QPixmap> getPictures() const;

    // лепка блоков для НОР
    vector <QGraphicsItem *> getNorBegBlocks();
    vector <QGraphicsItem *> getNorMidBlocks();
    vector <QGraphicsItem *> getNorEndBegBlocks();
    vector <QGraphicsItem *> getNorEndMidBlocks();

    //лепка блоков для НАНД
    vector <QGraphicsItem *> getNandBegBlocks();
    vector <QGraphicsItem *> getNandMidBlocks();
    vector <QGraphicsItem *> getNandEndBegBlocks();
    vector <QGraphicsItem *> getNandEndMidBlocks();

    // ПУСТО

    void SetWordLine(size_t count);
    void SetBitLine(size_t count);
    void ChangeCellDepth(size_t value);

    void update();

    ~MyGraphicsView();


    pair<size_t, size_t> getBlock_size() const;

    QTimer *getTimer() const;

signals:


private slots:
    void slotAlarmTimer();
private:
    map <string, QPixmap> pictures;
    pair <size_t, size_t> _counts;
    QGraphicsScene      *scene;

    // НОР ГРУППЫ
    QGraphicsItemGroup  *NorBegBlocksGroup;
    QGraphicsItemGroup  *NorMidBlocksGroup;
    QGraphicsItemGroup  *NorEndBegBlocksGroup;
    QGraphicsItemGroup  *NorEndMidBlocksGroup;

    //НАНД ГРУППЫ
    QGraphicsItemGroup  *NandBegBlocksGroup;
    QGraphicsItemGroup  *NandMidBlocksGroup;
    QGraphicsItemGroup  *NandEndBegBlocksGroup;
    QGraphicsItemGroup  *NandEndMidBlocksGroup;


    QTimer              *timer;
    int _type;
    QPixmap NandCellPicture;

    pair <size_t, size_t> _block_size;
private:
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};

#endif // MYGRAPHICSVIEW_H
