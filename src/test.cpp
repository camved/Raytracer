#include <iostream>
#include "vec3.h"
#include <cassert>
#include <cmath>
#include "ray.h" 

int main(){

    // Initialisation des vecteurs de tests
    vec3 a(1.0, 3.5, 7.2);
    vec3 b(2.0, 3.0, 8.4);
    double t = 5.0;
    vec3 c(1.0, 2.0, 3.0);
    double expected = std::sqrt(14);
    double eps = 1e-6;


    //initialisation des rayons tests
    vec3 o1(1.0, 2.0, 1.0);
    vec3 d1(1.0 ,2.0 ,3.0);
    double t2 = 2.0;

    ray ray1(o1, d1);


        //TESTS
    vec3 d = a+b;
    std::cout << d << std::endl;
    assert(a + b == vec3(3, 6.5, 15.6));
    std::cout << "Test addition ok" << std::endl;

    assert(a - b == vec3(-1, 0.5, -1.2));
    std::cout << "Test soustraction ok" << std::endl;

    assert(a * t == vec3(5, 17.5, 36));
    std::cout << "Test multiplication ok" << std::endl;

    assert(almost_equal(c.length(), std::sqrt(14)));
    std::cout << "Test norme ok" << std::endl;

    assert(areRaysEqual(ray1,ray1));
    std::cout << "Test cpomparateur rayons ok" << std::endl;

    assert(ray1.point_at(t2) == vec3(3.0, 6.0, 7.0));
    std::cout << "Test point_at rayons ok" << std::endl;

};