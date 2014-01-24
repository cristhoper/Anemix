#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QComboBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QtDebug>
#include <QMovie>

#include "stage.h"
#include "transition.h"
#include "serialcontroller.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadValues();
    QString toHex(int num);
    void saveValues();

public slots:
    void sendToSerial(QString);
    void saveToFile();
    void loadFromFile();
    void reloadSerialPorts();

private:
    
    QLabel *labelStage1, *labelStage2, *labelStage3, *labelStage4, *labelStage5;
    QLabel *stage1, *stage2, *stage3, *stage4, *stage5;
    QLabel *processLabel;

    Stage *st1u, *st1d, *st2u, *st2d, *st3u, *st3d, *st4u, *st4d, *st5u, *st5d;
    Transition *tt1, *tt2, *tt3, *tt4, *tt5;

    QPushButton *loadButton, *saveButton, *reloadSerialButton;
    QComboBox *comboPorts;
    QList<QString> colorTimeList,colorTimeListSerial;

    SerialController *port;

};

#endif // MAINWINDOW_H
