#ifndef ANNOTATION_H
#define ANNOTATION_H

#include <opencv2/opencv.hpp>
#include <QString>

/* YOLObox annotation format

scaled_xmin = box_box_xmin / image_width
scaled_ymin = box_ymin / image_height
scaled_width = box_width / image_width
scaled_height = height / image_height

*/

struct BoundingBox{
    uint16_t xmin, ymin, xmax, ymax;
};


struct YOLObox{
    float scaled_xmin, scaled_ymin, scaled_width, scaled_height;
};

class Annotation
{
public:
    Annotation(QString filename);
private:
    vector <uint16_t> class_id;
    vector <BoundingBox> bbox;
    vector <YOLObox> yolobox;
};

#endif // ANNOTATION_H
