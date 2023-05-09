#include "image.h"
#include "annotationfile.h"
#include <string>

Image::Image(std::string image_path)
{
    this->image = cv::imread(image_path);
    char *ptr, *tmp;
    char* path_ = &image_path[0];

    ptr = strtok(path_, "/");
    while (ptr != NULL)
    {
       tmp = ptr;
       ptr = strtok (NULL, "/");
    }
    this->image_name = tmp;
    this->size = std::make_tuple(this->image.cols, this->image.rows);

    std::string annotation_file_path = image_path;
    annotation_file_path.erase(annotation_file_path.begin()+(annotation_file_path.find(".")), annotation_file_path.end());
    annotation_file_path += ".txt";
    AnnotationFile annot(annotation_file_path, this->image.cols, this->image.rows);
    this->annotation_file = annot;
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
