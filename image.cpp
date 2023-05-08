#include "image.h"
#include "annotationfile.h"
#include <string>

Image::Image(std::string image_path)
{
    this->image = cv::imread(image_path);
    char *ptr, *tmp;
    ptr = strtok(image_path, "/");

    while (ptr != NULL)
    {
       tmp = ptr;
       ptr = strtok (NULL, "/");
    }
    this->image_name = ptr;
    this->size = std::make_tuple(this->image.cols, this->image.height);
    this->annotation_file = AnnotationFile(annotation_file_path, this->image.cols, this->image.height);
}

Image::Image(const Image& im)
{
    this->image = im.image;
    this->image_name = im.image_name;
    this->size = im.size;
    this->annotation_file = im.annotation_file;
}


Image& Image::operator=(const Image& im)
{
    this->image = im.image;
    this->image_name = im.image_name;
    this->size = im.size;
    this->annotation_file = im.annotation_file;
    return *this;
}
