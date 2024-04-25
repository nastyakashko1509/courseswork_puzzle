#ifndef TESTMOOD_H
#define TESTMOOD_H

#include <QDialog>
#include <QList>
#include <QRadioButton>

#include "puzzlethemes.h"

namespace Ui {
class TestMood;
}

class TestMood : public QDialog
{
    Q_OBJECT

public:
    explicit TestMood(QWidget *parent = nullptr);
    ~TestMood();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::TestMood *ui;

    // счётчики для определения настроения
    int counterGood = 0;
    int counterNormal = 0;
    int counterIrritated = 0;   // раздражённый
    int counterWicked = 0;      // злой
    int counterSad = 0;

    QList<QRadioButton*> radioButtons_1;
    QList<QRadioButton*> radioButtons_2;
    QList<QRadioButton*> radioButtons_3;
    QList<QRadioButton*> radioButtons_4;
    QList<QRadioButton*> radioButtons_5;

    void results_ofTest(int mood1, int mood2, int mood3, int mood4, int mood5);
};

#endif // TESTMOOD_H
