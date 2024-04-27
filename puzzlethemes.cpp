#include "puzzlethemes.h"
#include "ui_puzzlethemes.h"

PuzzleThemes::PuzzleThemes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PuzzleThemes)
{
    ui->setupUi(this);
}

PuzzleThemes::~PuzzleThemes()
{
    delete ui;
}
