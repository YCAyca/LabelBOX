#ifndef ANNOTATIONFILE_H
#define ANNOTATIONFILE_H

#include <opencv2/opencv.hpp>
#include <QString>
#include <QVector>
#include <string>


/* YOLObox annotation format

scaled_xmin = box_box_xmin / image_width
scaled_ymin = box_ymin / image_height
scaled_width = box_width / image_width
scaled_height = box_height / image_height

*/

struct BoundingBox{
    uint16_t xmin, ymin, xmax, ymax;
};


struct YOLObox{
    float scaled_xmin, scaled_ymin, scaled_width, scaled_height;
};

class AnnotationFile
{
public:
    AnnotationFile(std::string filename, uint16_t im_width, uint16_t im_height);
private:
    std::string filename;
    uint16_t image_width, image_height;
    QVector <uint16_t> class_ids;
    QVector <BoundingBox> bboxes;
    QVector <YOLObox> yoloboxes;
    void read_file_YOLO();
    void YOLO_tobbox();
    void bbox_toYOLO();
    void save_file_YOLO();

};

#endif // ANNOTATIONFILE_H
