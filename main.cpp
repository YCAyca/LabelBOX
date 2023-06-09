#include "mainwindow.h"
#include <iostream>
#include <QApplication>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char *argv[])
{
    #if __cplusplus >= 202002L
        // C++20 (and later) code
        cout << "C++20 (and later)" << endl;
    #endif

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
