#ifndef TRANSITION_H
#define TRANSITION_H

#include <QLineEdit>
#include <QLabel>
#include <QFont>
#include <QIntValidator>


class Transition : public QWidget
{
    Q_OBJECT

public:
    explicit Transition(QWidget *parent = 0,int x = 0, int y = 0, int w = WIDTH, int h = HEIGHT);
    explicit Transition(QWidget *parent = 0, QRect *position = 0);
    ~Transition();
    int getUptime();
    int getFadetime();
    void setTimes(QString values);

private slots:
    void setFade(QString val);
    void setUp(QString val);

private:
    QLineEdit *inputTu, *inputTf;

    QLabel *labelTu, *labelTf;
    int upTime,fadeTime;

    static const int WIDTH=100;
    static const int HEIGHT=119;
    
};

#endif // TR
