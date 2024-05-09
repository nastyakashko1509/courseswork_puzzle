// puzzle.h

#ifndef PUZZLE_H
#define PUZZLE_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QMessageBox>
#include <QTimer>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class Puzzle; }
QT_END_NAMESPACE

class Puzzle : public QDialog
{
    Q_OBJECT

public:
    Puzzle(QWidget *parent = nullptr);
    ~Puzzle();

protected:
    //void mousePressEvent(QMouseEvent *event) override;
    //void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::Puzzle *ui = nullptr;
    QGraphicsScene *scene = nullptr;
    QGraphicsView *view = nullptr;
    QList<QGraphicsPixmapItem *> pieces;
    QList<QPointF> initialPositions;
    QGraphicsPixmapItem *selectedPiece = nullptr;
    QPointF lastMousePos;
    QPointF initialPos;
    qreal pieceWidth;
    qreal pieceHeight;
    bool isPuzzleLoaded = false; // Инициализация переменной isPuzzleLoaded
    QVector<QPointF> reservedPositions;
    QMap<QGraphicsPixmapItem*, QPointF> reservedPositionsMap;

    void loadImage();
    void shufflePieces();
    void checkCompleted();
};

#endif // PUZZLE_H
