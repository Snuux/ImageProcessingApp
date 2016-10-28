/********************************************************************************
** Form generated from reading UI file 'brightnesscontrast.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGHTNESSCONTRAST_H
#define UI_BRIGHTNESSCONTRAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrightnessContrast
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *BrightnessContrast)
    {
        if (BrightnessContrast->objectName().isEmpty())
            BrightnessContrast->setObjectName(QStringLiteral("BrightnessContrast"));
        BrightnessContrast->resize(290, 103);
        verticalLayout = new QVBoxLayout(BrightnessContrast);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(BrightnessContrast);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox = new QSpinBox(BrightnessContrast);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(-255);
        spinBox->setMaximum(255);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        label = new QLabel(BrightnessContrast);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSlider_2 = new QSlider(BrightnessContrast);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(1000);
        horizontalSlider_2->setValue(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setInvertedAppearance(false);
        horizontalSlider_2->setInvertedControls(false);

        gridLayout->addWidget(horizontalSlider_2, 1, 2, 1, 1);

        horizontalSlider = new QSlider(BrightnessContrast);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 10));
        horizontalSlider->setMinimum(-255);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 0, 2, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(BrightnessContrast);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximum(10);
        doubleSpinBox->setSingleStep(0.01);
        doubleSpinBox->setValue(1);

        gridLayout->addWidget(doubleSpinBox, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(BrightnessContrast);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(BrightnessContrast);

        QMetaObject::connectSlotsByName(BrightnessContrast);
    } // setupUi

    void retranslateUi(QWidget *BrightnessContrast)
    {
        BrightnessContrast->setWindowTitle(QApplication::translate("BrightnessContrast", "Form", 0));
        label_2->setText(QApplication::translate("BrightnessContrast", "Contrast:", 0));
        label->setText(QApplication::translate("BrightnessContrast", "Brightness:", 0));
        pushButton->setText(QApplication::translate("BrightnessContrast", "Auto-Contrast", 0));
    } // retranslateUi

};

namespace Ui {
    class BrightnessContrast: public Ui_BrightnessContrast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGHTNESSCONTRAST_H
