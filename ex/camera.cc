#include "camera.h"

// vec3 oeil;
//     int image_width;
//     int image_height;

camera::camera() : oeil(0,0,0) , image_width(256), image_height(256){}
camera::camera(vec3 oeil_, int image_width_, int image_height_) : oeil(oeil_), image_width(image_width_), image_height(image_height_){}