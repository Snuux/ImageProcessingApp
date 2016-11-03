/********************************************************************************
** Form generated from reading UI file 'hsvcorrection.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HSVCORRECTION_H
#define UI_HSVCORRECTION_H

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

QT_BEGIN_NAMESPACE

class Ui_HSVCorrection
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSlider *horizontalSlider_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *HSVCorrection)
    {
        if (HSVCorrection->objectName().isEmpty())
            HSVCorrection->setObjectName(QStringLiteral("HSVCorrection"));
        HSVCorrection->resize(400, 300);
        verticalLayout = new QVBoxLayout(HSVCorrection);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(HSVCorrection);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox = new QSpinBox(HSVCorrection);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(-300);
        spinBox->setMaximum(300);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        horizontalSlider_2 = new QSlider(HSVCorrection);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_2->setMinimum(-100);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setValue(0);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setInvertedAppearance(false);
        horizontalSlider_2->setInvertedControls(false);

        gridLayout->addWidget(horizontalSlider_2, 1, 2, 1, 1);

        label = new QLabel(HSVCorrection);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSlider = new QSlider(HSVCorrection);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 10));
        horizontalSlider->setMinimum(-300);
        horizontalSlider->setMaximum(300);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 0, 2, 1, 1);

        label_3 = new QLabel(HSVCorrection);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spinBox_2 = new QSpinBox(HSVCorrection);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(-100);
        spinBox_2->setMaximum(100);

        gridLayout->addWidget(spinBox_2, 1, 1, 1, 1);

        spinBox_3 = new QSpinBox(HSVCorrection);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMinimum(-100);
        spinBox_3->setMaximum(100);

        gridLayout->addWidget(spinBox_3, 2, 1, 1, 1);

        horizontalSlider_3 = new QSlider(HSVCorrection);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_3->setMinimum(-100);
        horizontalSlider_3->setMaximum(100);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_3, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(HSVCorrection);

        QMetaObject::connectSlotsByName(HSVCorrection);
    } // setupUi

    void retranslateUi(QWidget *HSVCorrection)
    {
        HSVCorrection->setWindowTitle(QApplication::translate("HSVCorrection", "Form", 0));
        label_2->setText(QApplication::translate("HSVCorrection", "Saturation:", 0));
        label->setText(QApplication::translate("HSVCorrection", "Hue:", 0));
        label_3->setText(QApplication::translate("HSVCorrection", "Value:", 0));
    } // retranslateUi

};

namespace Ui {
    class HSVCorrection: public Ui_HSVCorrection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSVCORRECTION_H
