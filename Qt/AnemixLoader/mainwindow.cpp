#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    setAttribute(Qt::WA_AcceptTouchEvents);
    setGeometry(0,0,800,600);

    port = new SerialController(this);

    QFont smallFont = QFont("Helvetica",-1,QFont::Bold);
    QFont bigFont = QFont("Helvetica",-1,QFont::Bold);

    smallFont.setPointSize(10);
    bigFont.setPointSize(18);

    labelStage1 = new QLabel("",this);
    labelStage2 = new QLabel("",this);
    labelStage3 = new QLabel("",this);
    labelStage4 = new QLabel("",this);
    labelStage5 = new QLabel("",this);

    stage1 = new QLabel("STAGE 1",this);
    stage2 = new QLabel("STAGE 2",this);
    stage3 = new QLabel("STAGE 3",this);
    stage4 = new QLabel("STAGE 4",this);
    stage5 = new QLabel("STAGE 5",this);

    QLabel *title = new QLabel(this);
    QLabel *subTitle = new QLabel("COLOR CONTROL",this);

    QLabel *topTitle = new QLabel("TOP LED TAPE",this);
    QLabel *bottomTitle = new QLabel("BOTTOM LED TAPE",this);

    QLabel *uploadLabel = new QLabel(this);
    QPixmap uploadIcon(":/img/usb.png");

    QPixmap anemixIcon(":/img/the-anemix.png");
    QPixmap luxiaIcon(":/img/luxia.png");
    QPixmap octanoIcon(":/img/octano_logo.png");
    QPixmap loadIcon(":/img/load.png");
    QPixmap saveIcon(":/img/save.png");

    QMovie *movie = new QMovie(":/img/loading.gif");
    processLabel = new QLabel(this);

    QLabel *luxiaLabel = new QLabel(this);
    QLabel *octanoLabel = new QLabel(this);

    luxiaLabel->setPixmap(luxiaIcon);
    octanoLabel->setPixmap(octanoIcon);

    comboPorts = new QComboBox(this);

    comboPorts->addItems(port->enumerate());

    title->setPixmap(anemixIcon);
    subTitle->setFont(smallFont);
    topTitle->setFont(smallFont);
    bottomTitle->setFont(smallFont);

    stage1->setFont(smallFont);
    stage2->setFont(smallFont);
    stage3->setFont(smallFont);
    stage4->setFont(smallFont);
    stage5->setFont(smallFont);

    title->setGeometry(336,30,146,20);
    subTitle->setGeometry(356,50,128,10);
    topTitle->setGeometry(325,116,98,10);
    bottomTitle->setGeometry(325,454,130,10);

    stage1->setGeometry(62,157,54,10);
    stage2->setGeometry(193,157,54,10);
    stage3->setGeometry(325,157,54,10);
    stage4->setGeometry(455,157,54,10);
    stage5->setGeometry(594,157,54,10);

    int x1 = 40, x2 = 172, x3 = 304, x4 = 434, x5 = 568;
    int y1 = 176, y2 = 299, y3 = 350;

    st1u = new Stage(false,this,x1,y1);
    st1d = new Stage(true,this,x1,y2);
    tt1 = new Transition(this,x1,y3);

    st2u = new Stage(false,this,x2,y1);
    st2d = new Stage(true,this,x2,y2);
    tt2 = new Transition(this,x2,y3);

    st3u = new Stage(false,this,x3,y1);
    st3d = new Stage(true,this,x3,y2);
    tt3 = new Transition(this,x3,y3);

    st4u = new Stage(false,this,x4,y1);
    st4d = new Stage(true,this,x4,y2);
    tt4 = new Transition(this,x4,y3);

    st5u = new Stage(false,this,x5,y1);
    st5d = new Stage(true,this,x5,y2);
    tt5 = new Transition(this,x5,y3);

    int ww = 200, hh = 20;
    y3=500;

    labelStage1->setGeometry(x3,y3,ww,hh);
    labelStage2->setGeometry(x3,y3+hh,ww,hh);
    labelStage3->setGeometry(x3,y3+2*hh,ww,hh);
    labelStage4->setGeometry(x3,y3+3*hh,ww,hh);
    labelStage5->setGeometry(x3,y3+4*hh,ww,hh);

    uploadLabel->setGeometry(680,276,32,32);
    uploadLabel->setPixmap(uploadIcon);

    comboPorts->setGeometry(712,276,76,32);

    processLabel->setGeometry(688,308,16,16);
    processLabel->setMovie(movie);
    movie->start();

    luxiaLabel->setGeometry(715,550,66,32);
    octanoLabel->setGeometry(760,547,16,16);

    processLabel->hide();

    loadButton = new QPushButton(this);
    saveButton = new QPushButton(this);
    loadButton->setIcon(QIcon(loadIcon));
    saveButton->setIcon(QIcon(saveIcon));
    loadButton->setIconSize(QSize(24,24));
    saveButton->setIconSize(QSize(24,24));
    loadButton->setToolTip(tr("Load colors from file"));
    saveButton->setToolTip(tr("Save colors to file"));
    comboPorts->setToolTip(tr("Send colors to port"));
    loadButton->setGeometry(600,100,32,32);
    saveButton->setGeometry(637,100,32,32);

    colorTimeList = QList<QString>();
    colorTimeListSerial = QList<QString>();

    connect(comboPorts,SIGNAL(activated(QString)),this,SLOT(sendToSerial(QString)));
    connect(port,SIGNAL(transmissionEnd()),processLabel,SLOT(hide()));
    connect(saveButton,SIGNAL(clicked()),this,SLOT(saveToFile()));
    connect(loadButton,SIGNAL(clicked()),this,SLOT(loadFromFile()));
    connect(port,SIGNAL(deviceChange()),this,SLOT(reloadSerialPorts()));

}

MainWindow::~MainWindow()
{
    delete st1u;
    delete st2u;
    delete st3u;
    delete st4u;
    delete st5u;

    delete st1d;
    delete st2d;
    delete st3d;
    delete st4d;
    delete st5d;

    delete tt1;
    delete tt2;
    delete tt3;
    delete tt4;
    delete tt5;
}

void MainWindow::sendToSerial(QString val){
    processLabel->show();
    saveValues();
    port->save(colorTimeListSerial);
    port->selectedPort(val);

}

void MainWindow::reloadSerialPorts(){
    comboPorts->clear();
    comboPorts->addItems(port->enumerate());
}

void MainWindow::loadValues(){
    QStringList stage1val = colorTimeList.at(0).split("|");
    QStringList stage2val = colorTimeList.at(1).split("|");
    QStringList stage3val = colorTimeList.at(2).split("|");
    QStringList stage4val = colorTimeList.at(3).split("|");
    QStringList stage5val = colorTimeList.at(4).split("|");

    st1u->setColor(stage1val.at(1));
    st1d->setColor(stage1val.at(2));
    tt1->setTimes(stage1val.at(3));

    st2u->setColor(stage2val.at(1));
    st2d->setColor(stage2val.at(2));
    tt2->setTimes(stage2val.at(3));

    st3u->setColor(stage3val.at(1));
    st3d->setColor(stage3val.at(2));
    tt3->setTimes(stage3val.at(3));

    st4u->setColor(stage4val.at(1));
    st4d->setColor(stage4val.at(2));
    tt4->setTimes(stage4val.at(3));

    st5u->setColor(stage5val.at(1));
    st5d->setColor(stage5val.at(2));
    tt5->setTimes(stage5val.at(3));
}

void MainWindow::saveValues(){

    int r1,g1,b1,r2,g2,b2,tu,tf;

    colorTimeList.clear();
    colorTimeListSerial.clear();

    r1 = st1u->getColor().red();
    g1 = st1u->getColor().green();
    b1 = st1u->getColor().blue();
    r2 = st1d->getColor().red();
    g2 = st1d->getColor().green();
    b2 = st1d->getColor().blue();
    tu =tt1->getUptime();
    tf = tt1->getFadetime();
    colorTimeListSerial.append("H1|"+toHex(r1)+toHex(g1)+toHex(b1)+"|"+toHex(r2)+toHex(g2)+toHex(b2)+"|"+QString::number(tu) + "-"+QString::number(tf)+'G');
    colorTimeList.append("H1|"+QString::number(r1)+","+QString::number(g1)+","+QString::number(b1)+"|"+QString::number(r2)+","+QString::number(g2)+","+QString::number(b2)+"|"+QString::number(tu) + "-"+QString::number(tf));

    r1 = st2u->getColor().red();
    g1 = st2u->getColor().green();
    b1 = st2u->getColor().blue();
    r2 = st2d->getColor().red();
    g2 = st2d->getColor().green();
    b2 = st2d->getColor().blue();
    tu =tt2->getUptime();
    tf = tt2->getFadetime();
    colorTimeListSerial.append("H2|"+toHex(r1)+toHex(g1)+toHex(b1)+"|"+toHex(r2)+toHex(g2)+toHex(b2)+"|"+QString::number(tu) + "-"+QString::number(tf)+'G');
    colorTimeList.append("H2|"+QString::number(r1)+","+QString::number(g1)+","+QString::number(b1)+"|"+QString::number(r2)+","+QString::number(g2)+","+QString::number(b2)+"|"+QString::number(tu) + "-"+QString::number(tf));

    r1 = st3u->getColor().red();
    g1 = st3u->getColor().green();
    b1 = st3u->getColor().blue();
    r2 = st3d->getColor().red();
    g2 = st3d->getColor().green();
    b2 = st3d->getColor().blue();
    tu =tt3->getUptime();
    tf = tt3->getFadetime();
    colorTimeListSerial.append("H3|"+toHex(r1)+toHex(g1)+toHex(b1)+"|"+toHex(r2)+toHex(g2)+toHex(b2)+"|"+QString::number(tu) + "-"+QString::number(tf)+'G');
    colorTimeList.append("H3|"+QString::number(r1)+","+QString::number(g1)+","+QString::number(b1)+"|"+QString::number(r2)+","+QString::number(g2)+","+QString::number(b2)+"|"+QString::number(tu) + "-"+QString::number(tf));

    r1 = st4u->getColor().red();
    g1 = st4u->getColor().green();
    b1 = st4u->getColor().blue();
    r2 = st4d->getColor().red();
    g2 = st4d->getColor().green();
    b2 = st4d->getColor().blue();
    tu =tt4->getUptime();
    tf = tt4->getFadetime();
    colorTimeListSerial.append("H4|"+toHex(r1)+toHex(g1)+toHex(b1)+"|"+toHex(r2)+toHex(g2)+toHex(b2)+"|"+QString::number(tu) + "-"+QString::number(tf)+'G');
    colorTimeList.append("H4|"+QString::number(r1)+","+QString::number(g1)+","+QString::number(b1)+"|"+QString::number(r2)+","+QString::number(g2)+","+QString::number(b2)+"|"+QString::number(tu) + "-"+QString::number(tf));

    r1 = st5u->getColor().red();
    g1 = st5u->getColor().green();
    b1 = st5u->getColor().blue();
    r2 = st5d->getColor().red();
    g2 = st5d->getColor().green();
    b2 = st5d->getColor().blue();
    tu =tt5->getUptime();
    tf = tt5->getFadetime();
    colorTimeListSerial.append("H5|"+toHex(r1)+toHex(g1)+toHex(b1)+"|"+toHex(r2)+toHex(g2)+toHex(b2)+"|"+QString::number(tu) + "-"+QString::number(tf)+'G');
    colorTimeList.append("H5|"+QString::number(r1)+","+QString::number(g1)+","+QString::number(b1)+"|"+QString::number(r2)+","+QString::number(g2)+","+QString::number(b2)+"|"+QString::number(tu) + "-"+QString::number(tf));

}

void MainWindow::saveToFile(){
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Color configuration"), "",tr("Anemix Loader (*.anx);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),file.errorString());
            return;
        }
        saveValues();
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << colorTimeList;
    }
}

void MainWindow::loadFromFile(){
    QString fileName = QFileDialog::getOpenFileName(this,tr("Load Color configuration"), "",tr("Anemix Loader (*.anx);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        colorTimeList.clear();
        in >> colorTimeList;
        loadValues();
    }
}

QString MainWindow::toHex(int num)
{
    QChar val[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    QChar arg1 = val[num/16];
    QChar arg2 = val[num%16];

    QString ret = "";
    ret.append(arg1);
    ret.append(arg2);
    return ret;
}
