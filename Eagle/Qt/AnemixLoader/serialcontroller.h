#ifndef SERIALCONTROLLER_H
#define SERIALCONTROLLER_H

#include <QDebug>
#include <QStringList>
#include <QObject>
#include "qextserialport.h"
#include "qextserialenumerator.h"
#include <iostream>

class QextSerialPort;
class QextSerialEnumerator;

class SerialController: public QObject
{
    Q_OBJECT
public:
    explicit SerialController(QObject *parent = 0);
    ~SerialController();
    QList<QString> enumerate();
    void save(QStringList);
    void selectedPort(QString);

public slots:
    void refreshEnumerate(QextPortInfo);
    void write();

signals:
    void deviceChange();
    void transmissionEnd();

private:
    QextSerialPort *serial;
    QextSerialEnumerator *enumerator;
    int readBytes;
    QStringList bufferList;

};

#endif // SERIALCONTROLLER_H
