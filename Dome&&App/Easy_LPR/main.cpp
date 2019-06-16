#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        MainWindow w;
        w.setWindowTitle(QString("车牌识别系统"));
        w.show();
        return a.exec();
        /*
        QApplication a(argc, argv);
        CPlateRecognize pr;
        pr.setDetectType(PR_DETECT_CMSER | PR_DETECT_COLOR);

        vector<CPlate> plateVec;
        Mat src = imread("C://Users//Administrator//Desktop//good_park_test//BB960G.jpg");
        pr.setResultShow(true);
        int result = pr.plateRecognize(src, plateVec);
        pr.getDetectShow();
        CPlate plate = plateVec.at(0);
        string license = plate.getPlateStr();
        QString lice1 = QString::fromLocal8Bit(license.c_str());

        qDebug()<<lice1;
        //demo::test_plate_detect();
        */
        return 0;
}
