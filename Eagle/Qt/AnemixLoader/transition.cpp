#include "transition.h"

Transition::Transition(QWidget *parent, QRect *position) :  QWidget(parent) {
    Transition(parent,position->x(),position->y(),position->width(),position->height());
}

Transition::Transition(QWidget *parent, int x, int y,int w,int h) :  QWidget(parent) {

    setGeometry(x,y,w,h);

    QFont newFont("Helvetica",10,0);
    this->setFont(newFont);

    QString styleLineEdit = " QLineEdit { border: 0;}";
    QValidator *qVal = new QIntValidator(0, 999);

    inputTu = new QLineEdit("0",this);
    inputTf = new QLineEdit("0",this);

    labelTf = new QLabel("->",this);
    labelTu = new QLabel("Time",this);

    inputTu->setStyleSheet(styleLineEdit);
    inputTf->setStyleSheet(styleLineEdit);

    inputTf->setValidator(qVal);
    inputTu->setValidator(qVal);

    connect(inputTf,SIGNAL(textChanged(QString)),this,SLOT(setFade(QString)));
    connect(inputTu,SIGNAL(textChanged(QString)),this,SLOT(setUp(QString)));

    labelTu->setGeometry(11,70,28,14);
    inputTu->setGeometry(41,70,28,14);

    labelTf->setGeometry(72,70,28,14);
    inputTf->setGeometry(86,70,28,14);

    upTime = 0;
    fadeTime = 0;

}

Transition::~Transition(){
    delete inputTu;
    delete inputTf;
}

int Transition::getUptime(){
    return upTime;
}

int Transition::getFadetime(){
    return fadeTime;
}

void Transition::setTimes(QString values){
    QStringList val = values.split("-");
    inputTu->setText(val.at(0));
    inputTf->setText(val.at(1));
}

void Transition::setFade(QString val){
    fadeTime = val.toInt();
}

void Transition::setUp(QString val){
    upTime = val.toInt();
}
