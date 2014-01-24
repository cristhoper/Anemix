#include "serialcontroller.h"


SerialController::SerialController(QObject *parent){

    PortSettings settings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_XONXOFF, 1000};
    serial = new QextSerialPort(settings,QextSerialPort::EventDriven,parent);

    enumerator = new QextSerialEnumerator(parent);
    enumerator->setUpNotifications();

    connect(enumerator, SIGNAL(deviceDiscovered(QextPortInfo)), this, SLOT(refreshEnumerate(QextPortInfo)));
    connect(enumerator, SIGNAL(deviceRemoved(QextPortInfo)), this, SLOT(refreshEnumerate(QextPortInfo)));
    connect(serial,SIGNAL(readyRead()),this,SLOT(write()));
}

SerialController::~SerialController(){
    serial->close();
    delete serial;
    serial = NULL;
}

void SerialController::refreshEnumerate(QextPortInfo){
    emit deviceChange();
}

QList<QString> SerialController::enumerate(){

    QList<QString> portList = QList<QString>();
    foreach (QextPortInfo info, enumerator->getPorts()){
        portList.append(info.portName);
    }

    return portList;
}

void SerialController::selectedPort(QString portName){

    foreach (QextPortInfo info, QextSerialEnumerator::getPorts()){
        if(portName==info.portName){
            serial->setPortName(portName);
        }
    }
    qDebug() << serial->portName() << " Selected";
    serial->open(QIODevice::ReadWrite);
}

void SerialController::save(QStringList values){
    bufferList = values;

}

void SerialController::write(){
    qDebug() << "Waiting...";
    if(bufferList.size()>0){
        QByteArray data;
        int a = serial->bytesAvailable();
        data.resize(a);
        serial->read(data.data(), data.size());
        qDebug() << "received: " << data;
        if(data.contains("A")){
            QString rcv = bufferList[0];
            serial->write(rcv.toStdString().c_str(),rcv.size());
            serial->flush();
            serial->waitForBytesWritten(250);
            qDebug() << "sended: " << rcv;
            return;
        }
        else if(data.contains("B")){
            QString rcv = bufferList[1];
            serial->write(rcv.toStdString().c_str(),rcv.size());
            serial->flush();
            serial->waitForBytesWritten(250);
            qDebug() << "sended: " << rcv;
            return;
        }
        else if(data.contains("C")){
            QString rcv = bufferList[2];
            serial->write(rcv.toStdString().c_str(),rcv.size());
            serial->flush();
            serial->waitForBytesWritten(250);
            qDebug() << "sended: " << rcv;
            return;
        }
        else if(data.contains("D")){
            QString rcv = bufferList[3];
            serial->write(rcv.toStdString().c_str(),rcv.size());
            serial->flush();
            serial->waitForBytesWritten(250);
            qDebug() << "sended: " << rcv;
            return;
        }
        else if(data.contains("E")){
            QString rcv = bufferList[4];
            serial->write(rcv.toStdString().c_str(),rcv.size());
            serial->flush();
            serial->waitForBytesWritten(250);
            qDebug() << "sended: " << rcv;
            return;
        }
        else if(data.contains("F")){
            bufferList.clear();
            serial->flush();
            serial->close();
            serial->setPortName("");
            emit transmissionEnd();
            return;
        }
    }
    else{
        return;
    }
}








