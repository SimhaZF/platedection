#include "selectwindow.h"
#include "ui_selectwindow.h"
#include <QPropertyAnimation>

selectwindow::selectwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::selectwindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("设置菜单"));

    //窗口动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(1000);
    animation->setStartValue(QRect(2000, 30, 100, 30));
    animation->setEndValue(QRect(40, 30, 100, 30));

    QPropertyAnimation *animations = new QPropertyAnimation(this, "windowOpacity");
    animations->setDuration(1000);
    animations->setStartValue(0);
    animations->setEndValue(1);
    animation->start();
    animations->start();

    //按钮效果
    ui->label_2->setImageSize(200,200);
    ui->label_2->setQPixmapPath(":/new/prefix1/pictures/sm_s.png");
    ui->label_2->setRotate(true);
    ui->label_2->setImageTransparency(255);

    ui->label_3->setImageSize(200,200);
    ui->label_3->setQPixmapPath(":/new/prefix1/pictures/sm_n.png");
    ui->label_3->setRotate(true);
    ui->label_3->setImageTransparency(255);

    //返回按钮
    ui->label_6->setImageSize(80,80);
    ui->label_6->setQPixmapPath(":/new/prefix1/pictures/back_off.png");
    ui->label_6->setRotate(false);
    ui->label_6->setMagnify(false);
    ui->label_6->setImageTransparency(255);

    connect(ui->label_2, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked()));
    connect(ui->label_2, SIGNAL(clicked()), this, SLOT(PressClicked()));
    connect(ui->label_3, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked_8()));
    connect(ui->label_3, SIGNAL(clicked()), this, SLOT(PressClicked_8()));
    connect(ui->label_6, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked_9()));
    connect(ui->label_6, SIGNAL(clicked()), this, SLOT(PressClicked_9()));

    //ui->label_4->hide();
    //ui->label_5->hide();
}

selectwindow::~selectwindow()
{
    delete ui;
}

//调试按钮
void selectwindow:: PressClicked(void)   //点击
{
    ui->label_2->setQPixmapPath(":/new/prefix1/pictures/sm_n.png");
}
void selectwindow::ReleaseClicked(void)  //释放
{
    ui->label_2->setQPixmapPath(":/new/prefix1/pictures/sm_s.png");
    p = new test(this);
    p->show();
    this->hide();
}

//演示按钮
void selectwindow:: PressClicked_8(void) //点击
{
    ui->label_3->setQPixmapPath(":/new/prefix1/pictures/sm_s.png");
}
void selectwindow:: ReleaseClicked_8(void) //释放
{
    ui->label_3->setQPixmapPath(":/new/prefix1/pictures/sm_n.png");
    m = new showpr(this);
    m->show();
    this->hide();
}

//返回按钮
void selectwindow:: PressClicked_9(void) //点击
{
    ui->label_6->setQPixmapPath(":/new/prefix1/pictures/back_on.png");
}
void selectwindow:: ReleaseClicked_9(void) //释放
{
    ui->label_6->setQPixmapPath(":/new/prefix1/pictures/back_off.png");
    int ret = QMessageBox::warning(this,"提示","是否真的要退出登录",QMessageBox::Yes,QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        ui->label_6->setQPixmapPath(":/new/prefix1/pictures/back_off.png");
        this->parentWidget()->show();
        QPropertyAnimation *animation = new QPropertyAnimation(this->parentWidget(), "geometry");
        animation->setDuration(1000);
        animation->setStartValue(QRect(-1240, 25, 100, 30));
        animation->setEndValue(QRect(40, 25, 100, 30));

        QPropertyAnimation *animations = new QPropertyAnimation(this->parentWidget(), "windowOpacity");
        animations->setDuration(1000);
        animations->setStartValue(0);
        animations->setEndValue(1);
        animation->start();
        animations->start();
        this->close();
    }
}
