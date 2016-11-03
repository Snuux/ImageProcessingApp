/********************************************************************************
** Form generated from reading UI file 'blackwhitepoint.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLACKWHITEPOINT_H
#define UI_BLACKWHITEPOINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "libs/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_BlackWhitePoint
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *custom_plot;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider;
    QSpinBox *spinBox_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *BlackWhitePoint)
    {
        if (BlackWhitePoint->objectName().isEmpty())
            BlackWhitePoint->setObjectName(QStringLiteral("BlackWhitePoint"));
        BlackWhitePoint->resize(400, 300);
        verticalLayout = new QVBoxLayout(BlackWhitePoint);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        custom_plot = new QCustomPlot(BlackWhitePoint);
        custom_plot->setObjectName(QStringLiteral("custom_plot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(custom_plot->sizePolicy().hasHeightForWidth());
        custom_plot->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(custom_plot);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(BlackWhitePoint);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox = new QSpinBox(BlackWhitePoint);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(0);
        spinBox->setMaximum(255);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        label = new QLabel(BlackWhitePoint);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSlider_2 = new QSlider(BlackWhitePoint);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setValue(0);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setInvertedAppearance(true);
        horizontalSlider_2->setInvertedControls(false);

        gridLayout->addWidget(horizontalSlider_2, 1, 2, 1, 1);

        horizontalSlider = new QSlider(BlackWhitePoint);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 10));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 0, 2, 1, 1);

        spinBox_2 = new QSpinBox(BlackWhitePoint);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(255);

        gridLayout->addWidget(spinBox_2, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(BlackWhitePoint);

        QMetaObject::connectSlotsByName(BlackWhitePoint);
    } // setupUi

    void retranslateUi(QWidget *BlackWhitePoint)
    {
        BlackWhitePoint->setWindowTitle(QApplication::translate("BlackWhitePoint", "Form", 0));
        label_2->setText(QApplication::translate("BlackWhitePoint", "White Point:", 0));
        label->setText(QApplication::translate("BlackWhitePoint", "Black Point:", 0));
    } // retranslateUi

};

namespace Ui {
    class BlackWhitePoint: public Ui_BlackWhitePoint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLACKWHITEPOINT_H
