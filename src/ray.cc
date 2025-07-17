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