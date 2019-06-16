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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <logolabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    LogoLabel *clear;
    LogoLabel *close;
    LogoLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 600);
        MainWindow->setMinimumSize(QSize(1280, 600));
        MainWindow->setMaximumSize(QSize(1280, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(0, 0, 1280, 600));
        label->setMinimumSize(QSize(1280, 600));
        label->setMaximumSize(QSize(1280, 600));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/pictures/ldbg.png);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(800, 270, 91, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(800, 340, 91, 51));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(870, 280, 191, 31));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit->setFont(font1);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(870, 350, 191, 31));
        lineEdit_2->setFont(font1);
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 0, 281, 161));
        QFont font2;
        font2.setPointSize(80);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setStyleSheet(QStringLiteral("color: rgb(43, 33, 67);"));
        label_4->setAlignment(Qt::AlignCenter);
        clear = new LogoLabel(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(800, 430, 80, 80));
        close = new LogoLabel(centralWidget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(900, 430, 80, 80));
        label_5 = new LogoLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1000, 430, 80, 80));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", 0));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("MainWindow", "00:00", 0));
        clear->setText(QString());
        close->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
