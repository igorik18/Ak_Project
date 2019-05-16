#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(int type, QWidget *parent)
    : QGraphicsView(parent), _type(type)
{

    /* Немного поднастроим отображение виджета и его содержимого */
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    /* Также зададим минимальные размеры виджета*/
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

    _celldepth_k = 1;

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

    pictures["BACKGROUND"] = QPixmap("circuit/background.jpg");
    pictures["BABM"] = QPixmap("circuit/blue_and_blue_mid.jpg");
    pictures["BI"] = QPixmap("circuit/blue_into.jpg");
    pictures["BIO"] = QPixmap("circuit/blue_into_orrange.jpg");
    pictures["CELL"] = QPixmap("circuit/cell.jpg");
    pictures["OAOL"] = QPixmap("circuit/orrange_and_orrange_left.jpg");
    pictures["OAOM"] = QPixmap("circuit/orrange_and_orrange_mid.jpg");
    pictures["OIB"] = QPixmap("circuit/orrange_into_blue.jpg");
    pictures["OIM"] = QPixmap("circuit/orrange_into_mid.jpg");
    pictures["OIL"] = QPixmap("circuit/orrange_into_left.jpg");
    pictures["OU"] = QPixmap("circuit/orrange_up.jpg");
    pictures["TOIB"] = QPixmap("circuit/two_orrange_into_blue.jpg");

    pictures["BABML"] = QPixmap("circuit/light_circuit/blue_and_blue_mid.jpg");
    pictures["BIL"] = QPixmap("circuit/light_circuit/blue_into.jpg");
    pictures["BIOBL"] = QPixmap("circuit/light_circuit/blue_into_orrange_bl.jpg");
    pictures["BIOOL"] = QPixmap("circuit/light_circuit/blue_into_orrange_ol.jpg");
    pictures["BIOBOL"] = QPixmap("circuit/light_circuit/blue_into_orrange_bol.jpg");
    pictures["OAOLL"] = QPixmap("circuit/light_circuit/orrange_and_orrange_left.jpg");
    pictures["OAOML"] = QPixmap("circuit/light_circuit/orrange_and_orrange_mid.jpg");
    pictures["OIBBL"] = QPixmap("circuit/light_circuit/orrange_into_blue_bl.jpg");
    pictures["OIBOL"] = QPixmap("circuit/light_circuit/orrange_into_blue_ol.jpg");
    pictures["OIBBOL"] = QPixmap("circuit/light_circuit/orrange_into_blue_bol.jpg");
    pictures["OILL"] = QPixmap("circuit/light_circuit/orrange_into_left.jpg");
    pictures["OIML"] = QPixmap("circuit/light_circuit/orrange_into_mid.jpg");
    pictures["OUL"] = QPixmap("circuit/light_circuit/orrange_up.jpg");
    pictures["TOIBBL"] = QPixmap("circuit/light_circuit/two_orrange_into_blue_bl.jpg");
    pictures["TOIBOL"] = QPixmap("circuit/light_circuit/two_orrange_into_blue_ol.jpg");
    pictures["TOIBBOL"] = QPixmap("circuit/light_circuit/two_orrange_into_blue_bol.jpg");

    pictures["CELL_1_0"] = QPixmap("circuit/CELL_1/CELL_1_0.jpg");
    pictures["CELL_1_1"] = QPixmap("circuit/CELL_1/CELL_1_1.jpg");

    pictures["CELL_2_00"] = QPixmap("circuit/CELL_2/CELL_2_00.jpg");
    pictures["CELL_2_01"] = QPixmap("circuit/CELL_2/CELL_2_01.jpg");
    pictures["CELL_2_10"] = QPixmap("circuit/CELL_2/CELL_2_10.jpg");
    pictures["CELL_2_11"] = QPixmap("circuit/CELL_2/CELL_2_11.jpg");

    pictures["CELL_3_000"] = QPixmap("circuit/CELL_3/CELL_3_000.jpg");
    pictures["CELL_3_001"] = QPixmap("circuit/CELL_3/CELL_3_001.jpg");
    pictures["CELL_3_010"] = QPixmap("circuit/CELL_3/CELL_3_010.jpg");
    pictures["CELL_3_011"] = QPixmap("circuit/CELL_3/CELL_3_011.jpg");
    pictures["CELL_3_100"] = QPixmap("circuit/CELL_3/CELL_3_100.jpg");
    pictures["CELL_3_101"] = QPixmap("circuit/CELL_3/CELL_3_101.jpg");
    pictures["CELL_3_110"] = QPixmap("circuit/CELL_3/CELL_3_110.jpg");
    pictures["CELL_3_111"] = QPixmap("circuit/CELL_3/CELL_3_111.jpg");

    pictures["CELL_4_0000"] = QPixmap("circuit/CELL_4/CELL_4_0000.jpg");
    pictures["CELL_4_0001"] = QPixmap("circuit/CELL_4/CELL_4_0001.jpg");
    pictures["CELL_4_0010"] = QPixmap("circuit/CELL_4/CELL_4_0010.jpg");
    pictures["CELL_4_0011"] = QPixmap("circuit/CELL_4/CELL_4_0011.jpg");
    pictures["CELL_4_0100"] = QPixmap("circuit/CELL_4/CELL_4_0100.jpg");
    pictures["CELL_4_0101"] = QPixmap("circuit/CELL_4/CELL_4_0101.jpg");
    pictures["CELL_4_0110"] = QPixmap("circuit/CELL_4/CELL_4_0110.jpg");
    pictures["CELL_4_0111"] = QPixmap("circuit/CELL_4/CELL_4_0111.jpg");
    pictures["CELL_4_1000"] = QPixmap("circuit/CELL_4/CELL_4_1000.jpg");
    pictures["CELL_4_1001"] = QPixmap("circuit/CELL_4/CELL_4_1001.jpg");
    pictures["CELL_4_1010"] = QPixmap("circuit/CELL_4/CELL_4_1010.jpg");
    pictures["CELL_4_1011"] = QPixmap("circuit/CELL_4/CELL_4_1011.jpg");
    pictures["CELL_4_1100"] = QPixmap("circuit/CELL_4/CELL_4_1100.jpg");
    pictures["CELL_4_1101"] = QPixmap("circuit/CELL_4/CELL_4_1101.jpg");
    pictures["CELL_4_1110"] = QPixmap("circuit/CELL_4/CELL_4_1110.jpg");
    pictures["CELL_4_1111"] = QPixmap("circuit/CELL_4/CELL_4_1111.jpg");

    NandCellPicture = pictures["CELL_1_0"];
    NorCellPicture = pictures["CELL_1_0"];
    BABMPicture = pictures["BABM"];
    BIPicture = pictures["BI"];
    BIOPicture = pictures["BIO"];
    OAOLPicture = pictures["OAOL"];
    OAOMPicture = pictures["OAOM"];
    OIBPicture = pictures["OIB"];
    OILPicture = pictures["OIL"];
    OIMPicture = pictures["OIM"];
    OUPicture = pictures["OU"];
    TOIBPicture = pictures["TOIB"];



    // Подключаем СЛОТ для отрисовки к таймеру
    words_table.second = _counts.second;
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

size_t MyGraphicsView::getCelldepth_k() const
{
    return _celldepth_k;
}

pair<size_t, size_t> MyGraphicsView::getCounts() const
{
    return _counts;
}

void MyGraphicsView::ClearTable()
{
    words_table.first.clear();
    words_table.second = 0;
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

    if (write_lighting.first && write_lighting.second == 0)
    {
        OUPicture = pictures["OUL"];
        OAOMPicture = pictures["OAOML"];
    }
    else if (read_lighting.first && read_lighting.second == 0) BIPicture = pictures["BIL"];
    else
    {
        OUPicture = pictures["OU"];
        OAOMPicture = pictures["OAOM"];
        BIPicture = pictures["BI"];
    }
    for (size_t i = 0; i < _counts.first-1; i++)
    {
        if (words_table.first.size() > 0 && i == words_table.first[0].find("1", i))
        {
           NorCellPicture = pictures["CELL_1_1"];
        }
        else NorCellPicture = pictures["CELL_1_0"];


        QGraphicsItem *URItem = scene->addPixmap(OUPicture);
        QGraphicsItem *ULItem = scene->addPixmap(OAOMPicture);
        QGraphicsItem *DRItem = scene->addPixmap(BIPicture);
        QGraphicsItem *DLItem = scene->addPixmap(NorCellPicture);

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
            if (words_table.first.size() > j &&
                i == words_table.first[j].find("1", i))
            {
                 //qDebug() << "cell11";
                 NorCellPicture = pictures["CELL_1_1"];
            }
            else NorCellPicture = pictures["CELL_1_0"];

            if (write_lighting.first && write_lighting.second == j)
            {
                OAOMPicture = pictures["OAOML"];
                BIOPicture = pictures["BIOOL"];
            }
            else if (read_lighting.first && read_lighting.second <= j)
            {
                BIOPicture = pictures["BIO"];
                if (read_lighting.second != j) BIOPicture = pictures["BIOBL"];
                BABMPicture = pictures["BABML"];
            }
            else
            {
                BIOPicture = pictures["BIO"];
                BABMPicture = pictures["BABM"];
                OAOMPicture = pictures["OAOM"];
            }

            QGraphicsItem *URItem = scene->addPixmap(BIOPicture);
            QGraphicsItem *ULItem = scene->addPixmap(OAOMPicture);
            QGraphicsItem *DRItem = scene->addPixmap(BABMPicture);
            QGraphicsItem *DLItem = scene->addPixmap(NorCellPicture);

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

    //if (words_table.first.size() >= 1)
    //{
    if (words_table.first.size() > 0)
    {
        size_t pos = words_table.first[0].find("1", _counts.first-1);
        if (_counts.first-1 == pos) NorCellPicture = pictures["CELL_1_1"];
        else NorCellPicture = pictures["CELL_1_0"];
    }
    else NorCellPicture = pictures["CELL_1_0"];
        //}
    if (write_lighting.first && write_lighting.second == 0)
    {
        OUPicture = pictures["OUL"];
        OIMPicture = pictures["OIML"];
    }
    else if (read_lighting.first && read_lighting.second == 0) BIPicture = pictures["BIL"];
    else
    {
        OUPicture = pictures["OU"];
        OIMPicture = pictures["OIM"];
        BIPicture = pictures["BI"];
    } 

    QGraphicsItem *URItem = scene->addPixmap(OUPicture);
    QGraphicsItem *ULItem = scene->addPixmap(OIMPicture);
    QGraphicsItem *DRItem = scene->addPixmap(BIPicture);
    QGraphicsItem *DLItem = scene->addPixmap(NorCellPicture);
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
   // else BIPicture = pictures["BI"];
        for (size_t i = 1; i < _counts.second; i++)
        {

            if (words_table.first.size() > i &&
                _counts.first-1 == words_table.first[i].find("1", _counts.first-1)) NorCellPicture = pictures["CELL_1_1"];
            else NorCellPicture = pictures["CELL_1_0"];

            if (write_lighting.first && write_lighting.second == i)
            {
                OIMPicture = pictures["OIML"];
                BIOPicture = pictures["BIOOL"];
            }
            else if (read_lighting.first && read_lighting.second <= i)
            {
                BIOPicture = pictures["BIO"];
                if (read_lighting.second != i) BIOPicture = pictures["BIOBL"];
                BABMPicture = pictures["BABML"];
            }
            else
            {
                BIOPicture = pictures["BIO"];
                BABMPicture = pictures["BABM"];
                OIMPicture = pictures["OIM"];
            }

            QGraphicsItem *URItem = scene->addPixmap(BIOPicture);
            QGraphicsItem *ULItem = scene->addPixmap(OIMPicture);
            QGraphicsItem *DRItem = scene->addPixmap(BABMPicture);
            QGraphicsItem *DLItem = scene->addPixmap(NorCellPicture);
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
    if (_counts.first == 0 || _counts.second == 0 || _celldepth_k < 1) return NandBegBlockItems;
    for (size_t i = 0; i < _counts.first-1; i++)
    {
        //for (size_t k = 0; k < _celldepth_k; k++)
        //{
        string str(_celldepth_k, '0');
        //if (_celldepth_k > 0) str.append(_celldepth_k, '0');
        if (words_table.first.size() > 0)
        {
            size_t pos = words_table.first[0].find("1", i*_celldepth_k);
            while (pos < (i+1)*_celldepth_k)
            {
                str[pos%_celldepth_k] = '1';
                pos = words_table.first[0].find("1", pos+1);
            }
            reverse(str.begin(), str.end());
            NandCellPicture = pictures["CELL_" + QString::number(str.size()).toStdString() + "_" + str];
        }
        else NandCellPicture = pictures["CELL_" + QString::number(str.size()).toStdString() + "_" + str];
        //}
        if (write_lighting.first && write_lighting.second == 0)
        {
            OUPicture = pictures["OUL"];
            OAOLPicture = pictures["OAOLL"];
        }
       // else if (read_lighting.first && read_lighting.second == 0) BIPicture = pictures["BIL"];
        else
        {
            OUPicture = pictures["OU"];
            OAOLPicture = pictures["OAOL"];
        }




        QGraphicsItem *URItem = scene->addPixmap(OUPicture);
        QGraphicsItem *ULItem = scene->addPixmap(OAOLPicture);
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
    if (_counts.first == 0 || _counts.second == 0 || _celldepth_k < 1) return NandMidBlockItems;
    for (size_t i = 0; i < _counts.first-1; i++)
    {
        for (size_t j = 1; j < _counts.second; j++)
        {
            string str(_celldepth_k, '0');
            if (words_table.first.size() > j)
            {
                size_t pos = words_table.first[j].find("1", i*_celldepth_k);
                while (pos < (i+1)*_celldepth_k)
                {
                    str[pos%_celldepth_k] = '1';
                    pos = words_table.first[j].find("1", pos+1);
                }
                reverse(str.begin(), str.end());
                NandCellPicture = pictures["CELL_" + QString::number(str.size()).toStdString() + "_" + str];
            }
            else NandCellPicture = pictures["CELL_" + QString::number(str.size()).toStdString() + "_" + str];

            if (write_lighting.first && write_lighting.second == j)
            {
                OUPicture = pictures["OUL"];
                TOIBPicture = pictures["TOIBOL"];
            }
            else if (read_lighting.first && read_lighting.second <= j)
            {
                if (read_lighting.second != j) TOIBPicture = pictures["TOIBBL"];
                else TOIBPicture = pictures["TOIB"];
            }
            else
            {
                OUPicture = pictures["OU"];
                TOIBPicture = pictures["TOIB"];
            }


            QGraphicsItem *URItem = scene->addPixmap(OUPicture);
            QGraphicsItem *ULItem = scene->addPixmap(TOIBPicture);
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
    if (_counts.first == 0 || _counts.second == 0 || _celldepth_k < 1) return NandEndBegBlockItems;
    string str(_celldepth_k, '0');
    if (words_table.first.size() > 0)
    {
        size_t pos = words_table.first[0].find("1", (_counts.first-1)*_celldepth_k);
        while (pos < _counts.first*_celldepth_k)
        {
            str[pos%_celldepth_k] = '1';
            pos = words_table.first[0].find("1", pos+1);
        }
        reverse(str.begin(), str.end());
        NandCellPicture = pictures["CELL_" + QString::number(str.size()).toStdString() + "_" + str];
    }
    else NandCellPicture = pictures["CELL_" + QString::number(str.size()).toStdString() + "_" + str];

    if (write_lighting.first && write_lighting.second == 0)
    {
        OUPicture = pictures["OUL"];
        OILPicture = pictures["OILL"];
    }
    else
    {
        OUPicture = pictures["OU"];
        OILPicture = pictures["OIL"];
    }


    QGraphicsItem *URItem = scene->addPixmap(OUPicture);
    QGraphicsItem *ULItem = scene->addPixmap(OILPicture);
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

    if (_counts.first == 0 || _counts.second == 0 || _celldepth_k < 1) return NandEndMidBlockItems;
        for (size_t i = 1; i < _counts.second; i++)
        {
            string str(_celldepth_k, '0');
           //if (_celldepth_k > 0) str.append(_celldepth_k, '0');
            if (words_table.first.size() > i)
            {
                size_t pos = words_table.first[i].find("1", (_counts.first-1)*_celldepth_k);
                while (pos < _counts.first*_celldepth_k)
                {
                    str[pos%_celldepth_k] = '1';
                    pos = words_table.first[i].find("1", pos+1);
                }
                reverse(str.begin(), str.end());
                NandCellPicture = pictures["CELL_" + QString::number(str.size()).toStdString() + "_" + str];
            }
            else NandCellPicture = pictures["CELL_" + QString::number(str.size()).toStdString() + "_" + str];

            if (write_lighting.first && write_lighting.second == i)
            {
                OUPicture = pictures["OUL"];
                OIBPicture = pictures["OIBOL"];
            }
            else if (read_lighting.first && read_lighting.second <= i)
            {
                if (read_lighting.second != i) OIBPicture = pictures["OIBBL"];
                else OIBPicture = pictures["OIB"];
            }
            else
            {
                OUPicture = pictures["OU"];
                OIBPicture = pictures["OIB"];
            }

            QGraphicsItem *URItem = scene->addPixmap(OUPicture);
            QGraphicsItem *ULItem = scene->addPixmap(OIBPicture);
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
    _celldepth_k = value;
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
    update();
}

bool MyGraphicsView::RecordInfo(string word)
{
    if (words_table.first.size() >= _counts.second) return false;
    words_table.first.push_back(word);
    write_lighting.first = true;
    write_lighting.second = words_table.first.size()-1; //
    timer->start(1000);
    update();
    return true;
}

string MyGraphicsView::ReadInfo(size_t number)
{
    if (number >= words_table.first.size()) return string();
    read_lighting.first = true;
    read_lighting.second = number;
    timer->start(1000);
    update();
    return words_table.first.at(number);
}

void MyGraphicsView::update()
{
    if (words_table.second != _counts.second)
    {
        words_table.first.clear();
        words_table.second = _counts.second;
    }
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

        if (write_lighting.first) write_lighting.first = false;
        if (read_lighting.first) read_lighting.first = false;
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
        if (write_lighting.first) write_lighting.first = false;
        if (read_lighting.first) read_lighting.first = false;
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
