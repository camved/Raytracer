#include "../vec3.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std; 

int main(){

    cout << "=== TESTS VEC3 ===" << endl;

    vec3 a(1.0, 3.5, 7.2);
    vec3 b(2.0, 3.0, 8.4);
    double t = 5.0;
    vec3 c(1.0, 2.0, 3.0);
    double expected = std::sqrt(14);


    assert(a == a);
    std::cout << "Test égalité ok" << std::endl;
    assert(-a == vec3(-1,-3.5,-7.2));
    std::cout << "Test opposé ok" << std::endl;
    assert(a + b == vec3(3, 6.5, 15.6));
    std::cout << "Test addition ok" << std::endl;
    assert(a - b == vec3(-1, 0.5, -1.2));
    std::cout << "Test soustraction ok" << std::endl;
    assert(a * t == vec3(5, 17.5, 36));
    std::cout << "Test multiplication ok" << std::endl;
    assert((a / t) == vec3(0.2, 0.7, 1.44));
    std::cout << "Test division ok" << std::endl;
    assert(c.length() == expected);
    std::cout << "Test longueur double ok" << std::endl;
    assert(dot(a,b) == 72.98);
    std::cout << "Test dot ok" << std::endl;
    assert(cross(a,b) == vec3(7.8, 6,-4) );
    std::cout << "Test cross ok" << std::endl;
    assert(unit_vector(c) == c/sqrt(14));
    std::cout << "Test unit_vector ok" << std::endl;

}