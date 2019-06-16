#include "showpr.h"
#include "ui_showpr.h"

using namespace easypr;
using namespace cv;
using namespace std;

showpr::showpr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showpr)
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

    ui->label_4->setImageSize(60,60);
    ui->label_4->setQPixmapPath(":/new/prefix1/pictures/start_off.png");
    ui->label_4->setRotate(false);
    ui->label_4->setMagnify(false);
    ui->label_4->setImageTransparency(255);

    ui->label_5->setImageSize(60,60);
    ui->label_5->setQPixmapPath(":/new/prefix1/pictures/back_off_s.png");
    ui->label_5->setRotate(false);
    ui->label_5->setMagnify(false);
    ui->label_5->setImageTransparency(255);

    ui->label_6->setImageSize(41,61);
    ui->label_6->setQPixmapPath(":/new/prefix1/pictures/l_off.png");
    ui->label_6->setRotate(false);
    ui->label_6->setMagnify(false);
    ui->label_6->setImageTransparency(255);

    ui->label_7->setImageSize(41,61);
    ui->label_7->setQPixmapPath(":/new/prefix1/pictures/r_off.png");
    ui->label_7->setRotate(false);
    ui->label_7->setMagnify(false);
    ui->label_7->setImageTransparency(255);

    connect(ui->label_4, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked()));
    connect(ui->label_4, SIGNAL(clicked()), this, SLOT(PressClicked()));
    connect(ui->label_5, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked_8()));
    connect(ui->label_5, SIGNAL(clicked()), this, SLOT(PressClicked_8()));
    connect(ui->label_6, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked_6()));
    connect(ui->label_6, SIGNAL(clicked()), this, SLOT(PressClicked_6()));
    connect(ui->label_7, SIGNAL(rmclicked()), this, SLOT(ReleaseClicked_7()));
    connect(ui->label_7, SIGNAL(clicked()), this, SLOT(PressClicked_7()));

    ui->label_6->setEnabled(false);
    ui->label_7->setEnabled(false);

    //获取listWidget 的当前行行号
    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),this,SLOT(ListRowNum(int)));
}

showpr::~showpr()
{
    delete ui;
}

//开始按钮
void showpr::PressClicked(void)
{
    ui->label_4->setQPixmapPath(":/new/prefix1/pictures/start_on.png");
}
void showpr::ReleaseClicked(void)
{
    ui->label_4->setQPixmapPath(":/new/prefix1/pictures/start_off.png");

    //获取文件路径
    dir = QFileDialog::getExistingDirectory(this);
    if(dir.isEmpty())
        return;
    //过滤文件并显示在列表中
    QDir Dir(dir);
    QStringList filter;  //过滤器
    filter<<"*.png"<<"*.jpg";
    QStringList files = Dir.entryList(filter);
    if(files.isEmpty())
        return;
    ui->label_6->setEnabled(true);
    ui->label_7->setEnabled(true);
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    ui->listWidget->addItems(files);
    ui->listWidget->setCurrentRow(0);
    //识别列表第一个
    dirs = dir;
    dirs.append("/");
    dirs.append(ui->listWidget->item(0)->text());
    Resnigez(dirs);
    num_now = 0;
}

//返回按钮
void showpr::PressClicked_8(void)
{
    ui->label_5->setQPixmapPath(":/new/prefix1/pictures/back_on_s.png");
}
void showpr::ReleaseClicked_8(void)
{
    ui->label_5->setQPixmapPath(":/new/prefix1/pictures/back_off_s.png");
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

//上一张图片按钮
void showpr::PressClicked_6(void)
{
    ui->label_6->setQPixmapPath(":/new/prefix1/pictures/l_on.png");
}
void showpr::ReleaseClicked_6(void)
{
    ui->label_6->setQPixmapPath(":/new/prefix1/pictures/l_off.png");
    int num;
    int num_up;
    num = ui->listWidget->count(); //获取图片数目
    //是否是第一个，是就跳到最后一个循环
    if(num_cliked == 0)
    {
        num_cliked = num;
        num_cliked--;
        num_up = num_cliked;
    }
    else
    {
        num_cliked--;
        num_up = num_cliked;
    }

    //进行车牌识别并显示
    dirs = dir;
    dirs.append("/");
    dirs.append(ui->listWidget->item(num_up)->text());
    Resnigez(dirs);
    ui->listWidget->setCurrentRow(num_cliked);
}

//下一张图片按钮
void showpr::PressClicked_7(void)
{
    ui->label_7->setQPixmapPath(":/new/prefix1/pictures/r_on.png");
}
void showpr::ReleaseClicked_7(void)
{
    ui->label_7->setQPixmapPath(":/new/prefix1/pictures/r_off.png");
    int num;
    int num_down;
    num = ui->listWidget->count(); //获取图片数目
    //是否是最后一个，是就跳到第一个循环
    if(num_cliked == (num-1))
    {
        num_cliked = 0;
        num_down = num_cliked;
    }
    else
    {
        num_cliked++;
        num_down = num_cliked;
    }

    //进行车牌识别并显示
    dirs = dir;
    dirs.append("/");
    dirs.append(ui->listWidget->item(num_down)->text());
    Resnigez(dirs);
    ui->listWidget->setCurrentRow(num_cliked);
}

//识别车牌函数
void showpr::Resnigez(QString targ_dir)
{
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
    time = QDateTime::currentDateTime();
    ui->listWidget_2->addItem("识别结果："+lice1+"\n "+"\t"+time.toString("yyyy-MM-dd hh:mm:ss ddd"));
    ui->listWidget_2->scrollToBottom();
}

//获取当前行号
void showpr::ListRowNum(int num_now)
{
    qDebug() << "获取的行号：" << num_now;
    num_cliked = num_now;
}

//单击列表中的车牌
void showpr::on_listWidget_clicked(const QModelIndex &index)
{
    //进行车牌识别并显示
    ui->listWidget->setCurrentRow(num_cliked);
    dirs = dir;
    dirs.append("/");
    dirs.append(ui->listWidget->item(num_cliked)->text());
    Resnigez(dirs);
    ui->listWidget->setCurrentRow(num_cliked);
}
