#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <dune.h>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    dune d;
    virtual void paintEvent(QPaintEvent*);
    QTimer *t;
    int k;
protected:
    //virtual void timerEvent(QTimerEvent *);
private:


signals:

public slots:
    void startT();
    void stopT();
    void step();

};

#endif // WIDGET_H
