#include "annotationfile.h"
#include <iostream>
#include <fstream>

AnnotationFile::AnnotationFile(std::string filename, im_width, im_height)
{
    this->filename = filename;
    this->image_width = im_width;
    this->image_height = im_height;
    read_file_YOLO();
    YOLO_tobbox();
}

AnnotationFile::read_file_YOLO()
{
    std::fstream annotation_file (this->filename, ios::app);

    if (annotation_file.is_open()){
        while(annotation_file) { // always check whether the file is open
            std::string line;
            YOLObox box;
            std::getline (annotation_file, line);
            char *ptr; // declare a ptr pointer
            ptr = strtok(line, " "); // split the line into class id, yoloxmin, yoloymin, yolowidth, yoloheight
            this->class_id.append(std::stou(ptr));
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

AnnotationFile::YOLO_tobbox()
{
    for (YOLObox & yolobox : this->yoloboxes)
    {
        BoundingBox box;

        box.xmin = yolobox.scaled_xmin * this->image_width;
        box.ymin = yolobox.scaled_ymin * this->image_height;
        uint16_t width = yolobox.scaled_width * this->image_width;
        uint16_t height = yolobox.scaled_heigth * this->image_height;
        box.xmax = box.xmin + width;
        box.ymax = box.ymin + height;

        this->bboxes.append(box);
    }
}
