#ifndef PUZZLETHEMES_H
#define PUZZLETHEMES_H

#include <QDialog>
#include <QPalette>

namespace Ui {
class PuzzleThemes;
}

class PuzzleThemes : public QDialog
{
    Q_OBJECT

public:
    explicit PuzzleThemes(QWidget *parent = nullptr);
    ~PuzzleThemes();

private:
    Ui::PuzzleThemes *ui;
};

#endif // PUZZLETHEMES_H
