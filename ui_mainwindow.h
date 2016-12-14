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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
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
#include "addcolor.h"
#include "binarization.h"
#include "blackwhitepoint.h"
#include "boxgauss.h"
#include "brightnesscontrast.h"
#include "convolution.h"
#include "curvecorrection.h"
#include "histogramchange.h"
#include "hsvcorrection.h"
#include "libs/qcustomplot.h"
#include "medianborderfilter.h"
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
    QVBoxLayout *verticalLayout_14;
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
    QVBoxLayout *verticalLayout_10;
    CurveCorrection *widget_8;
    QWidget *tab_9;
    QVBoxLayout *verticalLayout_11;
    HSVCorrection *widget_9;
    QWidget *tab_10;
    QVBoxLayout *verticalLayout_12;
    BlackWhitePoint *widget_10;
    QWidget *tab_11;
    QVBoxLayout *verticalLayout_13;
    MedianBorderFilter *widget_11;
    QWidget *tab_12;
    QVBoxLayout *verticalLayout_16;
    AddColor *widget_13;
    QWidget *tab_13;
    QVBoxLayout *verticalLayout_3;
    BoxGauss *widget_12;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *applyButton;
    QPushButton *revertButton;
    QVBoxLayout *verticalLayout_15;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_17;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBox;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QCustomPlot *customPlot;
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
        MainWindow->resize(1000, 414);
        MainWindow->setMinimumSize(QSize(1000, 0));
        MainWindow->setIconSize(QSize(1, 1));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
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
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy1);
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
        sizePolicy1.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy1);
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
        verticalLayout_10 = new QVBoxLayout(tab_6);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        widget_8 = new CurveCorrection(tab_6);
        widget_8->setObjectName(QStringLiteral("widget_8"));

        verticalLayout_10->addWidget(widget_8);

        tabWidget->addTab(tab_6, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        verticalLayout_11 = new QVBoxLayout(tab_9);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        widget_9 = new HSVCorrection(tab_9);
        widget_9->setObjectName(QStringLiteral("widget_9"));

        verticalLayout_11->addWidget(widget_9);

        tabWidget->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        verticalLayout_12 = new QVBoxLayout(tab_10);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        widget_10 = new BlackWhitePoint(tab_10);
        widget_10->setObjectName(QStringLiteral("widget_10"));

        verticalLayout_12->addWidget(widget_10);

        tabWidget->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        verticalLayout_13 = new QVBoxLayout(tab_11);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        widget_11 = new MedianBorderFilter(tab_11);
        widget_11->setObjectName(QStringLiteral("widget_11"));

        verticalLayout_13->addWidget(widget_11);

        tabWidget->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        verticalLayout_16 = new QVBoxLayout(tab_12);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        widget_13 = new AddColor(tab_12);
        widget_13->setObjectName(QStringLiteral("widget_13"));

        verticalLayout_16->addWidget(widget_13);

        tabWidget->addTab(tab_12, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName(QStringLiteral("tab_13"));
        verticalLayout_3 = new QVBoxLayout(tab_13);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_12 = new BoxGauss(tab_13);
        widget_12->setObjectName(QStringLiteral("widget_12"));

        verticalLayout_3->addWidget(widget_12);

        tabWidget->addTab(tab_13, QString());

        verticalLayout_14->addWidget(tabWidget);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_14->addWidget(comboBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        applyButton = new QPushButton(centralWidget);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout_2->addWidget(applyButton);

        revertButton = new QPushButton(centralWidget);
        revertButton->setObjectName(QStringLiteral("revertButton"));
        revertButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(revertButton);


        verticalLayout_14->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy2);
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);

        verticalLayout_15->addWidget(graphicsView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_17->addItem(verticalSpacer);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_17->addWidget(checkBox);

        undoButton = new QPushButton(centralWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setEnabled(true);

        verticalLayout_17->addWidget(undoButton);

        redoButton = new QPushButton(centralWidget);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setEnabled(true);

        verticalLayout_17->addWidget(redoButton);


        horizontalLayout_3->addLayout(verticalLayout_17);

        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy3);
        customPlot->setMinimumSize(QSize(300, 100));
        customPlot->setBaseSize(QSize(0, 200));

        horizontalLayout_3->addWidget(customPlot);


        verticalLayout_15->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_15);


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

        tabWidget->setCurrentIndex(0);


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
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "1. Histogram change", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "2. Brightness and Contrast", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "3. Palette", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "4. Binarization", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "5. To Greyscale", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "6. Scale and Rotate", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "7. Matrix Convolution", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "8. Gamma-, S-, Custom Curves", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QApplication::translate("MainWindow", "9. HSV Correction", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QApplication::translate("MainWindow", "10. Choose B/W Points", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_11), QApplication::translate("MainWindow", "11-12. Median, Sharpen Filters", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_12), QApplication::translate("MainWindow", "13. Color Add", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_13), QApplication::translate("MainWindow", "14. Box, Gauss Filters", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "RGB Channels", 0)
         << QApplication::translate("MainWindow", "Red Channel", 0)
         << QApplication::translate("MainWindow", "Green Channel", 0)
         << QApplication::translate("MainWindow", "Blue Channel", 0)
        );
        applyButton->setText(QApplication::translate("MainWindow", "Apply", 0));
        revertButton->setText(QApplication::translate("MainWindow", "Revert", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Full/Half View", 0));
        undoButton->setText(QApplication::translate("MainWindow", "Undo", 0));
        redoButton->setText(QApplication::translate("MainWindow", "Redo", 0));
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
