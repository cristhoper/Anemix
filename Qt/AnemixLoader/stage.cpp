#include "stage.h"

Stage::Stage(bool down, QWidget *parent, QRect *position) :  QWidget(parent) {
    Stage(down, parent,position->x(),position->y(),position->width(),position->height());
}

Stage::Stage(bool down, QWidget *parent, int x, int y,int w,int h) :  QWidget(parent) {

    int down_yR, down_yG, down_yB;
    setGeometry(x,y,w,h);

    this->down = down;

    QFont newFont("Helvetica",10,0);
    this->setFont(newFont);

    color = new QColor(0,0,0);

    QString styleLineEdit = " QLineEdit { border: 0;}";
    QValidator *qVal = new QIntValidator(0, 255);

    inputR = new QLineEdit("0",this);
    inputG = new QLineEdit("0",this);
    inputB = new QLineEdit("0",this);

    labelR = new QLabel("R",this);
    labelG = new QLabel("G",this);
    labelB = new QLabel("B",this);

    inputR->setStyleSheet(styleLineEdit);
    inputG->setStyleSheet(styleLineEdit);
    inputB->setStyleSheet(styleLineEdit);

    inputR->setValidator(qVal);
    inputG->setValidator(qVal);
    inputB->setValidator(qVal);

    connect(inputR,SIGNAL(textChanged(QString)),this,SLOT(setRed(QString)));
    connect(inputG,SIGNAL(textChanged(QString)),this,SLOT(setGreen(QString)));
    connect(inputB,SIGNAL(textChanged(QString)),this,SLOT(setBlue(QString)));

    if(down){
        down_yR = 47;
        down_yG = 67;
        down_yB = 87;
    }
    else{
        down_yR = 6;
        down_yG = 26;
        down_yB = 46;
    }
    inputR->setGeometry(51,down_yR,28,14);
    inputG->setGeometry(51,down_yG,28,14);
    inputB->setGeometry(51,down_yB,28,14);
    labelR->setGeometry(35,down_yR,14,14);
    labelG->setGeometry(35,down_yG,14,14);
    labelB->setGeometry(35,down_yB,14,14);

}

void Stage::paintEvent(QPaintEvent *event){

    QPainter painter(this);

    int hx,hy,hw,hh;
    int rx,ry,rw,rh;
    int gx,gy,gw,gh;
    int bx,by,bw,bh;
    int cx,cy,cw,ch;

    /* Width & height */
    hw = 100;hh = 2;
    rw = 2;rh = 14;
    gw = 2;gh = 14;
    bw = 2;bh = 14;
    cw = 100;ch = 15;

    /* x & y */
    if(this->down){
        cx=0;cy=0;
        hx=0;hy=104;
        rx=49;ry=47;
        gx=49;gy=67;
        bx=49;by=87;
    }
    else{
        hx=0;hy=0;
        rx=49;ry=6;
        gx=49;gy=26;
        bx=49;by=46;
        cx=0;cy=104;
    }

    QRect h(hx,hy,hw,hh);
    QRect r(rx,ry,rw,rh);
    QRect g(gx,gy,gw,gh);
    QRect b(bx,by,bw,bh);
    QRect c(cx,cy,cw,ch);

    painter.fillRect(h,Qt::white);
    painter.fillRect(r,Qt::red);
    painter.fillRect(g,Qt::green);
    painter.fillRect(b,Qt::blue);
    painter.fillRect(c,getColor());

}

QColor Stage::getColor(){
    return color->toRgb();
}

void Stage::setColor(QString value){
    QStringList values = value.split(",");
    inputR->setText(values.at(0));
    inputG->setText(values.at(1));
    inputB->setText(values.at(2));
}

void Stage::setRed(QString value){
    qDebug() << "Valor: " << value;
    color->setRed(value.toInt());
    emit redValue(0,value);
    update();
}

void Stage::setGreen(QString value){
    qDebug() << "Valor: " << value;
    color->setGreen(value.toInt());
    emit greenValue(1,value);
    update();
}

void Stage::setBlue(QString value){
    qDebug() << "Valor: " << value;
    color->setBlue(value.toInt());
    emit blueValue(2,value);
    update();
}

Stage::~Stage(){
    delete inputR;
    delete inputG;
    delete inputB;
}
