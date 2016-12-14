/********************************************************************************
** Form generated from reading UI file 'boxgauss.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXGAUSS_H
#define UI_BOXGAUSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoxGauss
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *BoxGauss)
    {
        if (BoxGauss->objectName().isEmpty())
            BoxGauss->setObjectName(QStringLiteral("BoxGauss"));
        BoxGauss->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(BoxGauss);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(BoxGauss);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        spinBox = new QSpinBox(BoxGauss);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setSingleStep(1);
        spinBox->setValue(3);

        horizontalLayout_3->addWidget(spinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(BoxGauss);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(BoxGauss);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        doubleSpinBox = new QDoubleSpinBox(BoxGauss);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setEnabled(false);
        doubleSpinBox->setReadOnly(false);
        doubleSpinBox->setValue(1);

        horizontalLayout_4->addWidget(doubleSpinBox);

        label_3 = new QLabel(BoxGauss);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        doubleSpinBox_2 = new QDoubleSpinBox(BoxGauss);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setReadOnly(false);
        doubleSpinBox_2->setValue(1);

        horizontalLayout_4->addWidget(doubleSpinBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(BoxGauss);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        lineEdit = new QLineEdit(BoxGauss);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit);

        plainTextEdit = new QPlainTextEdit(BoxGauss);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setEnabled(true);
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setBackgroundVisible(false);

        verticalLayout_2->addWidget(plainTextEdit);


        retranslateUi(BoxGauss);

        QMetaObject::connectSlotsByName(BoxGauss);
    } // setupUi

    void retranslateUi(QWidget *BoxGauss)
    {
        BoxGauss->setWindowTitle(QApplication::translate("BoxGauss", "Form", 0));
        label->setText(QApplication::translate("BoxGauss", "Matrix Size:", 0));
        pushButton->setText(QApplication::translate("BoxGauss", "Box Filter", 0));
        label_2->setText(QApplication::translate("BoxGauss", "Average:", 0));
        label_3->setText(QApplication::translate("BoxGauss", "Variance:", 0));
        pushButton_3->setText(QApplication::translate("BoxGauss", "Gauss Filter", 0));
    } // retranslateUi

};

namespace Ui {
    class BoxGauss: public Ui_BoxGauss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXGAUSS_H
