#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

private:

    QPointF previousPoint;      // Координаты предыдущей точки
    QPointF previousPointOnline;
    QColor changedColor;
    qint32 changedBrush = 10;
    QList<QPointF> coordinateArray;
    QList<QPointF> drawLineArray;
    QString transferData;
    QPointF tempPaint;
    QString sendButtonPress;
    QGraphicsItemGroup  *group_1;
    PaintScene *tempscene;

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void slotColor(QColor a);
    void slotBrush(qint32 a);
    void drawFromOnline(QString setCoordinate, QColor brushColor, qint32 brushSize);
    void sceneTrans(PaintScene *scene);

};

#endif // PAINTSCENE_H
