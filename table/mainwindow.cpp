#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"
#include<QString>
#include <QStandardItemModel>
#include <vector>
#include <QFile>

QStandardItemModel* model=new QStandardItemModel(0,3);
QStandardItemModel* model2=new QStandardItemModel(0,2);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setWindowTitle("MyTable");
    ui->tableView->setMinimumHeight(550);
    ui->tableView->setMinimumWidth(700);
    ui->tableView2->setWindowTitle("MyTable");
    ui->tableView2->setMinimumHeight(550);
    ui->tableView2->setMinimumWidth(700);
    //QStandardItemModel* model=new QStandardItemModel(12,3);
    //QStandardItemModel* model2=new QStandardItemModel(12,3);

    model->setHeaderData(0, Qt::Horizontal, "упражнение");
    model->setHeaderData(1,Qt::Horizontal,"повторения");
    model->setHeaderData(2, Qt::Horizontal, "вес");
    model2->setHeaderData(0, Qt::Horizontal, "препарат");
    model2->setHeaderData(1,Qt::Horizontal,"дозировка, МГ");
    model2->setHeaderData(2, Qt::Horizontal, "дней в нед");

    ui->tableView->setModel(model);
    ui->tableView2->setModel(model2);


    vector<excer> t;
    QFile inp("Input.txt");
    if(inp.open(QIODevice::ReadOnly |  QIODevice::Text))
    {QTextStream in(&inp);
        int len;
        in>>len;
        in.readLine();
        for(int i=0; i<len; i++)
        {
            excer m;
            in>>m;
            QString name1=m.name;
            QString amount1=QString::number(m.amount);
            QString weight1=QString::number(m.weight);
            model->setItem(i,0,new QStandardItem(name1));
            model->setItem(i,1,new QStandardItem(amount1));
            model->setItem(i,2,new QStandardItem(weight1));
            t.push_back(m);
            in.readLine();

        }


    }
    vector<anabolic> t1;
    QFile inp2("Input2.txt");
    if(inp2.open(QIODevice::ReadOnly |  QIODevice::Text))
    {QTextStream in2(&inp2);
        int len;
        in2>>len;
        in2.readLine();
        for(int i=0; i<len; i++)
        {
            anabolic m;
            in2>>m;
            QString name1=m.name;
            QString doze1=QString::number(m.doze);
            model2->setItem(i,0,new QStandardItem(name1));
            model2->setItem(i,1,new QStandardItem(doze1));
            t1.push_back(m);
            in2.readLine();

        }


    }




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}


void MainWindow::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex()==0)
    {
        QString name1=ui->lineEdit->text();
        QString amount1=ui->lineEdit2->text();
        QString weight1=ui->lineEdit3->text();
        model->setItem(model->rowCount(),0,new QStandardItem(name1));
        model->setItem(model->rowCount()-1,1,new QStandardItem(amount1));
        model->setItem(model->rowCount()-1,2,new QStandardItem(weight1));


    }
    if(ui->comboBox->currentIndex()==1)
    {
        QString name1=ui->lineEdit->text();
        QString doze1=ui->lineEdit2->text();
        model2->setItem(model2->rowCount(),0,new QStandardItem(name1));
        model2->setItem(model2->rowCount()-1,1,new QStandardItem(doze1));


    }


}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->comboBox_2->currentIndex()==0)
    {
        int num1=ui->lineEdit4->text().toInt();
        model->removeRow(num1-1);


    }
    if(ui->comboBox_2->currentIndex()==1)
    {
        int num1=ui->lineEdit4->text().toInt();
        model2->removeRow(num1-1);


    }
}


void MainWindow::on_pushButton5_clicked()
{

    vector<excer> v;
    for(int i=0; i<model->rowCount(); i++)
    {
        QModelIndex h1=model->item(i,0)->index();
        QVariant a1=h1.data();
        QModelIndex h2=model->item(i,1)->index();
        QVariant a2=h2.data();
        QModelIndex h3=model->item(i,2)->index();
        QVariant a3=h3.data();
        excer g;
        g.name=a1.toString();
        g.amount=a2.toInt();
        g.weight=a3.toInt();
        v.push_back(g);


    }
    QFile oup("Input.txt");
    if(oup.open(QIODevice::WriteOnly | QIODevice::Text))
    {QTextStream out1(&oup);
        out1<<model->rowCount()<<endl;;
    for(int i=0; i<model->rowCount(); i++)
    {
            out1<<v[i]<<endl;

    }
    }

    vector<anabolic> v2;
    for(int i=0; i<model2->rowCount(); i++)
    {
        QModelIndex h1=model2->item(i,0)->index();
        QVariant a1=h1.data();
        QModelIndex h2=model2->item(i,1)->index();
        QVariant a2=h2.data();
        anabolic g;
        g.name=a1.toString();
        g.doze=a2.toInt();
        v2.push_back(g);


    }
    QFile oup2("Input2.txt");
    if(oup2.open(QIODevice::WriteOnly | QIODevice::Text))
    {QTextStream out2(&oup2);
        out2<<model2->rowCount()<<endl;;
        for(int i=0; i<model2->rowCount(); i++)
        {
            out2<<v2[i]<<endl;

        }
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    vector<excer> v;
    for(int i=0; i<model->rowCount(); i++)
    {
        QModelIndex h1=model->item(i,0)->index();
        QVariant a1=h1.data();
        QModelIndex h2=model->item(i,1)->index();
        QVariant a2=h2.data();
        QModelIndex h3=model->item(i,2)->index();
        QVariant a3=h3.data();
        excer g;
        g.name=a1.toString();
        g.amount=a2.toInt();
        g.weight=a3.toInt();
        v.push_back(g);


    }
    sort(v.begin(), v.end(), [](const excer &a, const excer &b)
         {
        return a.name < b.name;
    });
    for(int i=0; i<v.size(); i++)
    {

        QString name1=v[i].name;
        QString amount1=QString::number(v[i].amount);
        QString weight1=QString::number(v[i].weight);
        model->setItem(i,0,new QStandardItem(name1));
        model->setItem(i,1,new QStandardItem(amount1));
        model->setItem(i,2,new QStandardItem(weight1));


    }


}


void MainWindow::on_pushButton_3_clicked()
{
    vector<anabolic> v;
    for(int i=0; i<model2->rowCount(); i++)
    {
        QModelIndex h1=model2->item(i,0)->index();
        QVariant a1=h1.data();
        QModelIndex h2=model2->item(i,1)->index();
        QVariant a2=h2.data();
        anabolic g;
        g.name=a1.toString();
        g.doze=a2.toInt();
        v.push_back(g);


    }
    sort(v.begin(), v.end(), [](const anabolic &a, const anabolic &b)
         {
             return a.name < b.name;
         });
    for(int i=0; i<v.size(); i++)
    {

        QString name1=v[i].name;
        QString doze1=QString::number(v[i].doze);
        model2->setItem(i,0,new QStandardItem(name1));
        model2->setItem(i,1,new QStandardItem(doze1));


    }


}

