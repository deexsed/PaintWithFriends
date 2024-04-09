#include "paintscene.h"
#include <qdebug.h>
#include "paint.h"
#include <QGraphicsItemGroup>
#include <QThread>

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
    QList<QPointF> coordinateArray;

    QList<QPointF> coordinateArrayCursor;

    group_1 = new QGraphicsItemGroup();
}

PaintScene::~PaintScene()
{

}


void PaintScene::drawFromOnline(QString setCoordinate, QColor brushColor, qint32 brushSize)
{

    if(setCoordinate.length() <= 10)
    {
        QPointF coordinate;
        coordinate.setX(setCoordinate.left(setCoordinate.indexOf("|")).toInt());
        setCoordinate.remove(0, setCoordinate.indexOf("|") + 1);
        coordinate.setY(setCoordinate.left(setCoordinate.indexOf("|")).toInt());
        setCoordinate.clear();

        addEllipse((coordinate.x() + 50) - brushSize/2,
                   (coordinate.y() + 50) - brushSize/2,
                   brushSize,
                   brushSize,
                   QPen(Qt::NoPen),
                   QBrush(brushColor));
        previousPointOnline = coordinate;
    }

    if(setCoordinate.length() > 15)
    {
        while(setCoordinate.length() > 1)
        {
            QPointF coordinate;
            coordinate.setX(setCoordinate.left(setCoordinate.indexOf("|")).toInt());
            setCoordinate.remove(0, setCoordinate.indexOf("|") + 1);
            coordinate.setY(setCoordinate.left(setCoordinate.indexOf("|")).toInt());
            setCoordinate.remove(0, setCoordinate.indexOf("|") + 1);

            coordinateArray << coordinate;
        }
        setCoordinate.clear();

        // Отрисовываем линии с использованием предыдущей координаты
            if(previousPointOnline == QPointF(0.0, 0.0))
            {
                previousPointOnline = coordinateArray.takeFirst();
            }
            while(coordinateArray.length() != 0)
            {
                QPointF tempest = coordinateArray.takeFirst();
                addLine(previousPointOnline.x()+50,
                        previousPointOnline.y()+50,
                        tempest.x()+50,
                        tempest.y()+50,
                        QPen(brushColor, brushSize, Qt::SolidLine, Qt::RoundCap));
                previousPointOnline = tempest;
            }
    }
    previousPointOnline = QPointF(0.0, 0.0);
}

void PaintScene::sceneTrans(PaintScene *scene)
{
    tempscene = scene;
    tempscene->addItem(group_1);
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // При нажатии кнопки мыши отрисовываем эллипс
    addEllipse(event->scenePos().x() - changedBrush/2,
               event->scenePos().y() - changedBrush/2,
               changedBrush,
               changedBrush,
               QPen(Qt::NoPen),
               QBrush(changedColor));
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();
    // Передача данных
    sendButtonPress = QString::number(previousPoint.x()) + "|" + QString::number(previousPoint.y()) + "|";
}


void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << event->scenePos();
    i++;
    group_1->hide();
    group_1 = new QGraphicsItemGroup();
    tempscene->addItem(group_1);
    i = 0;
    group_1->addToGroup(tempscene->addEllipse(event->scenePos().x() - changedBrush/2,
                                                         event->scenePos().y() - changedBrush/2,
                                                         changedBrush,
                                                         changedBrush,
                                              QPen(Qt::NoPen),
                                              QBrush(changedColor)));


    if( event->buttons() == Qt::LeftButton )
    {
    // Отрисовываем линии с использованием предыдущей координаты
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(changedColor,changedBrush,Qt::SolidLine,Qt::RoundCap));
    // Обновляем данные о предыдущей координате
    previousPoint = event->scenePos();
    // Передача данных
//    drawLineArray << previousPoint;
//    QPointF temp = drawLineArray.takeFirst();
    transferData += QString::number(previousPoint.x()) + "|" + QString::number(previousPoint.y()) + "|";
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        Paint paint;

        if(sendButtonPress != 0)
        {
            paint.sendingDate(sendButtonPress, changedColor, changedBrush);
            sendButtonPress.clear();
        }

        if(transferData != 0)
        {
            paint.sendingDate(transferData, changedColor, changedBrush);
            transferData.clear();
        }
    }
}

void PaintScene::slotColor(QColor a)
{
    changedColor = a;
}

void PaintScene::slotBrush(qint32 a)
{
    changedBrush = a;
}
