#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "selectwindow.h"

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
    void up_time();

    void PressClicked();

    void ReleaseClicked();

    void PressClicked_8();

    void ReleaseClicked_8();

    void PressClicked_9();

    void ReleaseClicked_9();

private:
    Ui::MainWindow *ui;
     QProcess *mpro;
     QTimer *mtimer;
     QDateTime time;
     selectwindow *w;

};

#endif // MAINWINDOW_H
