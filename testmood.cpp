#include "testmood.h"
#include "ui_testmood.h"

TestMood::TestMood(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TestMood)
{
    ui->setupUi(this);

    ui->label_2->hide();
    ui->pushButton_2->hide();
    ui->radioButton_6->hide();
    ui->radioButton_7->hide();
    ui->radioButton_8->hide();
    ui->radioButton_9->hide();
    ui->radioButton_10->hide();

    ui->label_3->hide();
    ui->pushButton_3->hide();
    ui->radioButton_11->hide();
    ui->radioButton_12->hide();
    ui->radioButton_13->hide();
    ui->radioButton_14->hide();
    ui->radioButton_15->hide();

    ui->label_5->hide();
    ui->pushButton_4->hide();
    ui->radioButton_16->hide();
    ui->radioButton_17->hide();
    ui->radioButton_18->hide();
    ui->radioButton_19->hide();
    ui->radioButton_20->hide();

    ui->label_6->hide();
    ui->pushButton_5->hide();
    ui->radioButton_21->hide();
    ui->radioButton_22->hide();
    ui->radioButton_23->hide();
    ui->radioButton_24->hide();
    ui->radioButton_25->hide();

    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->textEdit->hide();

    QPixmap backgroundImage("/home/nastya/Загрузки/morning.jpg"); // путь к изображению
    ui->label_4->setPixmap(backgroundImage.scaled(ui->label_4->size(), Qt::IgnoreAspectRatio));
    QPixmap backgroundImage_1("/home/nastya/Загрузки/intresting.jpg"); // путь к изображению
    ui->label_7->setPixmap(backgroundImage_1.scaled(ui->label_7->size(), Qt::IgnoreAspectRatio));
    ui->label_7->hide();

    ui->pushButton->setStyleSheet("background-color: red;");
    ui->pushButton_2->setStyleSheet("background-color: orange;");
    ui->pushButton_3->setStyleSheet("background-color: yellow;");
    ui->pushButton_4->setStyleSheet("background-color: blue;");
    ui->pushButton_5->setStyleSheet("background-color: green;");
}

TestMood::~TestMood()
{
    delete ui;
}

void TestMood::on_pushButton_clicked()
{
    bool check = false;
    radioButtons_1 = {ui->radioButton, ui->radioButton_2, ui->radioButton_3, ui->radioButton_4, ui->radioButton_5};
    for(auto button : radioButtons_1)
    {
        if(button->isChecked())
        {
            check = true;
        }
    }

    if (check)
    {
        QPixmap backgroundImage("/home/nastya/Загрузки/vegetables.jpg"); // путь к изображению
        ui->label_4->setPixmap(backgroundImage.scaled(ui->label_4->size(), Qt::IgnoreAspectRatio));

        int countHelp = 0;
        for(auto button : radioButtons_1)
        {
            if(button->isChecked() && countHelp == 0) counterGood++;

            if(button->isChecked() && countHelp == 1) counterNormal++;

            if(button->isChecked() && countHelp == 2) counterIrritated++;

            if(button->isChecked() && countHelp == 3) counterWicked++;

            if(button->isChecked() && countHelp == 4) counterSad++;

            countHelp++;

            button->hide();
        }

        ui->label->hide();
        ui->pushButton->hide();

        ui->label_2->show();
        ui->pushButton_2->show();
        ui->radioButton_6->show();
        ui->radioButton_7->show();
        ui->radioButton_8->show();
        ui->radioButton_9->show();
        ui->radioButton_10->show();
    }
}


void TestMood::on_pushButton_2_clicked()
{
    bool check = false;
    radioButtons_2 = {ui->radioButton_6, ui->radioButton_7, ui->radioButton_8, ui->radioButton_9, ui->radioButton_10};
    for(auto button : radioButtons_2)
    {
        if(button->isChecked())
        {
            check = true;
        }
    }

    if (check)
    {
        QPixmap backgroundImage("/home/nastya/Загрузки/superplay.jpg"); // путь к изображению
        ui->label_4->setPixmap(backgroundImage.scaled(ui->label_4->size(), Qt::IgnoreAspectRatio));

        int countHelp = 0;
        for(auto button : radioButtons_2)
        {
            if(button->isChecked() && countHelp == 0) counterGood++;

            if(button->isChecked() && countHelp == 1) counterNormal++;

            if(button->isChecked() && countHelp == 2) counterIrritated++;

            if(button->isChecked() && countHelp == 3) counterWicked++;

            if(button->isChecked() && countHelp == 4) counterSad++;

            countHelp++;

            button->hide();
        }

        ui->label_2->hide();
        ui->pushButton_2->hide();

        ui->label_3->show();
        ui->pushButton_3->show();
        ui->radioButton_11->show();
        ui->radioButton_12->show();
        ui->radioButton_13->show();
        ui->radioButton_14->show();
        ui->radioButton_15->show();
    }
}


void TestMood::on_pushButton_3_clicked()
{
    bool check = false;
    radioButtons_3 = {ui->radioButton_11, ui->radioButton_12, ui->radioButton_13, ui->radioButton_14, ui->radioButton_15};
    for(auto button : radioButtons_3)
    {
        if(button->isChecked())
        {
            check = true;
        }
    }

    if (check)
    {
        QPixmap backgroundImage("/home/nastya/Загрузки/music.jpg"); // путь к изображению
        ui->label_4->setPixmap(backgroundImage.scaled(ui->label_4->size(), Qt::IgnoreAspectRatio));

        int countHelp = 0;
        for(auto button : radioButtons_3)
        {
            if(button->isChecked() && countHelp == 0) counterGood++;

            if(button->isChecked() && countHelp == 1) counterNormal++;

            if(button->isChecked() && countHelp == 2) counterIrritated++;

            if(button->isChecked() && countHelp == 3) counterWicked++;

            if(button->isChecked() && countHelp == 4) counterSad++;

            countHelp++;

            button->hide();
        }

        ui->label_3->hide();
        ui->pushButton_3->hide();

        ui->label_5->show();
        ui->pushButton_4->show();
        ui->radioButton_16->show();
        ui->radioButton_17->show();
        ui->radioButton_18->show();
        ui->radioButton_19->show();
        ui->radioButton_20->show();
    }
}


void TestMood::on_pushButton_4_clicked()
{
    bool check = false;
    radioButtons_4 = {ui->radioButton_16, ui->radioButton_17, ui->radioButton_18, ui->radioButton_19, ui->radioButton_20};
    for(auto button : radioButtons_4)
    {
        if(button->isChecked())
        {
            check = true;
        }
    }

    if (check)
    {
        QPixmap backgroundImage("/home/nastya/Загрузки/animal.jpg"); // путь к изображению
        ui->label_4->setPixmap(backgroundImage.scaled(ui->label_4->size(), Qt::IgnoreAspectRatio));

        int countHelp = 0;
        for(auto button : radioButtons_4)
        {
            if(button->isChecked() && countHelp == 0) counterGood++;

            if(button->isChecked() && countHelp == 1) counterNormal++;

            if(button->isChecked() && countHelp == 2) counterIrritated++;

            if(button->isChecked() && countHelp == 3) counterWicked++;

            if(button->isChecked() && countHelp == 4) counterSad++;

            countHelp++;

            button->hide();
        }

        ui->label_5->hide();
        ui->pushButton_4->hide();

        ui->label_6->show();
        ui->pushButton_5->show();
        ui->radioButton_21->show();
        ui->radioButton_22->show();
        ui->radioButton_23->show();
        ui->radioButton_24->show();
        ui->radioButton_25->show();
    }
}

void TestMood::on_pushButton_5_clicked()
{
    ui->label_4->hide();
    ui->label_6->hide();
    ui->pushButton_5->hide();
    ui->radioButton_21->hide();
    ui->radioButton_22->hide();
    ui->radioButton_23->hide();
    ui->radioButton_24->hide();
    ui->radioButton_25->hide();

    ui->pushButton_6->show();
    ui->textEdit->show();
    ui->label_7->show();
}

void TestMood::results_ofTest(int counterGood, int counterNormal, int counterIrritated, int counterWicked, int counterSad)
{
    QList<int> massMood = {counterGood, counterNormal, counterIrritated, counterWicked, counterSad};
    int max = counterGood;

    for(int i = 0; i < massMood.size(); i++)
    {
        if (massMood[i] > max) max = massMood[i];
    }

    if (max == counterGood) ui->textEdit->setText("У вас хорошее настроение");

    else if (max == counterNormal) ui->textEdit->setText("У вас нормальное настроение");

    else if (max == counterIrritated) ui->textEdit->setText("Вы раздражены");

    else if (max == counterWicked) ui->textEdit->setText("Вы злы");

    else ui->textEdit->setText("У вас плохое настроение");
}

void TestMood::on_pushButton_6_clicked()
{
    ui->pushButton_7->show();
    results_ofTest(counterGood, counterNormal, counterIrritated, counterWicked, counterSad);
}



void TestMood::on_pushButton_7_clicked()
{
    PuzzleThemes *puzzleThemes = new PuzzleThemes();
    puzzleThemes->show();
    this->hide();
}

