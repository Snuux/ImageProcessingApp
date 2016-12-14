/********************************************************************************
** Form generated from reading UI file 'binarization.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINARIZATION_H
#define UI_BINARIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Binarization
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Binarization)
    {
        if (Binarization->objectName().isEmpty())
            Binarization->setObjectName(QStringLiteral("Binarization"));
        Binarization->resize(369, 295);
        verticalLayout = new QVBoxLayout(Binarization);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSlider = new QSlider(Binarization);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 10));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setValue(128);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        spinBox = new QSpinBox(Binarization);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(255);
        spinBox->setValue(128);

        horizontalLayout->addWidget(spinBox);

        pushButton = new QPushButton(Binarization);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(Binarization);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Binarization);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Binarization);

        QMetaObject::connectSlotsByName(Binarization);
    } // setupUi

    void retranslateUi(QWidget *Binarization)
    {
        Binarization->setWindowTitle(QApplication::translate("Binarization", "Form", 0));
        pushButton->setText(QApplication::translate("Binarization", "Simple Binarization", 0));
        pushButton_2->setText(QApplication::translate("Binarization", "Bredly Binarization", 0));
        pushButton_3->setText(QApplication::translate("Binarization", "Christian Binarization", 0));
    } // retranslateUi

};

namespace Ui {
    class Binarization: public Ui_Binarization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINARIZATION_H
