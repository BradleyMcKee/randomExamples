#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QDebug>
#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QFileDialog>


#include "frame.h"
#include "histequal.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_inputfile_clicked();

    void on_inputfile_2_clicked();

    void on_brightnessSlider_valueChanged(int value);

    void on_contrastSlider_valueChanged(int value);

    void on_inputfile_3_clicked();

    void on_inputfile_4_clicked();

    void on_inputfile_5_clicked();

    void on_inputfile_6_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QString originalFilename;
    QString overlayFilename;
    QString savef;


    QImage original, output;
    QFile temp,temp2,temp3,temp4;
};

#endif // MAINWINDOW_H
