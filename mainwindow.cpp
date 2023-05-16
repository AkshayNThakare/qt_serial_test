#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

#include "3rdparty/qextserialport/src/qextserialport.h"
#include "qtimer.h"
#include "qevent.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"


QextSerialPort *port_1;
QextSerialPort *port_2;
QextSerialPort *port_3;
QextSerialPort *port_4;


QTimer *timerSplitterID;
static bool isopen = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    qApp->installEventFilter(this);


    ui->comboBox->clear();
    ui->comboBox->addItem("1200");
    ui->comboBox->addItem("2400");
    ui->comboBox->addItem("9600");
    ui->comboBox->addItem("19200");
    ui->comboBox->addItem("115200");

    ui->comboBox->setCurrentIndex(4);
    ui->pushButton->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openPorts()
{
    QString bdstr = ui->comboBox->currentText();

    qDebug() << bdstr << bdstr.toInt();
    port_1 = new QextSerialPort("/dev/ttysWK0");
//    port_2->setBaudRate(BAUD115200);
//    port_1->setBaudRate(BAUD2400);
    port_1->setBaudRate(BaudRateType(bdstr.toInt()));
    port_1->setFlowControl(FLOW_OFF);
    port_1->setParity(PAR_NONE);
    port_1->setDataBits(DATA_8);
    port_1->setStopBits(STOP_1);
    port_1->setTimeout(500);

    port_1->open(QIODevice::ReadWrite | QIODevice::Unbuffered);


    port_2 = new QextSerialPort("/dev/ttysWK1");
//    port_2->setBaudRate(BAUD115200);
//    port_2->setBaudRate(BAUD2400);
    port_2->setBaudRate(BaudRateType(bdstr.toInt()));
    port_2->setFlowControl(FLOW_OFF);
    port_2->setParity(PAR_NONE);
    port_2->setDataBits(DATA_8);
    port_2->setStopBits(STOP_1);
    port_2->setTimeout(500);

    port_2->open(QIODevice::ReadWrite | QIODevice::Unbuffered);

    port_3 = new QextSerialPort("/dev/ttysWK2");
//    port_3->setBaudRate(BAUD115200);
//    port_3->setBaudRate(BAUD2400);
    port_3->setBaudRate(BaudRateType(bdstr.toInt()));
    port_3->setFlowControl(FLOW_OFF);
    port_3->setParity(PAR_NONE);
    port_3->setDataBits(DATA_8);
    port_3->setStopBits(STOP_1);
    port_3->setTimeout(500);

    port_3->open(QIODevice::ReadWrite | QIODevice::Unbuffered);


    port_4 = new QextSerialPort("/dev/ttysWK3");
//    port_4->setBaudRate(BAUD115200);
//    port_4->setBaudRate(BAUD2400);
    port_4->setBaudRate(BaudRateType(bdstr.toInt()));
    port_4->setFlowControl(FLOW_OFF);
    port_4->setParity(PAR_NONE);
    port_4->setDataBits(DATA_8);
    port_4->setStopBits(STOP_1);
    port_4->setTimeout(500);

    port_4->open(QIODevice::ReadWrite | QIODevice::Unbuffered);

    connect(port_1, SIGNAL(readyRead()), this, SLOT(onDataAvailable1()));
    connect(port_2, SIGNAL(readyRead()), this, SLOT(onDataAvailable2()));
    connect(port_3, SIGNAL(readyRead()), this, SLOT(onDataAvailable3()));
    connect(port_4, SIGNAL(readyRead()), this, SLOT(onDataAvailable4()));
}

void MainWindow::closePorts()
{
    port_1->close();
    port_2->close();
    port_3->close();
    port_4->close();
}

void MainWindow::onDataAvailable1()
{
    if (port_1->isOpen())
    {
        QByteArray mdata = port_1->readAll();
        qDebug() << "port_1\n";

//        qDebug() << mdata.toHex(); // hex data
        qDebug() << mdata;  //  ascii data

        ui->lineEdit1->clear();
        ui->lineEdit1->setText(mdata);
    }
    else
    {
        qDebug() << "port_1 error 2 port is not open";
    }
   // port->close();
}

void MainWindow::onDataAvailable2()
{
    if (port_2->isOpen())
    {
        QByteArray mdata = port_2->readAll();
        qDebug() << "port_2\n";

//        qDebug() << mdata.toHex(); // hex data
        qDebug() << mdata;  //  ascii data

        ui->lineEdit2->clear();
        ui->lineEdit2->setText(mdata);
    }
    else
    {
        qDebug() << "port_2 error 2 port is not open";
    }
   // port->close();
}

void MainWindow::onDataAvailable3()
{
    if (port_3->isOpen())
    {
        QByteArray mdata = port_3->readAll();
        qDebug() << "port_1\n";

//        qDebug() << mdata.toHex(); // hex data
        qDebug() << mdata;  //  ascii data

        ui->lineEdit3->clear();
        ui->lineEdit3->setText(mdata);
    }
    else
    {
        qDebug() << "port_3 error 2 port is not open";
    }
   // port->close();
}

void MainWindow::onDataAvailable4()
{
    if (port_4->isOpen())
    {
        QByteArray mdata = port_4->readAll();
        qDebug() << "port_4\n";

//        qDebug() << mdata.toHex(); // hex data
        qDebug() << mdata;  //  ascii data

        ui->lineEdit4->clear();
        ui->lineEdit4->setText(mdata);
    }
    else
    {
        qDebug() << "port_4 error 2 port is not open";
    }
   // port->close();
}

//bool MainWindow::eventFilter(QObject *watched, QEvent *event)
//{
//    if (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease)
//    {
//        static bool isopen = true;
//        QKeyEvent *keyEvent1 = static_cast<QKeyEvent *>(event);
//        if(keyEvent1->key() == Qt::Key_Enter)
//        {
//            if(isopen){
//                qDebug() << "closing ports";
//                closePorts();
//           }
//            else {
//                qDebug() << "opening ports";
//                openPorts();
//            }
//        }
//        return QObject::eventFilter(watched, event);
//    }
//    else {
//        return QObject::eventFilter(watched, event);
//    }
//}

void MainWindow::on_pushButton_clicked()
{
    if(!isopen){
        qDebug() << "opening ports";
        openPorts();
        isopen = true;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(isopen){
        qDebug() << "closing ports";
        closePorts();
        ui->lineEdit1->clear();
        ui->lineEdit2->clear();
        ui->lineEdit3->clear();
        ui->lineEdit4->clear();
        isopen = false;
    }
}
