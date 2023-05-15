/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *redValue_label;
    QLabel *greenValue_label;
    QLabel *blueValue_label;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QSlider *redSlider;
    QSlider *greenSlider;
    QSlider *blueSlider;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *redLed;
    QLabel *greenLed;
    QLabel *blueLed;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnOn;
    QPushButton *btnOff;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(480, 560);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(390, 20, 41, 92));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        redValue_label = new QLabel(layoutWidget);
        redValue_label->setObjectName("redValue_label");

        verticalLayout_3->addWidget(redValue_label);

        greenValue_label = new QLabel(layoutWidget);
        greenValue_label->setObjectName("greenValue_label");

        verticalLayout_3->addWidget(greenValue_label);

        blueValue_label = new QLabel(layoutWidget);
        blueValue_label->setObjectName("blueValue_label");

        verticalLayout_3->addWidget(blueValue_label);

        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(160, 20, 211, 91));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        redSlider = new QSlider(layoutWidget1);
        redSlider->setObjectName("redSlider");
        redSlider->setMaximum(255);
        redSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(redSlider);

        greenSlider = new QSlider(layoutWidget1);
        greenSlider->setObjectName("greenSlider");
        greenSlider->setMaximum(255);
        greenSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(greenSlider);

        blueSlider = new QSlider(layoutWidget1);
        blueSlider->setObjectName("blueSlider");
        blueSlider->setMaximum(255);
        blueSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(blueSlider);

        layoutWidget2 = new QWidget(Dialog);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(30, 20, 121, 91));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        redLed = new QLabel(layoutWidget2);
        redLed->setObjectName("redLed");

        verticalLayout->addWidget(redLed);

        greenLed = new QLabel(layoutWidget2);
        greenLed->setObjectName("greenLed");

        verticalLayout->addWidget(greenLed);

        blueLed = new QLabel(layoutWidget2);
        blueLed->setObjectName("blueLed");

        verticalLayout->addWidget(blueLed);

        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 190, 82, 121));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        btnOn = new QPushButton(widget);
        btnOn->setObjectName("btnOn");

        verticalLayout_4->addWidget(btnOn);

        btnOff = new QPushButton(widget);
        btnOff->setObjectName("btnOff");

        verticalLayout_4->addWidget(btnOff);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 0);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        redValue_label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">0</span></p></body></html>", nullptr));
        greenValue_label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">0</span></p></body></html>", nullptr));
        blueValue_label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">0</span></p></body></html>", nullptr));
        redLed->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#ff0000;\">Red LED</span></p></body></html>", nullptr));
        greenLed->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#55aa00;\">Green LED</span></p></body></html>", nullptr));
        blueLed->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#0f07ff;\">Bule LED</span></p></body></html>", nullptr));
        btnOn->setText(QCoreApplication::translate("Dialog", "On", nullptr));
        btnOff->setText(QCoreApplication::translate("Dialog", "Off", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "LED2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
