/********************************************************************************
** Form generated from reading UI file 'addcolor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOLOR_H
#define UI_ADDCOLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_AddColor
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AddColor)
    {
        if (AddColor->objectName().isEmpty())
            AddColor->setObjectName(QStringLiteral("AddColor"));
        AddColor->resize(320, 228);
        verticalLayout = new QVBoxLayout(AddColor);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddColor);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(AddColor);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(255);
        spinBox->setValue(255);

        horizontalLayout->addWidget(spinBox);

        horizontalSlider = new QSlider(AddColor);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 10));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setValue(255);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(AddColor);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(AddColor);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(AddColor);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(AddColor);

        QMetaObject::connectSlotsByName(AddColor);
    } // setupUi

    void retranslateUi(QWidget *AddColor)
    {
        AddColor->setWindowTitle(QApplication::translate("AddColor", "Form", 0));
        label->setText(QApplication::translate("AddColor", "Choose Alpha:", 0));
        label_2->setText(QApplication::translate("AddColor", "Choose Mode:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("AddColor", "Normal", 0)
         << QApplication::translate("AddColor", "Darken", 0)
         << QApplication::translate("AddColor", "Multiply", 0)
         << QApplication::translate("AddColor", "Color Burn", 0)
         << QApplication::translate("AddColor", "Linear Burn", 0)
         << QApplication::translate("AddColor", "Lighten", 0)
         << QApplication::translate("AddColor", "Screen", 0)
         << QApplication::translate("AddColor", "Color Dodge", 0)
         << QApplication::translate("AddColor", "Linear Dodge", 0)
        );
        pushButton->setText(QApplication::translate("AddColor", "Choose Color and Accept", 0));
    } // retranslateUi

};

namespace Ui {
    class AddColor: public Ui_AddColor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOLOR_H
