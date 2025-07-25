#include "color.h"
#include "vec3.h"
#include "ray.h"
#include <iostream>

double hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - std::sqrt(discriminant) ) / (2.0*a);
    }
}

color ray_color(ray& r) {
    auto t = hit_sphere(point3(0,0,-1), 0.5, r);
    if (t > 0.0) {
        vec3 N = unit_vector(r.point_at(t) - vec3(0,0,-1));
        return color(N.x()+1, N.y()+1, N.z()+1)*0.5;
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return color(1.0, 1.0, 1.0)*a + color(0.5, 0.7, 1.0)*a;
}
int main() {
    // Image
    auto aspect_ratio = 16.0/9.0;
    int image_width = 400;
    
    // Calculate the image height, and ensure that it's at least 1.
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
    
    // Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
    auto camera_center = point3(0, 0, 0);
    
    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);
    
    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;
    
    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + (pixel_delta_u + pixel_delta_v) * 0.5;
    
    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    
    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        
        for (int i = 0; i < image_width; i++) {
            // CORRECTION MAJEURE : Utilisez vraiment la caméra et ray_color !
            auto pixel_center = pixel00_loc + (pixel_delta_u)*i  + (pixel_delta_v)*j;
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);
            
            color pixel_color = ray_color(r);  // ← MAINTENANT on utilise ray_color !
            write_color(std::cout, pixel_color);
        }
    }
    
    std::clog << "\rDone.\n";
    return 0;  // ← return au lieu de }
}