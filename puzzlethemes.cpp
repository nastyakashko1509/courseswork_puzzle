#include "puzzlethemes.h"
#include "ui_puzzlethemes.h"

PuzzleThemes::PuzzleThemes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PuzzleThemes)
{
    ui->setupUi(this);

    ui->pushButton->setStyleSheet("background-color: green;");
    ui->comboBox->setStyleSheet("background-color: green;");

    QPixmap backgroundImage("/home/nastya/Загрузки/fon1.jpg"); // путь к изображению
    ui->label->setPixmap(backgroundImage.scaled(ui->label->size(), Qt::IgnoreAspectRatio));
}

PuzzleThemes::~PuzzleThemes()
{
    delete ui;
}
