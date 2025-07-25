#ifndef POINT_H
#define POINT_H

#include "vec3.h"

class point{
public:

    vec3 position;
    vec3 couleur;

    point(vec3 position_, vec3 couleur_);

};

#endif