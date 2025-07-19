#include "vec3.h"
#include <cmath>  

vec3::vec3() : x(0), y(0), z(0) {}
vec3::vec3(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}


//opérations

vec3 vec3::operator+(const vec3& v) const{
    return vec3(x+v.x, y+v.y, z+v.z);
}

vec3 vec3::operator-(const vec3& v) const{
    return vec3(x-v.x, y-v.y, z-v.z);
}

vec3 vec3::operator*(double v) const{
    return vec3(x*v, y*v, z*v);
}

double vec3::length() const{
    return std::sqrt(x*x+y*y+z*z);
}


bool operator==(const vec3& a, const vec3& b) {
    double epsilon = 1e-6;
    return std::abs(a.x - b.x) < epsilon 
        && std::abs(a.y - b.y) < epsilon 
        && std::abs(a.z - b.z) < epsilon;
}

bool almost_equal(double a, double b) {
    double eps = 1e-6;
    return std::abs(a - b) <  eps;
};

float vec3::dot(const vec3& v) const {
    return x * v.x + y * v.y + z * v.z;
}

std::ostream& operator<<(std::ostream& out, const vec3& v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

