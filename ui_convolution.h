/********************************************************************************
** Form generated from reading UI file 'convolution.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVOLUTION_H
#define UI_CONVOLUTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Convolution
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *Convolution)
    {
        if (Convolution->objectName().isEmpty())
            Convolution->setObjectName(QStringLiteral("Convolution"));
        Convolution->resize(400, 300);
        verticalLayout = new QVBoxLayout(Convolution);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Convolution);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(Convolution);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setValue(3);

        horizontalLayout->addWidget(spinBox);

        spinBox_2 = new QSpinBox(Convolution);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setValue(3);

        horizontalLayout->addWidget(spinBox_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Convolution);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox = new QDoubleSpinBox(Convolution);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(-99.99);
        doubleSpinBox->setSingleStep(0.001);
        doubleSpinBox->setValue(1);

        horizontalLayout_2->addWidget(doubleSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        pushButton = new QPushButton(Convolution);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        plainTextEdit = new QPlainTextEdit(Convolution);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);


        retranslateUi(Convolution);

        QMetaObject::connectSlotsByName(Convolution);
    } // setupUi

    void retranslateUi(QWidget *Convolution)
    {
        Convolution->setWindowTitle(QApplication::translate("Convolution", "Form", 0));
        label->setText(QApplication::translate("Convolution", "Matrix Size:", 0));
        label_2->setText(QApplication::translate("Convolution", "Coefficient:", 0));
        pushButton->setText(QApplication::translate("Convolution", "Ok", 0));
        plainTextEdit->setPlainText(QApplication::translate("Convolution", "111\n"
"111\n"
"111", 0));
    } // retranslateUi

};

namespace Ui {
    class Convolution: public Ui_Convolution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVOLUTION_H
