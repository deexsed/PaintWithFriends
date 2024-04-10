#include "Paint.h"
#include "ui_paint.h"
#include <QColor>
#include <qdebug.h>
#include <QAbstractSlider>

Paint::Paint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Paint)

{
    ui->setupUi(this);
    scene = new PaintScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->mapToGlobal(QPoint(0, 0));
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, 7777);

    colorDialog = new QColorDialog(this);

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readingData()));
    connect(this, &Paint::signalColor, scene, &PaintScene::slotColor);
    connect(this, &Paint::signalBrush, scene, &PaintScene::slotBrush);
    connect(this, &Paint::signalInfo, scene, &PaintScene::drawFromOnline);
    connect(this, &Paint::signalTrans, scene, &PaintScene::sceneTrans);

    setMouseTracking(true);
    emit signalTrans(scene);
}

Paint::~Paint()
{
    delete ui;
}

void Paint::on_pushButton_clicked()
{
    if(color.isValid())
    {
        colorDialog->setCurrentColor(color);
        colorDialog->exec();
        if(colorDialog->selectedColor().isValid())
            color = colorDialog->selectedColor();
    }
    else
    {
        color = colorDialog->getColor();
    }
    emit signalColor(color);
}

void Paint::on_backGroundButton_clicked()
{
    if(backgroundColor.isValid())
    {
        colorDialog->setCurrentColor(backgroundColor);
        colorDialog->exec();
        if(colorDialog->selectedColor().isValid())
            backgroundColor = colorDialog->selectedColor();
    }
    else
    {
        backgroundColor = QColorDialog::getColor();
    }
    scene->setBackgroundBrush(QBrush(backgroundColor, Qt::SolidPattern));

    QByteArray sendBackground;
    sendBackground.append("background" + backgroundColor.name());
    udpSocket->writeDatagram(sendBackground, QHostAddress::LocalHost, 7777);
    sendBackground.clear();
    // Тестовый метод очистки (слишком большая ресурсозатрачиваемость)
//    QSize clearLayer = ui->graphicsView->maximumSize();
//    scene->addLine(clearLayer.width(),
//                   clearLayer.height(),
//                   -clearLayer.width(),
//                   -clearLayer.width(),
//                   QPen(Qt::white,6000,Qt::SolidLine,Qt::RoundCap));
}

void Paint::on_horizontalSlider_valueChanged(qint32 brushSize)
{
    emit signalBrush(brushSize);
    QString s = QString::number(brushSize);
    ui->label->setText(s);
}

void Paint::readingData()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress senderIP;
        quint16 senderPort;
        udpSocket->readDatagram(datagram.data(), datagram.size(), &senderIP, &senderPort);

        // Тестовый метод очистки
//        if(datagram == "clearLayer")
//        {
//            qDebug() <<  datagram;
//            on_clearButton_clicked();
//        }
        if(datagram.contains("background"))
        {
            datagram.remove(0, datagram.indexOf("#"));
            scene->setBackgroundBrush(QBrush(QString(datagram), Qt::SolidPattern));
            backgroundColor = QString(datagram);
        }
        else
        {
            QColor setColor = QString(datagram.left(datagram.indexOf("|")));
            datagram.remove(0, datagram.indexOf("|") + 1);
            qDebug() << setColor.name();

            qint32 setBrushSize = datagram.left(datagram.indexOf("|")).toInt();
            datagram.remove(0, datagram.indexOf("|") + 1);

            QString transferCoord = datagram;
            datagram.clear();

            emit signalInfo(transferCoord, setColor, setBrushSize);
        }
    }
}


void Paint::sendingDate(QString coordinate, QColor brushColor, qint32 brushSize)
{
    QByteArray sendData;
    QString s = brushColor.name() + "|" + QString::number(brushSize) + "|" + coordinate;
    sendData.append(s);
    udpSocket->writeDatagram(sendData, QHostAddress::Any, 7777);
    sendData.clear();
}




