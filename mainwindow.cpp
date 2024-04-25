#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->radioButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->radioButton_2->hide();
    ui->radioButton_3->hide();
    ui->radioButton_4->hide();
    ui->radioButton_5->hide();

    QPalette palette_1 = ui->label_2->palette();
    palette_1.setColor(QPalette::WindowText, QColor(Qt::white));
    ui->label_2->setPalette(palette_1);
    QPalette palette_2 = ui->label_3->palette();
    palette_2.setColor(QPalette::WindowText, QColor(Qt::white));
    ui->label_3->setPalette(palette_2);
    QPalette palette_3 = ui->label_4->palette();
    palette_3.setColor(QPalette::WindowText, QColor(Qt::white));
    ui->label_4->setPalette(palette_3);

    ui->pushButton->setStyleSheet("background-color: green;");
    ui->pushButton_2->setStyleSheet("background-color: green;");
    ui->pushButton_7->setStyleSheet("background-color: blue;");
    ui->pushButton_8->setStyleSheet("background-color: green;");
    ui->pushButton_9->setStyleSheet("background-color: yellow;");
    ui->pushButton_10->setStyleSheet("background-color: blue;");

    QPixmap backgroundImage("/home/nastya/Загрузки/puz.jpg"); // путь к изображению
    ui->label->setPixmap(backgroundImage.scaled(ui->label->size(), Qt::IgnoreAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->pushButton_2->show();
    ui->pushButton_7->show();
    ui->pushButton_8->show();
    ui->radioButton->show();
    ui->radioButton_2->show();
    ui->radioButton_3->show();
    ui->radioButton_4->show();
    ui->radioButton_5->show();
    ui->pushButton->hide();

}


void MainWindow::on_pushButton_7_clicked()
{
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->pushButton->hide();
    ui->radioButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->radioButton_2->hide();
    ui->radioButton_3->hide();
    ui->radioButton_4->hide();
    ui->radioButton_5->hide();
    ui->label_5->show();
    ui->pushButton_9->show();
}


void MainWindow::on_pushButton_9_clicked()
{
    TestMood *testMood = new TestMood();
    testMood->show();
    this->hide();
}


void MainWindow::on_pushButton_10_clicked()
{
    close();
}


void MainWindow::on_pushButton_8_clicked()
{
    PuzzleThemes *puzzleThemes = new PuzzleThemes();
    puzzleThemes->show();
    this->hide();
}


void MainWindow::on_pushButton_3_clicked()
{
    Puzzle *puzzle = new Puzzle();
    puzzle->show();
    this->hide();
}

