#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(int type, QWidget *parent)
    : QGraphicsView(parent), _type(type)
{

    /* Немного поднастроим отображение виджета и его содержимого */
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    /* Также зададим минимальные размеры виджета
     * */
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);

    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(scene);          // Устанавливаем сцену в виджет
    scene->setSceneRect(10,0,width(),height());

    NorBegBlocksGroup = new QGraphicsItemGroup();
    NorEndBegBlocksGroup = new QGraphicsItemGroup();
    NorEndMidBlocksGroup = new QGraphicsItemGroup();
    NorMidBlocksGroup = new QGraphicsItemGroup();

    NandBegBlocksGroup = new QGraphicsItemGroup();
    NandEndBegBlocksGroup = new QGraphicsItemGroup();
    NandEndMidBlocksGroup = new QGraphicsItemGroup();
    NandMidBlocksGroup = new QGraphicsItemGroup();

    if (_type == _N_O_R_)
    {
        scene->addItem(NorBegBlocksGroup);
        scene->addItem(NorEndBegBlocksGroup);
        scene->addItem(NorEndMidBlocksGroup);
        scene->addItem(NorMidBlocksGroup);
    }
    else if (_type == _N_A_N_D_)
    {
        scene->addItem(NandBegBlocksGroup);
        scene->addItem(NandEndBegBlocksGroup);
        scene->addItem(NandEndMidBlocksGroup);
        scene->addItem(NandMidBlocksGroup);
    }


    timer = new QTimer();               // Инициализируем Таймер
    timer->setSingleShot(true);

    pictures["BACKGROUND"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/background.jpg");
    pictures["BABM"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/blue_and_blue_mid.jpg");
    pictures["BI"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/blue_into.jpg");
    pictures["BIO"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/blue_into_orrange.jpg");
    pictures["CELL"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/cell.jpg");
    pictures["OAOL"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/orrange_and_orrange_left.jpg");
    pictures["OAOM"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/orrange_and_orrange_mid.jpg");
    pictures["OIB"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/orrange_into_blue.jpg");
    pictures["OIM"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/orrange_into_mid.jpg");
    pictures["OIL"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/orrange_into_left.jpg");
    pictures["OU"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/orrange_up.jpg");
    pictures["TOIB"] = QPixmap("C:/Users/Igor/Documents/Arch_Proj/circuit/two_orrange_into_blue.jpg");

    pictures["CELL_1_0"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_1/CELL_1_0.jpg");
    pictures["CELL_1_1"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_1/CELL_1_1.jpg");

    pictures["CELL_2_00"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_2/CELL_2_00.jpg");
    pictures["CELL_2_01"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_2/CELL_2_01.jpg");
    pictures["CELL_2_10"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_2/CELL_2_10.jpg");
    pictures["CELL_2_11"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_2/CELL_2_11.jpg");

    pictures["CELL_3_000"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_3/CELL_3_000.jpg");
    pictures["CELL_3_001"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_3/CELL_3_001.jpg");
    pictures["CELL_3_010"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_3/CELL_3_010.jpg");
    pictures["CELL_3_011"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_3/CELL_3_011.jpg");
    pictures["CELL_3_100"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_3/CELL_3_100.jpg");
    pictures["CELL_3_101"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_3/CELL_3_101.jpg");
    pictures["CELL_3_110"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_3/CELL_3_110.jpg");
    pictures["CELL_3_111"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_3/CELL_3_111.jpg");

    pictures["CELL_4_0000"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_0000.jpg");
    pictures["CELL_4_0001"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_0001.jpg");
    pictures["CELL_4_0010"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_0010.jpg");
    pictures["CELL_4_0011"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_0011.jpg");
    pictures["CELL_4_0100"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_0100.jpg");
    pictures["CELL_4_0101"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_0101.jpg");
    pictures["CELL_4_0110"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_0110.jpg");
    pictures["CELL_4_0111"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_0111.jpg");
    pictures["CELL_4_1000"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_1000.jpg");
    pictures["CELL_4_1001"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_1001.jpg");
    pictures["CELL_4_1010"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_1010.jpg");
    pictures["CELL_4_1011"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_1011.jpg");
    pictures["CELL_4_1100"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_1100.jpg");
    pictures["CELL_4_1101"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_1101.jpg");
    pictures["CELL_4_1110"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_1110.jpg");
    pictures["CELL_4_1111"] = QPixmap("C:/Users/Igor/Downloads/CELL_BLOCKS/CELL_BLOCKS/CELL_4/CELL_4_1111.jpg");

    NandCellPicture = pictures["CELL_1_0"];

    // Подключаем СЛОТ для отрисовки к таймеру
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(10);                   // Стартуем таймер на 50 миллисекунд
}

MyGraphicsView::~MyGraphicsView()
{

}

void MyGraphicsView::slotAlarmTimer()
{
    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета

    scene->setSceneRect(10,0,width,height);

    update();
}

QTimer *MyGraphicsView::getTimer() const
{
    return timer;
}

pair<size_t, size_t> MyGraphicsView::getBlock_size() const
{
    return _block_size;
}

map<string, QPixmap> MyGraphicsView::getPictures() const
{
    return pictures;
}

vector<QGraphicsItem *> MyGraphicsView::getNorBegBlocks()
{
    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета
    vector<QGraphicsItem *> NorBegBlockItems;
    if (_counts.first == 0 || _counts.second == 0) return NorBegBlockItems;
    for (size_t i = 0; i < _counts.first-1; i++)
    {
        QGraphicsItem *URItem = scene->addPixmap(pictures["OU"]);
        QGraphicsItem *ULItem = scene->addPixmap(pictures["OAOM"]);
        QGraphicsItem *DRItem = scene->addPixmap(pictures["BI"]);
        QGraphicsItem *DLItem = scene->addPixmap(pictures["CELL"]);

        URItem->setPos(width - URItem->boundingRect().width() - i*(URItem->boundingRect().width() + ULItem->boundingRect().width()), 0);
        ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width() - i*(URItem->boundingRect().width() + ULItem->boundingRect().width()), 0);
        DRItem->setPos(width - DRItem->boundingRect().width() - i*(DRItem->boundingRect().width() + DLItem->boundingRect().width()), URItem->boundingRect().height());
        DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width() - i*(DRItem->boundingRect().width() + DLItem->boundingRect().width()), ULItem->boundingRect().height());

        NorBegBlockItems.push_back(URItem);
        NorBegBlockItems.push_back(ULItem);
        NorBegBlockItems.push_back(DRItem);
        NorBegBlockItems.push_back(DLItem);
    }
    return NorBegBlockItems;
}

vector<QGraphicsItem *> MyGraphicsView::getNorMidBlocks()
{
    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета

    vector<QGraphicsItem *> NorMidBlockItems;
    if (_counts.first == 0 || _counts.second == 0) return NorMidBlockItems;
    for (size_t i = 0; i < _counts.first-1; i++)
    {
        for (size_t j = 1; j < _counts.second; j++)
        {
            QGraphicsItem *URItem = scene->addPixmap(pictures["BIO"]);
            QGraphicsItem *ULItem = scene->addPixmap(pictures["OAOM"]);
            QGraphicsItem *DRItem = scene->addPixmap(pictures["BABM"]);
            QGraphicsItem *DLItem = scene->addPixmap(pictures["CELL"]);

            URItem->setPos(width - URItem->boundingRect().width() -  i*(URItem->boundingRect().width() + ULItem->boundingRect().width()), j*NorBegBlocksGroup->boundingRect().height());
            ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width() - i*(URItem->boundingRect().width() + ULItem->boundingRect().width()), j*NorBegBlocksGroup->boundingRect().height());
            DRItem->setPos(width - DRItem->boundingRect().width() - i*(DRItem->boundingRect().width() + DLItem->boundingRect().width()), j*NorBegBlocksGroup->boundingRect().height() + URItem->boundingRect().height());
            DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width() - i*(DRItem->boundingRect().width() + DLItem->boundingRect().width()), j*NorBegBlocksGroup->boundingRect().height() + ULItem->boundingRect().height());

            NorMidBlockItems.push_back(URItem);
            NorMidBlockItems.push_back(ULItem);
            NorMidBlockItems.push_back(DRItem);
            NorMidBlockItems.push_back(DLItem);
        }
    }
    return NorMidBlockItems;
}

vector<QGraphicsItem *> MyGraphicsView::getNorEndBegBlocks()
{
    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета
    vector<QGraphicsItem *> NorEndBegBlockItems;
    if (_counts.first == 0 || _counts.second == 0) return NorEndBegBlockItems;
    QGraphicsItem *URItem = scene->addPixmap(pictures["OU"]);
    QGraphicsItem *ULItem = scene->addPixmap(pictures["OIM"]);
    QGraphicsItem *DRItem = scene->addPixmap(pictures["BI"]);
    QGraphicsItem *DLItem = scene->addPixmap(pictures["CELL"]);
    if (_counts.first > 1)
    {
        URItem->setPos(width - URItem->boundingRect().width() - NorBegBlocksGroup->boundingRect().width(), 0);
        ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width() - NorBegBlocksGroup->boundingRect().width(), 0);
        DRItem->setPos(width - DRItem->boundingRect().width() - NorBegBlocksGroup->boundingRect().width(), URItem->boundingRect().height());
        DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width() - NorBegBlocksGroup->boundingRect().width(), ULItem->boundingRect().height());
    }
    else if (_counts.first == 1)
    {
        URItem->setPos(width - URItem->boundingRect().width(), 0);
        ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width(), 0);
        DRItem->setPos(width - DRItem->boundingRect().width(), URItem->boundingRect().height());
        DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width(), ULItem->boundingRect().height());
    }
    NorEndBegBlockItems.push_back(URItem);
    NorEndBegBlockItems.push_back(ULItem);
    NorEndBegBlockItems.push_back(DRItem);
    NorEndBegBlockItems.push_back(DLItem);
    return NorEndBegBlockItems;
}

vector<QGraphicsItem *> MyGraphicsView::getNorEndMidBlocks()
{
    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета
    vector<QGraphicsItem *> NorEndMidBlockItems;

    if (_counts.first == 0 || _counts.second == 0) return NorEndMidBlockItems;
        for (size_t i = 1; i < _counts.second; i++)
        {
            QGraphicsItem *URItem = scene->addPixmap(pictures["BIO"]);
            QGraphicsItem *ULItem = scene->addPixmap(pictures["OIM"]);
            QGraphicsItem *DRItem = scene->addPixmap(pictures["BABM"]);
            QGraphicsItem *DLItem = scene->addPixmap(pictures["CELL"]);
            if (_counts.first > 1)
            {
                URItem->setPos(width - URItem->boundingRect().width() - NorBegBlocksGroup->boundingRect().width(), i*NorEndBegBlocksGroup->boundingRect().height());
                ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width() - NorBegBlocksGroup->boundingRect().width(), i*NorEndBegBlocksGroup->boundingRect().height());
                DRItem->setPos(width - DRItem->boundingRect().width() - NorBegBlocksGroup->boundingRect().width(), i*NorEndBegBlocksGroup->boundingRect().height() + URItem->boundingRect().height());
                DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width() - NorBegBlocksGroup->boundingRect().width(), i*NorEndBegBlocksGroup->boundingRect().height() + ULItem->boundingRect().height());
            }
            else if (_counts.first == 1)
            {
                URItem->setPos(width - URItem->boundingRect().width(), i*NorEndBegBlocksGroup->boundingRect().height());
                ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width(), i*NorEndBegBlocksGroup->boundingRect().height());
                DRItem->setPos(width - DRItem->boundingRect().width(), i*NorEndBegBlocksGroup->boundingRect().height() + URItem->boundingRect().height());
                DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width(), i*NorEndBegBlocksGroup->boundingRect().height() + ULItem->boundingRect().height());
            }
            NorEndMidBlockItems.push_back(URItem);
            NorEndMidBlockItems.push_back(ULItem);
            NorEndMidBlockItems.push_back(DRItem);
            NorEndMidBlockItems.push_back(DLItem);
        }
        return NorEndMidBlockItems;
}

vector<QGraphicsItem *> MyGraphicsView::getNandBegBlocks()
{
    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета
    vector<QGraphicsItem *> NandBegBlockItems;
    if (_counts.first == 0 || _counts.second == 0) return NandBegBlockItems;
    for (size_t i = 0; i < _counts.first-1; i++)
    {
        QGraphicsItem *URItem = scene->addPixmap(pictures["OU"]);
        QGraphicsItem *ULItem = scene->addPixmap(pictures["OAOL"]);
        QGraphicsItem *DRItem = scene->addPixmap(pictures["BACKGROUND"]);
        QGraphicsItem *DLItem = scene->addPixmap(NandCellPicture);

        URItem->setPos(width - URItem->boundingRect().width() - i*(URItem->boundingRect().width() + ULItem->boundingRect().width()), 0);
        ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width() - i*(URItem->boundingRect().width() + ULItem->boundingRect().width()), 0);
        DRItem->setPos(width - DRItem->boundingRect().width() - i*(DRItem->boundingRect().width() + DLItem->boundingRect().width()), URItem->boundingRect().height());
        DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width() - i*(DRItem->boundingRect().width() + DLItem->boundingRect().width()), ULItem->boundingRect().height());

        NandBegBlockItems.push_back(URItem);
        NandBegBlockItems.push_back(ULItem);
        NandBegBlockItems.push_back(DRItem);
        NandBegBlockItems.push_back(DLItem);
    }
    return NandBegBlockItems;
}

vector<QGraphicsItem *> MyGraphicsView::getNandMidBlocks()
{
    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета

    vector<QGraphicsItem *> NandMidBlockItems;
    if (_counts.first == 0 || _counts.second == 0) return NandMidBlockItems;
    for (size_t i = 0; i < _counts.first-1; i++)
    {
        for (size_t j = 1; j < _counts.second; j++)
        {
            QGraphicsItem *URItem = scene->addPixmap(pictures["OU"]);
            QGraphicsItem *ULItem = scene->addPixmap(pictures["TOIB"]);
            QGraphicsItem *DRItem = scene->addPixmap(pictures["BACKGROUND"]);
            QGraphicsItem *DLItem = scene->addPixmap(NandCellPicture);

            URItem->setPos(width - URItem->boundingRect().width() -  i*(URItem->boundingRect().width() + ULItem->boundingRect().width()), j*NandBegBlocksGroup->boundingRect().height());
            ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width() - i*(URItem->boundingRect().width() + ULItem->boundingRect().width()), j*NandBegBlocksGroup->boundingRect().height());
            DRItem->setPos(width - DRItem->boundingRect().width() - i*(DRItem->boundingRect().width() + DLItem->boundingRect().width()), j*NandBegBlocksGroup->boundingRect().height() + URItem->boundingRect().height());
            DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width() - i*(DRItem->boundingRect().width() + DLItem->boundingRect().width()), j*NandBegBlocksGroup->boundingRect().height() + ULItem->boundingRect().height());

            NandMidBlockItems.push_back(URItem);
            NandMidBlockItems.push_back(ULItem);
            NandMidBlockItems.push_back(DRItem);
            NandMidBlockItems.push_back(DLItem);
        }
    }
    return NandMidBlockItems;
}

vector<QGraphicsItem *> MyGraphicsView::getNandEndBegBlocks()
{
    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета
    vector<QGraphicsItem *> NandEndBegBlockItems;
    if (_counts.first == 0 || _counts.second == 0) return NandEndBegBlockItems;
    QGraphicsItem *URItem = scene->addPixmap(pictures["OU"]);
    QGraphicsItem *ULItem = scene->addPixmap(pictures["OIL"]);
    QGraphicsItem *DRItem = scene->addPixmap(pictures["BACKGROUND"]);
    QGraphicsItem *DLItem = scene->addPixmap(NandCellPicture);
    if (_counts.first > 1)
    {
        URItem->setPos(width - URItem->boundingRect().width() - NandBegBlocksGroup->boundingRect().width(), 0);
        ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width() - NandBegBlocksGroup->boundingRect().width(), 0);
        DRItem->setPos(width - DRItem->boundingRect().width() - NandBegBlocksGroup->boundingRect().width(), URItem->boundingRect().height());
        DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width() - NandBegBlocksGroup->boundingRect().width(), ULItem->boundingRect().height());
    }
    else if (_counts.first == 1)
    {
        URItem->setPos(width - URItem->boundingRect().width(), 0);
        ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width(), 0);
        DRItem->setPos(width - DRItem->boundingRect().width(), URItem->boundingRect().height());
        DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width(), ULItem->boundingRect().height());
    }
    NandEndBegBlockItems.push_back(URItem);
    NandEndBegBlockItems.push_back(ULItem);
    NandEndBegBlockItems.push_back(DRItem);
    NandEndBegBlockItems.push_back(DLItem);
    return NandEndBegBlockItems;

}

vector<QGraphicsItem *> MyGraphicsView::getNandEndMidBlocks()
{
    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета
    vector<QGraphicsItem *> NandEndMidBlockItems;

    if (_counts.first == 0 || _counts.second == 0) return NandEndMidBlockItems;
        for (size_t i = 1; i < _counts.second; i++)
        {
            QGraphicsItem *URItem = scene->addPixmap(pictures["OU"]);
            QGraphicsItem *ULItem = scene->addPixmap(pictures["OIB"]);
            QGraphicsItem *DRItem = scene->addPixmap(pictures["BACKGROUND"]);
            QGraphicsItem *DLItem = scene->addPixmap(NandCellPicture);
            if (_counts.first > 1)
            {
                URItem->setPos(width - URItem->boundingRect().width() - NandBegBlocksGroup->boundingRect().width(), i*NandEndBegBlocksGroup->boundingRect().height());
                ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width() - NandBegBlocksGroup->boundingRect().width(), i*NandEndBegBlocksGroup->boundingRect().height());
                DRItem->setPos(width - DRItem->boundingRect().width() - NandBegBlocksGroup->boundingRect().width(), i*NandEndBegBlocksGroup->boundingRect().height() + URItem->boundingRect().height());
                DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width() - NandBegBlocksGroup->boundingRect().width(), i*NandEndBegBlocksGroup->boundingRect().height() + ULItem->boundingRect().height());
            }
            else if (_counts.first == 1)
            {
                URItem->setPos(width - URItem->boundingRect().width(), i*NandEndBegBlocksGroup->boundingRect().height());
                ULItem->setPos(width - ULItem->boundingRect().width() - URItem->boundingRect().width(), i*NandEndBegBlocksGroup->boundingRect().height());
                DRItem->setPos(width - DRItem->boundingRect().width(), i*NandEndBegBlocksGroup->boundingRect().height() + URItem->boundingRect().height());
                DLItem->setPos(width - DLItem->boundingRect().width() - DRItem->boundingRect().width(), i*NandEndBegBlocksGroup->boundingRect().height() + ULItem->boundingRect().height());
            }
            NandEndMidBlockItems.push_back(URItem);
            NandEndMidBlockItems.push_back(ULItem);
            NandEndMidBlockItems.push_back(DRItem);
            NandEndMidBlockItems.push_back(DLItem);
        }
        return NandEndMidBlockItems;

}

void MyGraphicsView::SetWordLine(size_t count)
{
    _counts.second = count;
    update();
}

void MyGraphicsView::SetBitLine(size_t count)
{
    _counts.first = count;
    update();
}

void MyGraphicsView::ChangeCellDepth(size_t value)
{
    switch (value)
    {
        case 1:
        {
            NandCellPicture = pictures["CELL_1_0"];
            break;
        }
        case 2:
        {
            NandCellPicture = pictures["CELL_2_00"];
            break;
        }
        case 3:
        {
            NandCellPicture = pictures["CELL_3_000"];
            break;
        }
        case 4:
        {
            NandCellPicture = pictures["CELL_4_0000"];
            break;
        }
    }
    slotAlarmTimer();
}

void MyGraphicsView::update()
{
    if (_type == _N_O_R_)
    {
        this->deleteItemsFromGroup(NorBegBlocksGroup);
        this->deleteItemsFromGroup(NorEndBegBlocksGroup);
        this->deleteItemsFromGroup(NorEndMidBlocksGroup);
        this->deleteItemsFromGroup(NorMidBlocksGroup);

        vector<QGraphicsItem*> BegBlocks = getNorBegBlocks();
        for (size_t i = 0; i < BegBlocks.size(); i++)
            NorBegBlocksGroup->addToGroup(BegBlocks.at(i));

        vector<QGraphicsItem*> EndBegBlocks = getNorEndBegBlocks();
        for (size_t i = 0; i < EndBegBlocks.size(); i++)
            NorEndBegBlocksGroup->addToGroup(EndBegBlocks.at(i));

        _block_size = make_pair(NorEndBegBlocksGroup->boundingRect().width(), NorEndBegBlocksGroup->boundingRect().height());

        vector<QGraphicsItem*> MidBlocks = getNorMidBlocks();
        for (size_t i = 0; i < MidBlocks.size(); i++)
            NorMidBlocksGroup->addToGroup(MidBlocks.at(i));

        vector<QGraphicsItem*> EndMidBlocks = getNorEndMidBlocks();
        for (size_t i = 0; i < EndMidBlocks.size(); i++)
            NorEndMidBlocksGroup->addToGroup(EndMidBlocks.at(i));
    }
    else if (_type == _N_A_N_D_)
    {
        this->deleteItemsFromGroup(NandBegBlocksGroup);
        this->deleteItemsFromGroup(NandEndBegBlocksGroup);
        this->deleteItemsFromGroup(NandEndMidBlocksGroup);
        this->deleteItemsFromGroup(NandMidBlocksGroup);

        vector<QGraphicsItem*> BegBlocks = getNandBegBlocks();
        for (size_t i = 0; i < BegBlocks.size(); i++)
            NandBegBlocksGroup->addToGroup(BegBlocks.at(i));

        vector<QGraphicsItem*> EndBegBlocks = getNandEndBegBlocks();
        for (size_t i = 0; i < EndBegBlocks.size(); i++)
            NandEndBegBlocksGroup->addToGroup(EndBegBlocks.at(i));

        _block_size = make_pair(NandEndBegBlocksGroup->boundingRect().width(), NandEndBegBlocksGroup->boundingRect().height());

        vector<QGraphicsItem*> MidBlocks = getNandMidBlocks();
        for (size_t i = 0; i < MidBlocks.size(); i++)
            NandMidBlocksGroup->addToGroup(MidBlocks.at(i));

        vector<QGraphicsItem*> EndMidBlocks = getNandEndMidBlocks();
        for (size_t i = 0; i < EndMidBlocks.size(); i++)
            NandEndMidBlocksGroup->addToGroup(EndMidBlocks.at(i));

    }
}

/* Этим методом перехватываем событие изменения размера виджет
 */
void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
    timer->start(50);   // Как только событие произошло стартуем таймер для отрисовки
    QGraphicsView::resizeEvent(event);  // Запускаем событие родителького класса
}


/* Метод для удаления всех элементов из группы
 * */
void MyGraphicsView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    /* Перебираем все элементы сцены, и если они принадлежат группе,
     * переданной в метод, то удаляем их
     * */
    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
       if(item->group() == group ) {
          group->removeFromGroup(item);
          delete item;
       }
    }
}
