#ifndef CORRECTWORDS_H
#define CORRECTWORDS_H

#include <QObject>
#include <QWidget>
#include <QPainter>

class correctWords : public QWidget
{
    Q_OBJECT
public:
    explicit correctWords(QList<QString> words, QWidget *parent = 0);
    void testWord(QString m);
    void setString(QString l);
    void setList(QList<QString> words);
    void cheat();
    void timeUp();
signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);

private:
    int points;
    int highScore;
    QList<QString> allWords;
    QList<bool> foundWords;
    QString sevLet;
};

#endif // CORRECTWORDS_H
