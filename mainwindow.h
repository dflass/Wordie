#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "correctwords.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void createList();
    QVector<QChar> obtainRand(QList<QString> dict7, int r);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void oneSec();

    void on_pushButton_4_clicked();

private:
    correctWords *listings;
    QTimer *timer;

    QVector<QChar> sevLet;
    QList<QString> all;
    QHash<QString, QString> dict;
    QList<QString> dict7;

    int sec;
    int playing;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
