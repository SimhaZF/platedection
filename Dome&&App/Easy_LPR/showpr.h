#ifndef SHOWPR_H
#define SHOWPR_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QProcess>
#include <QString>
#include <QDateTime>
#include "logolabel.h"
#include <QApplication>
#include <iostream>
#include "include/easypr.h"
#include "include/easypr/util/switch.hpp"
#include "include/easypr/core/plate.hpp"
#include <QDir>
#include <QFileDialog>
#include <QStringList>
#include <QDateTime>

namespace Ui {
class showpr;
}

class showpr : public QMainWindow
{
    Q_OBJECT

public:
    explicit showpr(QWidget *parent = 0);
    ~showpr();

private:
    Ui::showpr *ui;
    QString dirs;
    QDateTime time;
    int num_now;
    QString dir;
    int num_cliked;

public slots:
    void ReleaseClicked();

    void PressClicked();

    void ReleaseClicked_8();

    void PressClicked_8();

    void ReleaseClicked_6();

    void PressClicked_6();

    void ReleaseClicked_7();

    void PressClicked_7();

    void Resnigez(QString targ_dir);

    void ListRowNum(int);
private slots:
    void on_listWidget_clicked(const QModelIndex &index);
};

#endif // SHOWPR_H
