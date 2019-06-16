/********************************************************************************
** Form generated from reading UI file 'showpr.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPR_H
#define UI_SHOWPR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <logolabel.h>

QT_BEGIN_NAMESPACE

class Ui_showpr
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *listWidget;
    LogoLabel *label_4;
    LogoLabel *label_5;
    LogoLabel *label_6;
    LogoLabel *label_7;
    QListWidget *listWidget_2;

    void setupUi(QMainWindow *showpr)
    {
        if (showpr->objectName().isEmpty())
            showpr->setObjectName(QStringLiteral("showpr"));
        showpr->resize(1280, 600);
        showpr->setMinimumSize(QSize(1280, 600));
        showpr->setMaximumSize(QSize(1280, 600));
        centralwidget = new QWidget(showpr);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1280, 600));
        label->setMinimumSize(QSize(1280, 600));
        label->setMaximumSize(QSize(1280, 600));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/pictures/bg4.jpg);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 40, 691, 501));
        QFont font;
        font.setPointSize(70);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(770, 40, 481, 221));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral(""));
        label_3->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(770, 260, 221, 281));
        listWidget->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label_4 = new LogoLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(350, 540, 60, 60));
        label_5 = new LogoLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1220, 540, 60, 60));
        label_6 = new LogoLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 260, 41, 61));
        label_7 = new LogoLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(730, 260, 41, 61));
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(990, 260, 251, 281));
        listWidget_2->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        showpr->setCentralWidget(centralwidget);

        retranslateUi(showpr);

        QMetaObject::connectSlotsByName(showpr);
    } // setupUi

    void retranslateUi(QMainWindow *showpr)
    {
        showpr->setWindowTitle(QApplication::translate("showpr", "MainWindow", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class showpr: public Ui_showpr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPR_H
