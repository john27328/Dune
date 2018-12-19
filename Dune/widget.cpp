#include "widget.h"
#include <QSize>
#include <QRect>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    //qDebug()<<"Widget";
    t=new QTimer;
    //resize(1000,1000);
    //qDebug()<<"Widget end";
    k=0;
    connect(t,SIGNAL(timeout()),this,SLOT(step()));
}

void Widget::paintEvent(QPaintEvent *)
{
    //qDebug()<<"paintEvent";
    //resize(1000,1000);
    QPainter paint(this);
    QPen pen1(Qt::white);
    QPen pen0(Qt::white);
    QBrush brush1(Qt::black);
    QBrush brush0(Qt::white);

    //qDebug()<<width()<<height();
    //const int N=100;

    double w=width(), h=height(),wr=w/nKl,hr=h/nKl;
    for (int i=0;i<nKl;i++)
        for (int j=0;j<nKl;j++)
        {

            if (d.live(i,j))
            {
                paint.setPen(pen1);
                paint.setBrush(brush1);
                paint.drawRect(QRect(wr*i,hr*j,wr,hr));
            }
//            else
//            {
//                paint.setPen(pen0);
//                paint.setBrush(brush0);
//            }
            //paint.drawRect(QRect(wr*i,hr*j,wr,hr));
            if(k!=0)
            {
                paint.setPen(Qt::black);
                paint.drawText(QRect(wr*i,hr*j,wr,hr),QString::number(d.m(i,j)));
            }
        }
    //qDebug()<<"paintEvent end";
}

void Widget::startT()
{
    //qDebug()<<"Widget::startT";
    //d.restart();
    t->start(500);

    //qDebug()<<"Widget::startT end";

}

void Widget::stopT()
{
    //qDebug()<<"Widget::stopT";
    t->stop();
    //qDebug()<<"Widget::stopT end";
}

void Widget::step()
{
    //qDebug()<<"Widget::step";
    d.step();
    update();
    //qDebug()<<"Widget::step end";
}

