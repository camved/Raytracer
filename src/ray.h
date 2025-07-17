#ifndef RAY_H
#define RAY_H


#include <ostream> 
#include "vec3.h"


class ray {
    public:

    vec3 origin;
    vec3 direction;
    
    ray();
    ray(vec3& origin_, vec3& direction_);

    //getteurs
    vec3 get_origin()const;
    vec3 get_direction()const;

    //méthodes
    vec3 point_at(double t)const;

};

bool areRaysEqual(const ray& r1, const ray& r2);
std::ostream& operator<<(std::ostream& out, const ray& r); //print

#endif