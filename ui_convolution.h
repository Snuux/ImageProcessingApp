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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *verticalSpacer;

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
        spinBox->setEnabled(false);
        spinBox->setValue(0);

        horizontalLayout->addWidget(spinBox);

        spinBox_2 = new QSpinBox(Convolution);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setEnabled(false);
        spinBox_2->setValue(0);

        horizontalLayout->addWidget(spinBox_2);

        checkBox = new QCheckBox(Convolution);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(false);
        checkBox->setChecked(true);

        horizontalLayout->addWidget(checkBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(Convolution);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBox = new QComboBox(Convolution);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

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

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        checkBox_2 = new QCheckBox(Convolution);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_2);

        pushButton = new QPushButton(Convolution);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        plainTextEdit = new QPlainTextEdit(Convolution);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Convolution);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Convolution);
    } // setupUi

    void retranslateUi(QWidget *Convolution)
    {
        Convolution->setWindowTitle(QApplication::translate("Convolution", "Form", 0));
        label->setText(QApplication::translate("Convolution", "Matrix Size:", 0));
        checkBox->setText(QApplication::translate("Convolution", "Auto", 0));
        label_4->setText(QApplication::translate("Convolution", "Preset:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Convolution", "Simple 3x3", 0)
         << QApplication::translate("Convolution", "Right Simple 3x3", 0)
         << QApplication::translate("Convolution", "Left Simple 3x3", 0)
         << QApplication::translate("Convolution", "Up Simple 3x3", 0)
         << QApplication::translate("Convolution", "Down Simple 3x3", 0)
         << QApplication::translate("Convolution", "Negative", 0)
         << QApplication::translate("Convolution", "Box 3x3", 0)
         << QApplication::translate("Convolution", "Box 3x3 Norm", 0)
         << QApplication::translate("Convolution", "Box 5x5", 0)
         << QApplication::translate("Convolution", "Box 5x5 Norm", 0)
         << QApplication::translate("Convolution", "Gauss 3x3", 0)
         << QApplication::translate("Convolution", "Gauss 3x3 Norm", 0)
         << QApplication::translate("Convolution", "Gauss 5x5", 0)
         << QApplication::translate("Convolution", "Gauss 5x5 Norm", 0)
         << QApplication::translate("Convolution", "Sharpen 3x3", 0)
         << QApplication::translate("Convolution", "Sharpen 5x5", 0)
        );
        label_2->setText(QApplication::translate("Convolution", "Divider:", 0));
        checkBox_2->setText(QApplication::translate("Convolution", "Normalize", 0));
        pushButton->setText(QApplication::translate("Convolution", "Ok", 0));
        plainTextEdit->setPlainText(QApplication::translate("Convolution", "1 1 1 \n"
"1 1 1 \n"
"1 1 1 ", 0));
    } // retranslateUi

};

namespace Ui {
    class Convolution: public Ui_Convolution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVOLUTION_H
