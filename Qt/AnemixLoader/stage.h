#ifndef STAGE_H
#define STAGE_H

#include <QLineEdit>
#include <QLabel>
#include <QPainter>
#include <QFont>
#include <QColor>
#include <QIntValidator>
#include <QtDebug>

class Stage: public QWidget {
    Q_OBJECT

public:
    explicit Stage(bool down = false, QWidget *parent = 0,int x = 0, int y = 0, int w = WIDTH, int h = HEIGHT);
    explicit Stage(bool down = false, QWidget *parent = 0, QRect *position = 0);
    ~Stage();

    QColor getColor();
    void setColor(QString values);

protected:
  void paintEvent(QPaintEvent *event);


public slots:

private slots:
  void setRed(QString val);
  void setGreen(QString val);
  void setBlue(QString val);

signals:
  void redValue(int,QString);
  void greenValue(int,QString);
  void blueValue(int,QString);

private:
    QLineEdit *inputR, *inputG, *inputB;
    QLineEdit *inputTu, *inputTf;

    QLabel *labelR, *labelG, *labelB;
    QLabel *labelTu, *labelTf;

    QColor *color;

    bool down;
    static const int WIDTH=100;
    static const int HEIGHT=119;

};

#endif
