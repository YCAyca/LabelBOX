#include "annotationfile.h"
#include <iostream>
#include <fstream>

AnnotationFile::AnnotationFile(std::string filename, uint16_t im_width, uint16_t im_height)
{
    this->filename = filename;
    this->image_width = im_width;
    this->image_height = im_height;
    read_file_YOLO();
    YOLO_tobbox();
}

void AnnotationFile::read_file_YOLO()
{
    std::fstream annotation_file (this->filename, std::ios::app);

    if (annotation_file.is_open()){
        while(annotation_file) { // always check whether the file is open
            std::string line;
            YOLObox box;
            std::getline (annotation_file, line);
            char *ptr; // declare a ptr pointer
            char* line_ = &line[0]; // getline requires string, strtok requires char *
            ptr = strtok(line_, " "); // split the line into class id, yoloxmin, yoloymin, yolowidth, yoloheight
            this->class_ids.append(std::stoi(ptr));
            ptr = strtok (NULL, " , ");
            box.scaled_xmin = std::stof(ptr);
            ptr = strtok (NULL, " , ");
            box.scaled_ymin = std::stof(ptr);
            ptr = strtok (NULL, " , ");
            box.scaled_width = std::stof(ptr);
            ptr = strtok (NULL, " , ");
            box.scaled_height = std::stof(ptr);
            this->yoloboxes.append(box);
        }
    }
    annotation_file.close();
}

void AnnotationFile::YOLO_tobbox()
{
    for (YOLObox & yolobox : this->yoloboxes)
    {
        BoundingBox box;

        box.xmin = yolobox.scaled_xmin * this->image_width;
        box.ymin = yolobox.scaled_ymin * this->image_height;
        uint16_t width = yolobox.scaled_width * this->image_width;
        uint16_t height = yolobox.scaled_height * this->image_height;
        box.xmax = box.xmin + width;
        box.ymax = box.ymin + height;

        this->bboxes.append(box);
    }
}
