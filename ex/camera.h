#ifndef CAMERA_H
#define CAMERA_H


#include "vec3.h"
#include <iostream>


class camera{
    public:

    vec3 oeil;
    int image_width;
    int image_height;

    camera(); //constructeur par défaut
    camera(vec3 oeil_, int image_width_, int image_height_); //constructeur

};

#endif