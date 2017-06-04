#include "correctwords.h"

correctWords::correctWords(QList<QString> words, QWidget *){

    points = 0;
    highScore = 0;
    allWords = words;
    for(int i = 0; i<allWords.length(); i++){
        foundWords.append(false);
    }
}

void correctWords::testWord(QString m){
    int y = allWords.indexOf(m);
    if((y!=-1)&&(foundWords.at(y)==false))
    {
        points += m.length();
        if(points>highScore){highScore=points;}
        foundWords.replace(y,true);
    }
    update();
}

void correctWords::setString(QString l){
    sevLet = l;
}

void correctWords::setList(QList<QString> words){
    allWords = words;
    foundWords.clear();
    for(int i = 0; i<allWords.length(); i++){
        foundWords.append(false);
    }
    update();
}

void correctWords::cheat(){
    foundWords.clear();
    for(int i = 0; i<allWords.length(); i++){
        foundWords.append(true);
    }
    update();
}

void correctWords::timeUp(){
    points = 0;
    cheat();
}

void correctWords::paintEvent(QPaintEvent*){
    QPainter painter(this);

    for(int i = 0; i<allWords.length(); i++){
        if(foundWords.at(i)){
            painter.drawText(50*(i/18)+10,10*(i%18)+10,allWords.at(i));
        }
        else{
            QString temp;
            for(int j = 0; j<allWords.at(i).length(); j++){
                temp.append("-");
            }
            painter.drawText(50*(i/18)+10,10*(i%18)+10,temp);
        }
    }
    painter.drawText(150,220, sevLet);
    painter.drawText(100,200, "Points:"+QString::number(points));
    painter.drawText(150,200, "High Score:"+QString::number(highScore));
}
