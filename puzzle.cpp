#include "puzzle.h"
#include "ui_puzzle.h"
#include <QMouseEvent>
#include <QScrollBar>

Puzzle::Puzzle(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Puzzle)
{
    ui->setupUi(this);

    // Создаем сцену и вид для отображения изображения
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    view->setGeometry(10, 50, 780, 500);
    view->setMouseTracking(true);  // Включаем отслеживание мыши
    view->setRenderHint(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Загрузка изображения
    loadImage();
}

void Puzzle::loadImage()
{
    QPixmap pixmap("/home/nastya/Загрузки/fon1.jpg");
    if (pixmap.isNull())
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось загрузить изображение");
        return;
    }

    // Установка масштаба для сцены
    qreal scaleFactor = qMin(view->viewport()->width() / qreal(pixmap.width()),
                             view->viewport()->height() / qreal(pixmap.height()));
    view->scale(scaleFactor, scaleFactor);

    // Добавление изображения на сцену
    QGraphicsPixmapItem *item = scene->addPixmap(pixmap);
    item->setFlag(QGraphicsItem::ItemIsSelectable, false);
    item->setFlag(QGraphicsItem::ItemIsMovable, false);
    item->setPos((view->viewport()->width() - pixmap.width() * scaleFactor) / 2,
                 (view->viewport()->height() - pixmap.height() * scaleFactor) / 2);

    // Разбиение изображения на части
    const int pieceWidth = pixmap.width() / 3;
    const int pieceHeight = pixmap.height() / 2;
    const qreal pieceScale = 10;  // Масштаб для кусочков пазла

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            QPixmap piece = pixmap.copy(i * pieceWidth, j * pieceHeight, pieceWidth, pieceHeight).scaled(pieceWidth * pieceScale, pieceHeight * pieceScale, Qt::KeepAspectRatio);
            QGraphicsPixmapItem *pieceItem = new QGraphicsPixmapItem(piece);
            pieceItem->setFlag(QGraphicsItem::ItemIsSelectable, true);
            pieceItem->setFlag(QGraphicsItem::ItemIsMovable, true);
            pieceItem->setPos(i * pieceWidth * pieceScale + QRandomGenerator::global()->bounded(-50, 50),
                              j * pieceHeight * pieceScale + QRandomGenerator::global()->bounded(-50, 50));
            scene->addItem(pieceItem);
            pieces.append(pieceItem);
        }
    }

    // Установка таймера для перемешивания частей
    QTimer::singleShot(5000, this, &Puzzle::shufflePieces);
}


void Puzzle::shufflePieces()
{
    for (QGraphicsPixmapItem *item : pieces)
    {
        item->setPos(QRandomGenerator::global()->bounded(view->viewport()->width() - item->boundingRect().width()),
                     QRandomGenerator::global()->bounded(view->viewport()->height() - item->boundingRect().height()));
    }
}

void Puzzle::checkCompleted()
{
    bool completed = true;
    for (QGraphicsPixmapItem *item : pieces)
    {
        if (qFuzzyCompare(item->x(), item->pos().x()) && qFuzzyCompare(item->y(), item->pos().y()))
        {
            completed = false;
            break;
        }
    }

    if (completed)
    {
        QMessageBox::information(this, "Поздравляем!", "Пазл собран!");
    }
}


void Puzzle::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView *currentView = scene->views().first();
    QGraphicsItem *item = scene->itemAt(currentView->mapToScene(event->pos()), currentView->transform());
    if (item && item != scene->items().first())
    {
        selectedPiece = static_cast<QGraphicsPixmapItem *>(item);
        lastMousePos = event->pos();
    }
    else
    {
        QCoreApplication::sendEvent(currentView, event);
    }
}

void Puzzle::mouseMoveEvent(QMouseEvent *event)
{
    if (selectedPiece)
    {
        QPointF delta = event->pos() - lastMousePos;
        selectedPiece->setPos(selectedPiece->pos() + delta);
        lastMousePos = event->pos();
    }
    else
    {
        QCoreApplication::sendEvent(view, event);
    }
}

void Puzzle::mouseReleaseEvent(QMouseEvent *event)
{
    if (selectedPiece)
    {
        selectedPiece = nullptr;
        checkCompleted();
    }
    else
    {
        QCoreApplication::sendEvent(view, event);
    }
}

Puzzle::~Puzzle()
{
    delete ui;
}
