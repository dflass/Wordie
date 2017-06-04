#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qdebug.h>
#include <algorithm>
#include <QFile.h>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sec = 0;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QFile dictionary("../wordsEn.txt");
    if(!dictionary.open((QFile::ReadOnly | QFile::Text))){
        qDebug() << "not working nut";
    }
    QTextStream in(&dictionary);
    QString q = in.readLine();
    while(q!=NULL){
        dict.insert(q,q);
        if(q.length()==7){dict7.append(q);}
        q=in.readLine();
    }
    createList();
    qDebug() << dict7.length();
    listings = new correctWords(all, this);
    QString sev = (QString)sevLet.at(0)+(QString)sevLet.at(1)+(QString)sevLet.at(2)+(QString)sevLet.at(3)+(QString)sevLet.at(4)+(QString)sevLet.at(5)+(QString)sevLet.at(6);
    listings->setString(sev);
    ui->verticalLayout->addWidget(listings);
    update();

    playing = 1;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(oneSec()));

    timer->start(1000);

    qDebug() << sev;
    qDebug() << "timr";
}

void MainWindow::oneSec(){
    if(playing == 1){
        sec+=1;
        if(sec==120){
            listings->timeUp();
            sec=0;
            timer->stop();
            playing = 0;
        }
        QString val = QString::number((120-sec)/60) + ":";
        if((120-sec)%60>=10) {val+=QString::number((120-sec)%60);}
        else{val+="0" + QString::number((120-sec)%60);}
        ui->lcdNumber->display(val);
    }
}

void MainWindow::createList(){
    sevLet = obtainRand(dict7,qrand()%(dict7.length()));
    qSort(sevLet);

    QList<QString> ans7;
    QList<QString> ans6;
    QList<QString> ans5;
    QList<QString> ans4;
    for(int p=1;p<=5040;p++){
        QString sevt = (QString)sevLet.at(0)+(QString)sevLet.at(1)+(QString)sevLet.at(2)+(QString)sevLet.at(3)+(QString)sevLet.at(4)+(QString)sevLet.at(5)+(QString)sevLet.at(6);
        QString sixt = (QString)sevLet.at(0)+(QString)sevLet.at(1)+(QString)sevLet.at(2)+(QString)sevLet.at(3)+(QString)sevLet.at(4)+(QString)sevLet.at(5);
        QString fivt = (QString)sevLet.at(0)+(QString)sevLet.at(1)+(QString)sevLet.at(2)+(QString)sevLet.at(3)+(QString)sevLet.at(4);
        QString fout = (QString)sevLet.at(0)+(QString)sevLet.at(1)+(QString)sevLet.at(2)+(QString)sevLet.at(3);
        if(dict.contains(sevt)){if(!ans7.contains(sevt)){ans7.append(sevt);};}
        if(dict.contains(sixt)){if(!ans6.contains(sixt)){ans6.append(sixt);};}
        if(dict.contains(fivt)){if(!ans5.contains(fivt)){ans5.append(fivt);};}
        if(dict.contains(fout)){if(!ans4.contains(fout)){ans4.append(fout);};}
        std::next_permutation(sevLet.begin(), sevLet.end());
    }
    all.clear();
    all.append(ans4);
    all.append(ans5);
    all.append(ans6);
    all.append(ans7);
}

QVector<QChar> MainWindow::obtainRand(QList<QString> dict7, int r)
{
    qDebug() << r;
    QString randWord = dict7.at(r);
    QVector<QChar> randChars;
    for(int i=0;i<7;i++){
        randChars.append(randWord.at(i));
    }
    return randChars;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString s = ui->lineEdit->text();
    listings->testWord(s);
    ui->lineEdit->clear();
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString s = ui->lineEdit->text();
    listings->testWord(s);
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    createList();
    listings->setList(all);
    QString sev = (QString)sevLet.at(0)+(QString)sevLet.at(1)+(QString)sevLet.at(2)+(QString)sevLet.at(3)+(QString)sevLet.at(4)+(QString)sevLet.at(5)+(QString)sevLet.at(6);
    listings->setString(sev);
    if(playing == 0){
        playing = 1;
        timer->start(1000);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    listings->cheat();
}

void MainWindow::on_pushButton_4_clicked()
{
    listings->timeUp();
    on_pushButton_3_clicked();
    sec=0;
    listings->update();
}
