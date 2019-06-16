#include "Tool.h"

Tool::Tool()
{
}
//设置图片旋转度数
void Tool::setPixMapRotate(QPixmap &pix, int rotateNumber ){
    int imageWidth = pix.width();
    int imageHeight = pix .height();

    QPixmap temp(pix.size());
    temp.fill(Qt::transparent);
    QPainter  painter(&temp);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.translate(imageWidth / 2, imageHeight / 2); //让图片的中心作为旋转的中心
    painter.rotate(rotateNumber); //顺时针旋转90度
    painter.translate(-(imageWidth / 2), -(imageHeight / 2)); //使原点复原
    painter.drawPixmap(0, 0,   pix);
    painter.end();
    pix = temp;
}
//设置图片透明度
void Tool::setPixMapTransparency(  QPixmap &pix,int transparencyNumber){
    QPixmap temp(pix.size());
    temp.fill(Qt::transparent);
    QPainter  imagePain(&temp);
    imagePain.setCompositionMode(QPainter::CompositionMode_Source);
    imagePain.drawPixmap(0, 0, pix);
    imagePain.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    imagePain.fillRect(temp.rect(), QColor(0, 0, 0, transparencyNumber));
    imagePain.end();
    pix = temp;
}

Tool::~Tool()
{
}
