#include "ray.h"
#include "vec3.h"

//constructeur
ray::ray(vec3& origin_, vec3& direction_)
    : origin(origin_), direction(direction_) {}

//getteur
vec3 ray::get_origin() const{
    return origin;
}

vec3 ray::get_direction()const{
    return direction;
}

//méthodes
vec3 ray::point_at(double t)const{
    return direction*t + origin;
}

bool areRaysEqual(const ray& r1, const ray& r2) {
    return  r1.origin==r2.origin
        && r1.direction==r2.direction;
}

std::ostream& operator<<(std::ostream& out, const ray& r1) {
    out << "(Origine : " << r1.origin << ", Direction : " << r1.direction << ")";
    return out;
}

bool hit_Sphere(const ray& r1, float r_circle, vec3& ori_sphere ){
    vec3 oc = r1.origin -ori_sphere;
    float a = r1.direction.dot(r1.direction);
    float b = 2* oc.dot(r1.direction);
    float c = oc.dot(oc) - (r_circle*r_circle);

    float delta = (b*b) - (4*a*c);
    return (delta >= 0);
};

// vec3 intersection_point(const ray& r1, float r_circle, vec3& ori_sphere ){
//     vec3 oc = r1.origin -ori_sphere;
//     float a = r1.direction.dot(r1.direction);
//     float b = 2* oc.dot(r1.direction);
//     float c = oc.dot(oc) - (r_circle*r_circle);
//     float delta = (b*b) - (4*a*c);

//     if(delta<0) 
    

//     return 
// }

