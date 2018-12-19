#ifndef DUNE_H
#define DUNE_H

#define nKl 100
class dune
{
public:
    dune();
    int live(int i,int j);
    void step();
    void restart();
    int N,M,W,p;
    int m(int i, int j);
private:
    int mas[nKl][nKl];
    int mas0[nKl][nKl];

};

#endif // DUNE_H
