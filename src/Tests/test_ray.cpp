#include "../vec3.h"
#include "../ray.h"
#include <iostream>
#include <cassert>
#include <cmath>


using namespace std;

int main(){
    point3 origin(0,1,0);
    vec3 direction(1,2,3);
    double t = 2;
    ray ray1(origin,direction);

    cout << "=== TESTS RAY ===" << endl;
    assert(ray1.point_at(t) == vec3(2,5,6));
    cout << "point_at test passed" << endl;
}