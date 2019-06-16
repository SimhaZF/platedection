#ifndef TOOL_H
#define TOOL_H

#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <qsize.h>
class Tool :public QObject
{
    Q_OBJECT
public:
    Tool();
    ~Tool();
    static void setPixMapTransparency(  QPixmap &pix, int transparencyNumber=255);
    static void setPixMapRotate(QPixmap &pix, int rotateNumber = 0);
};

#endif // TOOL_H
