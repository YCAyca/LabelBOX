#ifndef IMAGE_H
#define IMAGE_H

#include <opencv2/opencv.hpp>
#include <QString>
#include "annotation.h"

class Image
{
public:
    Image(QString image_path);
private:
    cv::Mat image;
    QString image_name;
    std::tuple<uint16_t, uint16_t> size;
    Annotation annotations;
};

#endif // IMAGE_H
