#ifndef IMAGE_H
#define IMAGE_H

#include <opencv2/opencv.hpp>
#include <string>
#include "annotationfile.h"

class Image
{
public:
    Image(std::string image_path); // default constructor
    Image(const Image& im); // copy constructor
    Image& operator=(const Image& im); // assignment constructor
private:
    cv::Mat image;
    std::string image_name;
    std::tuple<uint16_t, uint16_t> size;
    AnnotationFile annotation_file;
};

#endif // IMAGE_H
