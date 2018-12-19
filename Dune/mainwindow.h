#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "widget.h"

#include <QMainWindow>
#include <QSize>
#include <QRect>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QCheckBox>
//#define N 100


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSpinBox *NSB;
    QSpinBox *MSB;
    QSpinBox *WSB;
    QSpinBox *PSB;
    QSpinBox *TSB;
    QLabel *NL;
    QLabel *ML;
    QLabel *WL;
    QLabel *PL;
    QHBoxLayout *hl;
    QPushButton *pb;
    QPushButton *pbC;
    QVBoxLayout *vl;
    Widget *w;
    QCheckBox *cb;
public slots:
    void startT();
    void stopT();
    void restart();
    void t();
    void setCb(int k);
};

#endif // MAINWINDOW_H
