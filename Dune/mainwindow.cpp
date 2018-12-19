#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    //qDebug()<<"MainWindow::MainWindow";
    //resize(1000,1000);
    hl  = new QHBoxLayout;
    NL=new QLabel("N=");
    NSB = new QSpinBox; NSB->setRange(0,8);
    ML=new QLabel("M=");
    MSB = new QSpinBox; MSB->setRange(0,8);
    WL=new QLabel("W=");
    WSB = new QSpinBox; WSB->setRange(1,20);
    PL = new QLabel("P живая, %");
    PSB = new QSpinBox; PSB->setRange(-2,100);
    TSB = new QSpinBox; TSB->setRange(0,1000);
    cb = new QCheckBox("отладка");
    hl->addWidget(NL);
    hl->addWidget(NSB);
    hl->addWidget(ML);
    hl->addWidget(MSB);
    hl->addWidget(WL);
    hl->addWidget(WSB);
    hl->addWidget(PL);
    hl->addWidget(PSB);
    hl->addStretch();
    hl->addWidget(cb);
    pb = new QPushButton("Старт");
    pbC = new QPushButton("Стоп"); pbC->setEnabled(0);
    hl->addWidget(TSB); TSB->setEnabled(0);
    hl->addWidget(pb);
    hl->addWidget(pbC);
    vl = new QVBoxLayout;
    w = new Widget;

    //w->resize(600,600);
    w->setMinimumSize(600,600);
    vl->addWidget(w);
    vl->addLayout(hl);
    setLayout(vl);
    connect(pb,SIGNAL(clicked()),this,SLOT(startT()));
    connect(pbC,SIGNAL(clicked()),this,SLOT(stopT()));
    connect(NSB,SIGNAL(valueChanged(int)),this,SLOT(restart()));
    connect(MSB,SIGNAL(valueChanged(int)),this,SLOT(restart()));
    connect(WSB,SIGNAL(valueChanged(int)),this,SLOT(restart()));
    connect(PSB,SIGNAL(valueChanged(int)),this,SLOT(restart()));
    connect(w->t,SIGNAL(timeout()),this,SLOT(t()));
    connect(cb,SIGNAL(stateChanged(int)),this,SLOT(setCb(int)));

    restart();
    //qDebug()<<"MainWindow::MainWindow end";
}

MainWindow::~MainWindow()
{

}

void MainWindow::startT()
{
    //qDebug()<<"MainWindow::startT";
    pb->setEnabled(0);
    pbC->setEnabled(1);
    NSB->setEnabled(0);
    MSB->setEnabled(0);
    WSB->setEnabled(0);
    PSB->setEnabled(0);
    TSB->setValue(0);
    w->startT();
    //connect(w->t,SIGNAL(timeout()),this,SLOT(t()));
    //qDebug()<<"MainWindow::startT end";
}

void MainWindow::stopT()
{
    //qDebug()<<"MainWindow::stopT";
    pb->setEnabled(1);
    pbC->setEnabled(0);
    NSB->setEnabled(1);
    MSB->setEnabled(1);
    WSB->setEnabled(1);
    PSB->setEnabled(1);
    w->stopT();    w->d.restart(); w->update();
    //qDebug()<<"MainWindow::stopT end";
}

void MainWindow::restart()
{
    //qDebug()<<"MainWindow::restart";
    w->d.N=NSB->value();
    w->d.M=MSB->value();
    w->d.W=WSB->value();
    w->d.p=PSB->value();
    w->d.restart(); w->update();
    //qDebug()<<"re"<<w->d.N<<w->d.M<<w->d.W;
    //qDebug()<<"MainWindow::restart end";
}

void MainWindow::t()
{
    //qDebug()<<"MainWindow::t";
    TSB->setValue(TSB->value()+1);
    //qDebug()<<"MainWindow::t end";
}

void MainWindow::setCb(int kl)
{
    w->k=kl; qDebug()<<kl;
    w->update();
}

