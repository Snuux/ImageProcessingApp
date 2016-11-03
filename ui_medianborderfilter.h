/********************************************************************************
** Form generated from reading UI file 'medianborderfilter.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIANBORDERFILTER_H
#define UI_MEDIANBORDERFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MedianBorderFilter
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MedianBorderFilter)
    {
        if (MedianBorderFilter->objectName().isEmpty())
            MedianBorderFilter->setObjectName(QStringLiteral("MedianBorderFilter"));
        MedianBorderFilter->resize(400, 300);
        verticalLayout = new QVBoxLayout(MedianBorderFilter);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(MedianBorderFilter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setValue(3);

        horizontalLayout->addWidget(spinBox);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MedianBorderFilter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(MedianBorderFilter);

        QMetaObject::connectSlotsByName(MedianBorderFilter);
    } // setupUi

    void retranslateUi(QWidget *MedianBorderFilter)
    {
        MedianBorderFilter->setWindowTitle(QApplication::translate("MedianBorderFilter", "Form", 0));
        groupBox->setTitle(QApplication::translate("MedianBorderFilter", "Median Filter", 0));
        label->setText(QApplication::translate("MedianBorderFilter", "Matrix size:", 0));
        pushButton->setText(QApplication::translate("MedianBorderFilter", "Apply", 0));
        groupBox_2->setTitle(QApplication::translate("MedianBorderFilter", "Sharpen Filter", 0));
        pushButton_2->setText(QApplication::translate("MedianBorderFilter", "Apply", 0));
    } // retranslateUi

};

namespace Ui {
    class MedianBorderFilter: public Ui_MedianBorderFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIANBORDERFILTER_H
