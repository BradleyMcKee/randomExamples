/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *displayOriginal;
    QLabel *displayOverlay;
    QLabel *displayOverlayNOHE;
    QPushButton *inputfile;
    QPushButton *inputfile_2;
    QPushButton *inputfile_3;
    QPushButton *inputfile_4;
    QPushButton *inputfile_5;
    QLabel *displayHE;
    QLabel *displayBright;
    QLabel *displayContrast;
    QSlider *brightnessSlider;
    QSlider *contrastSlider;
    QLabel *label;
    QLabel *label_2;
    QPushButton *inputfile_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1600, 900);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        displayOriginal = new QLabel(centralWidget);
        displayOriginal->setObjectName(QStringLiteral("displayOriginal"));
        displayOriginal->setGeometry(QRect(50, 50, 350, 340));
        displayOverlay = new QLabel(centralWidget);
        displayOverlay->setObjectName(QStringLiteral("displayOverlay"));
        displayOverlay->setGeometry(QRect(520, 50, 350, 340));
        displayOverlayNOHE = new QLabel(centralWidget);
        displayOverlayNOHE->setObjectName(QStringLiteral("displayOverlayNOHE"));
        displayOverlayNOHE->setGeometry(QRect(1080, 50, 350, 340));
        inputfile = new QPushButton(centralWidget);
        inputfile->setObjectName(QStringLiteral("inputfile"));
        inputfile->setGeometry(QRect(170, 410, 101, 22));
        inputfile_2 = new QPushButton(centralWidget);
        inputfile_2->setObjectName(QStringLiteral("inputfile_2"));
        inputfile_2->setGeometry(QRect(640, 410, 101, 22));
        inputfile_3 = new QPushButton(centralWidget);
        inputfile_3->setObjectName(QStringLiteral("inputfile_3"));
        inputfile_3->setGeometry(QRect(130, 830, 181, 22));
        inputfile_4 = new QPushButton(centralWidget);
        inputfile_4->setObjectName(QStringLiteral("inputfile_4"));
        inputfile_4->setGeometry(QRect(650, 830, 101, 22));
        inputfile_5 = new QPushButton(centralWidget);
        inputfile_5->setObjectName(QStringLiteral("inputfile_5"));
        inputfile_5->setGeometry(QRect(1210, 830, 101, 22));
        displayHE = new QLabel(centralWidget);
        displayHE->setObjectName(QStringLiteral("displayHE"));
        displayHE->setGeometry(QRect(40, 460, 350, 340));
        displayBright = new QLabel(centralWidget);
        displayBright->setObjectName(QStringLiteral("displayBright"));
        displayBright->setGeometry(QRect(520, 460, 350, 340));
        displayContrast = new QLabel(centralWidget);
        displayContrast->setObjectName(QStringLiteral("displayContrast"));
        displayContrast->setGeometry(QRect(1080, 460, 350, 340));
        brightnessSlider = new QSlider(centralWidget);
        brightnessSlider->setObjectName(QStringLiteral("brightnessSlider"));
        brightnessSlider->setGeometry(QRect(630, 810, 131, 20));
        brightnessSlider->setContextMenuPolicy(Qt::ActionsContextMenu);
        brightnessSlider->setMinimum(-50);
        brightnessSlider->setMaximum(50);
        brightnessSlider->setSliderPosition(25);
        brightnessSlider->setOrientation(Qt::Horizontal);
        contrastSlider = new QSlider(centralWidget);
        contrastSlider->setObjectName(QStringLiteral("contrastSlider"));
        contrastSlider->setGeometry(QRect(1210, 810, 111, 21));
        contrastSlider->setContextMenuPolicy(Qt::ActionsContextMenu);
        contrastSlider->setMinimum(-50);
        contrastSlider->setMaximum(50);
        contrastSlider->setSingleStep(1);
        contrastSlider->setPageStep(10);
        contrastSlider->setSliderPosition(5);
        contrastSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(780, 810, 101, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1330, 810, 101, 20));
        inputfile_6 = new QPushButton(centralWidget);
        inputfile_6->setObjectName(QStringLiteral("inputfile_6"));
        inputfile_6->setGeometry(QRect(1210, 410, 101, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        displayOriginal->setText(QString());
        displayOverlay->setText(QString());
        displayOverlayNOHE->setText(QString());
        inputfile->setText(QApplication::translate("MainWindow", "Browse for Image", Q_NULLPTR));
        inputfile_2->setText(QApplication::translate("MainWindow", "Browse for Overlay", Q_NULLPTR));
        inputfile_3->setText(QApplication::translate("MainWindow", "Save Histogram Equalized", Q_NULLPTR));
        inputfile_4->setText(QApplication::translate("MainWindow", "Save Image", Q_NULLPTR));
        inputfile_5->setText(QApplication::translate("MainWindow", "Save Image", Q_NULLPTR));
        displayHE->setText(QString());
        displayBright->setText(QString());
        displayContrast->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Brightness Slider", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Contrast Slider", Q_NULLPTR));
        inputfile_6->setText(QApplication::translate("MainWindow", "Save Image", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
