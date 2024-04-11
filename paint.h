#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QUdpSocket>
#include <QHostAddress>
#include <paintscene.h>
#include <QColorDialog>

namespace Ui {
class Paint;
}

class Paint : public QWidget
{
    Q_OBJECT

public:
    explicit Paint(QWidget *parent = 0);
    ~Paint();
    PaintScene *scene;  // Объявляем кастомную графическую сцену
    qint32 brushSize;

    void sendingDate(QString coordinate, QColor brushColor, qint32 brushSize);
    void getPaintStatus(bool isPaintDone);

private:
    Ui::Paint *ui;
    QUdpSocket *udpSocket;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    QColor color;
    QColor backgroundColor;
    QColorDialog *colorDialog;

signals:
    void signalColor(QColor);
    void signalBrush(qint32);
    void signalInfo(QString, QColor, qint32);
    void signalTrans(PaintScene *scene);

private slots:
    void on_pushButton_clicked();
    void on_horizontalSlider_valueChanged(qint32 value);
    void readingData();
    void on_backGroundButton_clicked();
};

#endif // PAINT_H
