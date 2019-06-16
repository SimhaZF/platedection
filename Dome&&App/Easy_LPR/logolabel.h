#ifndef LOGOLABEL_H
#define LOGOLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include "Tool.h"
#include "qdebug.h"
#include <QTimer>
#include <QTimerEvent>
class LogoLabel :public QLabel
{
    Q_OBJECT
public:
    explicit LogoLabel(QWidget *parent = 0);
    LogoLabel(const QString &text, QWidget *parent = 0);
    void setQPixmapPath(QString path);
    void setImageSize(int imageWidth, int imageHeight);
signals:
    // 鼠标单击信号
    void clicked();
    void rmclicked();
protected:
    // 鼠标单击事件
    void mousePressEvent(QMouseEvent *);    //压下
    void mouseReleaseEvent(QMouseEvent *);  //释放
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    //定时器
    void timerEvent(QTimerEvent *event);
private:
    //图片缓存（使用缓存技术免得重复打开图片造成浪费）
    QPixmap logoPix;
    //是否在旋转
    bool isRotate = true;
    bool isMagnify = true;
    //存储图片的大小
    int imageWidth = 0;
    int imageHeight = 0;
    //图片的地址
    QString pixmapPath;
    //旋转定时器
    int rotateTimerId;
    //旋转度数
    int rotateNumber = 0;
    public slots:
public :
    //按钮是否放大
    void setMagnify(bool isMagnify){
        this->isMagnify = isMagnify;
    }
    //按钮是否旋转
    void setRotate(bool isRotate){
        this->isRotate = isRotate;
    }
    //按钮旋转
    void setImageTransparency(int transNumber);
};

#endif // LOGOLABEL_H
