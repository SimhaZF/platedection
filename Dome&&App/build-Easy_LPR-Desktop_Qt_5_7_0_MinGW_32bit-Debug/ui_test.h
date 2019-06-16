/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

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

class Ui_test
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    LogoLabel *label_5;
    LogoLabel *label_6;

    void setupUi(QMainWindow *test)
    {
        if (test->objectName().isEmpty())
            test->setObjectName(QStringLiteral("test"));
        test->resize(1280, 600);
        test->setMinimumSize(QSize(1280, 600));
        test->setMaximumSize(QSize(1280, 600));
        centralwidget = new QWidget(test);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1280, 600));
        label->setMinimumSize(QSize(1280, 600));
        label->setMaximumSize(QSize(1280, 600));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/pictures/bg1.jpg);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(38, 70, 620, 501));
        QFont font;
        font.setPointSize(70);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(36, 26, 511, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(860, 40, 561, 241));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral(""));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(700, 330, 481, 111));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font2.setPointSize(48);
        label_4->setFont(font2);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new LogoLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1190, 510, 80, 80));
        label_6 = new LogoLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(562, 27, 101, 31));
        test->setCentralWidget(centralwidget);

        retranslateUi(test);

        QMetaObject::connectSlotsByName(test);
    } // setupUi

    void retranslateUi(QMainWindow *test)
    {
        test->setWindowTitle(QApplication::translate("test", "MainWindow", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class test: public Ui_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
