/********************************************************************************
** Form generated from reading UI file 'curvecorrection.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVECORRECTION_H
#define UI_CURVECORRECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "libs/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CurveCorrection
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *gamma_plot;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *pushButton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QCustomPlot *s_plot;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    QCustomPlot *custom_plot;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CurveCorrection)
    {
        if (CurveCorrection->objectName().isEmpty())
            CurveCorrection->setObjectName(QStringLiteral("CurveCorrection"));
        CurveCorrection->resize(409, 378);
        verticalLayout = new QVBoxLayout(CurveCorrection);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(CurveCorrection);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gamma_plot = new QCustomPlot(tab);
        gamma_plot->setObjectName(QStringLiteral("gamma_plot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gamma_plot->sizePolicy().hasHeightForWidth());
        gamma_plot->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(gamma_plot);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(tab);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setSingleStep(0.001);
        doubleSpinBox->setValue(1);

        horizontalLayout->addWidget(doubleSpinBox);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(tab);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setSingleStep(0.001);
        doubleSpinBox_2->setValue(1);

        horizontalLayout_2->addWidget(doubleSpinBox_2);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        s_plot = new QCustomPlot(tab_2);
        s_plot->setObjectName(QStringLiteral("s_plot"));
        sizePolicy.setHeightForWidth(s_plot->sizePolicy().hasHeightForWidth());
        s_plot->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(s_plot);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(false);

        horizontalLayout_7->addWidget(label_5);

        spinBox = new QSpinBox(tab_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setMaximum(256);
        spinBox->setValue(127);

        horizontalLayout_7->addWidget(spinBox);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setMinimum(-99.99);
        doubleSpinBox_3->setSingleStep(0.001);
        doubleSpinBox_3->setValue(1);

        horizontalLayout_5->addWidget(doubleSpinBox_3);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        doubleSpinBox_4 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setMinimum(-99.99);
        doubleSpinBox_4->setSingleStep(0.001);
        doubleSpinBox_4->setValue(1);

        horizontalLayout_6->addWidget(doubleSpinBox_4);


        verticalLayout_4->addLayout(horizontalLayout_6);


        horizontalLayout_4->addLayout(verticalLayout_4);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        custom_plot = new QCustomPlot(tab_3);
        custom_plot->setObjectName(QStringLiteral("custom_plot"));

        verticalLayout_6->addWidget(custom_plot);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(CurveCorrection);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CurveCorrection);
    } // setupUi

    void retranslateUi(QWidget *CurveCorrection)
    {
        CurveCorrection->setWindowTitle(QApplication::translate("CurveCorrection", "Form", 0));
        label->setText(QApplication::translate("CurveCorrection", "Coefficient A:", 0));
        label_2->setText(QApplication::translate("CurveCorrection", "Coefficient Gamma:", 0));
        pushButton->setText(QApplication::translate("CurveCorrection", "Ok", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CurveCorrection", "Gamma Correction", 0));
        label_5->setText(QApplication::translate("CurveCorrection", "Middle Point:", 0));
        label_3->setText(QApplication::translate("CurveCorrection", "Coefficient A:", 0));
        label_4->setText(QApplication::translate("CurveCorrection", "Coefficient Gamma:", 0));
        pushButton_2->setText(QApplication::translate("CurveCorrection", "Ok", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CurveCorrection", "S-Correction", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("CurveCorrection", "Custom Curve Correction", 0));
    } // retranslateUi

};

namespace Ui {
    class CurveCorrection: public Ui_CurveCorrection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVECORRECTION_H
