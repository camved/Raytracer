#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3{
public:

double e[3];
vec3() : e{0,0,0}{}
vec3(double e0, double e1, double e2) : e{e0,e1,e2}{}

vec3 operator-() const  {return vec3(-e[0],-e[1],-e[2]);}
double operator[] (int i) const{return e[i];}
double& operator[](int i){return e[i];}

double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }


vec3& operator+=(const vec3& v){
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];

    return *this;
}

vec3&  operator*=(const double t){
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;

        return *this;
}

vec3& operator/=(const double t){
    if (t != 0 ){
        e[0] /= t;
        e[1] /= t;
        e[2] /= t;

        return *this;
    }
    
}

double length() const{
    return sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
}

};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << "(" << v.e[0]<< ", " <<  v.e[1] << ", " <<  v.e[2] <<")"; 
}

inline vec3 operator+ (const vec3 v1, const vec3 v2){
    return vec3(v1.e[0]+v2.e[0],v1.e[1]+v2.e[1], v1.e[2]+v2.e[2]);
}

inline vec3 operator- (const vec3 v1, const vec3 v2){
    return vec3(v1.e[0]-v2.e[0],v1.e[1]-v2.e[1], v1.e[2]-v2.e[2]);
}

inline vec3 operator* (const vec3 v1, const double t){
    return  vec3 (v1.e[0]*t,v1.e[1]*t,v1.e[2]*t) ;
}

inline vec3 operator/(const vec3 v1,double t){ 
    return v1 * (1/t);
}

inline double dot(vec3 v1, vec3 v2){
    return (v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2]);
}


inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

inline bool operator==(const vec3& a, const vec3& b) {  // ← inline ajouté
    double epsilon = 1e-6;
    return std::abs(a.e[0] - b.e[0]) < epsilon  // ← std::abs
        && std::abs(a.e[1] - b.e[1]) < epsilon
        && std::abs(a.e[2] - b.e[2]) < epsilon;
}



#endif