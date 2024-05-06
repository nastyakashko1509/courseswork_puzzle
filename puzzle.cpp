#include "puzzle.h"
#include "ui_puzzle.h"
#include <QMouseEvent>
#include <QScrollBar>
#include <QRandomGenerator>
#include <QTimer>
#include <cmath>

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

    // Загрузка изображения с последующей задержкой перед показом пазлов
    loadImage();
}

void Puzzle::loadImage()
{
    // Загрузка изображения
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
    QGraphicsPixmapItem *backgroundItem = scene->addPixmap(pixmap);
    backgroundItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
    backgroundItem->setFlag(QGraphicsItem::ItemIsMovable, false);
    backgroundItem->setPos((view->viewport()->width() - pixmap.width() * scaleFactor) / 2,
                           (view->viewport()->height() - pixmap.height() * scaleFactor) / 2);

    // Разбиение изображения на части
    pieceWidth = pixmap.width() / 3;
    pieceHeight = pixmap.height() / 2;
    const qreal pieceScale = 10.0;  // Масштаб для кусочков пазла

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

            // Добавление контура вместо пазлинки
            QGraphicsRectItem *outline = new QGraphicsRectItem(QRectF(i * pieceWidth * pieceScale, j * pieceHeight * pieceScale, pieceWidth * pieceScale, pieceHeight * pieceScale), nullptr);
            QPen pen(Qt::red);
            pen.setWidthF(4.0); // Установка толщины контура
            outline->setPen(pen);
            outline->setFlag(QGraphicsItem::ItemIsSelectable, false);
            outline->setFlag(QGraphicsItem::ItemIsMovable, false);
            scene->addItem(outline);
        }
    }

    // Инициализация начальных позиций пазлинок
    for (QGraphicsPixmapItem *item : pieces)
    {
        initialPositions.append(item->pos());
    }

    // Показываем изображение на некоторое время, затем перемешиваем пазлы
    QTimer::singleShot(5000, [=]() {
        scene->removeItem(backgroundItem);
        delete backgroundItem;
        shufflePieces();
    });
}

void Puzzle::shufflePieces()
{
    QList<QGraphicsPixmapItem *> shuffledPieces = pieces;
    for (int i = shuffledPieces.size() - 1; i > 0; --i)
    {
        int j = QRandomGenerator::global()->bounded(i + 1); // Получаем случайный индекс от 0 до i
        std::swap(shuffledPieces[i], shuffledPieces[j]); // Перемещаем элементы списка
    }

    qreal x = 0, y = 0;
    for (QGraphicsPixmapItem *item : shuffledPieces)
    {
        item->setPos(x, y);
        x += pieceWidth * 10;
        if (x >= 3 * pieceWidth * 10)
        {
            x = 0;
            y += pieceHeight * 10;
        }
    }
}

void Puzzle::checkCompleted()
{
    bool completed = true;
    for (QGraphicsPixmapItem *item : pieces)
    {
        qreal distance = QLineF(item->pos(), QPointF(item->x(), item->y())).length();
        if (distance == 0)
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
        selectedPiece = dynamic_cast<QGraphicsPixmapItem *>(item);
        if (selectedPiece) {
            lastMousePos = event->pos();
            qreal randomAngle = QRandomGenerator::global()->generate() * 2 * M_PI;
            QPointF randomDirection = QPointF(cos(randomAngle), sin(randomAngle));
            initialPos = selectedPiece->pos();
        } else {
            qDebug() << "Error: Selected item is not a QGraphicsPixmapItem";
        }
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
        qreal minDistance = 0.8 * pieceWidth * 10;
        QPointF correctPos = initialPos;
        bool moved = false;

        // Инициализация зарезервированных позиций пазлинок
        for (int i = 0; i < pieces.size(); ++i)
        {
            reservedPositionsMap[pieces[i]] = initialPositions[i];
            qreal distance = QLineF(selectedPiece->scenePos(), reservedPositionsMap[selectedPiece]).length();

            // Проверка расстояний между перемещенной пазлинкой и ее зарезервированной позицией
            if (distance < minDistance)
            {
                correctPos = reservedPositionsMap[selectedPiece];
                moved = true;
            }

            if (moved)
            {
                selectedPiece->setPos(correctPos);
                checkCompleted();
            }
            else
            {
                selectedPiece->setPos(initialPos);
            }
            selectedPiece = nullptr;
        }
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
