#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QProcess>
#include <QString>
#include <QDateTime>
#include "logolabel.h"
#include "test.h"
#include "showpr.h"

namespace Ui {
class selectwindow;
}

class selectwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit selectwindow(QWidget *parent = 0);
    ~selectwindow();

private:
    Ui::selectwindow *ui;

    test *p;
    showpr *m;
public slots:
    void ReleaseClicked();

    void PressClicked();

    void ReleaseClicked_8();

    void PressClicked_8();

    void ReleaseClicked_9();

    void PressClicked_9();

};

#endif // SELECTWINDOW_H
