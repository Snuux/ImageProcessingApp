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
#include <QtWidgets/QPlainTextEdit>
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
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CurveCorrection)
    {
        if (CurveCorrection->objectName().isEmpty())
            CurveCorrection->setObjectName(QStringLiteral("CurveCorrection"));
        CurveCorrection->resize(409, 453);
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
        doubleSpinBox_2->setDecimals(3);
        doubleSpinBox_2->setSingleStep(0.001);
        doubleSpinBox_2->setValue(2);

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
        doubleSpinBox_4->setDecimals(3);
        doubleSpinBox_4->setMinimum(-99.99);
        doubleSpinBox_4->setSingleStep(0.001);
        doubleSpinBox_4->setValue(2);

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
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(custom_plot->sizePolicy().hasHeightForWidth());
        custom_plot->setSizePolicy(sizePolicy1);
        custom_plot->setMinimumSize(QSize(0, 300));

        verticalLayout_6->addWidget(custom_plot);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, -1);
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_8->addWidget(pushButton_3);


        verticalLayout_6->addLayout(horizontalLayout_8);

        plainTextEdit = new QPlainTextEdit(tab_3);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);
        plainTextEdit->setMaximumSize(QSize(16777215, 47));

        verticalLayout_6->addWidget(plainTextEdit);

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
        label_6->setText(QApplication::translate("CurveCorrection", "Custom Points (x,y,x,y,x,y...):", 0));
        pushButton_3->setText(QApplication::translate("CurveCorrection", "Apply", 0));
        plainTextEdit->setPlainText(QApplication::translate("CurveCorrection", "0 0.00 1 0.01 2 0.02 3 0.03 4 0.04 5 0.05 6 0.06 7 0.07 8 0.08 9 0.09 10 0.10 11 0.10 12 0.11 13 0.12 14 0.13 15 0.14 16 0.15 17 0.16 18 0.16 19 0.17 20 0.18 21 0.19 22 0.20 23 0.21 24 0.21 25 0.22 26 0.23 27 0.24 28 0.24 29 0.25 30 0.26 31 0.27 32 0.27 33 0.28 34 0.29 35 0.30 36 0.30 37 0.31 38 0.32 39 0.32 40 0.33 41 0.34 42 0.34 43 0.35 44 0.36 45 0.36 46 0.37 47 0.37 48 0.38 49 0.39 50 0.39 51 0.40 52 0.41 53 0.41 54 0.42 55 0.42 56 0.43 57 0.43 58 0.44 59 0.45 60 0.45 61 0.46 62 0.46 63 0.47 64 0.47 65 0.48 66 0.48 67 0.49 68 0.49 69 0.50 70 0.50 71 0.51 72 0.51 73 0.52 74 0.52 75 0.53 76 0.53 77 0.54 78 0.54 79 0.55 80 0.55 81 0.56 82 0.56 83 0.56 84 0.57 85 0.57 86 0.58 87 0.58 88 0.59 89 0.59 90 0.59 91 0.60 92 0.60 93 0.61 94 0.61 95 0.61 96 0.62 97 0.62 98 0.62 99 0.63 100 0.63 101 0.64 102 0.64 103 0.64 104 0.65 105 0.65 106 0.65 107 0.66 108 0.66 109 0.66 110 0.67 111 0.67 112 0.67 113 0.68 114 0.68 115 0.68 116 0.69 117 0.69 118 0.69 119 0.70 120 0.70 121 0.70 122 0.70 123 0.71 124 0.71 125 0.71 1"
                        "26 0.72 127 0.72 128 0.72 129 0.72 130 0.73 131 0.73 132 0.73 133 0.74 134 0.74 135 0.74 136 0.74 137 0.75 138 0.75 139 0.75 140 0.75 141 0.76 142 0.76 143 0.76 144 0.76 145 0.77 146 0.77 147 0.77 148 0.77 149 0.77 150 0.78 151 0.78 152 0.78 153 0.78 154 0.79 155 0.79 156 0.79 157 0.79 158 0.79 159 0.80 160 0.80 161 0.80 162 0.80 163 0.80 164 0.81 165 0.81 166 0.81 167 0.81 168 0.81 169 0.82 170 0.82 171 0.82 172 0.82 173 0.82 174 0.82 175 0.83 176 0.83 177 0.83 178 0.83 179 0.83 180 0.83 181 0.84 182 0.84 183 0.84 184 0.84 185 0.84 186 0.84 187 0.85 188 0.85 189 0.85 190 0.85 191 0.85 192 0.85 193 0.85 194 0.86 195 0.86 196 0.86 197 0.86 198 0.86 199 0.86 200 0.86 201 0.87 202 0.87 203 0.87 204 0.87 205 0.87 206 0.87 207 0.87 208 0.88 209 0.88 210 0.88 211 0.88 212 0.88 213 0.88 214 0.88 215 0.88 216 0.88 217 0.89 218 0.89 219 0.89 220 0.89 221 0.89 222 0.89 223 0.89 224 0.89 225 0.89 226 0.90 227 0.90 228 0.90 229 0.90 230 0.90 231 0.90 232 0.90 233 0.90 234 0.90 235 0.90 236 0.91 237 0.91 238 0.91 239 0.91 "
                        "240 0.91 241 0.91 242 0.91 243 0.91 244 0.91 245 0.91 246 0.91 247 0.92 248 0.92 249 0.92 250 0.92 251 0.92 252 0.92 253 0.92 254 0.92 255 0.92 ", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("CurveCorrection", "Custom Curve Correction", 0));
    } // retranslateUi

};

namespace Ui {
    class CurveCorrection: public Ui_CurveCorrection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVECORRECTION_H
