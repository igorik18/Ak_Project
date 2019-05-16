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
#include <algorithm>
#include <QDebug>
#include <QMessageBox>
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



    void SetWordLine(size_t count);
    void SetBitLine(size_t count);
    void ChangeCellDepth(size_t value);
    bool RecordInfo(string word);
    string ReadInfo(size_t number);

    void update();

    ~MyGraphicsView();


    pair<size_t, size_t> getBlock_size() const;

    QTimer *getTimer() const;

    pair<size_t, size_t> getCounts() const;

    void ClearTable();

    size_t getCelldepth_k() const;

signals:


private slots:
    void slotAlarmTimer();
private:
    map <string, QPixmap> pictures;
    pair <size_t, size_t> _counts;
    QGraphicsScene      *scene;
    pair <vector <string>, size_t> words_table;

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

    pair <bool, int> write_lighting;
    pair <bool, int> read_lighting;


    QTimer              *timer;
    int _type;
    size_t _celldepth_k;

    // КАРТИНКИ
    QPixmap NandCellPicture;
    QPixmap NorCellPicture;
    QPixmap BABMPicture;
    QPixmap BIPicture;
    QPixmap BIOPicture;
    QPixmap OAOLPicture;
    QPixmap OAOMPicture;
    QPixmap OIBPicture;
    QPixmap OILPicture;
    QPixmap OIMPicture;
    QPixmap OUPicture;
    QPixmap TOIBPicture;

    pair <size_t, size_t> _block_size;
private:
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};

#endif // MYGRAPHICSVIEW_H
