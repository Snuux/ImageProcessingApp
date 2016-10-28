/********************************************************************************
** Form generated from reading UI file 'palette.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PALETTE_H
#define UI_PALETTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Palette
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Palette)
    {
        if (Palette->objectName().isEmpty())
            Palette->setObjectName(QStringLiteral("Palette"));
        Palette->resize(356, 292);
        verticalLayout = new QVBoxLayout(Palette);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Palette);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(Palette);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(255);
        spinBox->setValue(3);

        horizontalLayout->addWidget(spinBox);

        pushButton = new QPushButton(Palette);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(Palette);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        lineEdit = new QLineEdit(Palette);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        retranslateUi(Palette);

        QMetaObject::connectSlotsByName(Palette);
    } // setupUi

    void retranslateUi(QWidget *Palette)
    {
        Palette->setWindowTitle(QApplication::translate("Palette", "Form", 0));
        label->setText(QApplication::translate("Palette", "Color number:", 0));
        pushButton->setText(QApplication::translate("Palette", "Get Colors...", 0));
    } // retranslateUi

};

namespace Ui {
    class Palette: public Ui_Palette {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PALETTE_H
