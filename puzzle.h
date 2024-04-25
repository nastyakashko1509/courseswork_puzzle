#ifndef PUZZLE_H
#define PUZZLE_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QRandomGenerator>
#include <QTimer>
#include <QMessageBox>
#include <QMouseEvent>

namespace Ui {
class Puzzle;
}

class Puzzle : public QDialog
{
    Q_OBJECT

public:
    explicit Puzzle(QWidget *parent = nullptr);
    ~Puzzle();

private slots:
    void loadImage();
    void shufflePieces();
    void checkCompleted();

private:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    Ui::Puzzle *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPixmapItem *selectedPiece = nullptr;
    QList<QGraphicsPixmapItem *> pieces;
    QPointF lastMousePos;
};

#endif // PUZZLE_H
