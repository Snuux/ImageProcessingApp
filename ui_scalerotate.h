/********************************************************************************
** Form generated from reading UI file 'scalerotate.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALEROTATE_H
#define UI_SCALEROTATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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

class Ui_ScaleRotate
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QSlider *horizontalSlider_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QDoubleSpinBox *doubleSpinBox;
    QSlider *horizontalSlider;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QSpinBox *spinBox_4;
    QLabel *label_2;
    QSpinBox *spinBox_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QSpinBox *spinBox_6;
    QLabel *label_3;
    QSpinBox *spinBox_7;
    QPushButton *pushButton_11;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QSlider *horizontalSlider_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *ScaleRotate)
    {
        if (ScaleRotate->objectName().isEmpty())
            ScaleRotate->setObjectName(QStringLiteral("ScaleRotate"));
        ScaleRotate->resize(342, 428);
        verticalLayout = new QVBoxLayout(ScaleRotate);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_3 = new QPushButton(ScaleRotate);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);

        doubleSpinBox_3 = new QDoubleSpinBox(ScaleRotate);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setMinimum(0.2);
        doubleSpinBox_3->setMaximum(8);
        doubleSpinBox_3->setSingleStep(0.01);
        doubleSpinBox_3->setValue(1);

        horizontalLayout_3->addWidget(doubleSpinBox_3);

        horizontalSlider_3 = new QSlider(ScaleRotate);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setEnabled(true);
        horizontalSlider_3->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_3->setMinimum(20);
        horizontalSlider_3->setMaximum(800);
        horizontalSlider_3->setValue(100);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(ScaleRotate);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        doubleSpinBox = new QDoubleSpinBox(ScaleRotate);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(0.2);
        doubleSpinBox->setMaximum(8);
        doubleSpinBox->setSingleStep(0.01);
        doubleSpinBox->setValue(1);

        horizontalLayout->addWidget(doubleSpinBox);

        horizontalSlider = new QSlider(ScaleRotate);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 10));
        horizontalSlider->setMinimum(20);
        horizontalSlider->setMaximum(800);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);


        verticalLayout->addLayout(horizontalLayout);

        groupBox_2 = new QGroupBox(ScaleRotate);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(20000);

        verticalLayout_4->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(groupBox_2);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(20000);

        verticalLayout_4->addWidget(spinBox_3);


        horizontalLayout_4->addLayout(verticalLayout_4);

        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        horizontalLayout_4->addWidget(pushButton_10);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_6->addWidget(pushButton_5);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_6->addWidget(comboBox);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);

        spinBox_4 = new QSpinBox(groupBox_2);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMinimum(1);
        spinBox_4->setMaximum(20000);

        horizontalLayout_7->addWidget(spinBox_4);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_7->addWidget(label_2);

        spinBox_5 = new QSpinBox(groupBox_2);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setMinimum(1);
        spinBox_5->setMaximum(20000);

        horizontalLayout_7->addWidget(spinBox_5);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_8->addWidget(label_4);

        spinBox_6 = new QSpinBox(groupBox_2);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setMinimum(1);
        spinBox_6->setMaximum(20000);

        horizontalLayout_8->addWidget(spinBox_6);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_8->addWidget(label_3);

        spinBox_7 = new QSpinBox(groupBox_2);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setMinimum(1);
        spinBox_7->setMaximum(20000);

        horizontalLayout_8->addWidget(spinBox_7);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_2);

        pushButton_11 = new QPushButton(groupBox_2);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        horizontalLayout_9->addWidget(pushButton_11);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(ScaleRotate);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        spinBox = new QSpinBox(ScaleRotate);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(-360);
        spinBox->setMaximum(360);

        horizontalLayout_2->addWidget(spinBox);

        horizontalSlider_2 = new QSlider(ScaleRotate);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximumSize(QSize(16777215, 10));
        horizontalSlider_2->setMinimum(-360);
        horizontalSlider_2->setMaximum(360);
        horizontalSlider_2->setValue(0);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_2);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(ScaleRotate);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        checkBox = new QCheckBox(ScaleRotate);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(true);
        checkBox->setChecked(false);

        horizontalLayout_5->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(ScaleRotate);

        comboBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ScaleRotate);
    } // setupUi

    void retranslateUi(QWidget *ScaleRotate)
    {
        ScaleRotate->setWindowTitle(QApplication::translate("ScaleRotate", "Form", 0));
        pushButton_3->setText(QApplication::translate("ScaleRotate", "Nearest Neighbor", 0));
        pushButton->setText(QApplication::translate("ScaleRotate", "Bilinear Zoom", 0));
        groupBox_2->setTitle(QApplication::translate("ScaleRotate", "Fixed Operations", 0));
        pushButton_10->setText(QApplication::translate("ScaleRotate", "Resize", 0));
        pushButton_5->setText(QApplication::translate("ScaleRotate", "Zoom", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ScaleRotate", "x0.5", 0)
         << QApplication::translate("ScaleRotate", "x1", 0)
         << QApplication::translate("ScaleRotate", "x2", 0)
         << QApplication::translate("ScaleRotate", "x4", 0)
         << QApplication::translate("ScaleRotate", "x8", 0)
        );
        label->setText(QApplication::translate("ScaleRotate", "Left Top", 0));
        label_2->setText(QApplication::translate("ScaleRotate", "Right top", 0));
        label_4->setText(QApplication::translate("ScaleRotate", "Left Bot", 0));
        label_3->setText(QApplication::translate("ScaleRotate", "Right Bot", 0));
        pushButton_11->setText(QApplication::translate("ScaleRotate", "Crop", 0));
        pushButton_2->setText(QApplication::translate("ScaleRotate", "Rotate", 0));
        groupBox->setTitle(QApplication::translate("ScaleRotate", "Fixed Rotation", 0));
        pushButton_6->setText(QApplication::translate("ScaleRotate", "90\302\260 Clockwise", 0));
        pushButton_7->setText(QApplication::translate("ScaleRotate", "90\302\260 Counter Clockwise", 0));
        pushButton_4->setText(QApplication::translate("ScaleRotate", "180\302\260", 0));
        pushButton_8->setText(QApplication::translate("ScaleRotate", "Flip Horizontal", 0));
        pushButton_9->setText(QApplication::translate("ScaleRotate", "Flip Vertical", 0));
        checkBox->setText(QApplication::translate("ScaleRotate", "Real-Time", 0));
    } // retranslateUi

};

namespace Ui {
    class ScaleRotate: public Ui_ScaleRotate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALEROTATE_H
