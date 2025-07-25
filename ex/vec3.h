#ifndef VEC3_H
#define VEC3_H// Définir maintenant


#include <cmath>
#include <ostream>  // nécessaire pour std::ostream



class vec3 {
    public:
    
    
    double x;
    double y;
    double z;


    vec3(); //constructeur par défaut
    vec3(double x_, double y_, double z_); //constructeur


    vec3 operator+(const vec3& v) const; //addition
    vec3 operator-(const vec3& v) const; //soustraction
    vec3 operator*(double t) const; //multiplication
    double length() const; //norme du vecteur
    float dot(const vec3& v1) const;
    
};

using point3 = vec3;

bool operator==(const vec3& a, const vec3& b);
bool almost_equal(double a, double b);


std::ostream& operator<<(std::ostream& out, const vec3& v); //print

#endif