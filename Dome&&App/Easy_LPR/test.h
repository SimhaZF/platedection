#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QProcess>
#include <QString>
#include <QDateTime>
#include "logolabel.h"
#include <QFileDialog>
#include <qfile>
#include <QDebug>
#include <QIODevice>
#include <QApplication>
#include <iostream>
#include "G:\\platedection\\Dome&&App\\Easy_LPR\\include\\easypr.h"
#include "G:\\platedection\\Dome&&App\\Easy_LPR\\include\\easypr\\util\\switch.hpp"
#include "G:\\platedection\\Dome&&App\\Easy_LPR\\include\\easypr\\core\\plate.hpp"


namespace Ui {
class test;
}

class test : public QMainWindow
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = 0);
    ~test();

private:
    Ui::test *ui;

public slots:
    void ReleaseClicked();

    void PressClicked();

    void ReleaseClicked_1();

    void PressClicked_1();

};

#endif // TEST_H
