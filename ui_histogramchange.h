/********************************************************************************
** Form generated from reading UI file 'histogramchange.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMCHANGE_H
#define UI_HISTOGRAMCHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistogramChange
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QVBoxLayout *verticalLayout_4;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox_5;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *spinBox_6;
    QVBoxLayout *verticalLayout_6;
    QSlider *horizontalSlider_5;
    QSlider *horizontalSlider_6;
    QSlider *horizontalSlider_7;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *HistogramChange)
    {
        if (HistogramChange->objectName().isEmpty())
            HistogramChange->setObjectName(QStringLiteral("HistogramChange"));
        HistogramChange->resize(295, 295);
        verticalLayout = new QVBoxLayout(HistogramChange);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(HistogramChange);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFlat(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(255);
        spinBox->setValue(128);

        horizontalLayout->addWidget(spinBox);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(255);
        spinBox_2->setValue(128);

        horizontalLayout->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(255);
        spinBox_3->setValue(128);

        horizontalLayout->addWidget(spinBox_3);

        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMaximum(255);
        spinBox_4->setValue(128);

        horizontalLayout->addWidget(spinBox_4);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 10));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setValue(128);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider);

        horizontalSlider_2 = new QSlider(groupBox);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setValue(128);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider_2);

        horizontalSlider_3 = new QSlider(groupBox);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setValue(128);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider_3);

        horizontalSlider_4 = new QSlider(groupBox);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_4->setMaximum(255);
        horizontalSlider_4->setValue(128);
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider_4);


        verticalLayout_2->addLayout(verticalLayout_4);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(HistogramChange);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spinBox_5 = new QSpinBox(groupBox_2);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setMaximum(255);

        horizontalLayout_2->addWidget(spinBox_5);

        doubleSpinBox = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(0.01);
        doubleSpinBox->setMaximum(10);
        doubleSpinBox->setSingleStep(0.01);
        doubleSpinBox->setValue(1);

        horizontalLayout_2->addWidget(doubleSpinBox);

        spinBox_6 = new QSpinBox(groupBox_2);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setMaximum(255);

        horizontalLayout_2->addWidget(spinBox_6);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalSlider_5 = new QSlider(groupBox_2);
        horizontalSlider_5->setObjectName(QStringLiteral("horizontalSlider_5"));
        horizontalSlider_5->setMinimumSize(QSize(0, 10));
        horizontalSlider_5->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_5->setBaseSize(QSize(0, 10));
        horizontalSlider_5->setMaximum(255);
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(horizontalSlider_5);

        horizontalSlider_6 = new QSlider(groupBox_2);
        horizontalSlider_6->setObjectName(QStringLiteral("horizontalSlider_6"));
        horizontalSlider_6->setMinimumSize(QSize(0, 10));
        horizontalSlider_6->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_6->setBaseSize(QSize(0, 10));
        horizontalSlider_6->setMinimum(1);
        horizontalSlider_6->setMaximum(1000);
        horizontalSlider_6->setValue(100);
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(horizontalSlider_6);

        horizontalSlider_7 = new QSlider(groupBox_2);
        horizontalSlider_7->setObjectName(QStringLiteral("horizontalSlider_7"));
        horizontalSlider_7->setMinimumSize(QSize(0, 10));
        horizontalSlider_7->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_7->setBaseSize(QSize(0, 10));
        horizontalSlider_7->setMaximum(255);
        horizontalSlider_7->setValue(0);
        horizontalSlider_7->setOrientation(Qt::Horizontal);
        horizontalSlider_7->setInvertedAppearance(true);
        horizontalSlider_7->setInvertedControls(true);

        verticalLayout_6->addWidget(horizontalSlider_7);


        verticalLayout_5->addLayout(verticalLayout_6);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(HistogramChange);

        QMetaObject::connectSlotsByName(HistogramChange);
    } // setupUi

    void retranslateUi(QWidget *HistogramChange)
    {
        HistogramChange->setWindowTitle(QApplication::translate("HistogramChange", "Form", 0));
        groupBox->setTitle(QApplication::translate("HistogramChange", "4-value Histogram Correction", 0));
        groupBox_2->setTitle(QApplication::translate("HistogramChange", "3-value Histogram Correction", 0));
    } // retranslateUi

};

namespace Ui {
    class HistogramChange: public Ui_HistogramChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMCHANGE_H
