/********************************************************************************
** Form generated from reading UI file 'togreyscale.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOGREYSCALE_H
#define UI_TOGREYSCALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToGreyscale
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *horizontalGroupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QGroupBox *horizontalGroupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_6;
    QComboBox *comboBox;
    QGroupBox *horizontalGroupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_7;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ToGreyscale)
    {
        if (ToGreyscale->objectName().isEmpty())
            ToGreyscale->setObjectName(QStringLiteral("ToGreyscale"));
        ToGreyscale->resize(400, 339);
        verticalLayout = new QVBoxLayout(ToGreyscale);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(ToGreyscale);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(ToGreyscale);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(ToGreyscale);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        horizontalGroupBox = new QGroupBox(ToGreyscale);
        horizontalGroupBox->setObjectName(QStringLiteral("horizontalGroupBox"));
        horizontalLayout = new QHBoxLayout(horizontalGroupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_4 = new QPushButton(horizontalGroupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(horizontalGroupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);


        verticalLayout->addWidget(horizontalGroupBox);

        horizontalGroupBox_2 = new QGroupBox(ToGreyscale);
        horizontalGroupBox_2->setObjectName(QStringLiteral("horizontalGroupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(horizontalGroupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_6 = new QPushButton(horizontalGroupBox_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);

        comboBox = new QComboBox(horizontalGroupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addWidget(horizontalGroupBox_2);

        horizontalGroupBox_3 = new QGroupBox(ToGreyscale);
        horizontalGroupBox_3->setObjectName(QStringLiteral("horizontalGroupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(horizontalGroupBox_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_7 = new QPushButton(horizontalGroupBox_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_3->addWidget(pushButton_7);

        spinBox = new QSpinBox(horizontalGroupBox_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(2);
        spinBox->setMaximum(50);

        horizontalLayout_3->addWidget(spinBox);

        horizontalSlider = new QSlider(horizontalGroupBox_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 10));
        horizontalSlider->setMinimum(2);
        horizontalSlider->setMaximum(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);


        verticalLayout->addWidget(horizontalGroupBox_3);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(ToGreyscale);

        QMetaObject::connectSlotsByName(ToGreyscale);
    } // setupUi

    void retranslateUi(QWidget *ToGreyscale)
    {
        ToGreyscale->setWindowTitle(QApplication::translate("ToGreyscale", "Form", 0));
        pushButton->setText(QApplication::translate("ToGreyscale", "Simple Average", 0));
        pushButton_2->setText(QApplication::translate("ToGreyscale", "Human Eye (0.3;0.59;0.11)", 0));
        pushButton_3->setText(QApplication::translate("ToGreyscale", "HSL Light (Cmax+Cmin)/2", 0));
        horizontalGroupBox->setTitle(QApplication::translate("ToGreyscale", "Decomposition", 0));
        pushButton_4->setText(QApplication::translate("ToGreyscale", "Max (p=max)", 0));
        pushButton_5->setText(QApplication::translate("ToGreyscale", "Min (p=min)", 0));
        horizontalGroupBox_2->setTitle(QApplication::translate("ToGreyscale", "Single Color Channel", 0));
        pushButton_6->setText(QApplication::translate("ToGreyscale", "Single Color Channel", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ToGreyscale", "Red Channel", 0)
         << QApplication::translate("ToGreyscale", "Green Channel", 0)
         << QApplication::translate("ToGreyscale", "Blue Channel", 0)
        );
        horizontalGroupBox_3->setTitle(QApplication::translate("ToGreyscale", "Custom N of gray shades", 0));
        pushButton_7->setText(QApplication::translate("ToGreyscale", "Custom N of gray shades", 0));
    } // retranslateUi

};

namespace Ui {
    class ToGreyscale: public Ui_ToGreyscale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOGREYSCALE_H
