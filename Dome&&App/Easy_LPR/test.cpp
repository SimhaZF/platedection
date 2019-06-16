#include "test.h"
#include "ui_test.h"
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>

using namespace easypr;
using namespace cv;
using namespace std;

test::test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);

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
    ui->label_5->setImageSize(80,80);
    ui->label_5->setQPixmapPath(":/new/prefix1/pictures/back_off.png");
    ui->label_5->setRotate(false);
    ui->label_5->setMagnify(false);
    ui->label_5->setImageTransparency(255);

    ui->label_6->setImageSize(101,31);
    ui->label_6->setQPixmapPath(":/new/prefix1/pictures/image_off.png");
    ui->label_6->setRotate(false);
    ui->label_6->setMagnify(false);
    ui->label_6->setImageTransparency(255);

    connect(ui->label_5, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked()));
    connect(ui->label_5, SIGNAL(clicked()), this, SLOT(PressClicked()));
    connect(ui->label_6, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked_1()));
    connect(ui->label_6, SIGNAL(clicked()), this, SLOT(PressClicked_1()));
}

test::~test()
{
    delete ui;
}

void test::PressClicked()
{
    ui->label_5->setQPixmapPath(":/new/prefix1/pictures/back_on.png");
}
void test::ReleaseClicked()
{
    ui->label_5->setQPixmapPath(":/new/prefix1/pictures/back_off.png");
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

//打开目录并识别车牌
void test::PressClicked_1(void)
{
    ui->label_6->setQPixmapPath(":/new/prefix1/pictures/image_on.png");
}
void test::ReleaseClicked_1(void)
{
     ui->label_6->setQPixmapPath(":/new/prefix1/pictures/image_off.png");

     //目录字符串处理
     QString targ_dir = QFileDialog::getOpenFileName(this);
     if(targ_dir.isEmpty ())
         return;
     ui->lineEdit->setText(targ_dir);
     String num_data;
     num_data = targ_dir.toStdString();

     //车牌读取
     CPlateRecognize pr;
     pr.setDetectType(PR_DETECT_CMSER | PR_DETECT_COLOR);
     vector<CPlate> plateVec;
     Mat src = imread(num_data);
     pr.setLifemode(true);  //开启生活模式，增加鲁棒性
     pr.setMaxPlates(4);    //识别车牌数目
     int result = pr.plateRecognize(src, plateVec);
     if(result)
     {
         QMessageBox::warning(this,"错误","无法识别车牌信息，请重新输入图像！",QMessageBox::Yes);
         return;
     }
     pr.setResultShow(false);
     pr.getDetectShow();
     CPlate plate = plateVec.at(0);
     Mat plateMat = plate.getPlateMat();  //车牌截取图片读取
     string license = plate.getPlateStr();
     QString lice1 = QString::fromLocal8Bit(license.c_str());

     //图片显示
     cvtColor(src,src,CV_BGR2RGB);//opencv读取图片按照BGR方式读取，为了正常显示，所以将BGR转为RGB
     QImage showImage((const uchar*)src.data,src.cols,src.rows,src.cols*src.channels(),QImage::Format_RGB888);
     ui->label_2->setPixmap(QPixmap::fromImage(showImage));

     //车牌截取显示
     cvtColor(plateMat,plateMat,CV_BGR2RGB);//opencv读取图片按照BGR方式读取，为了正常显示，所以将BGR转为RGB
     QImage showImage_1((const uchar*)plateMat.data,plateMat.cols,plateMat.rows,plateMat.cols*plateMat.channels(),QImage::Format_RGB888);
     ui->label_3->setPixmap(QPixmap::fromImage(showImage_1));

     //识别信息显示
     ui->label_4->setText(lice1);

     /*
     QFile file(targ_dir);
     if(file.open(QIODevice::ReadOnly))
     {
         QString hex_data = file.readAll();
     }
     file.close();*/
}


