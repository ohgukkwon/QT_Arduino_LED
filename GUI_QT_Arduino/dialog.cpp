
#include "dialog.h"
#include "./ui_dialog.h"
#include <QtSerialPort/QSerialPort>   //Qt 6
#include <QtSerialPort/QSerialPortInfo>  //Qt 6
#include <QDebug>
#include <QtWidgets>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;
//    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
//    foreach(const QSerialPortInfo & serialPortInfo, QSerialPortInfo::availablePorts()){
//        qDebug() <<"Was vender ID: "  <<serialPortInfo.hasVendorIdentifier();
//        if(serialPortInfo.hasVendorIdentifier()){
//            qDebug()<< "Vender ID: " << serialPortInfo.vendorIdentifier();
//        }
//        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
//        if(serialPortInfo.hasProductIdentifier()){
//            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
//        }
    foreach(const QSerialPortInfo &serialportInfo, QSerialPortInfo::availablePorts()){
        if(serialportInfo.hasVendorIdentifier() && serialportInfo.hasProductIdentifier()){
            if(serialportInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialportInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialportInfo.portName();
                    arduino_is_available = true;
                }
            }

        }

    }
    if(arduino_is_available){
        // open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }else{
        // give error message if not available
        QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
    }
}

Dialog::~Dialog()
{
    if(arduino ->isOpen()){
        arduino ->close();
    }
    delete ui;
}


void Dialog::on_redSlider_valueChanged(int value)
{
    ui->redValue_label->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%1</span>").arg(value));
    Dialog::updateRGB(QString("r%1").arg(value));
    qDebug() << value;
}

void Dialog::on_greenSlider_valueChanged(int value)
{
    ui->greenValue_label->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%1</span>").arg(value));
    Dialog::updateRGB(QString("g%1").arg(value));
    qDebug() << value;
}

void Dialog::on_blueSlider_valueChanged(int value)
{
    ui->blueValue_label->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%1</span>").arg(value));
    Dialog::updateRGB(QString("b%1").arg(value));
    qDebug() << value;
}

void Dialog::updateRGB(QString command)
{
    if(arduino->isWritable()){
        arduino->write(command.toStdString().c_str());
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}

void Dialog::on_btnOn_clicked()
{
    writeToSerialPort("on\n");
}


void Dialog::on_btnOff_clicked()
{
    writeToSerialPort("off\n");
}

void Dialog::writeToSerialPort(const QByteArray &data)
{
    //QSerialPort.write(data);
    arduino->write(data);
}

