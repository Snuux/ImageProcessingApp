/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "binarization.h"
#include "brightnesscontrast.h"
#include "convolution.h"
#include "histogramchange.h"
#include "libs/qcustomplot.h"
#include "palette.h"
#include "scalerotate.h"
#include "togreyscale.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionImage_Size;
    QAction *actionBox_Blur;
    QAction *actionGaussian_Blur;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionConvert_to_Greyscale;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBox;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    HistogramChange *widget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    BrightnessContrast *widget_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_5;
    Palette *widget_3;
    QWidget *tab_7;
    QVBoxLayout *verticalLayout_6;
    Binarization *widget_4;
    QWidget *tab_8;
    QVBoxLayout *verticalLayout_7;
    ToGreyscale *widget_5;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout;
    ScaleRotate *widget_6;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_9;
    Convolution *widget_7;
    QWidget *tab_6;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuImage;
    QMenu *menuFilter;
    QMenu *menuBlur;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuFormat;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 495);
        MainWindow->setMinimumSize(QSize(1000, 0));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionImage_Size = new QAction(MainWindow);
        actionImage_Size->setObjectName(QStringLiteral("actionImage_Size"));
        actionBox_Blur = new QAction(MainWindow);
        actionBox_Blur->setObjectName(QStringLiteral("actionBox_Blur"));
        actionGaussian_Blur = new QAction(MainWindow);
        actionGaussian_Blur->setObjectName(QStringLiteral("actionGaussian_Blur"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionConvert_to_Greyscale = new QAction(MainWindow);
        actionConvert_to_Greyscale->setObjectName(QStringLiteral("actionConvert_to_Greyscale"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_8 = new QVBoxLayout(centralWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);

        horizontalLayout->addWidget(graphicsView);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setFlat(false);
        groupBox->setCheckable(true);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 9, -1, 9);
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_3->addWidget(comboBox);

        customPlot = new QCustomPlot(groupBox);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy2);
        customPlot->setMinimumSize(QSize(300, 200));
        customPlot->setBaseSize(QSize(0, 200));

        verticalLayout_3->addWidget(customPlot);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy3);
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new HistogramChange(tab);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_4->addWidget(widget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sizePolicy3.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy3);
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_2 = new BrightnessContrast(tab_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        verticalLayout_2->addWidget(widget_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_5 = new QVBoxLayout(tab_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        widget_3 = new Palette(tab_3);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        verticalLayout_5->addWidget(widget_3);

        tabWidget->addTab(tab_3, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        verticalLayout_6 = new QVBoxLayout(tab_7);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        widget_4 = new Binarization(tab_7);
        widget_4->setObjectName(QStringLiteral("widget_4"));

        verticalLayout_6->addWidget(widget_4);

        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        verticalLayout_7 = new QVBoxLayout(tab_8);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        widget_5 = new ToGreyscale(tab_8);
        widget_5->setObjectName(QStringLiteral("widget_5"));

        verticalLayout_7->addWidget(widget_5);

        tabWidget->addTab(tab_8, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout = new QVBoxLayout(tab_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_6 = new ScaleRotate(tab_4);
        widget_6->setObjectName(QStringLiteral("widget_6"));

        verticalLayout->addWidget(widget_6);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        verticalLayout_9 = new QVBoxLayout(tab_5);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        widget_7 = new Convolution(tab_5);
        widget_7->setObjectName(QStringLiteral("widget_7"));

        verticalLayout_9->addWidget(widget_7);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabWidget->addTab(tab_6, QString());

        verticalLayout_3->addWidget(tabWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(groupBox);


        verticalLayout_8->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuImage = new QMenu(menuBar);
        menuImage->setObjectName(QStringLiteral("menuImage"));
        menuFilter = new QMenu(menuBar);
        menuFilter->setObjectName(QStringLiteral("menuFilter"));
        menuBlur = new QMenu(menuFilter);
        menuBlur->setObjectName(QStringLiteral("menuBlur"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuFormat = new QMenu(menuEdit);
        menuFormat->setObjectName(QStringLiteral("menuFormat"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuImage->menuAction());
        menuBar->addAction(menuFilter->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuImage->addAction(actionImage_Size);
        menuFilter->addAction(menuBlur->menuAction());
        menuBlur->addAction(actionBox_Blur);
        menuBlur->addAction(actionGaussian_Blur);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(menuFormat->menuAction());
        menuFormat->addAction(actionConvert_to_Greyscale);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Export As...", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionImage_Size->setText(QApplication::translate("MainWindow", "Image Size...", 0));
        actionBox_Blur->setText(QApplication::translate("MainWindow", "Box Blur", 0));
        actionGaussian_Blur->setText(QApplication::translate("MainWindow", "Gaussian Blur", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0));
        actionConvert_to_Greyscale->setText(QApplication::translate("MainWindow", "Convert to Greyscale", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Histogram", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "RGB Channels", 0)
         << QApplication::translate("MainWindow", "Red Channel", 0)
         << QApplication::translate("MainWindow", "Green Channel", 0)
         << QApplication::translate("MainWindow", "Blue Channel", 0)
        );
        pushButton->setText(QApplication::translate("MainWindow", "Apply", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Revert", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "1. Histogram change", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "2. Brightness and Contrast", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "3. Palette", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "4. Binarization", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "5. To Greyscale", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "6. Scale and Rotate", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "7. Matrix Convolution", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "8. Gamma-, S-, Custom Curves", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuImage->setTitle(QApplication::translate("MainWindow", "Image", 0));
        menuFilter->setTitle(QApplication::translate("MainWindow", "Filter", 0));
        menuBlur->setTitle(QApplication::translate("MainWindow", "Blur", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuFormat->setTitle(QApplication::translate("MainWindow", "Format", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
