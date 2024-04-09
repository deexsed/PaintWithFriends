#include "Paint.h"
#include "ui_paint.h"
#include <QColorDialog>
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
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, 7777);

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
    QColor color = QColorDialog::getColor();
    emit signalColor(color);
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

        QColor setColor = QString(datagram.left(datagram.indexOf("|")));
        datagram.remove(0, datagram.indexOf("|") + 1);

        qint32 setBrushSize = datagram.left(datagram.indexOf("|")).toInt();
        datagram.remove(0, datagram.indexOf("|") + 1);

        QString transferCoord = datagram;
        datagram.clear();

        emit signalInfo(transferCoord, setColor, setBrushSize);
    }
}


void Paint::sendingDate(QString coordinate, QColor brushColor, qint32 brushSize)
{
    QByteArray sendData;
    QString s = brushColor.name() + "|" + QString::number(brushSize) + "|" + coordinate;
    sendData.append(s);
    udpSocket->writeDatagram(sendData, QHostAddress::LocalHost, 7777);
    sendData.clear();
}




