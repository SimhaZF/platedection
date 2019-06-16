#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QtSql/QSqlDriver>
#include <QApplication>
#include <QTextEdit>
#include <QObject>
#include <QDateTime>
#include <QCoreApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QVariantList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //时间
    mtimer = new QTimer;
    mpro = new QProcess;
    connect(mtimer,SIGNAL(timeout()),this,SLOT(up_time()));
    mtimer->start(1000);

    //窗口动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(1000);
    animation->setStartValue(QRect(40, -600, 100, 30));
    animation->setEndValue(QRect(40, 30, 100, 30));

    QPropertyAnimation *animations = new QPropertyAnimation(this, "windowOpacity");
    animations->setDuration(1000);
    animations->setStartValue(0);
    animations->setEndValue(1);
    animation->start();
    animations->start();

    //按钮动画
    ui->clear->setImageSize(80,80);
    ui->clear->setQPixmapPath(":/new/prefix1/pictures/clear_off.png");
    ui->clear->setMagnify(false);
    ui->clear->setImageTransparency(255);

    ui->close->setImageSize(80,80);
    ui->close->setQPixmapPath(":/new/prefix1/pictures/close_off.png");
    ui->close->setMagnify(false);
    ui->close->setImageTransparency(255);

    ui->label_5->setImageSize(80,80);
    ui->label_5->setQPixmapPath(":/new/prefix1/pictures/go_off.png");
    ui->label_5->setMagnify(false);
    ui->label_5->setImageTransparency(255);

    connect(ui->clear, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked()));
    connect(ui->clear, SIGNAL(clicked()), this, SLOT(PressClicked()));
    connect(ui->close, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked_8()));
    connect(ui->close, SIGNAL(clicked()), this, SLOT(PressClicked_8()));
    connect(ui->label_5, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked_9()));
    connect(ui->label_5, SIGNAL(clicked()), this, SLOT(PressClicked_9()));

    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*时间更新槽函数*/
void MainWindow::up_time()
{
    ui->label_4->setText(QTime::currentTime().toString("hh:mm"));
}

//清除按钮
void MainWindow::PressClicked(void)
{
    ui->clear->setQPixmapPath(":/new/prefix1/pictures/clear_on");
}
void MainWindow::ReleaseClicked(void)
{
    ui->clear->setQPixmapPath(":/new/prefix1/pictures/clear_off.png");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

//关机按钮
void MainWindow::PressClicked_8(void)
{
    ui->close->setQPixmapPath(":/new/prefix1/pictures/close_on.png");
}
void MainWindow::ReleaseClicked_8(void)
{
    ui->close->setQPixmapPath(":/new/prefix1/pictures/close_off.png");
    int ret = QMessageBox::warning(this,"提示","是否真的要退出系统？",QMessageBox::Yes,QMessageBox::No);
    if(ret == QMessageBox::Yes)
        this->close();
}

//登录按钮
void MainWindow::PressClicked_9(void)
{
    ui->label_5->setQPixmapPath(":/new/prefix1/pictures/go_on.png");
}
void MainWindow::ReleaseClicked_9(void)
{
    ui->label_5->setQPixmapPath(":/new/prefix1/pictures/go_off.png");

    //登录按钮，需要判断用户名和密码是否正确对应
    //如果错误弹出提示对话框

    //--------------------------------------
    //使用SQlite比对用户名和密码
   QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");

    database.setDatabaseName("user.db");




    if(database.open())
    {
        qDebug()<<"Database Opened";
        QSqlQuery query;//新建查询实例


        QString select_all_sql = "select * from zhanghao";
        query.prepare(select_all_sql);

        //如果数据库打开成功，就创建一个关联的QSqlQuery对象，最后由QSqlQuery来执行插入数据工作。
        //特别注意：QSqlQuery对象的创建必须在db文件open成功以后才行，否则会出错。
        if(query.exec())
        {
            //此处为访问所有的数据
            qDebug()<<"读取成功";
            //定义登陆界面的两个文本框输入的内容
            int uname=ui->lineEdit->text().toInt();
            int password=ui->lineEdit_2->text().toInt();
            qDebug()<<"create success";
            if(ui->lineEdit->text()==NULL||ui->lineEdit_2->text()==NULL)
            {
                //如果输入为空
                QMessageBox::warning(this,"提示","请输入账号或密码!",QMessageBox::Ok);
            }
            else
            {
                //输入不为空时
                int nameno=0;//用来seek处定位行数，索引
                while(query.next())//循环进行查找
                {
                    qDebug()<<"searchsuccess";
                    if(uname==query.value(1).toInt())//此处value（1）是存着学号的列
                    {
                        //value(int n) ：获得属性的值。其中n表示你查询的第n个属性，
                        //比方我们使用“select * from student”就相当于
                        //“select id, name from student”，那么value(0)返回id属性的值，value(1)返回name属性的值
                        nameno=query.value(0).toInt();//此处value（0）是存着序号的列
                    }
                    else
                    {
                        qDebug()<<"none";
                    }
                }
                if(query.seek(nameno))
                {
                    //seek(int n) ：query指向结果集的第n条记录。定位到刚刚找到的用户名（学号）对应的行，查找密码进行对比
                    qDebug()<<"select success";
                    int spassword=query.value(2).toInt();//读出此行存储的密码
                    qDebug()<<uname<<spassword;
                    if(spassword==password)
                    {
                        //如果密码匹配，跳转进入主界面
                        QMessageBox::information(NULL,QString(tr(" ")),
                                                     QString(tr("登录成功")));
                        qDebug()<<"login success";
                        w = new selectwindow(this);
                        w->show();
                        this->hide();
                    }
                    else
                    {//用户名和密码不对应
                        int ret = QMessageBox::warning(this,"提示","账号或密码错误，请重新输入!",QMessageBox::Ok);
                               if(ret == QMessageBox::Ok)
                               {
                                   ui->lineEdit->clear();
                                   ui->lineEdit_2->clear();
                               }
                     }
                }
            }
        }
    }
}
