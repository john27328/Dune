#include "dune.h"
#include <QDebug>
#include <time.h>

dune::dune()
{
    //qDebug()<<"dune";
    p=-2;
    restart();
     //qDebug()<<"dune  end";
}


int dune::live(int i, int j)
{
    //qDebug()<<"live";
    return mas[i][j]==0;
}
/*************************************************************************************************************
Разработайте автомат "Дюны", поведение которого подчинено следующим правилам:
1) клетка может находиться в активном и пассивном состоянии;
2) если клетка была активна и из восьми соседних клеток более N активны, то клетка прячется;
3) время нахождения в спрятанном состоянии равно W тактов;
4) если время прятанья окончилось и вокруг не более M активных клеток, то клетка вновь становится активной
**************************************************************************************************************/
void dune::step()
{
    //qDebug()<<"step";
    int s=0;
    for (int i=0;i<nKl;i++)
        for (int j=0;j<nKl;j++)
        {
            s=0;
            for (int i0=-1;i0<=1;i0++)
                for (int j0=-1;j0<=1;j0++)
                    if(!(i0==0 && j0==0))
                        if (live(i+i0,j+j0)) s++;
            //qDebug()<<s;
            if (mas[i][j]==0)
            {
                if (s>N) mas0[i][j]=W;
                //qDebug()<<"dead";
            }
            else
            {

                if (mas[i][j]!=1 || s<=M )
                    mas0[i][j]--;
            }
        }
    for (int i=0;i<nKl;i++)
        for (int j=0;j<nKl;j++)
            mas[i][j]=mas0[i][j];
    //qDebug()<<"step end ";
}

void dune::restart()
{
    //qDebug()<<"restart";
    srand(time(NULL));

    for (int i=0;i<nKl;i++)
        for (int j=0;j<nKl;j++)
        {
            if (p>0)
            {
                mas[i][j]=mas0[i][j]=W;
                if (int((rand()%100)/p)==0)  mas[i][j]=mas0[i][j]=0;
            }
            if (p==0)
                mas[i][j]=mas0[i][j]=rand()%W;
            if (p==-1)
            {
                if(i>nKl/3 && i<nKl*2/3 && j>nKl/3 && j<nKl*2/3)
                    mas[i][j]=mas0[i][j]=W;
                else
                    mas[i][j]=mas0[i][j]=0;
            }
            if (p==-2)
            {
                if(i>nKl/3 && i<nKl*2/3 && j>nKl/3 && j<nKl*2/3)
                    mas[i][j]=mas0[i][j]=0;
                else
                    mas[i][j]=mas0[i][j]=W;
            }
        }
}

int dune::m(int i, int j)
{
    int x;
    if((i)>=0 && (i)<nKl && (j)>=0 && (j)<nKl)
        x=mas[i][j];
    else
        x=1;
    return x;
}
