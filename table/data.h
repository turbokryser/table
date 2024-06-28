#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include<QString>
#include <QTextStream>
using namespace  std;



#endif // DATA_H

struct excer
{
    QString name;
    int amount;
    int weight;
    excer()
    {
        name="";
        amount=0;
        weight=0;
    }
    excer(int a, QString b, int c)
    {
        name=b;
        amount=a;
        weight=c;
    }
    friend QTextStream& operator>> (QTextStream& in, excer& b)
    {
        b.name=in.readLine();
        in>>b.amount>>b.weight;

     return in;
    }
    friend QTextStream& operator<< (QTextStream& of, excer& b)
    {
        of<<b.name<<endl<<b.amount<<" "<<b.weight;
        return of;
    }


};

struct anabolic
{
    QString name;
    int doze;
    anabolic()
    {
        name="";
        doze=0;
    }
    anabolic(int a, QString b)
    {
        name=b;
        doze=a;

    }
    friend QTextStream& operator>> (QTextStream& in, anabolic& b)
    {
        b.name=in.readLine();
        in>>b.doze;

        return in;
    }
    friend QTextStream& operator<< (QTextStream& of, anabolic& b)
    {
        of<<b.name<<endl<<b.doze;
        return of;
    }


};
