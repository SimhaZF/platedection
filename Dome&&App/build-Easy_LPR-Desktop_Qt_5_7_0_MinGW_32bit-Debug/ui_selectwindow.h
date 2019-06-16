/********************************************************************************
** Form generated from reading UI file 'selectwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTWINDOW_H
#define UI_SELECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <logolabel.h>

QT_BEGIN_NAMESPACE

class Ui_selectwindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    LogoLabel *label_2;
    LogoLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    LogoLabel *label_6;

    void setupUi(QMainWindow *selectwindow)
    {
        if (selectwindow->objectName().isEmpty())
            selectwindow->setObjectName(QStringLiteral("selectwindow"));
        selectwindow->resize(1280, 600);
        selectwindow->setMinimumSize(QSize(1280, 600));
        selectwindow->setMaximumSize(QSize(1280, 600));
        centralwidget = new QWidget(selectwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1280, 600));
        label->setMinimumSize(QSize(1280, 600));
        label->setMaximumSize(QSize(1280, 600));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/pictures/bg1.png);"));
        label_2 = new LogoLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 30, 300, 300));
        label_3 = new LogoLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(800, 30, 300, 300));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(420, 510, 201, 61));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(660, 510, 201, 61));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new LogoLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 510, 80, 80));
        selectwindow->setCentralWidget(centralwidget);
        label->raise();
        label_3->raise();
        label_2->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();

        retranslateUi(selectwindow);

        QMetaObject::connectSlotsByName(selectwindow);
    } // setupUi

    void retranslateUi(QMainWindow *selectwindow)
    {
        selectwindow->setWindowTitle(QApplication::translate("selectwindow", "MainWindow", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QApplication::translate("selectwindow", "\350\260\203\350\257\225\346\250\241\345\274\217", 0));
        label_5->setText(QApplication::translate("selectwindow", "\346\274\224\347\244\272\346\250\241\345\274\217", 0));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class selectwindow: public Ui_selectwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTWINDOW_H
