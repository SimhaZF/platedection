#include "LogoLabel.h"

LogoLabel::LogoLabel(QWidget *parent) :
QLabel(parent)
{
}

LogoLabel::LogoLabel(const QString &text, QWidget *parent) :
QLabel(parent)
{
    setText(text);
}

//鼠标释放事件
void LogoLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
        emit rmclicked();//(this);
}
//鼠标压下事件
void LogoLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton)
        emit clicked();//(this);
}
//鼠标进入事件
void LogoLabel::enterEvent(QEvent *)
{
    this->setWindowOpacity(1);
    QPixmap tempLogoPix = logoPix.scaled(imageWidth, imageHeight);
    //如果可以旋转就启动定时器
    if (isRotate){
        rotateTimerId = startTimer(15);
    }
    //如果放大就设置图片发达1.5倍
    if (isMagnify){
        setImageSize(this->imageWidth*1.5, this->imageHeight*1.5);
    }
}
//设置图片大小事件
void LogoLabel::setImageSize(int imageWidth, int imageHeight){
    this->imageWidth = imageWidth;
    this->imageHeight = imageHeight;
}
//设置图片路劲
void LogoLabel::setQPixmapPath(QString path){
    pixmapPath = path;
    logoPix = QPixmap(path);
    QPixmap tempLogoPix = logoPix.scaled(imageWidth, imageHeight);
    Tool::setPixMapTransparency(tempLogoPix);
    this->setPixmap(tempLogoPix);
}
//设置图片透明度
void LogoLabel::setImageTransparency(int transNumber){
    QPixmap tempLogoPix = logoPix.scaled(imageWidth, imageHeight);
    Tool::setPixMapTransparency(tempLogoPix, transNumber);
    this->setPixmap(tempLogoPix);
}
//定时器
void LogoLabel::timerEvent(QTimerEvent *event){
    if (event->timerId() == rotateTimerId)
    {
        if (isRotate){
            //默认一次旋转2个角度
            rotateNumber += 2;
            QPixmap tempLogoPix = logoPix.scaled(imageWidth, imageHeight);
            Tool::setPixMapRotate(tempLogoPix, rotateNumber);
            this->setPixmap(tempLogoPix);
        }
        else{
            killTimer(rotateTimerId);
            rotateTimerId = 0;
        }
    }
    else{
        QWidget::timerEvent(event);
    }
}
//鼠标离开事件
void LogoLabel::leaveEvent(QEvent *)
{
    if (isRotate && (rotateTimerId != 0)){
        killTimer(rotateTimerId);
    }
    if (isMagnify){
        setImageSize(this->imageWidth / 1.5, this->imageHeight / 1.5);
    }
    QPixmap tempLogoPix = logoPix.scaled(imageWidth, imageHeight);
    Tool::setPixMapTransparency(tempLogoPix);
    this->setPixmap(tempLogoPix);
    rotateNumber = 0;
}
